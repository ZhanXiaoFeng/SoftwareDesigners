#pragma once


/* 五大常用算法
*/
class Algorithm
{
public:
	Algorithm();

	/* 动态规划算法（Dynamic Programming Algorithm）
	* 动态规划算法的核心就是提供了一个memory来缓存重复子问题的结果，避免了大量的重复计算。
	* 动态规划算法的难点在于怎么将问题转化为能够利用动态规划算法来解决。
	* 举例：Fibonacci、背包问题
	*
	* 1）问题的阶段
	* 2）每个阶段的状态
	* 3）从前一个阶段转化到后一个阶段之间的递推关系
	*/

	/* 分治算法（Divide and Conquer）
	* 把一个大的问题分为若干个子问题，然后在子问题继续向下分，分治算法是递归的典型应用。
	* 举例：排序算法(快速排序，归并排序)，傅立叶变换(快速傅立叶变换)
	* 
	* 1）分解，将要解决的问题划分成若干规模较小的同类问题；
	* 2）求解，当子问题划分得足够小时，用较简单的方法解决；
	* 3）合并，按原问题的要求，将子问题的解逐层合并构成原问题的解。
	*/

	/* 回溯算法（backtracking algorithm）
	* 回溯算法是深度优先策略的典型应用，递归遍历。
	* 举例：八皇后问题、迷宫问题
	* 
	* 1、针对所给问题，定义问题的解空间，它至少包含问题的一个（最优）解。
	* 2、确定易于搜索的解空间结构,使得能用回溯法方便地搜索整个解空间 。
	* 3、以深度优先的方式搜索解空间，并且在搜索过程中用剪枝函数避免无效搜索。
	*/

	/* 贪心算法（greedy algorithm）
	* 获取到问题的局部最优解，不一定能获取到全局最优解，不同的贪婪策略会导致得到差异非常大的结果。
	* 举例：最小生成树的Prim算法和Kruskal算法都是漂亮的贪心算法。
	* 
	* 1、建立数学模型来描述问题；
	* 2、把求解的问题分成若干个子问题；
	* 3、对每一子问题求解，得到子问题的局部最优解；
	* 4、把子问题的解局部最优解合成原来解问题的一个解。
	*/

	/* 分支限界算法（Branch and Bound Method）
	* 运用这种算法的技巧性很强，不同类型的问题解法也各不相同。
	* 基本思想是对有约束条件的最优化问题的所有可行解（数目有限）空间进行搜索。
	*/
};

//////////////////////////////////////////////////////////////////////////

/* 

	Search
	├ sequentialSearch				顺序查找（遍历）
	├ binarySearch					二分查找（对有序表进行折中查找，适用于静态表）
	├ orderedSequentialSearch
	└ HashTable					哈希查找（利用hash表查找）

https://www.cnblogs.com/onepixel/articles/7674659.html
十大经典排序算法
	├ bubbleSort			冒泡排序（交换排序）（有改进的方法）
	├ quickSort			快速排序（交换排序）
	├ insertionSort		插入排序（插入排序）（有改进的方法）
	├ shellSort			希尔排序（插入排序改进）（1959年，第一个突破O(n^2)的排序算法）
	├ selectionSort		选择排序（选择排序）
	├ heapSort				堆排序  （选择排序）
	├ mergeSort			归并排序（归并排序）
	├ countingSort			计数排序（非比较排序）
	├ bucketSort			桶排序  （非比较排序）(计数排序改进)
	└ radixSort			基数排序（非比较排序）
*/
class SortAndSearch
{
public:
	SortAndSearch();


	/* 冒泡排序（bubbleSort）
	* 时间复杂度：O（n^2）
	* 算法稳定性：稳定
	* 双for遍历O(n^2)，i和i+1对比交换位置
	*/
	void bubbleSort(int arr[], int len);

	/* 快速排序（Quicksort）是对冒泡排序的一种改进
	* 时间复杂度：O(nlogn)
	* 算法稳定性：不稳定
	* 已知的最快的排序方式，分治法
	*/
	void quickSort(int arr[], int low, int high);

	/* 选择排序（Selection Sort）
	* 时间复杂度：O(n2)
	* 双for遍历O(n^2)，每次把最小值放到最前面
	*/
	void selectionSort(int arr[], int len);

	/* 直接插入排序（Straight Insertion Sort）
	* 时间复杂度：O(n^2)
	* 算法稳定性：稳定
	* 取出一个值O(n),遍历比较O(n)，然后插入
	*/
	void insertionSort(int arr[], int len);

	/* 希尔排序(Shell's Sort)
	* 时间复杂度：O(n^（1.3—2）)
	* 算法稳定性：不稳定
	* 希尔排序没有快速排序算法快，但是容易实现，建议使用
	*/
	void shellSort(int arr[], int len);

	/* 归并排序（MERGE-SORT）
	* 时间复杂度 O(n log n)
	* 算法稳定性：稳定
	* 速度仅次于快速排序，分治法,一般用于对总体无序，但是各子项相对有序的数列
	*/
	void mergeSort(int arr[], int start, int end, int *result);

	/* 堆排序（Heap Sort）
	* 构建大顶堆，对堆进行排序，代码实现比较麻烦
	*/
	void heapSort(int arr[], int len);
};

