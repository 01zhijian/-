#pragma once
class ���ģʽ
{
};


/* ------------------------------ ѧϰ�ʼ� ------------------------------ *

���ģʽ
	���ģʽ����������г��������ͨ�ý�������������ṩ��һ�������ͽ�����Գ���
����ľ�����֤�Ľ�������ķ�������Ϊ����ṩ��ͨ�õĴʻ��

- ������
- �ṹ��
- ��Ϊ��
- �ܹ���




*/


/* ------------------------------ ѧϰ�ʼ� ------------------------------ *

����ģʽ
- Ψһʵ��
- ȫ�ַ���
- ��־�����������桢�̳߳�...
- ������ģʽһ��ʹ��

ʵ�ֵ�
- ˽�й��캯��
- ˽�о�̬����
- ˽�о�̬����




*/

// Eager initialization
class EagerSingleton
{
private:
	EagerSingleton() {}
	~EagerSingleton()
	{
		delete m_Singleton; 
	}

public:
	static EagerSingleton* GetSingleton()
	{
		return m_Singleton;
	}

private:
	static EagerSingleton* m_Singleton;
};

EagerSingleton* EagerSingleton::m_Singleton = new EagerSingleton();

// ʹ�ó������������Դ���٣��Ҳ������ļ�ϵͳ�����ݿ���������Դ����ʹ��
// ȱ�㣺û���쳣����

