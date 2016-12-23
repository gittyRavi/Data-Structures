#include<iostream>							// <cstdio> can be used in place of <malloc.h> and <process.h>
#include<conio.h>
#include<malloc.h>							// malloc.h and process.h is for memory allocation in c and c_plus_plus
#include<process.h>
using namespace std;

struct node
	{
		int data;
		node *next;
	};
	
class queue
	{
		node *frnt,*rear;
		public:
			queue()					// constructor
				{
					frnt=NULL;
					rear=NULL;
				}
			void insert();			// to insert can be named enqueue()
			void del();				// to delete can be named dequeue()
			void show();			// to display list can be named front()
	};

void queue::insert()
	{
		int value;
		node *ptr;
		cout<<endl<<"Insertion"<<endl;
		cout<<"Enter a number to insert :"<<endl;
		cin>>value;
		ptr=new node;
		ptr->data=value;
		ptr->next=NULL;
		if(frnt==NULL)
			frnt=ptr;
		else
			rear->next=ptr;
		rear=ptr;
		cout<<endl<<"New item is inserted to the Queue."<<endl<<endl;
	}

void queue::del()
	{
		if(frnt==NULL)
			{
				cout<<endl<<"Queue is already empty."<<endl<<endl;
			}
		else
			{	
				node *temp;
				temp=frnt;
				frnt=frnt->next;
				cout<<endl<<"Deletion operation :"<<endl<<"Deleted value is "<<temp->data<<endl;
				delete temp;
			}
	}
	
void queue::show()
	{
		node *ptr1;
		ptr1=frnt;
		if(frnt==NULL)
			{
				cout<<endl<<"The queue is empty."<<endl<<endl;
			}
		else
			{
				cout<<endl<<"The queue is "<<endl;
		
				while(ptr1!=NULL)
					{
						cout<<ptr1->data<<" ";
						ptr1=ptr1->next;
					}
				cout<<"End"<<endl<<endl;
			}
	}
	
int main()
	{
		queue q;
		int choice;
		while(1)
			{
				cout<<"\t\tQueue using linked list."<<endl<<endl;
				cout<<"1:Insertion."<<endl;
				cout<<"2:Deletion."<<endl;
				cout<<"3:Display queue."<<endl;
				cout<<"4:Exit."<<endl;
				cout<<"Enter your choice(1-4) :"<<endl;
				cin>>choice;
				switch(choice)
					{
						case 1: q.insert();
								break;
						case 2:q.del();
								break;
						case 3:q.show();
								break;
						case 4:exit(0);						// when do while is not used use exit(0)
								break;
						default:cout<<"Please enter correct choice(1-4)."<<endl<<endl;
						getch();
						break;
					}
			}
			return 0;
			getch();
	}
