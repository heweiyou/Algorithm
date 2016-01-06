#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x7fffffff

struct Edge
{
	int d;//与边相连节点
	int w;//边权值
	friend bool operator<(Edge e1,Edge e2)
	{
		return e1.w > e2.w;
	}
};


void Prim(int n,int src,vector<Edge>* adj)
{
	bool* flag = new bool[n+1];
	int* pre = new int[n+1];
	int* dis = new int[n+1];
	priority_queue<Edge> q;
	Edge tmp;
	int cnt;
	int u,v,w;

	for(int i = 1; i <= n; i++)
	{
		flag[i] = false;//各节点均在false状态
		dis[i] = INF;
	}

	cnt = 0;
	tmp.d = src;
	tmp.w = 0;
	pre[src] = -1;
	
	q.push(tmp);

	while(!q.empty())
	{

		u = q.top().d;
		if(flag[u])
		{
			q.pop();
			continue;
		}else
		{
			cnt += q.top().w;
			q.pop();
		}

		for(int i = 0; i < adj[u].size(); i++)
		{
			v = adj[u][i].d;
			w = adj[u][i].w;
			if(!flag[v] && w < dis[v])
			{
				dis[v] = w;
				tmp.d = v;
				tmp.w = w;
				q.push(tmp);
				pre[v] = u;
			}
		}
		flag[u] = true;
	}


	printf("Selected:\n");
	for(int i = 1; i <= n; i++)
	{
		if(src != i)
		{
			printf("  Edge %d %d\n",pre[i],i);
		}
	}
	printf("The minimum sum of weight is %d\n",cnt);

	delete []flag;
	delete []pre;
	delete []dis;
}

int main()
{
	//n为节点数,m为边数
	int n,m;
	//u,v为节点编号(节点编号从1开始)，w为权值
	int u,v,w;
	vector<Edge>* adj;
	Edge tmp;

	while(scanf("%d %d",&n,&m) != EOF && n && m)
	{
		adj = new vector<Edge>[n+1];
		for(int i = 0 ; i < m; i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			tmp.w = w;
			tmp.d = v;
			adj[u].push_back(tmp);
			tmp.d = u;
			adj[v].push_back(tmp);
		}

		Prim(n,1,adj);
		delete []adj;
	}
	return 0;
}
