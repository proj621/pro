#include<iostream>
using namespace std;
const int n =10;
int stack[n];
int top=-1;

// diplay function
void display(){
    if(top<0){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack elements are:";
        for(int i=0;i<=top;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

// push operation
void push(int value){
    if(top>=n-1){
        cout<<"Overflow condition occurs."<<endl;
    }else{
        top++;
        stack[top]=value;
        cout<<value<<" is pushed into the stack."<<endl;
    }
}

// pop operation
void pop(){
    if(top<0){
        cout<<"Underflow condition occurs."<<endl;
    }else{
        cout<<stack[top]<<" is popped from the stack."<<endl;
        top--;
    }
}

// top element in stack
void peek() {
    if (top < 0) {
        cout << "Stack is empty"<< endl;
    } else {
        cout << "Top element is: "<< stack[top] << endl;
    }
}

//menu function
void menu(){
    cout<<"STACK MENU:"<<endl;
    cout<<"1. PUSH operation"<<endl;
    cout<<"2. POP operation"<<endl;
    cout<<"3. TOP elemnt of the stack"<<endl;
    cout<<"4. Display the stack"<<endl;
    cout<<"5. Exit"<<endl;
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
                cout << "Enter the value you want to push: ";
                cin >> value;
                push(value);
                display();
                break;
        case 2:
                pop();
                display();
                break;
        case 3:
                peek();
                display();
                break;        
        case 4:
                display();
                break;
        case 5:
                cout<<"Exiting"<<endl;  
                break;             
        default:
                cout<<"Invalid choice!!";
                break;
    
    }    

    }while(choice!=5);
    
    return 0;

}