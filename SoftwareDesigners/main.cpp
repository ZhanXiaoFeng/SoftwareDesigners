// SoftwareDesigners.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Chapter1.h"	//计算机系统知识
#include "Chapter2.h"	//程序设计语言基础知识
#include "Chapter3.h"	//数据结构
#include "Chapter4.h"	//操作系统知识
#include "Chapter5.h"	//软件工程基础知识
#include "Chapter6.h"	//结构化开发方法
#include "Chapter7.h"	//面向对象技术
#include "Chapter8.h"	//算法设计与分析
#include "Chapter9.h"	//数据库技术基础
#include "Chapter10.h"	//网络与信息安全基础知识
#include "Chapter11.h"	//标准化和软件知识产权基础知识
#include "Chapter12.h"	//软件系统分析与设计

int main() 
{
    std::cout << "Hello World!\n"; 

	Chapter1 c1;
	Chapter2 c2;
	Chapter3 c3;
	Chapter4 c4;
	Chapter5 c5;
	Chapter6 c6;
	Chapter7 c7;
	Chapter8 c8;
	Chapter9 c9;
	Chapter10 c10;
	Chapter11 c11;
	Chapter12 c12;

#ifdef _WIN32
	system("PAUSE");
#endif
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
