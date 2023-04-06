#pragma once
class 设计模式
{
};


/* ------------------------------ 学习笔记 ------------------------------ *

设计模式
	设计模式是软件开发中常见问题的通用解决方法。它们提供了一种描述和交流针对常见
问题的经过验证的解决方案的方法，并为设计提供了通用的词汇表。

- 创建型
- 结构型
- 行为型
- 架构型




*/


/* ------------------------------ 学习笔记 ------------------------------ *

单例模式
- 唯一实例
- 全局访问
- 日志、驱动、缓存、线程池...
- 与其它模式一起使用

实现点
- 私有构造函数
- 私有静态变量
- 私有静态方法




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

// 使用场景：管理的资源较少，且不是像文件系统、数据库这样的资源方可使用
// 缺点：没有异常处理

