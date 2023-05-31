#pragma once


/// @file     Comment.h
/// @brief    代码规范示例
///   
///    文件注释、类注释、函数注释、成员注释、变量注释
/// 
/// @author   01之间
/// @date     2023年5月30日 23点57分

/// @brief 获取两个数中的较大者
/// @param x
/// @param y
/// @return 返回 x 与 y 中的较大者
#define MAX(x, y) ((x) < (y) ? (y) : (x))

/// @class Comment Comment.h "Life/C++/Comment.h"
/// @brief 这是一个注释类
/// 
///   更为详细的描述
/// 
class Comment
{
public:
    /// @addtogroup 第一组

    /// @brief 构造函数
    Comment();

    /// @brief 析构函数
    ~Comment();

    /// @addtogroup 第二组

    /// @brief 递归实现二分查找
    /// @param[in]  arr       有序数组地址 arr
    /// @param[in] minSub     查找范围的最小下标 minSub
    /// @param[in] maxSub     查找范围的最大下标 maxSub
    /// @param[in] num        待查找数字
    /// @return               返回数组下标
    /// @retval -1            没有找到目标值
    int BinarySearch(int* arr, int minSub, int maxSub, int num);

public:
    int m_key;      /// 公有成员变量

private:
    int m_value;    /// 私有成员变量
};

