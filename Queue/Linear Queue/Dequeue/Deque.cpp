#include <iostream>
using namespace std;

#define size 5

int deque[size];
int f = -1, r = -1;

void enqueue_rear() {
    int n;
    cout << "\nEnter data to insert...";
    cin>>n;
    if ((f == 0 && r == size - 1) || (f == r + 1)) {
        cout << "\n Deque is full" << endl;
    } 
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[r] = n;
        cout << "\nData inserted" << endl;
    } 
    else if (r == size - 1) {
        r = 0;
        deque[r] = n;
        cout << "Data inserted" << endl;
    } else {
        r++;
        deque[r] = n;
        cout << "Data inserted" << endl;
    }
}

void enqueue_front() {
    int n;
    cout << "Enter the data to insert...";
    cin>>n;
    if ((f == 0 && r == size - 1) || (f == r + 1)) {
        cout << "Deque is full" << endl;
    } 
    else if (f == -1 && r == -1) {
        f = r = 0;
        deque[f] = n;
        cout << "Data inserted" << endl;
    } 
    else if (f == 0) {
        f = size - 1;
        deque[f] = n;
        cout << "Data inserted" << endl;
    } else {
        f = f - 1;
        deque[f] = n;
        cout << "Data inserted" << endl;
    }
}

void display() {
    if (f == -1 && r == -1) {
        cout << "Deque is empty" << endl;
        return;
    }

    int i ;
    while (i != r) {
        cout << deque[i] << " ";
        i = (i + 1) % size;
    }
    cout << deque[r] << endl;
}

void dequeue_rear() {
    if (f == -1 && r == -1) {
        cout << "Deque is empty" << endl;
    } 
    else if (f == r) {
        cout << "The deleted element is " << deque[r] << endl;
        f = r = -1;
    } 
    else if (r == 0) {
        cout << "The deleted element is " << deque[r] << endl;
        r = size - 1;
    } 
    else {
        cout << "The deleted element is " << deque[r] << endl;
        r = r - 1;
    }
}

void dequeue_front() {
    if (f == -1 && r == -1) {
        cout << "Deque is empty" << endl;
    } 
    else if (f == r) {
        cout << "The deleted element is " << deque[f] << endl;
        f = r = -1;
    } 
    else if (f == size - 1) {
        cout << "The deleted element is " << deque[f] << endl;
        f = 0;
    } 
    else {
        cout << "The deleted element is " << deque[f] << endl;
        f = f + 1;
    }
}

int main() {
    int opt, n;
    while (true) {
        cout << "\n1. Insert Rear\n2. Insert Front\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cin >> opt;
        switch (opt) {
            case 1:
                enqueue_rear();
                break;
            case 2:
                enqueue_front();
                break;
            case 3:
                dequeue_rear();
                break;
            case 4:
                dequeue_front();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid option! Try again." << endl;
        }
    }
    return 0;
}
