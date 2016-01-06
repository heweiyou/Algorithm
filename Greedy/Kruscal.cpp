#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 105

struct Edge
{
	int u,v;//边节点
	int w;//边上权值
};
bool cmp(Edge e1,Edge e2)
{
	return e1.w < e2.w;
}

int parent[MAX];
int rank[MAX];
void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(int x)
{
	if(parent[x] != x)
	{
		return (parent[x] = findParent(parent[x]));
	}else
	{
		return x;
	}
}

void merge(int a,int b)
{

	if(a != b)
	{
		if(rank[a] < rank[b])
		{
			parent[a] = b;
		}else if(rank[a] > rank[b])
		{
			parent[a] = b;
		}else
		{
			parent[a] = b;
			rank[a] += 1;
		}
	}
}

void Kruscal(Edge* e,int n,int m)
{
	bool flag[MAX];
	int u,v,w;
	int cnt;//最小生成树所有边权值之和
	int elen;//已计算边数
	
	cnt = 0;
	elen = 0;

	for(int i = 1; i <= n; i++)
	{
		flag[i] = false;
	}
	
	init(n);
	sort(e,e+m,cmp);
	
	printf("Selected:\n");
	for(int i = 0 ; i < m; i++)
	{
		u = findParent(e[i].u);
		v = findParent(e[i].v);
		w = e[i].w;

		if(u != v )  
		{
			merge(u,v);	
			cnt += w;
			elen++;
			printf("  edge %d %d\n",e[i].u,e[i].v);
		}

		if(elen == n-1) break;
	}

	printf("The minimum sum of weight is %d\n",cnt);
}

int main()
{
	int n,m;
	Edge e[MAX];

	while(scanf("%d %d",&n,&m) != EOF && n && m)
	{
		for(int i = 0 ; i < m; i++)
		{
			scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		}

		Kruscal(e,n,m);
	}
	return 0;
}

