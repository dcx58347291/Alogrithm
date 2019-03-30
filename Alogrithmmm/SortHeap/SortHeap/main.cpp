#include <iostream>
#include <algorithm>
#include "Heap.h"
#include "SortTestHelper.h"

using namespace std;


// heapSort1, �����е�Ԫ��������ӵ�����, �ڽ�����Ԫ�شӶ�������ȡ����, �����������
// �����Ǵ����ѵĹ���, ���ǴӶ�������ȡ��Ԫ�صĹ���, ʱ�临�ӶȾ�ΪO(nlogn)
// ���������������ʱ�临�Ӷ�ΪO(nlogn)
template<typename T>
void heapSort1(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++)
		maxheap.insert(arr[i]);

	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();

}


// heapSort2, �������ǵ�heapify���̴�����
// ��ʱ, �����ѵĹ���ʱ�临�Ӷ�ΪO(n), ������Ԫ�����δӶ���ȡ����, ʵ�����Ӷ�ΪO(nlogn)
// �����������ʱ�临�Ӷ���Ȼ��O(nlogn), ���Ǳ�����heapSort1���ܸ���, ��Ϊ�����ѵ����ܸ���
template<typename T>
void heapSort2(T arr[], int n) {

	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();

}

//ԭ�ض������е�shiftDown����
template<typename T>
void __shiftDown(T arr[], int n, int k)
{
	while (2 * k + 1 < n) {
		int j = 2 * k + 1;		//����ѭ���У�arr[k] �� arr[j] ����λ��

		if (j + 1 < n  && arr[j + 1] > arr[j])
			j++;

		if (arr[k] >= arr[j])
			break;

		swap(arr[k], arr[j]);
		k = j;
	}
}


//ԭ�ض�����
template<typename T>
void heapSort(T arr, int n)
{
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		__shiftDown(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}




// �Ƚ� Merge Sort, ���� Quick Sort �ͱ��ڽ��ܵ����� Heap Sort ������Ч��
// �⼸�������㷨���� O(nlogn) ����������㷨
int main() {

	int n = 1000000;

	//����1��һ���Բ���
	cout << "Test for Random Array , size=" << n << ", random range [ 0 ," << n << " ]" << endl;
	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyArray(arr1, n);
	int *arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);

	delete[] arr1, arr2, arr3;

	cout << endl;

	//���Խ������������
	int swapTimes = 1000;
	cout << "Test for Random Nearly Ordered Array, size = " << n << " , swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyArray(arr1, n);
	arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);

	delete[] arr1, arr2, arr3;

	cout << endl;

	//����3 ���Դ��ڰ���������ͬԪ�ص�����
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyArray(arr1, n);
	arr3 = SortTestHelper::copyArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);


	delete[] arr1, arr2, arr3;

	cout << endl;

	return 0;
}