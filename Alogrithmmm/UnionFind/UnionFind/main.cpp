#include <iostream>
#include "UnionFindTestHelper.h"
#include"UnionFind2.h"

using namespace std;

// ����UF1
int main() {

	
	int n = 1000000;

	// ��ȻisConnectedֻ��ҪO(1)��ʱ��, ������union������ҪO(n)��ʱ��
	// ������Թ��̵��㷨���Ӷ���O(n^2)��
	//UnionFindTestHelper::testUF2(n);
	UnionFindTestHelper::testUF3(n);
	UnionFindTestHelper::testUF4(n);
	UnionFindTestHelper::testUF5(n);
	
	

	return 0;
}