//circular linked list
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
Node* addToEmpty(Node *last, int data);
Node* append(Node *last, int data);
Node* createList(Node *last){
	int n, d;
	cout<<"Enter the number of values: ";
	cin>>n;
	cout<<"Enter the first value: ";
	cin>>d;
	last = addToEmpty(last,d);
	for(int i=1; i<n; i++){
		cout<<"Enter the next value: ";
		cin>>d;
		last = append(last,d);
	}return last;
}
Node* addToEmpty(Node *last, int data){
	Node *n = new Node();
	n->data = data;
	last = n;
	last->next = last;
	return last;
}
Node* push(Node *last, int data){
	if(last==NULL){
		last = addToEmpty(last,data);
		return last;
	}
	Node *n = new Node();
	n->data = data;
	n->next = last->next;
	last->next = n;
	return last;
}
Node* append(Node *last, int data){
	if(last==NULL){
		last = addToEmpty(last,data);
		return last;
	}
	Node *n = new Node();
	n->data = data;
	n->next = last->next;
	last->next = n;
	last = n;
	return last;
}
Node* addAfter(Node *last, int data, int item){
	if(last->data==item){
		last = append(last,data);
		return last;
	}
	Node *n = new Node();
	n->data = data;
	Node *temp = last;
	while(temp->data!=item){
		temp = temp->next;
	}
	n->next = temp->next;
	temp->next = n;
	return last;
}
Node* del(Node *last, int data){
	Node *temp = last;
	if(temp==NULL){
		cout<<"Empty!"<<endl;
		return last;
	}
	if(last == last->next && last->data == data){
		last = NULL;
		return last;
	}
	while(temp->next->data!=data){
		temp = temp->next;
	}
	Node *t = temp->next;
	temp->next = t->next;
	if(t==last){
		delete t;
		last = temp;
		return last;
	}
	delete t;
	return last;
}
void reverse(Node *last){
	Node *temp = last;
	while(temp!=last->next){
		cout<<temp->data<<" ";
		temp->next = temp;
	}
	cout<<temp->data<<endl;
}
void display(Node *last){
	if(last==NULL){
		cout<<"Empty!"<<endl;
		return;
	}
	Node *temp = last->next;
	while(temp!=last){
		cout<<temp->data<<" ";
		temp=temp->next;
	}cout<<temp->data<<endl;
}
int main(){
	int choice,value,item;
	Node *last = NULL;
	while(1){
		cout<<"1. Create a circular linked list."<<endl;
		cout<<"2. Add to empty list."<<endl;
		cout<<"3. Add at the beginning of the list."<<endl;
		cout<<"4. Add at the end of the list."<<endl;
		cout<<"5. Add after a node."<<endl;
		cout<<"6. Delete a node."<<endl;
		cout<<"7. Display the list."<<endl;
		cout<<"8. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				last = createList(last);
				break;
			case 2:
				cout<<"Enter the value: ";
				cin>>value;
				last = addToEmpty(last,value);
				break;
			case 3:
				cout<<"Enter the value: ";
				cin>>value;
				last = push(last,value);
				break;
			case 4:
				cout<<"Enter the value: ";
				cin>>value;
				last = append(last,value);
				break;
			case 5:
				cout<<"Enter the node after which new node is to be inserted: ";
				cin>>item;
				cout<<"Enter the value: ";
				cin>>value;
				last = addAfter(last,value,item);
				break;
			case 6:
				cout<<"Enter the node to be deleted: ";
				cin>>value;
				last = del(last,value);
				break;
			case 7:
				cout<<"Created circular linked-list is: ";
				display(last);
				break;
			case 8:
				cout<<"EXIT";
				exit(0);
				break;
		}
	}
}
