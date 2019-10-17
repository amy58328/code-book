#include<bits/stdc++.h>

using namespace std;

struct node
{
	int n;
	node* link ;
};

int main()
{
	node* ptr = NULL;

	node* ptr1 = (node*)malloc(sizeof(node));
	ptr1->link = NULL;
	ptr1->n = 12;

	ptr -> link = ptr1;


	node* ptr2 = (node*)malloc(sizeof(node));
	ptr2->link = NULL;
	ptr2->n = 13;

	ptr1->link = ptr2;

	// for(node* pp = ptr ; pp != NULL ; pp = pp->link)
	// {
	// 	if(pp -> link == NULL)
	// 	{
	// 		pp -> link = ptr1;
	// 		break;
	// 	}
			
	// }

	for(node* pp = ptr1 ; pp->link != NULL ; pp = pp->link)
	{
		cout << pp->n << endl;
	}




	
}