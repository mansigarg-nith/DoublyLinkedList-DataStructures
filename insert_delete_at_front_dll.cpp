//doubly-linked list insertion and deletion at front
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *prev;
		Node *next;
};
void push(Node **h, int d){
	Node *n = new Node();
	n->prev = NULL;
	n->data = d;
	n->next = *h;
	if(*h!=NULL){
		(*h)->prev = n;
	}
	*h = n;
}
Node * del(Node *h){
	if(h==NULL){
		cout<<"Doubly linked-list is already empty!";
		return h;
	}
	if(h->next==NULL){
		cout<<"Doubly linked-list is empty now!";
		return h;
	}
	Node *temp = h;
	h = temp->next;
	temp = temp->next;
	temp->prev = NULL;
	h = temp;
	return h;
}
void printList(Node *h){
	while(h!=NULL){
		cout<<h->data<<" ";
		h = h->next;
	}
}
int main(){
	Node *t, *head = NULL;
	cout<<"Enter the number of elements in doubly-linked list: ";
	int n;
	cin>>n;
	int i=0;
	if(n<=0){
		cout<<"You can't insert the elements!"<<endl;
	}
	if(n>0){
		cout<<"Insertion at beginning: "<<endl;
		while(i<n){
			cout<<"Push: ";
			int d;
			cin>>d;
			push(&head,d);
			i++;
		}
		cout<<"Created doubly-linked list is: ";
		printList(head);
		cout<<endl;
	}
	if(head==NULL){
		cout<<"Can't delete element from front!"<<endl;
		cout<<"Doubly linked-list is already empty!";
	}
	if(head->next==NULL){
		cout<<"After deletion from front: ";
		cout<<"Doubly linked-list is empty now!";
	}
	else{
		cout<<"Deleting the element from front."<<endl;
		t = del(head);
		cout<<"Doubly linked-list after deletion of the front element: ";
		printList(t);
	}
}
