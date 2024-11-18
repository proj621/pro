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
    cout<<"1. Display the Circular Doubly Linked List"<<endl;
    cout<<"2. Insert at the beginning"<<endl;
    cout<<"3. Insert at a specific value location"<<endl;
    cout<<"4. Insert at the end"<<endl;
    cout<<"5. Delete from the beginning"<<endl;
    cout<<"6. Delete a specific value"<<endl;
    cout<<"7. Delete from the end"<<endl;
    cout<<"8. Exit"<<endl;
}

//create a circular doubly node function
void createCirDoubly(Node *head1)
{
    int x, y;
    cout << "Enter the value:";
    cin >> x;
    head1->data= x;
    cout << "You want to add more(1 for yes, 0 for no):";
    cin >> y;
    if (y == 1)
    {
        head1->next = (Node *)malloc(sizeof(Node));
        head1->next->prev = head1;
        createCirDoubly(head1->next); // Recursive call for the next node
    }
    else
    {
        head1->next = head;
        head->prev = head1; 
    }
}
//display function for circular doubly linked list
void displayCirDoubly(Node* &head){
    if (!head) {
        cout <<"Circular Doubly Linked List is empty." << endl;
        return;
    }

    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

//insert at beg. function in circular doubly
void insertAtBegCirDoubly(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    if(head==nullptr){
        ptr->next=ptr;
        ptr->prev=ptr;
        head=ptr;
    }else{
     Node*temp=head->prev;
     ptr->next=head;
     ptr->prev=temp;
     temp->next=ptr;
     head->prev=ptr;
     head=ptr;
    }
}

//insert at end function in circular doubly
void insertAtEndCirDoubly(Node* &head, int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    if(head==nullptr){
        ptr->next=ptr;
        ptr->prev=ptr;
        head=ptr;
    }else{
        Node* temp=head->prev;
        ptr->next=head;
        ptr->prev=temp;
        temp->next=ptr;
        head->prev=ptr;
    }
}


//insert at a specified value location in circular doubly
void insertAtVallocCirDoubly(Node* &head, int valloc, int value){
    if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=value;
    Node* temp=head;
    while(temp->data!=valloc){
        
        temp=temp->next;
         if(temp==head){
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

//delete at beg. function in circular doubly
void deleteAtBegCirDoubly(Node* &head){
     if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    if(head->next==head){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
   Node* temp=head;
   Node* temp1=head->prev;
   head=head->next;
   head->prev=temp1;
   temp1->next=head;
   free(temp);
}

//delete at end function in circular doubly
void deleteAtEndCirDoubly(Node* &head){
      if(head==nullptr){
        cout<<"It is empty"<<endl;
        return;
    }
    if(head->next==head){//when there is only one element
      free(head);
      head=nullptr;
      return;
    }
   Node* temp=head->prev;
   Node* temp1=temp->prev;
   temp1->next=head;
   head->prev=temp1;
   free(temp);
  
}

//delete a specific value in circular doubly
void deleteAtValulocCirDoubly(Node* &head,int valloc){
     if(head==nullptr){
      cout<<"List is empty"<<endl;
      return;
    }
   Node* temp=head;
   Node* temp1;
   while(temp->data!=valloc){
    temp1=temp;
    temp=temp->next;
    if(temp==head){
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
    createCirDoubly(head);
    
  int choice;
do{
    displayMenu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        displayCirDoubly(head);
        break;
        }

    case 2:{
        int value;
        cout<<"Enter the value to be insert: ";
        cin>>value;
        insertAtBegCirDoubly(head,value);    
        displayCirDoubly(head);
        break;  
    }
    case 3:{
        int val;
        int loc;
        cout<<"Enter the value to be insert: ";
        cin>>val;
        cout<<"Enter the value where we have to insert: ";
        cin>>loc;
        insertAtVallocCirDoubly(head,loc,val);  
        displayCirDoubly(head); 
        break;  
    }
    case 4:{
        int v;
        cout<<"Enter the value to be insert: ";
        cin>>v;
        insertAtEndCirDoubly(head,v); 
        displayCirDoubly(head);
        break;
    }      
    case 5:{
        deleteAtBegCirDoubly(head); 
        displayCirDoubly(head); 
        break;
         }

    case 6:{
        int posi;
        cout<<"Enter the value which you have to delete: ";
        cin>>posi;
        deleteAtValulocCirDoubly(head,posi);   
        displayCirDoubly(head);
        break; 
    }          
    case 7:{
        deleteAtEndCirDoubly(head);   
        displayCirDoubly(head);
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