// 面向对象


/* ------------------------------ 学习笔记 ------------------------------ *
抽象类不能够被实例化，即不能通过使用抽象类去创建一个对象 


*/

#define ABSTRACT_CLASS class
#define CONCRETE_CLASS class

#include <iostream>
#include <string>

using namespace std;


ABSTRACT_CLASS AEmployee
{
public:
	AEmployee(const string& strName)
		: m_StrName(strName) {}
	~AEmployee() {}

	// 抽象层只是定义接口，其真正的实现方式留给子类实现
	// 这也是符合现实，不同员工其薪水的计算方式有所不同
	virtual double GetSalary() const = 0;
	virtual int Compare(const AEmployee* obj) const
	{
		return m_StrName.compare(obj->m_StrName);
	}

	// 获取名称
	const string& GetName() const
	{
		return m_StrName;
	}

private:
	string m_StrName;
};

CONCRETE_CLASS CAdminEmployee : public AEmployee
{
public:
	enum class Position
	{
		ONE,
		TWO
	};

public:
	CAdminEmployee(const string& strName, Position position)
		: AEmployee(strName), m_Position(position)
	{
		
	}

	~CAdminEmployee() {}

	// 获取薪水
	virtual double GetSalary() const override
	{
		double salary = 0;

		switch (m_Position)
		{
		case Position::ONE: salary = 5000; break;
		case Position::TWO: salary = 6000; break;
		default:
			salary = -1;
		}

		return salary;
	}

private:
	Position m_Position;
};

CONCRETE_CLASS CServiceEmployee : public AEmployee
{
public:
	CServiceEmployee(const string& strName, double basicSalary)
		: AEmployee(strName), m_BasicSalary(basicSalary)
	{

	}

	~CServiceEmployee() {}

	virtual double GetSalary() const override
	{
		return m_BasicSalary + 6 * m_BasicSalary / 100;
	}

private:
	double m_BasicSalary;
};

int main_面向对象编程()
{
	CAdminEmployee admin{ "a管理员 01zhijian", CAdminEmployee::Position::ONE };
	CServiceEmployee service{ "b服务员 01zhijian", 3000 };

	cout << admin.GetName() << " = " << admin.GetSalary() << endl;
	cout << service.GetName() << " = " << service.GetSalary() << endl;
	cout << admin.Compare(&service) << endl;

	return 0;
}


/* ------------------------------ 学习笔记 ------------------------------ *
抽象类对继承（和多态）的使用非常严格
它是一种有用的机制，可以促进代码重用，并帮助您创建更精确的模型，更好地表示来自
现实生活中的某些情况


*/
