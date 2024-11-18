#include<iostream>
using namespace std;
const int n=5;
//circular queue using circular linked list
struct Node{
    int data;
    Node* next;
};
Node* f=nullptr;
Node* r=nullptr;

// enqueue operation of Linked list
void enqueueLl(int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    if(ptr==nullptr){
        cout<<"we can not enqueue "<<value<<endl;
        return;
    }
    ptr->data=value;
    ptr->next=nullptr;
    if(f==nullptr){
        f=ptr;
        r=ptr;
        r->next=f;
    }else{
        r->next=ptr;
        r=ptr;
        r->next=f;
    }
    cout<<value<<" is enqueued in the circular queue."<<endl;
}

// dequeue operation of Linked list
int dequeueLl(){
    if(f==nullptr){
        cout<<"Circular queue is empty"<<endl;
        return -1;
    }
    int value;
    if(f==r){
        value=f->data;
        free(f);
        f=nullptr;
        r=nullptr;
    }else{
        Node* temp=f;
        value=temp->data;
        f=f->next;
        r->next=f;
        free(temp);
    }
    cout<<value<<" is dequeued from the circular queue."<<endl;
    return value;
}

// display function of Linked list
void displayLl(){
    if(f==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    Node* temp= f;
    cout<<"Circular Queue elements are: ";
   do{
    cout<<temp->data<<" ";
    temp=temp->next;
    } while(temp!=f);
    cout<<endl;
}

// menu of Linked list
void menuLl(){
    cout<<"CIRCULAR QUEUE using Linked List menu:"<<endl;
    cout<<"1. ENQUEUE operation"<<endl;
    cout<<"2. DEQUEUE operation"<<endl;
    cout<<"3. Display the Circular Queue"<<endl;
    cout<<"4. Exit"<<endl;
}

//circular queue using arrays
int cirqueue[n];
int front=-1;
int rear=-1;

// enqueue operation of array
void enqueueAr(int value){
    if((rear + 1) % n == front){
        cout<<"Circular queue is full."<<endl;
        return;
    }
    if(front==-1){
    front=0;
    }
    rear = (rear + 1) % n;
    cirqueue[rear] = value;
    cout<<value<<" is enqueued into the circular queue."<<endl;

}

// dequeue operation of array
int dequeueAr(){
    if(front==-1){
        cout<<"Circular queue is empty."<<endl;
        return -1;
    }
    int value=cirqueue[front];
    if(front==rear){
       front=-1;
       rear=-1;
    }else{
        front=(front+1)%n;
    }
    cout<<value<<" is dequeued from the circular queue."<<endl;   
    return value;
}

// display function of array
void displayAr() {
    if(front==-1){
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Circular Queue elements are: ";
    int i = front;
    while (i != rear) {
        cout <<cirqueue[i] << " ";
        i=(i + 1) % n;
    }
    cout << cirqueue[rear] << endl;
}

// menu of array
void menuAr(){
    cout<<"CIRCULAR QUEUE using Arrays menu:"<<endl;
    cout<<"1. ENQUEUE operation"<<endl;
    cout<<"2. DEQUEUE operation"<<endl;
    cout<<"3. Display the Circular Queue"<<endl;
    cout<<"4. Exit"<<endl;
}

// main menu function
void mainMenu(){
    cout<<"MAIN MENU OF THE PROGRAM"<<endl;
    cout<<"1. Circular Queue using Arrays"<<endl;
    cout<<"2. Circular Queue using Linked List"<<endl;
    cout<<"3. Exit"<<endl;
}

int main(){

int choice;
do{
mainMenu();
cout<<"\nEnter your choice: ";
cin>>choice;
switch(choice){
    case 1: 
            int choiceAr;
            do{ 
            menuAr();
            cout<<"\nEnter your choice: ";
            cin>>choiceAr;
            switch (choiceAr){
                 case 1:
                    int value;
                    cout << "Enter the value you want to enqueue: ";
                    cin >> value;
                    enqueueAr(value);
                    displayAr();
                    break;
                 case 2:
                    dequeueAr();
                    displayAr();
                    break;     
                 case 3:
                    displayAr();
                    break;
                 case 4:
                    cout<<"Exiting"<<endl;  
                    break;             
                 default:
                    cout<<"Invalid choice!!"<<endl;
                    break;
                 }    
                 }while(choiceAr!=4 );
                    break;

    case 2: 
            int choiceLl;
            do{ 
            menuLl();
            cout<<"\nEnter your choice: ";
            cin>>choiceLl;
            switch (choiceLl){
                 case 1:
                    int value;
                    cout << "Enter the value you want to enqueue: ";
                    cin >> value;
                    enqueueLl(value);
                    displayLl();
                    break;
                 case 2:
                    dequeueLl();
                    displayLl();
                    break;     
                 case 3:
                    displayLl();
                    break;
                 case 4:
                    cout<<"Exiting"<<endl;  
                    break;             
                 default:
                    cout<<"Invalid choice!!"<<endl;
                    break;
                }    

                 }while(choiceLl!=4 );
                    break;

    case 3:  
            cout<<"Exiting"<<endl;
            break;

    default:
            cout<<"Invalid Choice!!"<<endl;
            break;            

}    

}while(choice!=3);
    
    return 0;

}
 