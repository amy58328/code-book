#include<bits/stdc++.h>

using namespace std;

int Queens[100][8]; // 存放 所有組合
int temp[8]; // 放找到的某一組
int total = 0; // 可能的個數
int row[8] = {0}, Left[15] = {0}, Right[15] = {0} ;

void queens(int c)
{
	if(c == 8)
	{
		for(int i=0 ;i<8 ;i++)
		{
			Queens[total][i] = temp[i]; // 找到的放到所有可能之一
		}

		total++;
		return ;
	}
	for(int i=0 ; i<8 ; i++)
	{
		int r = c+i;
		int l = c - i +7;
		if(Right[r] == 0 && Left[l] == 0 && row[i] == 0)
		{
			Right[r] = 1;
			Left[l] = 1;
			row[i] = 1;

			temp[c] = i;

			queens(c+1);

			// 當下一層沒有可能 ，設定歸零，再找下一個位子
			Right[r] = 0;
			Left[l] = 0;
			row[i] = 0;

		}
	}
}

int main()
{
	queens(0);
	cout << total << endl;
	return 0;
}
