#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head=nullptr;

//menu function
void displayMenu(){
    cout<<"MENU:"<<endl;
    cout<<"1. Display the Circular Singly Linked List"<<endl;
    cout<<"2. Insert at the beginning"<<endl;
    cout<<"3. Insert at a specific value location"<<endl;
    cout<<"4. Insert at the end"<<endl;
    cout<<"5. Delete from the beginning"<<endl;
    cout<<"6. Delete a specific value"<<endl;
    cout<<"7. Delete from the end"<<endl;
    cout<<"8. Exit"<<endl;
}

//create function
void createCircular(Node* &head1){
    int x,y;
    cout<<"Enter the value:";
    cin>>x;
    head1->data=x;
    cout<<"You want to add more (1 for yes, 0 for no):";
    cin>>y;
    if(y==1){
        head1->next=(Node*)malloc(sizeof(Node));
        createCircular(head1->next);
    }
    else{
        head1->next=head;
        return;
    }
}

//display function
void display(Node* head){
     if(!head){
        cout<<"circular list is empty"<<endl;
        return;
     }
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

//insert at beg. function
void insertAtBeg(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    if(!head){
        ptr->next=ptr; //only one node(points to itself)
        head=ptr;
    }
    else{
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    ptr->next=head;
    temp->next=ptr;
    head=ptr;
    }
}

//insert at end function
void insertAtEnd(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    if(!head){
        ptr->next=ptr;//only one node(points to itself)
        head=ptr;
    }else{
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
     }  
     temp->next=ptr; 
     ptr->next=head;
    }
}

//insert at a specified value
void insertAtLoc(Node* &head, int loc, int value){
Node* ptr=(Node*)malloc(sizeof(Node));
ptr->data=value;
Node* temp=head;
while(temp->data!=loc){
    temp=temp->next;
    if(temp==head){
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
    if(!head){
        cout<<"circular list is empty"<<endl;
        return;
    }
    if(head->next==head){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* temp1=head->next;
    temp->next=temp1;
    free(head);
    head=temp1;
    }


//delete at end function
void deleteAtEnd(Node* &head){
   if(!head){
        cout<<"circular list is empty"<<endl;
        return;
    }
    if(head->next==head){ //only one node is there
        free(head);
        head=nullptr;
    }else{
   Node* temp=head;
   Node* temp1;
   while(temp->next!=head){
    temp1=temp;
    temp=temp->next;
   }
   temp1->next=head;
   free(temp);
  }

}

//delete a specified value
void deleteAtLoc(Node* head, int loc){
    if(head->next==head){ //only one node is there
        free(head);
        head=nullptr;
        return;
    }
    Node* temp1;
    Node* temp2;
    Node* temp=head;
    while(temp->data!=loc){
        temp1=temp;
        temp=temp->next;
        if(temp==head){
            cout<<"Location  value  not found"<<endl;
            return;
        }
    }
    temp2=temp->next;
    temp1->next=temp2;
    free(temp);
      
}

//main function
int main(){
    head=(Node*)malloc(sizeof(Node));
    createCircular(head);

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
       cout<<"Exiting"<<endl;  
        break; 
    }            
    default:
    {
       cout<<"Invalid choice!!";
       break;
    }

    }

    } while(choice!=8);
    return 0;
}