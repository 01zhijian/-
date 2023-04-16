#pragma once


/* ------------------------------ 学习笔记 ------------------------------ *

软件设计原则：
- SOLID（单一责任原则、开放封闭原则、里氏替换原则、接口隔离原则和依赖反转原则）
- DRY（Don't Repeat Yourself）
- YAGNI（You Ain't Gonna Need it）你不需要它
- KISS（Keep it simple, stupid）
- LoD（Law of Demeter）迪米特法则
- Composition over Inheritance
- 封装变化
- Hollywood Principle 好莱坞守则
- Program Against Abstractions（反抽象程序）


在设计过程中，不应该受到“Tunnel Version”的影响，这意味着不应该只关注完成或实现
目标，还应该关注其它效果

可追溯到分析模型
	设计过程应该追溯到分析模型，这意味着它应该满足软件开发高质量产品所需的所有需求

不应该重新发明车轮
	设计过程不应该重新发明轮子，这意味着它不应该浪费时间或精力去创造已经存在的东西

Minimize Intellectual distance
	The design process should reduce the gap between real-world problems and software
solutions for that problem meaning it should simply minimize intellectual distance.

展示统一性和整合性

适应改变
	软件的设计方式应该能够适应变化，这意味着软件应该更具用户的需要进行调整以适应变化

Degrade gently –
	The software should be designed in such a way that it degrades gracefully which means 
it should work properly even if an error occurs during the execution.

Assessed or quality
	对设计进行质量意义的评估，是在评价过程中对设计质量进行检查和关注的重要内容

设计不是编码，编码不是设计
	设计意味着描述程序的逻辑来解决任何问题，编码是一种用于实现设计的语言


Composition over Inheritance
	继承能够复用代码，但是导致强耦合，很难维护代码，父类的修改会对所有的子类造成
影响。

抽象的用处
- 理解抽象将使您能够理解何时需要了解某些技术或仅仅是如何使用它
- 理解抽象的另一个原因是当您开始学习工作区域之外的框架
- 当您第一次学习框架时，您将学习如何使用它。当您了解框架的工作原理之后，就会开始
	理解它的局限性

好莱坞原则是一个软件开发原则，它规定：“不要给我们打电话，我们会给你打电话。”
它建议高级组件应该规定应用程序中的控制流，而不是低级组件。这个原则经常被用于控制
反转和依赖注入。在传统的软件开发中，底层组件负责创建和管理它们所依赖的高层组件。
在 LOC 中，高级组件指定控制流，低级组件由单独的机制创建和管理。

防御式编程：子程序应该不因传入错误数据而被破坏，哪怕是由其他子程序产生的错误数据
	这种思想出现的错误造成的影响控制在有限的范围内

具体措施
	1）对输入进行检测：检测输入源（如：文件，网络、控制台等）数据的合法性；检查
	每一个函数输入参数的合法性
	处理方式：一旦出现非法输入被发现，那么应该根据情况进行处理。防御式编程最佳的
		形式就是一开始就不引入错误
	2）对非预期错误使用断言：空指针；输入或输出参数的值不在预期范围内；数组的越界
	处理方式：如果断言的条件返回错误，则终止程序执行


*/

