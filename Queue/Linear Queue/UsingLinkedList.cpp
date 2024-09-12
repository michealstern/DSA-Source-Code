#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;

void enqueue(){
    node *n = new node;
    cout<<"\nEnter value...";
    cin>>n->data;
    n->next=NULL;
    if(front==NULL){
        front=n;
        rear=n;   //rear will point to last node for o(1)
        cout<<"\nData inserted\n"<<endl;
    }
    else{
        rear->next=n;
        rear=n;
        cout<<"\nData inserted\n"<<endl;
    }
}
//============================================
void dequeue(){
    if(front==NULL){
        cout<<"\n ** queue is empty **\n";
    }
    else{
        node *r = front;
        front = r->next;
        delete r;
        cout<<"\n ** deleted element **\n"<<endl;
    }
}
//===============================================
void display(){
    if(front==NULL){
        cout<<"\n **Queue is empty**\n"<<endl;
    }
    else{
        node *r = front;
        while(r != NULL){
            cout<< r->data<<" ";
            r=r->next;
        }
        cout<<"\n"<<endl;
    }
}
//==============================================
int main(){
    int ch;
    cout<<"\n*********** Queue implementation using Linked List ***********\n"<<endl;
    while(1){
        cout<<"Enter 1. to insert element in the queue\n";
        cout<<"Enter 2. to delete elements of the queue\n";
        cout<<"Enter 3. to display elements of the queue\n";
        cout<<"Enter 4. to exit\n"<<endl;
        cout<<"Enter Your Choice....";
        cin>>ch;
        if(ch==1){
            enqueue();
        }
        else if(ch==2){
            dequeue();
        }
        else if(ch==3){
            display();
        }
        else{
            exit(0);
        }
    }
    return 0;
}