// **************Implement Stack Using Linked List**************

#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=NULL;
void push(){
    node *n=new node;
    cout<<"Enter data...";
    cin>>n->data;
    n->next=NULL;
    if(head==NULL){
        head=n;
        cout<<"\nData inserted into stack.\n"<<endl;
    }
    else{
        n->next=head;
        head=n;
        cout<<"\nData inserted into stack.\n"<<endl;
    }
}
void pop(){
    if(head==NULL){
        cout<<"\nStack empty.\n"<<endl;
    }
    else{
        node *t = head;
        head = head->next;
        delete t;
        cout<<"\nNode deleted.\n"<<endl;
    }
}
void display(){
    if(head==NULL){
        cout<<"\nStack empty.\n"<<endl;
    }
    else{ 
        node *r = head;
        while(r != NULL){
            cout << r->data << "->";
            r = r->next;
        }
        cout<<"NULL\n";
    }
}
int main(){
    int ch;
    cout<<"\n**************Implement Stack Using Linked List**************\n"<<endl;
    while(1){
        cout<<"\n1. push\n2. pop\n3. display\n4. Exit\n"<<endl;
        cout<<"\nEnter Your Choice...";
        cin>>ch;
        if(ch==1)
            push();
        else if(ch==2)
            pop();
        else if(ch==3)
            display();
        else
            exit(0);
    }
}