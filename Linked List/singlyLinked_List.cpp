#include<iostream>
using namespace std;
struct node
{
  int data; // for data stored.
  struct node *next;  // store the address of next node.
};
node *head = NULL; // Head asigned NULL when list is empty.
int p = 0, count = 0;
// <-------------------Insert at beginning------------------->

void insertAt_beg(){
  node *n = new node;    // New Node Created.
  cout<<"Enter data: ";  //Take out User input.
  cin>>n->data;
  n->next = NULL;       // Currently it's point to nothing.
  if(head == NULL){     // If list is the empty.
    head = n;           // Making it the first node in the list.
    cout<<"\nNew node inserted at the beg^. "<<endl;
  }
  else{         // If list is not empty.
    n->next = head;     //Next pointer point the first node. 
    head = n;
    cout<<"\nNew node inserted at the beg^. "<<endl;
  }
}

// <-------------------Insert at the End------------------->

void insertAt_end(){
  node *n = new node;       // New Node Created.
  cout<<"Enter data: ";     //Take out User input.
  cin>>n->data;
  n->next = NULL;           // Currently it's point to nothing.
  if(head==NULL){           // If list is the empty.
    head = n;
    cout<<"\nNew node inserted at the End. "<<endl;
  }
  else{                     // If list is not empty.
    node *t = head;         // This *t pointer points to the beginning node Head.
    while(t->next != NULL){ // Travers the node till NULL node.
      t = t->next;          // This pointr move the next node.
    }
    t->next = n;          // When loop reach tail new node attached after tail.
    cout<<"\nNew node inserted at the End. "<<endl;
  }
}

// <-------------------Delete first Node------------------->

void deleteAt_beg(){
  if(head==NULL){    // If list is the empty.
    cout<<"\nNo node available, Can't delete node. "<<endl;
  }
  else{         // If list is not empty.
    node *t = head;    // This *t pointer points to the beginning node Head. 
    head = head->next;      // Update head now head pointers point head->next node.
    delete t;           // Node delete and memory is free.
    cout<<"\nNode deleted at the beginning. "<<endl;
  }
}

// <-------------------Delete Last Node------------------->

void deleteAt_end(){
  if(head==NULL)
  {
    cout<<"\nNo node available, Can't Delete: "<<endl;
  }
  else if(head->next == NULL){   // If One Node is Available.
      delete head;    // Delete head.
      head = NULL;    // Now head free.
      cout<<"\nNode deleted at the End. "<<endl;
    }
  else{
      node *t, *r;  // Creat two temporary pointer.
      t = head;     // t pointers poit head node.
      while(t->next != NULL){  // to reach till last node.
        t = t->next;
      }
      r = head;
      while(r->next != t){  //traverse until r points to the second last node
        r = r->next;
      }
      r->next  = NULL;
      delete t;
      cout<<"\nNode deleted at the End. "<<endl;
    
  }
}

// <-------------------Insert Node at the Spacific Position------------------->

void insert_Spacific(){
    node *n = new node;
    cout<<"Enter data: ";
    cin>>n->data;
    n->next = NULL;
    cout<<"\nEnter Position When you want data insert: ";
    cin>>p;

    //1. if position is 1 and linked list is empty, then the new node is made the head.

    if(p==1 && head==NULL){  // List is empty.
        head = n;
        count++;
        cout<<"\nNode inserted."<<endl;
    } 

    //2. if position is 1 and there are already some nodes in the linked list, then the
    //   new node is inserted at the first position & the head is updated.

    else if (p==1 && head != NULL){  // If only one node is available.
        node *u = head;  // new node become head.
        head = n;  // The previous head move to next node.
        n->next = u;  
        count++;
        cout<<"\nNode inserted."<<endl;
    } 
    
    else if(p > count || p <= 0){
        cout<<"\nCan't insert node."<<endl;
    } 
    
    else {  // insert node any position.
        node *r, *t;
        r = head;
        int i = 1;
        while(i < p - 1){
            r = r->next;
            i++;
        }
        t = r->next; //To reach desired position, point next.
        r->next = n; // desired position new node inserted.
        n->next = t; // Now we make the new node the next node t.
        count++;
        cout<<"\nNode inserted."<<endl;
    }

}

// <-------------------Delete Node at the Spacific Position------------------->


void delete_Spacific(){
    cout << "Enter position: ";
    cin >> p;

    //1. If position is not valid.
    if (p > count || p <= 0 || head == NULL){
        cout << "No node available at the position.";
    }

    //2. if position 1 it means the starting node has to be deleted.
    else if (p == 1){
        node *t = head;
        head = t->next;
        delete t;
        count--;
        cout << "\nNode deleted."<<endl;
    }

    //3. if the position is valid and greater than 1 we delete that node.
    else{
        int i;
        node *r, *t, *u;
        r = head;
        while (i < p - 1){
            r = r->next;
            i++;
        }
        t = r->next;
        u = t->next;
        r->next = u;
        delete t;
        count--;
        cout << "\nnode deleted."<<endl;
        cout << "Total node=" << count;
    }
}

// <-------------------Searching Node-------------------->

void search(){
  int item;
  node *r;
  if(head==NULL){
    cout<<"No node available: "<<endl;
  }
  else{
    cout<<"Enter item :";
    cin>> item;
    r = head;
    while(r != NULL){
      if(item == r->data){
        cout<<item <<"Found the item in the list:"<<endl;
        break;
      }
      else{
        r = r->next;
      }
    }
    if(r == NULL){
        cout<<item <<"Item not found in the list: "<<endl;
    }
  }
}

// <-------------------Display Data------------------->

void display(){
  if (head == NULL){
    cout<<"\nNo node available: "<<endl;
  }
  else{
    node *r;
    r = head;
    while(r != NULL){
      cout<< r->data <<"->";
      r = r->next;
    }
    cout<<"NULL"<<endl;
  }
  cout << "\nTotal node=" << count<<endl;
}

// <-------------------Main Function------------------->

int main(){
  int ch;
  while(1){
    cout<<"\n*********** Singly Linked List ***********\n";
    cout<<"\n1. Insert at the beginning\n2. Insert at the End\n3. Delete at the beg\n4. Delete at the end\n5. Insert At the Spacific Position\n6. Delete At the Spacific Position\n7. Searching Node\n8. Display\n"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>ch;
    if(ch == 1)
      insertAt_beg();
    else if(ch == 2)
      insertAt_end();
    else if(ch == 3)
      deleteAt_beg();
    else if(ch == 4)
      deleteAt_end();
    else if(ch == 5)
      insert_Spacific();
    else if(ch == 6)
      delete_Spacific();
    else if(ch == 7)
      search();
    else if(ch == 8)
        display();
    else
      exit(0);
  }

  return 0;
}