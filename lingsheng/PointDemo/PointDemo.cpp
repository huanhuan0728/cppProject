#include <iostream>

using namespace std;

// 交换指针指向的值
void swapfunc(int* p1, int* p2)
{
    int temp = *p1; // 取p1指向的值
    *p1 = *p2;      // 将p2指向的值赋给p1指向的地址
    *p2 = temp;     // 将临时变量的值赋给p2指向的地址
}

int main()
{
    // === 演示1：直接访问变量 ===
    int i = 0;
    cout << "\n i在内存中的地址编号为： " << &i << endl;
    cout << "请输入i的值：" << endl;
    cin >> i;
    cout << "你输入i的值为：" << i << endl;

    // === 演示2：通过指针间接访问 ===
    int* p_demo = nullptr; // 修改了变量名，避免与后面的p重复
    int x = 560;

    cout << "\nx的地址编号为: " << &x << endl;
    p_demo = &x;
    cout << "指针p_demo的值（即x的地址编号）为：" << p_demo << endl;
    cout << "输出指针p_demo指向的地址里面的值：" << *p_demo << endl;

    // === 演示3：指针作为函数参数（交换值） ===
    int a1 = 20, b1 = 40;
    int* p1 = &a1;
    int* p2 = &b1;
    cout << "\n交换前: a1 = " << a1 << ", b1 = " << b1 << endl;
    cout << "通过指针访问: *p1 = " << *p1 << ", *p2 = " << *p2 << endl;
    swapfunc(p1, p2); // 调用函数交换a1和b1的值
    cout << "交换后: a1 = " << a1 << ", b1 = " << b1 << endl;


    // === 演示4：指针的自增操作 (p++) ===
    // 【注意】这部分代码有副作用，需要小心理解
    int a2 = 3;
    int* p_a2 = &a2; // 使用新的指针变量名
    cout << "\n演示指针自增前，a2的地址：" << p_a2 << ", a2的值：" << *p_a2 << endl;
    // *(p++) 这个表达式会先取p_a2当前指向的值（也就是3），然后p_a2指向下一个内存地址
    cout << "执行*(p_a2++)后输出的值为：" << *(p_a2++) << endl;
    // 此时p_a2已经不再指向a2了，它的地址已经改变了！
    cout << "执行自增后，指针p_a2的新地址为：" << p_a2 << endl;
    cout << "变量a2本身的值没有改变: a2 = " << a2 << endl;


    // === 演示5：通过指针交换用户输入的值 ===
    int a3, b3;
    int *pa_swap, *pb_swap; // 使用新的指针变量名
    cout << "\n请输入两个整数a和b的值：";
    cin >> a3 >> b3;

    pa_swap = &a3;
    pb_swap = &b3;

    if (a3 < b3)
    {
        cout << "a小于b，执行交换..." << endl;
        swapfunc(pa_swap, pb_swap);
    }
    cout << "最终结果: a=" << a3 << ", b=" << b3 << endl;
    cout << "通过指针访问: *pa_swap=" << *pa_swap << ", *pb_swap=" << *pb_swap << endl;


    // === 演示6：使用指针遍历数组 ===
    int any[5] = { 34, 56, 32, 89, 19 };
    int* pa_arr = any; // 数组名本身就是指向第一个元素的指针
    cout << "\n通过循环输出数组any的元素值：\n";
    for (int j = 0; j < 5; j++) // 使用j作为循环变量，避免与外面的i冲突
    {
        cout << *(pa_arr + j) << " ";
    }
    cout << endl; // 换行，让格式更好看

    cout << "any[0] = " << *pa_arr << endl;
    *pa_arr = 59; // 修改数组第一个元素的值
    cout << "修改后 any[0] = " << *pa_arr << " (或 any[0] = " << any[0] << ")" << endl;
    cout << "any[1]的值为：" << *(pa_arr + 1) << endl;


    // === 演示7：引用 (Reference) ===
    int max = 899;
    int& refmax = max; // refmax是max的别名
    cout << "\nmax的地址:" << &max << endl;
    cout << "refmax的地址:" << &refmax << endl; // 会发现地址完全相同
    cout << "max=" << max << endl;
    cout << "refmax=" << refmax << endl;
    refmax = 1000; // 修改别名
    cout << "通过别名修改后，max的值也变成了: " << max << endl;


    return 0;
}