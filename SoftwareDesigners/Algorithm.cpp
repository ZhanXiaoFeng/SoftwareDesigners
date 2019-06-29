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
	//���η�
	//�ҳ�һ������Ϊ��׼key�������õ�low��
	//�ѱ�key��ķŵ��ұߣ���keyС�ķŵ����
	//����ߺ��ұߵ�arr�ڽ�����ͬ����

	if (high <= low) return;

	int i = low;
	int j = high + 1;
	int key = arr[low];
	while (1) {
		//����>key
		while(arr[++i] < key) { 
			if(i == high) break;
		}
		//����<key
		while(arr[--j] > key) {
			if(j == low) break;
		}
		if(i >= j) break;
		//�ҵ��󽻻�
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
				arr[j + 1] = arr[j]; //����Ų
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
		j = mid + 1;                        //�����ظ��Ƚ�data[mid]
		k = 0;
		while (i <= mid && j <= end) {      //����data[start,mid]������(mid,end]��û��ȫ����������result��ȥ
			if (data[i] <= data[j])         //���data[i]С�ڵ���data[j]
				result[k++] = data[i++];    //��data[i]��ֵ����result[k]��֮��i,k����һ����ʾ����һλ
			else
				result[k++] = data[j++];    //���򣬽�data[j]��ֵ����result[k]��j,k����һ
		}
		while (i <= mid)                    //��ʾ����data(mid,end]�Ѿ�ȫ������result������ȥ�ˣ�������data[start,mid]����ʣ��
			result[k++] = data[i++];        //������data[start,mid]ʣ�µ�ֵ����һ��������result
		while (j <= end)                    //��ʾ����data[start,mid]�Ѿ�ȫ�����뵽result������ȥ�ˣ�������(mid,high]����ʣ��
			result[k++] = data[j++];        //������a[mid,high]ʣ�µ�ֵ����һ��������result

		for (i = 0; i < k; i++)             //���鲢��������ֵ��һ��������data[start,end]
			data[start + i] = result[i];    //ע�⣬Ӧ��data[start+i]��ʼ��ֵ	
	};

	if (start < end) {
		int mid = start + (end - start) / 2; //�������int
		mergeSort(arr, start, mid, result);  //����߽�������
		mergeSort(arr, mid + 1, end, result);//���ұ߽�������
		merge(arr, start, mid, end, result); //������õ����ݺϲ�
	}
}


