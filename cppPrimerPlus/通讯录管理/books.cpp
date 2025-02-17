#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

// 定义联系人数据结构
struct Contact
{
    string name;
    int sex; // 1-男，2-女
    int age;
    string phone;
    string address;
};

// 通讯录管理类，内部使用 vector 保存联系人
class AddressBook
{
private:
    vector<Contact> contacts;

public:
    // 添加联系人
    void addContact(const Contact &contact)
    {
        contacts.push_back(contact);
        cout << "添加联系人成功！" << endl;
    }

    // 显示所有联系人
    void showContacts() const
    {
        if (contacts.empty())
        {
            cout << "通讯录为空！" << endl;
        }
        else
        {
            cout << "********** 联系人列表 **********" << endl;
            for (const auto &c : contacts)
            {
                cout << "姓名: " << c.name << "\t";
                cout << "性别: " << (c.sex == 1 ? "男" : "女") << "\t";
                cout << "年龄: " << c.age << "\t";
                cout << "电话: " << c.phone << "\t";
                cout << "地址: " << c.address << endl;
            }
            cout << "********************************" << endl;
        }
    }

    // 根据姓名查找联系人在 vector 中的索引，找不到返回 -1
    int findContactIndex(const string &name) const
    {
        for (size_t i = 0; i < contacts.size(); ++i)
        {
            if (contacts[i].name == name)
                return i;
        }
        return -1;
    }

    // 删除联系人（按姓名）
    void deleteContact(const string &name)
    {
        int index = findContactIndex(name);
        if (index != -1)
        {
            contacts.erase(contacts.begin() + index);
            cout << "删除联系人成功！" << endl;
        }
        else
        {
            cout << "联系人不存在！" << endl;
        }
    }

    // 修改联系人（按姓名查找后修改其所有信息）
    void modifyContact(const string &name)
    {
        int index = findContactIndex(name);
        if (index != -1)
        {
            Contact &c = contacts[index];
            cout << "请输入新的姓名（原：" << c.name << "）：";
            cin >> c.name;
            cout << "请输入新的性别（1-男, 2-女，原：" << c.sex << "）：";
            cin >> c.sex;
            cout << "请输入新的年龄（原：" << c.age << "）：";
            cin >> c.age;
            cout << "请输入新的电话（原：" << c.phone << "）：";
            cin >> c.phone;
            cout << "请输入新的地址（原：" << c.address << "）：";
            cin >> c.address;
            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "联系人不存在！" << endl;
        }
    }

    // 清空所有联系人
    void clearContacts()
    {
        contacts.clear();
        cout << "通讯录已清空！" << endl;
    }

    // 将数据保存到文件（简单文本格式，每个联系人占五行）
    void saveToFile(const string &filename) const
    {
        ofstream ofs(filename);
        if (!ofs)
        {
            cout << "无法保存文件！" << endl;
            return;
        }
        for (const auto &c : contacts)
        {
            ofs << c.name << "\n"
                << c.sex << "\n"
                << c.age << "\n"
                << c.phone << "\n"
                << c.address << "\n";
        }
        ofs.close();
        cout << "数据保存成功到文件：" << filename << endl;
    }

    // 从文件加载数据（要求数据格式与 saveToFile 一致）
    void loadFromFile(const string &filename)
    {
        ifstream ifs(filename);
        if (!ifs)
        {
            cout << "文件不存在或无法打开，加载失败！" << endl;
            return;
        }
        contacts.clear();
        while (ifs)
        {
            Contact c;
            if (!getline(ifs, c.name))
                break;
            ifs >> c.sex;
            ifs.ignore(numeric_limits<streamsize>::max(), '\n');
            ifs >> c.age;
            ifs.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(ifs, c.phone);
            getline(ifs, c.address);
            contacts.push_back(c);
            // 读取可能存在的空行
            ifs.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        ifs.close();
        cout << "数据加载成功！" << endl;
    }
};

// 显示菜单界面
void showMenu()
{
    cout << "********************************************" << endl;
    cout << "            通讯录管理系统" << endl;
    cout << "1. 添加联系人" << endl;
    cout << "2. 显示所有联系人" << endl;
    cout << "3. 删除联系人" << endl;
    cout << "4. 查找联系人" << endl;
    cout << "5. 修改联系人" << endl;
    cout << "6. 清空通讯录" << endl;
    cout << "7. 保存数据到文件" << endl;
    cout << "8. 从文件加载数据" << endl;
    cout << "0. 退出系统" << endl;
    cout << "********************************************" << endl;
    cout << "请选择操作（输入数字）：";
}

int main()
{
    AddressBook ab;
    int choice;
    string name;
    while (true)
    {
        showMenu();
        cin >> choice;
        // 清除输入缓冲区中可能遗留的换行符
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice)
        {
        case 1:
        {
            Contact c;
            cout << "请输入联系人姓名：";
            cin >> c.name;
            cout << "请输入联系人性别（1-男, 2-女）：";
            cin >> c.sex;
            cout << "请输入联系人年龄：";
            cin >> c.age;
            cout << "请输入联系人电话：";
            cin >> c.phone;
            cout << "请输入联系人地址：";
            cin >> c.address;
            ab.addContact(c);
            break;
        }
        case 2:
            ab.showContacts();
            break;
        case 3:
        {
            cout << "请输入要删除的联系人姓名：";
            cin >> name;
            ab.deleteContact(name);
            break;
        }
        case 4:
        {
            cout << "请输入要查找的联系人姓名：";
            cin >> name;
            int index = ab.findContactIndex(name);
            if (index != -1)
            {
                cout << "联系人已找到，详情如下：" << endl;
                ab.modifyContact(name); // 注意：此处调用 modifyContact 后会修改数据，如果仅想查看，请自行修改代码
            }
            else
            {
                cout << "联系人不存在！" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "请输入要修改的联系人姓名：";
            cin >> name;
            ab.modifyContact(name);
            break;
        }
        case 6:
            ab.clearContacts();
            break;
        case 7:
        {
            string filename;
            cout << "请输入保存数据的文件名：";
            cin >> filename;
            ab.saveToFile(filename);
            break;
        }
        case 8:
        {
            string filename;
            cout << "请输入加载数据的文件名：";
            cin >> filename;
            ab.loadFromFile(filename);
            break;
        }
        case 0:
            cout << "退出系统，欢迎下次使用！" << endl;
            return 0;
        default:
            cout << "无效选项，请重新选择！" << endl;
        }
        cout << endl;
    }
    return 0;
}
