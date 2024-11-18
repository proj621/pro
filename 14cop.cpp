#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* insertBST(Node* root, int d){

    if(root == NULL){
        Node* temp = new Node();
        temp->data = d;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if(root->data < d){
        root->right = insertBST(root->right ,d);
    }
    else if(root->data > d){
        root->left = insertBST(root->left ,d);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    Node* stack[50];
    int top = -1;
    Node* curr = root;

    while(curr != NULL || top >= 0){
        while(curr != NULL){
            stack[++top] = curr;
            curr = curr->left;
        }

        Node* temp = stack[top--];
        cout<<temp->data<<" ";
        curr = temp->right;
    }

}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    Node* stack[50];
    int top = -1;
    Node* curr = root;

    stack[++top] = curr;

    while(top >= 0){
        curr = stack[top--];
        cout<<curr->data<<" ";

        if(curr->right){
            stack[++top] = curr->right;
        }
        if(curr->left){
            stack[++top] = curr->left;
        }
    }
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    Node* stack1[50];
    Node* stack2[50];

    int top1 = -1;  
    int top2 = -1;

    Node* curr = root;
    stack1[++top1] = curr;

    while(top1 >= 0){
        curr = stack1[top1--];
        stack2[++top2] = curr;

        if(curr->left){
            stack1[++top1] = curr->left;
        }
        if(curr->right){
            stack1[++top1] = curr->right;
        }
    }

    while(top2>= 0){
        cout<<stack2[top2]->data<<" ";
        top2--;
    } 
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        cout << "MENU\n";
        cout << "1. Insert into BST\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter the value to be inserted: ";
                cin >> val;
                root = insertBST(root, val);
                break;
            }
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "EXITING...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}