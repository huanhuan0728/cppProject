#include <iostream>
#include <string>

class ConstDemo{
    private:
    int modifiable;
    const std::string identifier;

    public:
    ConstDemo(int val, std::string id): modifiable(val), identifier(id){}

    int getValue() const{
        std::cout << "[调用const函数]getValue() -> 当前值为: " 
        << modifiable << std::endl;

        // 因为 const 成员函数不能修改任何非静态成员变量。
        // modifiableValue = 100; // 错误: assignment of member ‘ConstDemo::modifiableValue’ in read-only object

        return modifiable;
    }

    /**
     * @brief 一个普通（非 const）成员函数，可以修改对象的状态。
     * @param newValue 要设置的新值。
     */
    void setValue(int newValue)
    {
        std::cout << "[调用non-const函数setvalue()->将值从] " << modifiable 
        << "修改成 " << newValue << std::endl;

        this->modifiable = newValue;
    }

    //常成员函数只能调用其他常成员函数
    /**
     * @brief 一个常成员函数，用于演示调用限制。
     */
    void disPlay() const
    {
        std::cout << "\n[调用const函数]display() 开始..." << std::endl;

        // 允许: 在const成员函数在内部调用另外一个const函数
        getValue();

        //下面是不允许的代码，会有编译错误
        // 因为 const 成员函数不能调用非 const 成员函数。
        // setValue(999); // 错误: passing ‘const ConstDemo’ as ‘this’ argument discards qualifiers
        
        std::cout << "\n[调用const函数]display() 结束..." << std::endl;
    }
};

int main()
{
    std::cout << "---演示普通对象---" << std::endl;
    // 普通对象既可以调用const成员函数，也可以调用非const成员函数
    ConstDemo regularObject(10, "Regular");
    regularObject.getValue();   //OK
    regularObject.setValue(20); //OK
    regularObject.getValue();   //OK
    regularObject.disPlay();    //OK
    std::cout << "\n--- 演示常量对象 (只读对象) ---" << std::endl;
    // 常量对象是只读的，且只能调用常成员函数
    const ConstDemo constObject(100, "Const");
    constObject.getValue();
    constObject.disPlay();

    //下面的操作不被允许
    //constObject.setValue(200)

    return 0;
 
}