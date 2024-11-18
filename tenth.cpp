#include<iostream>
using namespace std;
const int n=10;
int queue[n];
int front=-1;
int rear=-1;

// enqueue operation
void enqueue(int value){
    if(rear>=n-1){
        cout<<"Overflow condition occur!!"<<endl;
    }else{
        if(front==-1)front=0;
        rear++;
        queue[rear]=value;
        cout<<value<<" is enqueued into the queue."<<endl;
    }
}

// dequeue operation
void dequeue(){
    if(front==-1 || front>rear){
        cout<<"Underflow condition occur!!"<<endl;
    }else{
        cout<<queue[front]<<" is dequeued from the queue."<<endl;
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }

}

// display function
void display() {
    if(front==-1 || front>rear){
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements are:";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// menu function
void menu(){
    cout<<"QUEUE MENU:"<<endl;
    cout<<"1. ENQUEUE operation"<<endl;
    cout<<"2. DEQUEUE operation"<<endl;
    cout<<"3. Display the queue"<<endl;
    cout<<"4. Exit"<<endl;
}

int main(){
    
    int choice;
    do{ 
    menu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice){
        case 1:
                int value;
                cout << "Enter the value you want to enqueue: ";
                cin >> value;
                enqueue(value);
                display();
                break;
        case 2:
                dequeue();
                display();
                break;     
        case 3:
                display();
                break;
        case 4:
                cout<<"Exiting"<<endl;  
                break;             
        default:
                cout<<"Invalid choice!!";
                break;
    
    }    

    }while(choice!=4 );
    
    return 0;

}