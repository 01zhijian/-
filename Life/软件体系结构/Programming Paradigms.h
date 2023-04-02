#pragma once


/* ------------------------------ 学习笔记 ------------------------------ *

结构化编程：
	强调结构化控制流的使用，例如循环和条件语句。结构化编程背后的主要思想是把一个
程序分解成更小的、易于管理的部分，这些部分易于理解、测试和修改。

结构化程序设计可以被分为三类
- 面向过程编程：将模块定义为“过程”或“函数”，用一组参数调用它们来执行任务。
	之后又被细分为
	- 面向服务编程：简单地将可重用模块定义为具有广告接口的“服务”
	- 微服务编程：侧重于创建不在内部存储数据的模块，因此在云部署中具有可伸缩性和弹性
	- 函数式编程：在技术上，意味着模块是由函数编写的，并且这些函数的输出仅仅来
		自它们的输入。函数式编程的定义是为无服务器计算而设计的，自那时一来扩展
		到在很大程度上等同于微服务

- 面向对象编程：将程序定义为向其发送命令的一组对象或资源。面向对象语言将定义数据
	资源并将其发送给处理命令

- 基于模型编程：最常见的例子是数据库语言 SQL

结构化编程的好处
- 它鼓励自顶向下的实现，从而提高代码的可读性和可维护性
- 它促进了代码的重用，因为即使是内部模块也可以被提取出来，用于其它应用程序
- 人们普遍认为开发时间和代码质量可以通过结构化编程来提高

结构化编程的缺点
	结构化编程最大的缺点是执行效率底下，内存使用量增加。这两个问题都产生于对模
块或进程的调用，调用完成后返回给调用方

Structured programming can also be applied incorrectly if the type of structure 
selected isn't right for the task at hand. The best-known example is the solving 
of math problems. RPL is an efficient way to state and solve a math problem 
because it eliminates the need to explicitly state execution order and eliminates 
recursion in code. However, if that problem were to be posed in structured programming
procedural or object form, the resulting code would be much less efficient than the 
RPL version.


*/


/* ------------------------------ 学习笔记 ------------------------------ *

Functional Programming
	强调使用 pure functions and immutable data。在函数编程中，函数是一级公民，
这意味着它们可以作为参数传递给其它函数，并作为值返回
	Functional programming（FP） 是通过使用 pure functions 来进行软件开发。换句
话说，通过应用和组合函数来构建程序。函数式语言关注的是声明和表达式，而不是语句
的执行。函数式编程中，函数也如同一个“变量”一样。FP 关注的是结果，而不是过程。

纯函数式编程是 FP 的一个子集，它将所有函数视为确定性数学函数或纯函数。不需要任何
外部代码就能够完成其任务，就意味着它是一个纯函数。相反的，能够改变外部代码状态
的函数就不是纯函数了。

优势
- 模块化
- lambda 演算
- Contains many functional constructs：These include lazy map, lazy evaluation, 
	and lists.
- 某些编程语言支持嵌套函数
- 问题容易定位和解决
- Keeps concurrency safe

关于函数式编程的相关概念
- 纯函数
- First-Class Functions
- Higher-Order Functions
- Immutability
- 递归
- Function Composition
- Referential Transparency

面向对象编程 VS 函数式编程
- 命令式程序关注解决问题的一步一步的过程，而声明式程序关注解决问题的结果
- 可变性

总的来说，不可变代码更易于更新，更易于管理，更易于测试和调试。而且因为变量是常量
所以生成的代码更容易理解和推理。许多程序员和软件开发人员更喜欢使用 FP 模型。

最终，适合您的编程泛型将取决于您想要的应用程序。OOP 最适合于标准化和简单的项目，
而 FP 最适合于需要可伸缩性和灵活性的项目。




*/


/* ------------------------------ 学习笔记 ------------------------------ *

面向对象编程
	面向对象程序设计（OOP）是一个基于“对象”概念的编程泛型，它是类的实例。OOP 
是一种基于封装、继承和多态原则来组织和构造代码的方法。

封装性：减少复杂性，增加重用性
抽象性：减少复杂性，隔离修改的影响
继承性：消除冗余代码
多态性：重构 switch 语句

优势
- 减少重复
- 性能
- 提高编写代码的效率

*/

