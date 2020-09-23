#include <iostream>
#include <algorithm>
#include <inttypes.h>
#include <stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node *link;

};

class DLL
{
	public: struct node * head;
	DLL()
	{
		head=NULL;
	}
	struct node* XOR (struct node* a, struct node* b)
	{
    		return (struct node *) ((uintptr_t) (a) ^ (uintptr_t) (b));
	}

    void insert_at_beginning(int data)
	{
		struct node *newnode=new(struct node);
		newnode->data=data;
		newnode->link=NULL;

		if (head!=NULL)
		{
			newnode->link=head;
			head->link=XOR(head->link,newnode);
		}

		head=newnode;
	}

	void insert_at_end(int data)
	{
		struct node *newnode=new(struct node);
		newnode->data=data;
		newnode->link=NULL;

		if (head==NULL)
		{
			head=newnode;

		}
		else
		{	struct node * current=head;
			struct node *prev=NULL;
			struct node *x;
			while(current->link!=prev)
			{	x=current;
				current=XOR(current->link,prev);
				prev=x;
			}
			current->link=XOR(current->link,newnode);
			newnode->link=current;

		}
	}

	void display()
	{
		cout<<"The list: "<<endl;
		struct node * current=head;
		struct node *prev=NULL;
		struct node *temp;
		while(current->link!=prev)
		{	temp=current;
				cout<<current->data<<" " ;
				current=XOR(current->link,prev);
				prev=temp;
		}
		cout<<current->data<<endl;
	}

};


int main()
{
	DLL dll = DLL();
	int choice, n;
	do
	{
		cout << "Enter 1 : Insert at beginning \nEnter 2 : Insert at end \nEnter 3 : Display list\nEnter 4 : Exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
                cout << "Enter the element to be inserted: ";
				cin >> n;
				dll.insert_at_beginning(n);
				break;
			case 2:
                cout << "Enter the element to be inserted: ";
				cin >> n;
				dll.insert_at_end(n);
				break;
			case 3:
                dll.display();
				break;
            case 4:
				_Exit(0);
			default : cout<<"Incorrrect Choice.";
		};
	} while(true);
}
