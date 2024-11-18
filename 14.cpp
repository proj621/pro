#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//create node function
Node* createnode(int data){
    Node* ptr= (Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->left=nullptr;
    ptr->right=nullptr;
    return ptr;
}

//insert function 
void insert(Node*& root, int data){
    if(root==nullptr){
        root=createnode(data);
    }else if(data<= root->data){
        insert(root->left,data);

    }else{
        insert(root->right,data);
    }

}

void preorder(Node*& root){
    if(root==nullptr){
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* ptr= s.top();
        s.pop();
        cout<<ptr->data<<" ";
        if(ptr->right) s.push(ptr->right);
        if(ptr->left) s.push(ptr->left);

    }
}

void inorder(Node*& root) {
    stack<Node*> s;
    Node* ptr=root;
    while(ptr!=nullptr || !s.empty()){
        while(ptr!=nullptr){
            s.push(ptr);
            ptr=ptr->left;
        }
        ptr=s.top();
        s.pop();
        cout<<ptr->data<<" ";
        ptr=ptr->right;
    }

}

void postorder (Node*& root) {
    if(root==nullptr){
      return;
    } 

    stack<Node*> s1, s2;
    s1.push(root);

    
    while (!s1.empty()) {
        Node* ptr = s1.top();
        s1.pop();
        s2.push(ptr);
        if (ptr->left) s1.push(ptr->left);
        if (ptr->right) s1.push(ptr->right);
    }

    while (!s2.empty()) {
        Node* ptr = s2.top();
        s2.pop();
        cout<<ptr->data<< " ";
    }
}

void menu(){
    cout<<"Binary Search Tree Operations using stacks:"<<endl;
    cout<<"1. INSERT operation"<<endl;
    cout<<"2. INORDER Traversal"<<endl;
    cout<<"3. PREORDER Traversal"<<endl;
    cout<<"4. POSTORDER Traversal"<<endl;
    cout<<"5. Exit"<<endl;
}


int main(){
    Node* root=nullptr;
    int choice;
do{
    menu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        int value;
        cout<<"Enter the value to be insert: ";
        cin>>value;
        insert(root,value);  
        cout<<"Inorder traversal after insertion: ";
        inorder(root);
        cout<<endl;
        break;  
    }
         
    case 2:{
        cout<<"Inorder Traversal of BST:";
        inorder(root);
        cout<<endl;
        break; 
    } 
    case 3:{
        cout<<"Preorder Traversal of BST:";
        preorder(root);
        cout<<endl;
        break;  
    }   
    case 4:{
         
        cout<<"Postorder Traversal of BST:";
        postorder(root);
        cout<<endl;
        break;   
    } 
    case 5:{
        cout<<"Exiting"<<endl;
        break;
    }
     
    default:
    {
       cout<<"Invalid choice!!"<<endl;
       break;
    }

    }

    } while(choice!=5);


    return 0;
}