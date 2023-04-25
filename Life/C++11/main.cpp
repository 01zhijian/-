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

int main()
{
    //TempFun(1, 2);
    //TempFun("11234", 2);
    //InitializerFun({ 1,2,3,4,5 });
    //People people = { { "lvjun", boy } };
    TestAuto();
    
    return 0;
};