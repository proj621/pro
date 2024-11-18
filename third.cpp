#include<iostream>
using namespace std;

// Node
struct Node
{
    int data;
    Node* next;
};
Node* head=nullptr;

//menu function
void displayMenu(){
    cout<<"MENU:"<<endl;
    cout<<"1. Display the Singly Linked List"<<endl;
    cout<<"2. Insert at the beginning"<<endl;
    cout<<"3. Insert at a specific value location"<<endl;
    cout<<"4. Insert at the end"<<endl;
    cout<<"5. Delete from the beginning"<<endl;
    cout<<"6. Delete a specific value"<<endl;
    cout<<"7. Delete from the end"<<endl;
    cout<<"8. Count the number of nodes in the list"<<endl;
    cout<<"9. Reverse the Singly Linked List"<<endl;
    cout<<"10. Exit"<<endl;
}

//create a node function
void create(Node* &head){
    int x,y;
    cout<<"Enter the value:";
    cin>>x;
    head->data=x;
    cout<<"You want to add more (1 for yes, 0 for no):";
    cin>>y;
    if(y==1){
        head->next=(Node*)malloc(sizeof(Node));
        create(head->next);
    }
    else{
        head->next=nullptr;
        return;
    }
}

//display function
void display(Node* &head){
      if(head==nullptr){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//insert at beg. function
void insertAtBeg(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    ptr->next=head;
    head=ptr;
}

//insert at end  function
void insertAtEnd(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    ptr->next=nullptr;
    if(head==nullptr){
        head=ptr;
    }else{
        Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
     }  
     temp->next=ptr; 
   
   }
 
}

//insert at a specific value
void insertAtLoc(Node* &head, int loc, int value){
Node* ptr=(Node*)malloc(sizeof(Node));
ptr->data=value;
Node* temp=head;
while(temp->data!=loc){
    temp=temp->next;
    if(temp==nullptr){
            cout<<"Location  value  not found"<<endl;
            return;
        }
}
Node* temp1=temp->next;
ptr->next=temp1;
temp->next=ptr;
}

//delete at beg. function
void deleteAtBeg(Node* &head){
    if(head==nullptr){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    free(temp);
}

//delete at end function
void deleteAtEnd(Node* &head){
    if(head==nullptr){
        cout<<"Linked List is empty"<<endl;
        return;
    }
    if(head->next==nullptr){
        free(head);
        head=nullptr;
        return;
    }
    Node* temp1;
    Node* temp=head;
    while(temp->next!=nullptr){ 
        temp1=temp;
        temp=temp->next;

    }
    temp1->next=nullptr;
    free(temp);
}

//delete a specific value
void deleteAtLoc(Node* head, int loc){  
    if(head->next==nullptr){
        free(head);
        head=nullptr;
        return;
    }
    Node* temp=head;
    Node* temp1;
    Node* temp2;
    
    while(temp->data!=loc){
        temp1=temp;
        temp=temp->next;
        if(temp==nullptr){
            cout<<"Location  value  not found"<<endl;
            return;
        }
    }
    temp2=temp->next;
    temp1->next=temp2;
    free(temp);
    }
     
 

//count the number of nodes in the list
int countNodes(Node* &head){
    if(head==nullptr){
        return 0;
    }
    int count=0;
    Node* temp=head;
    while (temp!=nullptr)
    {
       count++;
       temp=temp->next;
    }
    return count;
    
}

//reverse the list
void reverseSingleList(Node* &head){
    if(head==nullptr){
        cout<<"Linked List is empty."<<endl;
        return;
    }
    Node* current=head;
    Node* prev=nullptr;
    Node* save;
    while(current!=nullptr){
        save=current->next;
        current->next=prev;
        prev=current;
        current=save;
    }
    head=prev;
}

//main function
int main(){
    head=(Node*)malloc(sizeof(Node));
    create(head);

int choice;
do{
    displayMenu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        display(head);
        break;
        }

    case 2:{
        int value;
        cout<<"Enter the value to be insert: ";
        cin>>value;
        insertAtBeg(head,value);    
        display(head);
        break;  
    }
    case 3:{
        int val;
        int loc;
        cout<<"Enter the value to be insert: ";
        cin>>val;
        cout<<"Enter the location: ";
        cin>>loc;
        insertAtLoc(head,loc,val);  
        display(head); 
        break;  
    }
    case 4:{
        int v;
        cout<<"Enter the value to be insert: ";
        cin>>v;
        insertAtEnd(head,v); 
        display(head);
        break;
    }      
    case 5:{
        deleteAtBeg(head);  
        display(head); 
        break;
         }

    case 6:{
        int posi;
        cout<<"Enter the location: ";
        cin>>posi;
        deleteAtLoc(head,posi);   
        display(head);
        break; 
    }          
    case 7:{
        deleteAtEnd(head);   
        display(head);
        break; 
    } 
    case 8:{
        display(head);
        int nodeCount=countNodes(head);
        cout<<"Number of nodes in the singly Linked List: "<<nodeCount<<endl;
        break;  
    }   
    case 9:{
         
        cout<<"Reverse Singly Linked List:"<<endl;
        reverseSingleList(head); 
        display(head); 
        break;   
    } 
    case 10:{
       cout<<"Exiting"<<endl;  
        break; 
    }            
    default:
    {
       cout<<"Invalid choice!!"<<endl;
       break;
    }

    }

    } while(choice!=10);


    return 0;
}