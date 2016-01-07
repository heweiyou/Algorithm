#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define INF 0x7fffffff

struct Edge
{
	int d;//与边相连节点
	int w;//源点到d点权值和
	friend bool operator<(Edge e1,Edge e2)
	{
		return e1.w > e2.w;
	}
};

void printPath(int* pre,int x)
{
	if(pre[x] == -1)
	{
		printf("%d ",x);
	}else
	{
		printPath(pre,pre[x]);
		printf("%d ",x);
	}
}

void Dijkstra(int n,int src,vector<Edge>* adj)
{
	bool* flag = new bool[n+1];
	int* dis = new int[n+1];
	int* pre = new int[n+1];
	priority_queue<Edge> q;
	int u,v,w;
	int cnt;
	Edge tmp;

	for(int i = 1; i <= n; i++)
	{
		flag[i] = false;
		dis[i] = INF;
	}

	cnt = 0;
	pre[src] = -1;
	dis[src] = 0;
	tmp.d = src;
	tmp.w = 0;
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
			q.pop();
		}
		for(int i = 0 ; i < adj[u].size(); i++)
		{
			v = adj[u][i].d;
			w = adj[u][i].w;
			
			if(!flag[v] && dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				tmp.d = v;
				tmp.w = dis[v];
				q.push(tmp);
				pre[v] = u;
			}
			flag[u] = true;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(i != src)
		{
			printf("%d->%d minimum distance is %d,path is ",src,i,dis[i]);
			printPath(pre,i);
			printf("\n");
		}
	}
	
	delete []flag;
	delete []dis;
	delete []pre;
}

int main()
{
	int n,m;//n节点m边图(编号从1开始)
	vector<Edge>* adj;//邻接表
	int u,v,w;//u,v为节点编号,w为链接u,v节点边的权值
	Edge tmp;

	while(scanf("%d %d",&n,&m) != EOF && n && m)
	{
		adj = new vector<Edge>[n+1];
		
		for(int i = 0 ; i < m ; i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			tmp.w = w;
			tmp.d = v;
			adj[u].push_back(tmp);
			tmp.d = u;
			adj[v].push_back(tmp);
		}

		Dijkstra(n,1,adj);
		delete []adj;
	}
	return 0;
}
