#ifndef SORTTSTHELPER_H_
#define SORTTSTHELPER_H_


#include<iostream>
#include<ctime>
#include<cassert>
#include<string>
//#include"sort.h"
using namespace std;

namespace SortTestHelper
{
	//������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangL,rangR]
	int* generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

		return arr;
	}

	//��ӡ����
	template <typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	//���������㷨��ʱ��
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n) {

		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		return;
	}


	//��֤�����Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
				return false;
		return true;
	}


	//��������
	template<typename T>
	T * copyArray(T a[], int n)
	{
		T *arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

	//���ɽ������������
	int *generateNearlyOrderedArray(int n,int swapTimes)
	{
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = i;
		srand(time(NULL));
		for (int i=0; i < swapTimes; i++)
		{
			int posx = rand() % n;
			int posy = rand() % n;
			swap(arr[posx], arr[posy]);
		}
		return arr;
	}




}

#endif SORTTSTHELPER_H_