#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

//Stack using Linked List

// push operation of Linked list
void push(Node*& top, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    if(ptr==nullptr){
        cout<<"we can not push "<<value<<endl;
        return;
    }
    ptr->data=value;
    ptr->next=top;
    top=ptr;
    cout<<value<<" is pushed into the stack"<<endl;
}

// pop operation of Linked list
int pop(Node*& top){
    if(top==nullptr){
        cout<<"stack underflow occurs!!"<<endl;
        return -1;
    }
    int value=top->data;
    Node* temp=top;
    top=top->next;
    free(temp);
    cout<<value<<" is popped from the stack"<<endl;
    return value;
}

// peek operation of Linked list
int peek(Node*& top) {
    if(top==nullptr){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    cout<<"Top element is: "<<top->data<<endl;
    return top->data;
}

// display function of stack
void displaySt(Node*& top) {
    if(top==nullptr){
        cout<<"stack is empty"<<endl;
        return;
    }
    Node*temp=top;
    cout<<"Stack elements are:"; 
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout <<endl;;
}

// menu of stack
void menuSt(){
    cout<<"STACK using Linked List menu:"<<endl;
    cout<<"1. PUSH operation"<<endl;
    cout<<"2. POP operation"<<endl;
    cout<<"3. TOP element of the stack"<<endl;
    cout<<"4. Display the stack"<<endl;
    cout<<"5. Exit"<<endl;
}

//Queue using Linked List

// enqueue operation of Linked list
void enqueue(Node*& front, Node*& rear, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    if(ptr==nullptr){
        cout<<"we can not enqueue "<<value<<endl;
        return;
    }
    ptr->data=value;
    ptr->next=nullptr;
    if(front==nullptr){
        front=ptr;
        rear=ptr;
    }else{
        rear->next=ptr;
        rear=ptr;
    }
    cout<<value<<" is enqueue in the queue."<<endl;
}

// dequeue operation of Linked list
int dequeue(Node*& front, Node*& rear){
    if(front==nullptr){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int value=front->data;
    Node* temp=front;
    front=front->next;
    if(front==nullptr){
        rear=nullptr;
    }
    free(temp);
    cout<<value<<" is dequeue from the queue."<<endl;
    return value;
}

// display function of queue
void displayQ(Node*& front){
    if(front==nullptr){
        cout<<"Entire queue is empty"<<endl;
        return;
    }
    Node* temp=front;
    cout<<"Elements in the queue are:";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// menu of queue
void menuLl(){
    cout<<"QUEUE using Linked List menu:"<<endl;
    cout<<"1. ENQUEUE operation"<<endl;
    cout<<"2. DEQUEUE operation"<<endl;
    cout<<"3. Display the queue"<<endl;
    cout<<"4. Exit"<<endl;
}

// main menu function
void mainMenu(){
    cout<<"MAIN MENU OF THE PROGRAM"<<endl;
    cout<<"1. Stack using Linked List"<<endl;
    cout<<"2. Queue using Linked List"<<endl;
    cout<<"3. Exit"<<endl;
}

int main(){
Node* stack=nullptr;
Node* front=nullptr;
Node* rear=nullptr;  
int choice;
do{
mainMenu();
cout<<"\nEnter your choice: ";
cin>>choice;
switch(choice){
    case 1: 
            int choiceSt;
            do{ 
            menuSt();
            cout<<"\nEnter your choice: ";
            cin>>choiceSt;
            switch (choiceSt){
                case 1:
                    int val;
                    cout <<"Enter the value you want to push: ";
                    cin >>val;
                    push(stack,val);
                    displaySt(stack);
                    break;
                case 2:
                    pop(stack);
                    displaySt(stack);
                    break;
                case 3:
                    peek(stack);
                    displaySt(stack);
                    break;        
                case 4:
                    displaySt(stack);
                    break;
                case 5:
                    cout<<"Exiting"<<endl;  
                    break;             
                default:
                    cout<<"Invalid choice!!"<<endl;
                    break;
    
                }    

                }while(choiceSt!=5);
    
                    break;

    case 2: 
            int choiceQ;
            do{ 
            menuLl();
            cout<<"\nEnter your choice: ";
            cin>>choiceQ;
            switch (choiceQ){
                case 1:
                    int value;
                    cout << "Enter the value you want to enqueue: ";
                    cin >> value;
                    enqueue(front,rear,value);
                    displayQ(front);
                    break;
                case 2:
                    dequeue(front,rear);
                    displayQ(front);
                    break;     
                case 3:
                    displayQ(front);
                    break;
                case 4:
                    cout<<"Exiting"<<endl;  
                    break;             
                default:
                    cout<<"Invalid choice!!"<<endl;
                    break;
        
                }    

                }while(choiceQ!=4 );
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

