#include<bits/stdc++.h>
#define N 1000000 
using namespace std ;

int  dfs_time  ;

struct basic
{
	int color;
	int discover;
	int finish;
	int predcessor;
	deque<int>adj;
};

basic node[N];

void init()
{
	dfs_time = 0;
	for(int i=0 ; i<=N ; i++)
	{
		node[i].color = 0; //unfind= 0 , find= 1, finish = 2
		node[i].discover = 0;
		node[i].finish = 0;
		node[i].predcessor = -1;
	}
}

void dfs(int a)
{
	if(node[a].color == 0 )
	{
		node[a].color = 1;
		node[a].discover = ++ dfs_time;
		for(int i=0 ; i<node[a].adj.size() ; i++)
		{
			dfs(node[a].adj[i]);
		}
		node[a].color = 2;
		node[a].finish = ++ dfs_time;
	}
}
int main(int argc, char const *argv[])
{

	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

	init();
	int num_vertex;
	int num_edge;
	cin >> num_vertex >> num_edge;

	for(int i=0 ; i<num_edge ; i++)
	{
		int a , b;
		cin >> a>> b;
		node[a].adj.push_back(b);
	}

	int start ,end ;
	cin >>start >>end;

	dfs(start);

	if(node[end].color == 2)
		cout << "YES"<<endl;

	else 
		cout << "NO" <<endl;
	return 0;
}