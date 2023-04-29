#include <iostream>

using namespace std;

// 模板函数的默认参数（类模板的默认参数之前就已经存在）
// 规则：如果能够从函数实参推到出类型的话，那么默认模板参数就不会被使用，反之默认模板参数则可能会被使用
// 默认模板参数通常是需要跟默认函数参数一起使用的
// 函数模板的实参，总是由函数的实参推导出来的

template<typename T = int, typename U>
void TempFun(T t, U u)
{
    cout << t << endl;
}

// 初始化列表
void InitializerList()
{
    int a[] = { 1,2,3,4 };
    int b[]{ 1,2,3,4 };
}

#include <vector>

enum Gender {boy, girl};
class People
{
public:
    // 构造函数中使用初始化列表
    People(initializer_list<pair<string, Gender>> it)
    {
        for (auto i = it.begin(); i != it.end(); ++i)
        {
            data.emplace_back(*i);
        }
    }

private:
    vector<pair<string, Gender>> data;
};

// 函数参数使用初始化列表
// 使得集合类的数据类型初始化变得简单
void InitializerFun(initializer_list<int> valList)
{
    for (auto i = valList.begin(); i != valList.end(); ++i)
    {
        cout << *i << endl;
    }
}

const int& ReturnTempVal()
{
    return 0;
}

// 防止类型收窄：从浮点数到整型数、高精度浮点数到低精度浮点数、从整型到浮点数（如果整数大到浮点数无法精确地表述，也可以视为收窄、从整型到较低长度的整型

void TestNarrow()
{
    // 不会发生数据错误的或精度错误的情况不看作收窄
    // 在 C++11 中，列表初始化是唯一一种可以被防止类型收窄的初始化方式，这也是列表初始化区别与其他初始化方式的地方
    const int a = 10;
    char b = a;
    char c = { a }; // char 类型能够表示 10 不会发生类型收窄
    unsigned char d = -1;     // 编译通过
    //unsigned char e{ -1 };  // 编译不过

    int g = { 1 };
}

// 右尖括号 > 的改进
// 在 C++98 中，有一条需要程序员规避的规则：如果在实例化模板的时候出现了连续两个右尖括号，那么它们之间需要一个空格来进行分隔，以避免发生编译时错误
template<typename T> class X {};
template<typename T> class Y {};

void YouJianKuoHao()
{
    Y<X<int>> a{};  // 之前被识别为右移操作符
    Y<X<int> > b{};
}

// auto 声明的变量的类型必须由编译器在编译时期推导而得
// 从某种意义上来将（初始化），auto 并非一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译时期会将 auto 替代为变量的实际类型
// auto 的优点：方便代码的编写，增强代码的可读性；自动选择最合适的类型；能够在一定程度上支持泛型编程（跨平台）
void TestAuto()
{
    auto strName = "Test auto";
    cout << strName << endl;
}

// 增加性能
//#define MAX1(a, b) (((a) > (b)) ? (a) : (b))
// 
// 无法复现
//#define MAX2(a, b) (\
//auto _a = (a);\
//auto _b = (b);\
//(_a > _b) ? _a : _b;)

void action(int& val)
{
    cout << val << endl;
}

// 基于范围的 for 循环
#include <algorithm>
void TestRangeFor()
{
    // 普通 for 循环
    int arr[]{ 1,2,3,4,5 };
    for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
    {
        cout << *p << endl;
    }

    // 基于 for_each 的模板函数
    for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action);

    // 基于范围的 for 循环
    for (auto val : arr)
    {
        cout << val << endl;
    }

    // 想要使用基于范围的 for 循环，必须依赖于一些条件：首先，就是 for 循环的范围是可以确定的。其次，要求迭代的对象实现了 ++ 和 == 等操作符
}

// 原子类型
#include <atomic>
#include <thread>

atomic_llong total{ 0 };
//atomic_llong total2{ total }; 不允许拷贝构造、移动构造、operator= 等，以防止发生意外

void func()
{
    for (long long i = 0; i < 100000000LL; ++i)
    {
        total += i;
    }
}

void TestAtomic()
{
    thread t1{ func };
    thread t2{ func };

    t1.join();
    t2.join();

    cout << "total = " << total << endl;
}


class TypeId
{

};

void TestTypeId()
{
    TypeId a;
    int b = 0;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
}

// nullptr 空值
// 所有定义的 nullptr_t 类型都是等价的，行为也是完全一致
// nullptr_t 可以隐式转换成任意一个指针类型
// nullptr_t 类型数据不能转换为非指针类型，即使用 reinterpret_cast<nullptr_t>() 的方式也是不可以的
// nullptr_t 类型数据不适用于算术运算表达式
// nullptr_t 类型数据仅适用于关系运算符表达式，但仅能于 nullptr_t 类型数据或指针类型数据进行比较
void TestNullptr()
{
    nullptr_t ptr = nullptr;
    

    // C++11 版本不允许将空指针转换为布尔类型或整型，如果允许，说明编译器版本不够新
    // nullptr 类型数据与 void* 占用的内存空间大小相同
    // 不要对 nullptr 做取地址操作
}

// lambda 表达式
void TestLambda()
{
    [] {};
    int a = 3;
    int b = 4;
    [=] {return a + b; };
    auto func1 = [&](int c) {b = a + c; };
    auto func2 = [=, &b](int c) {return b += a + c; };

    // 直观的来讲，lambda 函数与普通函数可见的最大区别之一，就是 lambda 函数可以通过捕捉列表访问一些上下文中的数据
    // 捕获列表不允许重复传递
    // 仅能捕获父作用域的自动变量，捕获任何非此作用域或者是非自动变量（如静态变量等）都会导致编译器报错
}


int main()
{
    //TempFun(1, 2);
    //TempFun("11234", 2);
    //InitializerFun({ 1,2,3,4,5 });
    //People people = { { "lvjun", boy } };
    //TestAuto();
    //TestRangeFor();
    //TestAtomic();
    //TestTypeId();
    TestNullptr();
    
    return 0;
};