#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<algorithm>
#define loop(i,n) for(int i=0 ;i<n;i++)

using namespace std;

int main()
{
	int al[10];

	loop(i,10)
	{
		cin >> al[i];
	}

	loop(i,10)//algorithm
	{
		int min_site = i;
		for(int j=i+1 ; j<10 ; j++)
			if(al[j] < al[min_site])
				min_site = j;

		swap(al[i] , al[min_site]);

	}
	


	// printf

	loop(i,10)
		cout << al[i] << " " ;

}
