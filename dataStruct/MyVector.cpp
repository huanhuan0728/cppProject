// myVector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdexcept>

template <typename T>

class MyVector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
public:
    MyVector();
    ~MyVector();
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    void push_back(const T& value);
    size_t size() const;
    size_t capacity() const;

    // 访问操作
    T& operator[] (size_t index);
    const T& operator[] (size_t index) const;

private:
    void reallocate(size_t new_capacity);

};

template <typename T>
MyVector<T>::MyVector() :_data(nullptr), _size(0), _capacity(0) {
    std::cout << "MyVector default constructor called.\n"; << std::endl;
}

template <typename T>
size_t MyVector<T>::size() const {
    return _size;
}

template <typename T>
size_t MyVector<T>::capacity() const {
    return _capacity;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (_size >= _capacity)
    {
        size_t new_capacity = (_capacity == 0) ? 8 : _capacity * 2;
        reallocate(new_capacity);
    }

    //2. 在末尾添加新元素
    _data[_size] = value;
    _size++;
}

template <typename T>
void MyVector<T>::reallocate(size_t new_capacity) {
    std::cout << "Reallocating from" << _capacity << " to " << new_capacity << std::endl;

    //分配更大内存
    T* new_data = new T[new_capacity];

	//将旧数据复制到新内存
    if (data != nullptr)
    {
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }

        delete[] _data;
    }

    _data = new_data;
	capacity = new_capacity; 
}

template <typename T>
T& MyVector<T>::operator[](size_t index) { 
    if (index >= size) {
        throw std::out_of_range("Index out of range.");
    }
}

template <typename T>
const T& MyVector<T>::operator[](size_t index) const{
    if (index >= size) {
        throw std::out_of_range("Index out of range.");
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    std::cout << "Destructor called. Cleaning up memory." << std::endl;
    delete[] _data;//释放内存
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) : _data(nullptr), _size(other._size), _capacity(other._capacity) {
    std::cout << "Copy constructor callled" << std::endl;
    if (_capacity > 0)
    {
        _data = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    std::cout << "Copy assignment operator called." << endl;

    //防止自我赋值
    if (this == &other) {
        return *this;
    }

    //释放当前对象已有的资源
    delete[] _data;

    //进行深拷贝
    _size = other._size;
    _capacity = other._capacity;
    _data = nullptr;
    if (_capacity > 0) {
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    return *this;
}

int main()
{


    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
