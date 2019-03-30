#ifndef  DENSEGRAPH_H_
#define DENSEGRAPH_H_

#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//����ͼ - �ڽӾ���
class DenseGraph
{
private:
	int n, m;		//�洢ͼ�Ķ���ͱ�
	bool directed;	//��ʾ����ͼ��������ͼ
	vector<vector<bool>> g;

public:
	DenseGraph(int n, bool directed)
	{
		this->n = n;	//n��ʾͼ�ĵ���
		this->m = 0;	//��ʼ��ʱ����Ϊ0
		this->directed = directed;

		for (int i = 0; i < n; i++)
			//��vector���������vector��ÿ��vector����n��Ԫ�أ�ÿ��Ԫ�صĳ�ʼֵΪfalse
			g.push_back(vector<bool>(n, false));	
	}

	~DenseGraph()
	{

	}

	//����ͼ�Ķ�����
	int V()
	{
		return n;
	}

	//����ͼ�ı�
	int E()
	{
		return m;
	}

	void addEdge(int v, int w)	//v,wΪ��������֮�����Ӧ������
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);

		if (hasEdge(v, w))
			return;

		g[v][w] = true;
		if (!directed)	//����ͼ������ͼ�����Ӧ��g[w][v]ҲҪ��һ����
			g[w][v] = true;
		m++;
	}

	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}


	class adjIterator
	{
	private:
		DenseGraph &G;
		int v;
		int index;

	public:
		adjIterator(DenseGraph &graph, int v) :G(graph)
		{
			this->v = v;
			this->index = -1;
		}

		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for (index += 1; index < G.V(); index++)
				if (G.g[v][index])	//������Ԫ���Ƿ�Ϊtrue,Ϊtrueֱ�ӷ�������Ϊindex��Ԫ�ػ�ȥ
					return index;
			return -1;
		}

		bool end()
		{
			return index >= G.V();
		}
	};
};

#endif // ! DENSEGRAPH_H_
