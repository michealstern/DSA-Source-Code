#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head = NULL;
int p = 0, count = 0;

void insert_beg(){
    node *n = new node;
    cout<<"Enter data:- ";
    cin>>n->data;
    n->next = NULL;
    if(head == NULL){
        head = n;
        n->next = head; // The next pointer of the new node points to the head. n does he point at himself.
        cout<<"\nNode inserted at the Beginning.\n"<<endl;
        count++;
    }
    else{
        node *r, *t;
        r = t = head;
        head = n;  // new node.
        n->next = t; // t points the old node.
        while(r->next != t){
            r = r->next;
        }
        r->next = head;
        cout<<"\nNode inserted at the Beginning.\n"<<endl;
        count++;
    }
}

void insert_end(){
    node *n = new node;
    cout<<"Enter Data:- ";
    cin>>n->data;
    n->next = NULL;
    if(head == NULL){
        head = n;
        n->next = head;
        cout<<"\nNode inserted at the End.\n"<<endl;
        count++;
    }
    else{
        node *r = head;
        while(r->next != head){
            r = r->next;
        }
        r->next = n;
        n->next = head;
        cout<<"\nNode inserted at the End.\n"<<endl;
        count++;
    }
}

void delete_beg(){
    if(head == NULL){
        cout<<"\nNo node available, Can't delete.\n"<<endl;
    }
    else if(head->next == head){
        delete  head;
        head = NULL;
        cout<<"\nNode Deleted At the beginning.\n"<<endl;
        count--;
    }
    else{
        node *q, *r;
        q = r = head;
        head = head->next;
        while(r->next != q){
            r = r->next;
        }
        r->next = head;
        delete q;
        cout<<"\nNode Deleted At the beginning.\n"<<endl;
        count--;
    }
}

void delete_end(){
    if(head == NULL){
        cout<<"\nNo node available, Can't delete.\n"<<endl;
    }
    else if(head->next == head){
        delete  head;
        head = NULL;
        cout<<"\nNode Deleted At the End.\n"<<endl;
        count--;
    }
    else{
        node *r, *t;
        r = head;
        while(r->next != head){
            r = r->next;
        }
        t = head;
        while(t->next != r){
            t = t->next;
        }
        t->next = head;
        delete r;
        cout<<"\nNode Deleted At the End.\n"<<endl;
        count--;
    }
}

void insert_mid(){
    node *n = new node;
    cout<<"Enter data... ";
    cin>>n->data;
    n->next = NULL;
    cout<<"\nEnter Position When you want data insert...";
    cin>>p;
    if(p==1 && head==NULL){  // List is empty.
        head = n;
        n->next = head;
        count++;
        cout<<"\nNode inserted .\n"<<endl;
    } 
    else if(p == 1 && head != NULL){
        node *r = head;
        while(r->next != head){
            r = r->next;
        }
        r->next = n;
        n->next = head;
        count++;
        cout<<"\nNode Inserted At the spacific Position.\n"<<endl;
    }
    else if(p > count || p <= 0){
        cout<<"\nCan't Node insert.\n"<<endl;
    }
    else{
        int i = 1;
        node *r = head;
        while(i < p - 1){
            r = r->next;
            i++;
        }
        n->next = r->next;
        r->next = n;
        count++;
        cout<<"\nNode Inserted At the spacific Position.\n"<<endl;
    }
}

void delete_mid(){
   int i = 1;
   cout<<"Enter Position...";
   cin>>p;
   if(p > count || head == NULL || p < 1){
    cout<<"\nCan't Delete, Node not available.\n"<<endl;
   }
   else if(p == 1 && head->next == head){
    delete head;
    head = NULL;
    cout<<"\nNode Deleted.\n"<<endl;
    count--;
   }
   else if(p == 1 && head != NULL){
    node *q, *r;
    q = r = head;
    head = head->next;
    while(r->next != q){
        r = r->next;
    }
    r->next = head;
    delete q;
    cout<<"\nNode Deleted.\n"<<endl;
    count--;
   }
   else{
    node *q, *r;
    r = head;
    while(i < p - 1){
        r = r->next;
        i++;
    }
    q = r->next;
    r->next = q->next;
    count--;
    cout<<"\nNode Deleted.\n"<<endl;
   }
}

void search(){
  int item;
  node *r;
  if(head==NULL){
    cout<<"\nNo node available: "<<endl;
  }
  else{
    cout<<"Enter Data whatever you want...";
    cin>> item;
    r = head;
    while(r != NULL){
      if(item == r->data){
        cout<<item <<" <---Found the Data in the list.\n"<<endl;
        break;
      }
      else{
        r = r->next;
      }
    }
    if(r == NULL){
        cout<<item <<" Data not found in the list.\n"<<endl;
    }
  }
}

void display(){
    if(head == NULL){
        cout<<"\nNo node available.\n"<<endl;
    }
    else{
        node *r = head;
        while(r->next != head){
            cout<< r->data <<"->";
            r = r->next;
        }
        cout<<"NULL\n";
    }
}


int main(){
    int ch;
    while(1){
        cout<<"\n*********** Circular Linked List ***********\n"<<endl;
        cout<<"\n1. Insert At Beginning.\n2. Insert At End.\n3. Delete At Beginning.\n4. Delete At End.\n5. Insert At Mid.\n6. Delete At Mid.\n7. Search Data.\n8. Display Data.\n"<<endl;
        cout<<"Enter Your Choice....";
        cin>>ch;
        if(ch == 1)
           insert_beg();
        else if(ch == 2)
            insert_end();
        else if(ch == 3)
            delete_beg(); 
        else if(ch == 4)
            delete_end();
        else if(ch == 5)
            insert_mid();
        else if(ch == 6)
            delete_mid();
        else if(ch == 7)
            search();
        else if(ch == 8)
            display();
        else
            exit(0);
    }
}