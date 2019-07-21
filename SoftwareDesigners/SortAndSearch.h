#pragma once


/* 
四大查找
	Search
	├ sequentialSearch				顺序查找（无序，遍历）
	├ binarySearch					二分查找（对有序表进行折中查找，适用于静态表）
	├ orderedSequentialSearch		顺序查找（有序）
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

