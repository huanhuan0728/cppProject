#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <unordered_map>
using namespace std;

struct Contact
{
    string name;
    int sex; // 1-男，2-女
    int age;
    string phone;
    string address;
};

class AddressBook
{
private:
    vector<Contact> contacts;
    unordered_map<string, size_t> nameIndex;

    // 输入验证辅助函数
    template <typename T>
    T getValidatedInput(const string &prompt, const string &errorMsg,
                        bool (*validator)(const T &))
    {
        T value;
        while (true)
        {
            cout << prompt;
            if (cin >> value && validator(value))
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

public:
    void addContact(const Contact &contact)
    {
        if (nameIndex.find(contact.name) != nameIndex.end())
        {
            cout << "联系人已存在！" << endl;
            return;
        }
        contacts.push_back(contact);
        nameIndex[contact.name] = contacts.size() - 1;
        cout << "添加成功！" << endl;
    }

    void showContacts() const
    {
        if (contacts.empty())
        {
            cout << "通讯录为空" << endl;
            return;
        }
        cout << "\n======== 联系人列表 ========" << endl;
        for (const auto &c : contacts)
        {
            cout << "姓名: " << c.name << "\t性别: "
                 << (c.sex == 1 ? "男" : "女") << "\t年龄: " << c.age
                 << "\n电话: " << c.phone << "\n地址: " << c.address << "\n\n";
        }
        cout << "============================" << endl;
    }

    void deleteContact(const string &name)
    {
        auto it = nameIndex.find(name);
        if (it == nameIndex.end())
        {
            cout << "联系人不存在" << endl;
            return;
        }

        size_t index = it->second;
        if (index != contacts.size() - 1)
        {
            contacts[index] = contacts.back();
            nameIndex[contacts[index].name] = index;
        }
        contacts.pop_back();
        nameIndex.erase(it);
        cout << "删除成功" << endl;
    }

    void modifyContact()
    {
        string oldName;
        cout << "请输入要修改的联系人姓名：";
        getline(cin, oldName);

        auto it = nameIndex.find(oldName);
        if (it == nameIndex.end())
        {
            cout << "联系人不存在" << endl;
            return;
        }

        Contact newContact;
        cout << "请输入新姓名（原：" << contacts[it->second].name << "）：";
        getline(cin, newContact.name);

        if (!newContact.name.empty() && nameIndex.find(newContact.name) != nameIndex.end())
        {
            cout << "该姓名已存在！" << endl;
            return;
        }

        auto sexValidator = [](int s)
        { return s == 1 || s == 2; };
        newContact.sex = getValidatedInput<int>(
            "性别（1-男，2-女）：", "无效输入，请重新输入！", sexValidator);

        auto ageValidator = [](int a)
        { return a > 0; };
        newContact.age = getValidatedInput<int>(
            "年龄：", "年龄必须为正整数！", ageValidator);

        cout << "电话：";
        getline(cin, newContact.phone);
        cout << "地址：";
        getline(cin, newContact.address);

        // 更新数据
        if (!newContact.name.empty())
        {
            nameIndex.erase(oldName);
            nameIndex[newContact.name] = it->second;
            contacts[it->second].name = newContact.name;
        }
        contacts[it->second].sex = newContact.sex;
        contacts[it->second].age = newContact.age;
        contacts[it->second].phone = newContact.phone;
        contacts[it->second].address = newContact.address;
        cout << "修改成功！" << endl;
    }

    void saveToBinary(const string &filename) const
    {
        ofstream ofs(filename, ios::binary);
        if (!ofs)
        {
            cout << "文件创建失败" << endl;
            return;
        }

        size_t count = contacts.size();
        ofs.write(reinterpret_cast<const char *>(&count), sizeof(count));

        for (const auto &c : contacts)
        {
            size_t len = c.name.size();
            ofs.write(reinterpret_cast<const char *>(&len), sizeof(len));
            ofs.write(c.name.c_str(), len);

            ofs.write(reinterpret_cast<const char *>(&c.sex), sizeof(c.sex));
            ofs.write(reinterpret_cast<const char *>(&c.age), sizeof(c.age));

            len = c.phone.size();
            ofs.write(reinterpret_cast<const char *>(&len), sizeof(len));
            ofs.write(c.phone.c_str(), len);

            len = c.address.size();
            ofs.write(reinterpret_cast<const char *>(&len), sizeof(len));
            ofs.write(c.address.c_str(), len);
        }
        cout << "保存成功" << endl;
    }

    void loadFromBinary(const string &filename)
    {
        ifstream ifs(filename, ios::binary);
        if (!ifs)
        {
            cout << "文件打开失败" << endl;
            return;
        }

        contacts.clear();
        nameIndex.clear();

        size_t count;
        ifs.read(reinterpret_cast<char *>(&count), sizeof(count));

        for (size_t i = 0; i < count; ++i)
        {
            Contact c;
            size_t len;

            ifs.read(reinterpret_cast<char *>(&len), sizeof(len));
            c.name.resize(len);
            ifs.read(&c.name[0], len);

            ifs.read(reinterpret_cast<char *>(&c.sex), sizeof(c.sex));
            ifs.read(reinterpret_cast<char *>(&c.age), sizeof(c.age));

            ifs.read(reinterpret_cast<char *>(&len), sizeof(len));
            c.phone.resize(len);
            ifs.read(&c.phone[0], len);

            ifs.read(reinterpret_cast<char *>(&len), sizeof(len));
            c.address.resize(len);
            ifs.read(&c.address[0], len);

            if (nameIndex.find(c.name) == nameIndex.end())
            {
                contacts.push_back(c);
                nameIndex[c.name] = contacts.size() - 1;
            }
        }
        cout << "加载成功" << endl;
    }
};
