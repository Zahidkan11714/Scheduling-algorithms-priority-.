#include <iostream>
#include<conio.h>
#include <windows.h>
using namespace std;
struct process
{
	char pname[5];
	int burst, arrival, priority;
	process *left, *right;	
};
class Sheduling
{
	process *first;
	int count, p;
	string pro[15];
	
	public:
		Sheduling()
		{
			first=NULL;
			count=0;
			p=0;
		}
		void P_creation()
		{
			process *new_p= new process;
			
			new_p->left=NULL;
			new_p->right=NULL;
			cout<<"\n Enter the process name: ";
			cin>>new_p->pname;
			cout<<"\n Enter the process burst time: ";
			cin>>new_p->burst;
			cout<<"\n Enter the arrival time: ";
			cin>>new_p->arrival;
			cout<<"\n Enter the process priority: ";
			cin>>new_p->priority;
			
			if(first==NULL)
			{
				first=new_p;
			}
			else
			{
				process *temp=first;
				
				while(temp->right!=NULL)
				{
					temp=temp->right;
				}
				temp->right=new_p;
				new_p->left=temp;
			}
			count++;
			cout<<"\n Process create successfull!";
		}
		void Short_job_first()
		{
				process *temp, *temp2;
				while(count!=0)
				{
					temp=first;
					temp2=temp;
					
					while(temp)
					{
						if(temp2->priority<temp->priority)
						{
							temp2=temp;
						}
						temp=temp->right;
					}
					
					while(temp2->burst!=0)
					{
						Sleep(3000);
						if(_kbhit())
						{
							P_creation();
							break;
						}
						else
						{
							temp2->burst--;
							cout<<"\n"<<temp2->pname<<"  "<<temp2->burst+1<<"  "<<temp2->arrival<<"  "<<temp2->priority;
						}
					}
					
					if(temp2->burst==0)
					{
						if(first->burst==temp2->burst)
						{
							first=first->right;
							if(first!=NULL)
							{
								first->left=NULL;
							}
						}
						else
						if(temp2->right==NULL)
						{
							temp2->left->right=NULL;
						}
						else
						{
							temp2->left->right=temp2->right;
							temp2->right->left=temp2->left;
						}
							pro[p++]=temp2->pname;
							cout<<"\n process "<<temp2->pname<<" terminate!";
							delete temp2;
						count--;
					}
			}
		}
		void Display()
		{
			cout<<"\n\n ***Sequence of terminating processes***\n";
			for(int i=0; i<p; i++)
			{
				cout<<"\n "<<i+1<<"-> "<<pro[i];
			}
			cout<<endl;
		}
};
int main()
{
	Sheduling p1;
	int opt;
	
	do{
		cout<<"\n 1-> Process Creation. ";
		cout<<"\n 2-> Display process Recently terminate.";
		cout<<"\n 3-> Switch oFF system. \n";
		cin>>opt;
		
		switch(opt)
		{
			case 1:
				p1.P_creation();
				p1.Short_job_first();
				break;
			case 2:
				p1.Display();
				break;
			case 3:
				system("cls");
				exit(0);
			default:
				cout<<"\n You enter invalid command!";
		}
	}while(opt!=3);
}
