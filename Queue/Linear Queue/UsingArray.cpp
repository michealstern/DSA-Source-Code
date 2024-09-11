#include<iostream>
#include<stdlib.h>
using namespace std;
#define size 5  //Size of elements.
int q[size];  //Store Queue.
int front=-1,rear=-1; //FRONT and REAR defined -1 means Queue is empty.

    //=================== enqueue()========================
void enqueue(){
    int data;
    cout<<"Enter elements...";
    cin>>data;
    if(rear==size-1){     //Queue is full.
        cout<<"\n**Queue is full**\n"<<endl;
    }
    else if(rear==-1 && front==-1){  //Queue is empty.
        front=rear=0;
        q[rear]=data;
        cout<<"\n**Data inserted successfully**\n"<<endl;
    }
    else{  //Already elements stored in Queue.
        rear++;
        q[rear]=data;
        cout<<"\n**Data inserted successfully**\n"<<endl;
    }
}
    //=====================dequeue=================
void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"\n**Queue is empty**\n"<<endl;
    }
    else if(front==rear){
        front=rear=-1;
        cout<<"\n**Queue is empty**\n"<<endl;
    }
    else{
        front++;
        cout<<"\n** Elements removed successfully **\n"<<endl;
    }
}
    //=========================display()=============
void display(){
    if(front==-1 && rear==-1){
        cout<<"\n**Queue is empty**\n"<<endl;
    }
    else{
        cout<<"\n**ELEMENTS ARE**"<<endl;
        for(int i=front;i<=rear;i++){
            cout<<q[i]<<endl;
        }
        cout<<"\n";
    }
}

int main(){
    int ch;
    cout<<"\n*********** Queue implementation using array ***********\n"<<endl;
    while(1){
        cout<<"1. to insert element in the queue\n";
        cout<<"2. to delete elements of the queue\n";
        cout<<"3. to display elements of the queue\n";
        cout<<"4. to exit\n"<<endl;
        cout<<"Enter Your Choice....";
        cin>>ch;
        cout<<"\n";
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