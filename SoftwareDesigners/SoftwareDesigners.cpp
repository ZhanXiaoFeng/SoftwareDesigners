// SoftwareDesigners.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _DEBUG
#else
#endif

#if defined(_WINDOWS) || defined(WIN32)
#endif

#ifdef _WIN64
#else
#endif

#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter7.h"
#include "Chapter8.h"
#include "Chapter9.h"
#include "Chapter10.h"
#include "Chapter11.h"
#include "Chapter12.h"

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
