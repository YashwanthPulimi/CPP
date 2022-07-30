#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

Node* middle(Node* head){
    
    
    
   Node*fast=head;
    Node*slow=head;
    
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return slow;
    
}
Node* reverse(Node* head){
    
    Node* curr=head;
    
    Node* prev=NULL;
    Node*next=NULL;
    
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    head=prev;
    
    
    return head;
}


void print(Node* head){
    
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool ispalindrome(Node* head){
    Node* temp=head;
    
    Node*mid=middle(head);
    
    Node* midnxt=mid->next;
    
    mid->next=NULL;
    
    Node* revhead=reverse(midnxt);
    
    while(head!=NULL && revhead!=NULL){
        if(temp->data!=revhead->data){
            return false;
        }
        
        temp=temp->next;
        revhead=revhead->next;
    }
    
    
    return true;
    
}

int main()
{
	
		Node *head = takeinput();
		print(head);
		if(ispalindrome(head)==true){
		    cout<<"true";
		}
		else{
		    cout<<"false";
		}

	
	return 0;
}