// n 點的數量
// m 邊的數量
// arr 連接到的頭
// num 那一組裡有多少個成員
#include<bits/stdc++.h>
#define N 100000

int arr[N+5];
int num[N+5];

using namespace std;

struct node
{
	int x;
	int y;
	int w;
};

void init()
{
	for(int i=0 ; i<= N ; i++)
	{
		num[i] = 0;
		arr[i] = i;
	}
}
bool rule(node &a,node &b)
{
	return a.w < b.w;
}

int find(int x)
{
	if(x == arr[x])
		return x;
	else 
	{
		arr[x] = find(arr[x]);
		return arr[x];
	}
}

bool issame(int a, int b)
{
	return find(a) == find(b);
}
void uni(int a,int b)//combine
{
	arr[find(a)] = find(b);
}
int main()
{
	#ifdef DEBUG
	freopen("input.in","r",stdins);
	freopen("output.out","w",stdout);
	#endif

	int n , m;
	vector<node>vec;

	while(cin >> n >> m)
	{	
		init();
		for(int i=0 ; i<m ; i++)
		{
			int a,b,c;
			cin >> a>>b>>c;
			vec.push_back((node){a,b,c});
		}

		// vector 的sort 要給開始跟結束
		sort(vec.begin(), vec.end(), rule);

		long long ans = 0;
		int edge = 0;

		for(int i=0 ; i<m ; i++)
		{
			int from = vec[i].x;
			int to = vec[i].y;

			from = find(from);
			to = find(to);

			if(!issame(from,to))
			{
				if(num[from] <= num[to])
				{
					num[to] ++;
					uni(to,from);
				}

				else 
				{
					num[from] ++;
					uni(from,to);
				}
				ans += vec[i].w;
				edge ++;

			}
		}
		vec.clear();
		if(edge < n-1)
			cout <<"-1" << endl;
		else 
			cout << ans <<endl;
	}
	
	return 0 ; 
}
