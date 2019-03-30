#ifndef SORT_H_
#define SORT_H_
#include<iostream>
using namespace std;

namespace Sort {
	//ѡ�������㷨
	template<typename T>
	void selectionSort(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] < arr[minIndex])
					minIndex = j;
			}
			swap(arr[i], arr[minIndex]);
		}
	}


	//���������㷨1
	template<typename T>
	void insertSort(T arr[], int n) 
	{
		for (int i = 1; i < n; i++)
		{
			T e = arr[i];
			int j;
			for (j = i; j > 0 && arr[j - 1] > e; j--)
				arr[j] = arr[j - 1];
			arr[j] = e;
		}
	}


	//���������㷨2
	//��arr[l..r]��Χ��������в�������
	template<typename T>
	void insertSort2(T arr[], int l, int r)
	{
		for (int i = l + 1; i <= r; i++)
		{
			T e = arr[i];
			int j;
			for (j = i; j > l && arr[j - 1] > e; j--)
				arr[j] = arr[j - 1];
			arr[j] = e;
		}
		//��ΪҪ�����ã�������Ҫ���ص��ú���
		return;
	}


	//�鲢����
	template<typename T>
	void mergeSort(T arr[], int n)
	{
		__mergeSort(arr, 0, n - 1);
	}

	//�ݹ�ʹ�ù�ܸ����򣬶�[l...r]�ķ�Χ��������
	template<typename T>
	void __mergeSort(T arr[], int l, int r)
	{
		/*if (l >= r)
			return;*/

		if (r - l <= 15)
		{
			insertSort2(arr, l, r);
			return;
		}

		int mid = (l + r) / 2;
		__mergeSort(arr, l, mid);
		__mergeSort(arr, mid + 1, r);
		if (arr[mid] > arr[mid + 1])	//�Ż��鲢�����㷨
			__merge(arr, l, mid, r);
	}

	//��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
	template<typename T>
	void __merge(T arr[], int l, int mid, int r)
	{
		//VS��֧�ֶ�̬��������, ����ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
		T *aux = new T[r - l + 1];

		for (int i = l; i <= r; i++)
			aux[i - l] = arr[i];
		int i = l, j = mid + 1;
		for (int k = l; k <= r; k++)
		{
			if (i > mid)
			{
				arr[k] = aux[j - l];
				j++;
			}
			else if(j > r)
			{
				arr[k] = aux[i - l];
				i++;
			}
			else if (aux[i - l] < aux[j - l])
			{
				arr[k] = aux[i - l];
				i++;
			}
			else 
			{
				arr[k] = aux[j - l];
				j++;
			}
		}
		delete[] aux;
	}



	//�����������
	template <typename T>
	void quickSort(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort(arr, 0, n - 1);
	}


	// ��arr[l...r]���ֽ��п�������
	template <typename T>
	void __quickSort(T arr[], int l, int r)
	{
		/*if (l >= r)
		return;*/

		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		int p = __partition(arr, l, r);
		__quickSort(arr, l, p - 1);
		__quickSort(arr, p + 1, r);
	}


	template <typename T>
	int __partition(T arr[], int l, int r) 
	{
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];

		// arr[l+1...j] < v ; arr[j+1...i) > v
		int j = l; 
		for (int i = l + 1; i <= r; i++)
			if (arr[i] < v) {
				j++;
				swap(arr[j], arr[i]);
			}

		swap(arr[l], arr[j]);

		return j;
	}


	//˫·��������
	template <typename T>
	void quickSort2(T arr[], int n)
	{
		srand(time(NULL));
		__quickSort2(arr, 0, n - 1);
	}


	// ��arr[l...r]���ֽ��п�������
	template <typename T>
	void __quickSort2(T arr[], int l, int r)
	{
		/*if (l >= r)
		return;*/

		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		int p = __partition2(arr, l, r);
		__quickSort2(arr, l, p - 1);
		__quickSort2(arr, p + 1, r);
	}


	//˫·������������partition����
	template <typename T>
	int __partition2(T arr[], int l, int r)
	{
		swap(arr[l], arr[rand() % (r - l + 1) + l]);
		T v = arr[l];

		//arr[l+1...i)<=v �� arr(j...r}>=v
		int i = l + 1, j = r;
		while (true) 
		{
			while (i <= r && arr[i] < v)
				i++;
			while (j >= l + 1 && arr[j] > v)
				j--;
			if (i > j)
				break;
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		swap(arr[l], arr[j]);

		return j;
	}



	//��·�����������
	template <typename T>
	void quickSort3Ways(T arr[], int n) {

		srand(time(NULL));
		__quickSort3Ways(arr, 0, n - 1);
	}


	//��·����������arr[l...r]
	//��arr[l...r]��Ϊ < v , == v , > v ������
	//�ݹ�� < v , > v �����ֽ�����¹��������
	template <typename T>
	void __quickSort3Ways(T arr[], int l, int r) {

		// ����С��ģ����, ʹ�ò�����������Ż�
		if (r - l <= 15) {
			insertSort2(arr, l, r);
			return;
		}

		// �����arr[l...r]�ķ�Χ��, ѡ��һ����ֵ��Ϊ�궨��pivot
		swap(arr[l], arr[rand() % (r - l + 1) + l]);

		T v = arr[l];

		int lt = l;     // arr[l+1...lt] < v
		int gt = r + 1; // arr[gt...r] > v
		int i = l + 1;    // arr[lt+1...i) == v
		while (i < gt) {
			if (arr[i] < v) {
				swap(arr[i], arr[lt + 1]);
				i++;
				lt++;
			}
			else if (arr[i] > v) {
				swap(arr[i], arr[gt - 1]);
				gt--;
			}
			else { // arr[i] == v
				i++;
			}
		}

		swap(arr[l], arr[lt]);

		__quickSort3Ways(arr, l, lt - 1);
		__quickSort3Ways(arr, gt, r);
	}

}


#endif SORT_H_