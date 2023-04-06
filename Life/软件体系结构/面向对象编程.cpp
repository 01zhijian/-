// �������


/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
�����಻�ܹ���ʵ������������ͨ��ʹ�ó�����ȥ����һ������ 


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

	// �����ֻ�Ƕ���ӿڣ���������ʵ�ַ�ʽ��������ʵ��
	// ��Ҳ�Ƿ�����ʵ����ͬԱ����нˮ�ļ��㷽ʽ������ͬ
	virtual double GetSalary() const = 0;
	virtual int Compare(const AEmployee* obj) const
	{
		return m_StrName.compare(obj->m_StrName);
	}

	// ��ȡ����
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

	// ��ȡнˮ
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

int main_���������()
{
	CAdminEmployee admin{ "a����Ա 01zhijian", CAdminEmployee::Position::ONE };
	CServiceEmployee service{ "b����Ա 01zhijian", 3000 };

	cout << admin.GetName() << " = " << admin.GetSalary() << endl;
	cout << service.GetName() << " = " << service.GetSalary() << endl;
	cout << admin.Compare(&service) << endl;

	return 0;
}


/* ------------------------------ ѧϰ�ʼ� ------------------------------ *
������Լ̳У��Ͷ�̬����ʹ�÷ǳ��ϸ�
����һ�����õĻ��ƣ����Դٽ��������ã�����������������ȷ��ģ�ͣ����õر�ʾ����
��ʵ�����е�ĳЩ���


*/
