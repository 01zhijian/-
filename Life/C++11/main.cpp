#include <iostream>

using namespace std;

// ģ�庯����Ĭ�ϲ�������ģ���Ĭ�ϲ���֮ǰ���Ѿ����ڣ�
// ��������ܹ��Ӻ���ʵ���Ƶ������͵Ļ�����ôĬ��ģ������Ͳ��ᱻʹ�ã���֮Ĭ��ģ���������ܻᱻʹ��
// Ĭ��ģ�����ͨ������Ҫ��Ĭ�Ϻ�������һ��ʹ�õ�
// ����ģ���ʵ�Σ������ɺ�����ʵ���Ƶ�������

template<typename T = int, typename U>
void TempFun(T t, U u)
{
    cout << t << endl;
}

// ��ʼ���б�
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
    // ���캯����ʹ�ó�ʼ���б�
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

// ��������ʹ�ó�ʼ���б�
// ʹ�ü�������������ͳ�ʼ����ü�
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

// ��ֹ������խ���Ӹ����������������߾��ȸ��������;��ȸ������������͵�����������������󵽸������޷���ȷ�ر�����Ҳ������Ϊ��խ�������͵��ϵͳ��ȵ�����

void TestNarrow()
{
    // ���ᷢ�����ݴ���Ļ򾫶ȴ���������������խ
    // �� C++11 �У��б��ʼ����Ψһһ�ֿ��Ա���ֹ������խ�ĳ�ʼ����ʽ����Ҳ���б��ʼ��������������ʼ����ʽ�ĵط�
    const int a = 10;
    char b = a;
    char c = { a }; // char �����ܹ���ʾ 10 ���ᷢ��������խ
    unsigned char d = -1;     // ����ͨ��
    //unsigned char e{ -1 };  // ���벻��

    int g = { 1 };
}

// �Ҽ����� > �ĸĽ�
// �� C++98 �У���һ����Ҫ����Ա��ܵĹ��������ʵ����ģ���ʱ����������������Ҽ����ţ���ô����֮����Ҫһ���ո������зָ����Ա��ⷢ������ʱ����
template<typename T> class X {};
template<typename T> class Y {};

void YouJianKuoHao()
{
    Y<X<int>> a{};  // ֮ǰ��ʶ��Ϊ���Ʋ�����
    Y<X<int> > b{};
}

// auto �����ı��������ͱ����ɱ������ڱ���ʱ���Ƶ�����
// ��ĳ����������������ʼ������auto ����һ�֡����͡�������������һ����������ʱ�ġ�ռλ�������������ڱ���ʱ�ڻὫ auto ���Ϊ������ʵ������
// auto ���ŵ㣺�������ı�д����ǿ����Ŀɶ��ԣ��Զ�ѡ������ʵ����ͣ��ܹ���һ���̶���֧�ַ��ͱ�̣���ƽ̨��
void TestAuto()
{
    auto strName = "Test auto";
    cout << strName << endl;
}

// ��������
//#define MAX1(a, b) (((a) > (b)) ? (a) : (b))
// 
// �޷�����
//#define MAX2(a, b) (\
//auto _a = (a);\
//auto _b = (b);\
//(_a > _b) ? _a : _b;)

void action(int& val)
{
    cout << val << endl;
}

// ���ڷ�Χ�� for ѭ��
#include <algorithm>
void TestRangeFor()
{
    // ��ͨ for ѭ��
    int arr[]{ 1,2,3,4,5 };
    for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
    {
        cout << *p << endl;
    }

    // ���� for_each ��ģ�庯��
    for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action);

    // ���ڷ�Χ�� for ѭ��
    for (auto val : arr)
    {
        cout << val << endl;
    }

    // ��Ҫʹ�û��ڷ�Χ�� for ѭ��������������һЩ���������ȣ����� for ѭ���ķ�Χ�ǿ���ȷ���ġ���Σ�Ҫ������Ķ���ʵ���� ++ �� == �Ȳ�����
}

// ԭ������
#include <atomic>
#include <thread>

atomic_llong total{ 0 };
//atomic_llong total2{ total }; �����������졢�ƶ����졢operator= �ȣ��Է�ֹ��������

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

// nullptr ��ֵ
// ���ж���� nullptr_t ���Ͷ��ǵȼ۵ģ���ΪҲ����ȫһ��
// nullptr_t ������ʽת��������һ��ָ������
// nullptr_t �������ݲ���ת��Ϊ��ָ�����ͣ���ʹ�� reinterpret_cast<nullptr_t>() �ķ�ʽҲ�ǲ����Ե�
// nullptr_t �������ݲ�����������������ʽ
// nullptr_t �������ݽ������ڹ�ϵ��������ʽ���������� nullptr_t �������ݻ�ָ���������ݽ��бȽ�
void TestNullptr()
{
    nullptr_t ptr = nullptr;
    

    // C++11 �汾��������ָ��ת��Ϊ�������ͻ����ͣ��������˵���������汾������
    // nullptr ���������� void* ռ�õ��ڴ�ռ��С��ͬ
    // ��Ҫ�� nullptr ��ȡ��ַ����
}

// lambda ���ʽ
void TestLambda()
{
    [] {};
    int a = 3;
    int b = 4;
    [=] {return a + b; };
    auto func1 = [&](int c) {b = a + c; };
    auto func2 = [=, &b](int c) {return b += a + c; };

    // ֱ�۵�������lambda ��������ͨ�����ɼ����������֮һ������ lambda ��������ͨ����׽�б����һЩ�������е�����
    // �����б������ظ�����
    // ���ܲ�����������Զ������������κηǴ�����������Ƿ��Զ��������羲̬�����ȣ����ᵼ�±���������
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