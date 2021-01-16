//doubly-linked list insertion and deletion at end
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *prev;
		Node *next;
};
void append(Node **h, int d){
	Node *n = new Node();
	Node *temp = *h;
	n->data = d;
	n->next = NULL;
	if(*h==NULL){
		n->prev = NULL;
		*h = n;
		return;
	} 
	while(temp->next !=NULL){
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}
void del(Node *h){
	Node *temp = h;
	if(temp->next == NULL){
		cout<<"Doubly linked-list is empty now.";
		return;
	}
	if(temp==NULL){
		cout<<"Doubly linked-list is already empty.";
		return;
	}
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	Node *t = temp->next;
	temp->next = NULL;
	delete t;
}
void printList(Node *h){
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
}
int main(){
	Node *head = NULL;
	cout<<"Enter the number of elements in the doubly-linked list: ";
	int n,i=0;
	cin>>n;
	if(n<=0){
		cout<<"Can't append the elements!";
	}
	if(n>0){
		cout<<"Append the elements."<<endl;
		while(i<n){
			int d;
			cout<<"Append: ";
			cin>>d;
			append(&head,d);
			i++;
		}
	cout<<"Created doubly linked-list is: ";
	printList(head);
	}
	cout<<endl;
	del(head);
	if(head!=NULL && head->next!=NULL){
		cout<<"Doubly linked-list after deletion of element from the end is: ";
		printList(head);
	}
}
