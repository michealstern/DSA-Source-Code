#include<iostream>
using namespace std;
struct node{ 
    int data;  // for data stored.
    node *prev; // Store the address of previous node.
    node *next; // // Store the address of next node.
};
node *head = NULL;  // Head asigned NULL when list is empty.

// <-------------------Insert at beginning------------------->

void insert_beg(){
    node *n=new node;
    cout<<"\nEnter data: ";
    cin>>n->data;
    n->prev=NULL;
    n->next=NULL;
 
    if(head==NULL){
        head=n;
        cout<<"\nNew node inserted at the beginning.\n"<<endl;
    }
    else{
        node *r=head;  // Here both *r & head points first node.
        head=n;  //head node updated first node become n.
        n->next=r;  // r points the next node of n.
        cout<<"\nNew node inserted at the beginning.\n"<<endl;
    }
}

// <-------------------Insert at the end------------------->

void insert_end(){
    node *n=new node;
    cout<<"\nEnter data: ";
    cin>>n->data;
    n->prev=NULL;
    n->next=NULL;
 
    if(head==NULL){
        head=n;
        cout<<"\nNew node inserted at the End.\n"<<endl;
    }
    else{
        node *r; 
        r=head;  // New pointers point the head node.
        while(r->next!=NULL){   // to reach till last node
            r=r->next;  // Travers r untill find out the last node.
        }
        r->next=n;  // After find out last node. new node inserted.
        cout<<"\nNew node inserted at the End.\n"<<endl;
    }
}

// <-------------------Display Data------------------->


void display(){
    if(head==NULL){
        cout<<"\n no node available \n"<<endl;
    }
    else{ 
        node *r;
        r=head;
        while(r!=NULL){
            cout<<r->data<<"->";
            r=r->next;
        }
        cout<<"NULL\n";
    }
}

// <-------------------Delete Beginning-------------------->

void del_beg(){
    if(head==NULL){
        cout<<"\n can not delete\n";
    }
    else if(head->next==NULL) {  //If there is only one node in the list
        node *p;  // New pointer
        p=head;   // point the head node.
        head=NULL; // head become null.
        delete p;
        cout<<"\n node deleted \n";
    }
    else {    //If the list contains two or more nodes
        node *t;  // New pointer t.
        t=head;   // point the head node.
        head=head->next; //Then the head is moved to another node
        head->prev=NULL;  //The pointer to the second node is set to null
        delete t;
        cout<<"\n node deleted\n";
    }
}

// <-------------------Main Function------------------->

int main(){
    int ch;
    while(1){
        cout<<"\n*********** Doubly Linked List ***********\n"<<endl;
        cout<<"\n1. Insert beginning\n2. Insert end\n3. Delete begining\n4. Display Data\n"<<endl;
        cout<<"Enter Your Choice....";
        cin>>ch;
        if(ch==1)
            insert_beg();
        else if(ch==2)
            insert_end();
        else if(ch==3)
            del_beg();
        else if(ch==4)
            display();
        else
            exit(0);
    }
}