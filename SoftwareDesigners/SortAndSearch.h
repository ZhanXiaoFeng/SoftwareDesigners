#pragma once


/*
	Search
	├── sequentialSearch
	├── orderedSequentialSearch
	├── binarySearch
	└── HashTable
	Sort
	├── bubbleSort
	├── shortBubbleSort
	├── selectionSort
	├── insertionSort
	├── shellSort
	├── gapInsertionSort
	├── mergeSort
	└── quickSort
*/


class SortAndSearch
{
public:
	SortAndSearch();
	~SortAndSearch();


	/* 冒泡排序（bubbleSort）
	* 时间复杂度：O（n²）
	* 算法稳定性：稳定
	*/
	void bubbleSort(int arr[], int len);

	/* 快速排序（Quicksort）是对冒泡排序的一种改进
	* 时间复杂度：O(nlogn)
	* 算法稳定性：不稳定
	* 已知的最快的排序方式，分治法思想，递归实现
	*/
	void quickSort(int arr[], int low, int high);

	/* 直接插入排序（Straight Insertion Sort）
	* 时间复杂度：O(n^2)
	* 算法稳定性：稳定
	*/
	void insertSort(int arr[], int len);

	/* 希尔排序(Shell's Sort)
	* 时间复杂度：O(n^（1.3—2）)
	* 算法稳定性：不稳定
	* 希尔排序没有快速排序算法快，但是容易实现，建议使用
	*/
	void shellSort(int arr[], int len);

	/* 归并排序（MERGE-SORT）
	* 时间复杂度 O(n log n)
	* 算法稳定性：稳定
	* 速度仅次于快速排序,一般用于对总体无序，但是各子项相对有序的数列
	*/
	void mergeSort(int arr[], int start, int end, int *result);
};

