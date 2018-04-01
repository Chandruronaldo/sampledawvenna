#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class QueueLL
{
	private:
	node *front,*rear;
	
	public:
	QueueLL()//Defaut constructor
	{
		front=NULL;
		rear=NULL;
	}
	
	void enqueue(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;// A new node has been created 
		if(rear==NULL)
		{
			front=temp;
			rear=temp;
			
		}
		else
		{
			rear->next=temp;
			rear=temp;
			cout<<"\n Insertion successful!";//THe node has been inserted at the end of the queue
		}
	}
	
	int dequeue()
	{
		node *temp=new node;
		temp=front;
		if(front==NULL)
		{
			return 0;
		}
		else
		{
			front=front->next;
			
			return temp->data;
			delete temp;
		}
	}
	bool isempty()
	{
		if(front==NULL)
		return true;
		else
		return false;
	}
	
	void display()
	{
		node *temp=new node;
		temp=front;
		//cout<<"\n Top-->";
		while(temp->next!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
		cout<<temp->data<<"-->TOP";
		//cout<<"Rear";
		
	}
};

class stack
{
	private:
	QueueLL Q1;
	QueueLL Q2;
	node *top;
	
	public:
	stack()
	{
		top=NULL;
	}
	
	void push(int val)
	{
		Q1.enqueue(val);
		Q2.enqueue(val);
	}
	
	int pop()
	{
		int m=0,n=0;
		while(Q1.isempty()!=false)
		{
			m=Q1.dequeue();
		}
		while(Q2.isempty()!=false)
		{
			n=Q2.dequeue();
			if(n!=m)
			{
				Q1.enqueue(n);
			}
		}
		return m;
	}
	void display()
	{
		Q1.display();
	}
};

int main() {
	stack a;
	int choice, val,again;
            cout<<"\n:: Stack using Queue ::\n";
            
	    do{
            cout<<"\n--->OPTIONS<---\n";
            cout<<"1. Push\n2. Pop\n";
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice){
	 case 1: cout<<"\nEnter the value to be insert: ";
                     cin>>val;
	         a.push(val);
	         a.display();
	         break;
	 case 2: a.pop();
	         a.display();
	         break;
	 default: cout<<"\nError!! Wrong info\n";
      }
      cout<<"\n\n Do you want to edit the stack ?\n1. Yes \n2. No";
      cin>>again;
   }while(again!=2);
	return 0;
}