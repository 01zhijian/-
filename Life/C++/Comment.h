#pragma once


/// @file     Comment.h
/// @brief    ����淶ʾ��
///   
///    �ļ�ע�͡���ע�͡�����ע�͡���Աע�͡�����ע��
/// 
/// @author   01֮��
/// @date     2023��5��30�� 23��57��

/// @brief ��ȡ�������еĽϴ���
/// @param x
/// @param y
/// @return ���� x �� y �еĽϴ���
#define MAX(x, y) ((x) < (y) ? (y) : (x))

/// @class Comment Comment.h "Life/C++/Comment.h"
/// @brief ����һ��ע����
/// 
///   ��Ϊ��ϸ������
/// 
class Comment
{
public:
    /// @addtogroup ��һ��

    /// @brief ���캯��
    Comment();

    /// @brief ��������
    ~Comment();

    /// @addtogroup �ڶ���

    /// @brief �ݹ�ʵ�ֶ��ֲ���
    /// @param[in]  arr       ���������ַ arr
    /// @param[in] minSub     ���ҷ�Χ����С�±� minSub
    /// @param[in] maxSub     ���ҷ�Χ������±� maxSub
    /// @param[in] num        ����������
    /// @return               ���������±�
    /// @retval -1            û���ҵ�Ŀ��ֵ
    int BinarySearch(int* arr, int minSub, int maxSub, int num);

public:
    int m_key;      /// ���г�Ա����

private:
    int m_value;    /// ˽�г�Ա����
};

