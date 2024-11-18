#include<iostream>
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

//search function
bool search(Node*& root , int data){
    if(root==nullptr){
        return false;
    }else if(root->data==data){
        return true;
    }else if(data< root->data){
        return search(root->left,data);

    }else{
        return search(root->right,data);
    }
}


Node* findMin(Node*& root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}

//delete function
void deletenode(Node*& root, int data){
    if(root==nullptr){
        return;
    }
    if(data < root->data){
        deletenode(root->left,data);
    }else if(data > root->data){
        deletenode(root->right,data);
    }else{

        if(root->left==nullptr){// node has one child or no children
            Node* temp=root->right;
            free(root);
            root=temp;
        }else if(root->right==nullptr){// node has one child or no children
            Node* temp=root->left;
            free(root);
            root=temp;
        }
        else{
            Node* temp=findMin(root->right);// node has two child
            root->data=temp->data;
            deletenode(root->right,temp->data);
        }
    }
}

//inorder function
void inorder(Node*& root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//preorder function
void preorder(Node*& root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//postorder function
void postorder(Node*& root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//menu function
void menu(){
    cout<<"Binary Search Tree Operations:"<<endl;
    cout<<"1. INSERT operation"<<endl;
    cout<<"2. DELETE operation"<<endl;
    cout<<"3. SEARCH operation"<<endl;
    cout<<"4. INORDER Traversal"<<endl;
    cout<<"5. PREORDER Traversal"<<endl;
    cout<<"6. POSTORDER Traversal"<<endl;
    cout<<"7. Exit"<<endl;
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
        int value;
        cout<<"Enter the value to be delete: ";
        cin>>value;
        deletenode(root,value);  
        cout<<"Inorder traversal after deletion: ";
        inorder(root);
        cout<<endl;
        break;
         }

    case 3:{
        int key;
        cout<<"Enter the search value: ";
        cin>>key;
        if(search(root,key)){
            cout<<key<<" found in BST."<<endl;
        }else{
            cout<<key<<" not found in BST."<<endl;
        }
        cout<<"Inorder traversal after search: ";
        inorder(root);
        cout<<endl;
        break; 
    }          
    case 4:{
        cout<<"Inorder Traversal of BST:";
        inorder(root);
        cout<<endl;
        break; 
    } 
    case 5:{
        cout<<"Preorder Traversal of BST:";
        preorder(root);
        cout<<endl;
        break;  
    }   
    case 6:{
         
        cout<<"Postorder Traversal of BST:";
        postorder(root);
        cout<<endl;
        break;   
    } 
    case 7:{
        cout<<"Exiting"<<endl;
        break;
    }
     
    default:
    {
       cout<<"Invalid choice!!"<<endl;
       break;
    }

    }

    } while(choice!=7);


    return 0;
}