//insert a node after a particular node
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
void printList(Node *h);
void insertAfter(Node *h, int k, int d){
	Node *n = new Node();
	Node *temp = h;
	while(temp->data!=k){
		temp = temp->next;
	}
	if(temp==NULL){
		cout<<"Previous node can't be NULL!"<<endl;
		return;
	}
	if(temp->next==NULL){
		append(&h,d);
		return;
	}
	n->data = d;
	n->next = temp->next;
	temp->next = n;
	n->prev = temp;
	if(n->next!=NULL){
		n->next->prev = n;
	}
	return;
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
	cout<<endl;
	}
	cout<<endl;
	if(head!=NULL){
		cout<<"Inserting a node after a particular node."<<endl;
		int d,k;
		cout<<"Enter the node after which new node is to be inserted: ";
		cin>>k;
		cout<<"Enter the new value: ";
		cin>>d;
		insertAfter(head,k,d);
		cout<<"Newly created doubly linked-list is: ";
		printList(head);
	}else{
		cout<<"You can't insert any node because doubly linked-list is empty!"<<endl;
	}
}
