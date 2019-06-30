#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>

using namespace std ;

int ans=-10000;

struct nood
{	
	int max ;
	int min ;
	int sum ;
	
};

void build_tree(nood* tree,int* num, int l,int r,int seat)
{
	if(l == r)
		tree[seat].max = tree[seat].min = tree[seat].sum =num[l];

	else
	{

		build_tree(tree,num,l,(r+l)/2,seat*2); // build left
		build_tree(tree,num,(r+l)/2+1,r,seat*2+1); // build right

		// max tree
		if(tree[seat*2].max >= tree[seat*2+1].max)
			tree[seat].max = tree[seat*2].max;

		else if(tree[seat*2].max < tree[seat*2+1].max)
			tree[seat].max = tree[seat*2+1].max;
		//min tree
		if(tree[seat*2].min <= tree[seat*2+1].min)
			tree[seat].min = tree[seat*2].min;
		else if(tree[seat*2].min >= tree[seat*2+1].min)
			tree[seat].min = tree[seat*2+1].min;
		//sum tree
			tree[seat].sum = tree[seat*2].sum + tree[seat*2+1].sum;
	}
}


void search(int fl,int fr,int seat,int l ,int r ,nood* tree)
{
	if(fl > r || fr < l)
		return ;
	if(fl<=l && fr >= r)
		ans = max(ans,tree[seat].max);
	else
	{
		search(fl,fr,seat*2,l,(r+l)/2,tree);
		search(fl,fr,seat*2+1,(r+l)/2+1,r,tree);

	}

}

int main(int argc, char const *argv[])
{
	int amount;
	cin >>amount;
	int num[amount];
	nood tree[amount*4];
	

	for(int i=0 ; i<amount ; i++)
		cin >> num[i];

	build_tree(tree,num,0,amount-1,1); // build tree
	// search range 
	cout<<"cin range" <<endl;
	int fl,fr;
	cin >> fl>>fr;
	

	search(fl,fr,1,0,amount-1,tree);
	cout << ans<<endl;
	cout <<"-------------------------"<< endl;

	// cout tree
	for(int i=1;i<4*amount;i=i*2)
	{
		for(int j=i;j<i*2 && j<4*amount;j++)
			printf("%d ", tree[j].max );
		printf("\n");
	}

	cout <<"-------------------------"<< endl;

	for(int i=1;i<4*amount;i=i*2)
	{
		for(int j=i;j<i*2 && j<4*amount;j++)
			printf("%d ", tree[j].min );
		printf("\n");
	}

	cout <<"--------------------------"<<endl;

	for(int i=1;i<4*amount;i=i*2)
	{
		for(int j=i;j<i*2 && j<4*amount;j++)
			printf("%d ", tree[j].sum );
		printf("\n");
	}

	return 0;
}
