#include <bits/stdc++.h>

using namespace std;

struct node
{
	int number;
	node *link;
};

node *link_list = NULL;

void insert( int add_num)
{
	node *n =(node*)malloc(sizeof(node));
	if(!n)
	{
		printf("memory is fall");
		exit(1);
	}

	n->number = add_num;
	n->link = NULL;

	if(link_list == NULL)
	{
		link_list = n ;
	}
	else
	{
		for(node *ptr = link_list ;ptr != NULL ; ptr = ptr->link)
		{
			if(ptr->link == NULL)
			{
				ptr->link = n;
				break;
			}
		}	
	}
}

void delete_num(int delete_number)
{
	bool found = false;
	for(node *ptr = link_list;ptr != NULL ; ptr = ptr->link)
	{
		if(ptr ->number == delete_number)
		{
			found = true;
			break;
		}
	}

	if(!found )
	{
		printf("no that number\n");
	}
	else
	{
		for(node *ptr = link_list ; ptr ->link != NULL ; ptr = ptr->link)
		{
			if(ptr == link_list)
			{
				if(ptr -> number == delete_number)
				{
					link_list = ptr->link;
				}
			}
			if(ptr -> link ->number  == delete_number)
			{
				node *n = (node*)malloc(sizeof(node*));
					n = ptr->link->link;
					ptr->link = n;
					break;

			}
		}
	}
}

void invert()
{
	node *middle ,*trail;
	middle = NULL;


	node *ptr ;
	ptr = link_list;
	while(ptr)
	{
		trail = middle;

		middle = ptr;
		ptr = ptr -> link;
		middle->link = trail;
	}
	link_list = middle;
}

int main(int argc, char const *argv[])
{
	int able ;
	printf("1. insert\n2. delete\n3. invert\n4. exit\n");
	while(cin >> able)
	{
		if(able == 1)
		{
			printf("insert number:\n");
			int add_num;
			cin >> add_num;
			insert(add_num);
			for(node *ptr = link_list ; ptr!= NULL ; ptr = ptr->link)
			{
				cout << ptr->number << " " ;
			}
			cout << endl;
		}
		
		else if(able == 2)
		{
			printf("delete number:");
			int delete_number;
			cin >> delete_number;
			delete_num(delete_number);
			for(node *ptr = link_list ; ptr!= NULL ; ptr = ptr->link)
			{
				cout << ptr->number << " " ;
			}
			cout << endl;
		}

		else if(able == 3)
		{
			invert();
			for(node *ptr = link_list ; ptr!= NULL ; ptr = ptr->link)
			{
				cout << ptr->number << " " ;
			}
			cout << endl;
		}
		else if(able == 4)
			break;
		printf("1. insert\n2. delete\n3. invert\n4. exit\n");

	}
	
	return 0;
}