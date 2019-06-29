#include "pch.h"
#include "Algorithm.h"
#include <iostream>
#include <random>

using namespace std;

Algorithm::Algorithm()
{

}




//////////////////////////////////////////////////////////////////////////

SortAndSearch::SortAndSearch()
{
	std::default_random_engine e;
	auto printArr = [](int arr[], int len) 
	{
		std::cout << "\n";
		for (int i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";
	};

	const int LEN = 256;
	int *a = new int[LEN];
	int *a2 = new int[LEN];
	memset(a, 0, LEN);
	memset(a2, 0, LEN);
	for (int i = 0; i < LEN; i++)
		a[i] = e() % 1000;
	printArr(a, LEN);

	//bubbleSort(a, LEN);
	//quickSort(a, 0, LEN - 1);
	//insertSort(a, LEN);
	//shellSort(a, LEN);
	mergeSort(a, 0, LEN - 1, a2);

	printArr(a, LEN);
	delete []a;
	delete []a2;
}


void SortAndSearch::bubbleSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void SortAndSearch::quickSort(int arr[], int low, int high) {
	//分治法
	//找出一个数作为基准key（这里用的low）
	//把比key大的放到右边，比key小的放到左边
	//对左边和右边的arr在进行相同操作

	if (high <= low) return;

	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (1) {
		//左找>key
		while(arr[++i] < key) { 
			if(i == high) break;
		}
		//右找<key
		while(arr[--j] > key) {
			if(j == low) break;
		}
		if(i >= j) break;
		//找到后交换
		std::swap(arr[i], arr[j]);
	}
	std::swap(arr[low], arr[j]);

	quickSort(arr, low, j - 1);
	quickSort(arr, j + 1, high);
}

void SortAndSearch::insertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j]; //往后挪
			arr[j + 1] = temp;
		}
	}
}

void SortAndSearch::shellSort(int arr[], int len) {
	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; i += 1) {
			int temp = arr[i];
			int j = i;
			for (; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

void SortAndSearch::mergeSort(int arr[], int start, int end, int *result) {
	auto merge = [](int *data, int start, int mid, int end, int *result) {
		int i, j, k;
		i = start;
		j = mid + 1;                        //避免重复比较data[mid]
		k = 0;
		while (i <= mid && j <= end) {      //数组data[start,mid]与数组(mid,end]均没有全部归入数组result中去
			if (data[i] <= data[j])         //如果data[i]小于等于data[j]
				result[k++] = data[i++];    //则将data[i]的值赋给result[k]，之后i,k各加一，表示后移一位
			else
				result[k++] = data[j++];    //否则，将data[j]的值赋给result[k]，j,k各加一
		}
		while (i <= mid)                    //表示数组data(mid,end]已经全部归入result数组中去了，而数组data[start,mid]还有剩余
			result[k++] = data[i++];        //将数组data[start,mid]剩下的值，逐一归入数组result
		while (j <= end)                    //表示数组data[start,mid]已经全部归入到result数组中去了，而数组(mid,high]还有剩余
			result[k++] = data[j++];        //将数组a[mid,high]剩下的值，逐一归入数组result

		for (i = 0; i < k; i++)             //将归并后的数组的值逐一赋给数组data[start,end]
			data[start + i] = result[i];    //注意，应从data[start+i]开始赋值	
	};

	if (start < end) {
		int mid = start + (end - start) / 2; //避免溢出int
		mergeSort(arr, start, mid, result);  //对左边进行排序
		mergeSort(arr, mid + 1, end, result);//对右边进行排序
		merge(arr, start, mid, end, result); //把排序好的数据合并
	}
}


