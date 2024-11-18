#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};
Node* head=nullptr;


//menu function
void displayMenu(){
    cout<<"MENU:"<<endl;
    cout<<"1. Display the Doubly Linked List"<<endl;
    cout<<"2. Insert at the beginning"<<endl;
    cout<<"3. Insert at a specific value location"<<endl;
    cout<<"4. Insert at the end"<<endl;
    cout<<"5. Delete from the beginning"<<endl;
    cout<<"6. Delete a specific value"<<endl;
    cout<<"7. Delete from the end"<<endl;
    cout<<"8. Exit"<<endl;
}

//create a doubly node function
void createDoubly(Node* &head){
    int x,y;
    cout<<"Enter the value:";
    cin>>x;
    head->data=x;
    head->next=nullptr;
    head->prev=nullptr;
    cout<<"You want to add more (1 for yes, 0 for no):";
    cin>>y;
    if(y==1){
        Node* temp=(Node*)malloc(sizeof(Node));
        head->next=temp;
        temp->prev=head;
        createDoubly(temp);
    }
    else{
        head->next=nullptr;
        return;
    }
}

//display function for doubly linked list
void displayDoubly(Node* &head){
    if (head == nullptr) {
        cout << "Doubly Linked List is empty." << endl;
        return;
    }

    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//insert at beg. function in doubly
void insertAtBegDoubly(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    ptr->prev=nullptr;
    if(head==nullptr){
        ptr->next=nullptr;
        head=ptr;
    }else{
    ptr->next=head;
    head->prev=ptr;
    head=ptr;
    }
}

//insert at end function in doubly
void insertAtEndDoubly(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    ptr->next=nullptr;
    if(head==nullptr){
        ptr->prev=nullptr;
        head=ptr;
    }else{
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->prev=temp;
    }
}


//insert at a specified value location in doubly
void insertAtVallocDoubly(Node* &head, int valloc, int value){
    if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    Node* temp=head;
    while(temp->data!=valloc){
        
        temp=temp->next;
         if(temp==nullptr){
            cout<<"Location  Value  not Found"<<endl;
            return;
        }
    }
    Node* temp1=temp->next;
    ptr->next=temp1;
    temp1->prev=ptr;
    ptr->prev=temp;
    temp->next=ptr;
}

//delete at beg. function in doubly
void deleteAtBegDoubly(Node* &head){
     if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    if(head->next==nullptr){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
   Node* temp=head;
   head=head->next;
   head->prev=nullptr;
   free(temp);
}

//delete at end function in doubly
void deleteAtEndDoubly(Node* &head){
      if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
     if(head->next==nullptr){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
   Node* temp=head;
   Node* temp1;
   while(temp->next!=nullptr){
    temp1=temp;
    temp=temp->next;
   }
   temp1->next=nullptr;
    free(temp);
}

//delete a specific value in doubly
void deleteAtValulocDoubly(Node* &head,int valloc){
     if(head->next==nullptr){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
   Node* temp=head;
   Node* temp1;
   while(temp->data!=valloc){
    temp1=temp;
    temp=temp->next;
    if(temp==nullptr){
        cout<<"Location Value not Found"<<endl;
        return;
    }

   }
   Node* temp2=temp->next;
   temp1->next=temp2;
   temp2->prev=temp1;
   free(temp);
}

//main function
int main(){
    head=(Node*)malloc(sizeof(Node));
    createDoubly(head);
    
    
    int choice;
do{
    displayMenu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        displayDoubly(head);
        break;
        }

    case 2:{
        int value;
        cout<<"Enter the value to be insert: ";
        cin>>value;
        insertAtBegDoubly(head,value);    
        displayDoubly(head);
        break;  
    }
    case 3:{
        int val;
        int loc;
        cout<<"Enter the value to be insert: ";
        cin>>val;
        cout<<"Enter the value where we have to insert: ";
        cin>>loc;
        insertAtVallocDoubly(head,loc,val);  
        displayDoubly(head); 
        break;  
    }
    case 4:{
        int v;
        cout<<"Enter the value to be insert: ";
        cin>>v;
        insertAtEndDoubly(head,v); 
        displayDoubly(head);
        break;
    }      
    case 5:{
        deleteAtBegDoubly(head); 
        displayDoubly(head); 
        break;
         }

    case 6:{
        int posi;
        cout<<"Enter the value which you have to delete: ";
        cin>>posi;
        deleteAtValulocDoubly(head,posi);   
        displayDoubly(head);
        break; 
    }          
    case 7:{
        deleteAtEndDoubly(head);   
        displayDoubly(head);
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