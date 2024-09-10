#include<iostream>
using namespace std;
#define size 5  // Stack Size.
int s[size],top=-1; //Make an array 's' in which store the stack elements. 
void push(){
    if(top==size-1){  //Stack is full (5-1=4, 0,1,2,3,4)
        cout<<"stack full can not insert element\n";
    }
    else{
        top++;
        cout<<"\nEnter element to be pushed...";
        cin>>s[top];
        cout<<"\nElement inserted\n"<<endl;
    }
}
void pop(){
    if(top==-1){
        cout<<"\nStack empty can not delete\n"<<endl;
    }
    else{
        top--;
        cout<<"\nElement removed\n"<<endl;
    }
}
void display(){
    if(top==-1){
        cout<<"\nStack empty \n"<<endl;
    }
    for(int i = top; i>=0; i--){
        cout<<s[i]<<"\n";
    }
}
int main(){
    int ch;
    cout<<"\n**************Implement Stack Using Array**************\n"<<endl;
    while(1){
        cout<<"\n1. For push()\n2. For pop()\n3. For display()\n4. For exit()\n"<<endl;
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
    return 0;
}
