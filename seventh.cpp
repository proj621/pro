#include<iostream>
using namespace std;

// Node
struct Node
{
    int data;
    Node* next;
};


//create a node function
void createList(Node* &head){
    int x,y;
    cout<<"Enter the value:";
    cin>>x;
    head->data=x;
    cout<<"You want to add more (1 for yes, 0 for no):";
    cin>>y;
    if(y==1){
        head->next=(Node*)malloc(sizeof(Node));
        createList(head->next);
    }
    else{
        head->next=nullptr;
        return;
    }
}

//display function
void display(Node* head){
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

Node* mergeSortedList(Node* &head1, Node* &head2){
    Node* temp=(Node*)malloc(sizeof(Node));
    Node* temp1=temp;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->data <= head2->data){
            temp1->next=head1;
            head1=head1->next;

        }else{
            temp1->next=head2;
            head2=head2->next;
        }
        temp1=temp1->next;
    }
    if(head1!=nullptr){//remaining values will be append of list1
        temp1->next=head1;
    }
    if(head2!=nullptr){//reaining values will be append of list2
        temp1->next=head2;
    }
    Node* mergedHead=temp->next;
    free(temp);
    return mergedHead;
}

int main(){
   Node* head1=(Node*)malloc(sizeof(Node));
   Node* head2=(Node*)malloc(sizeof(Node));
    cout<<"Enter the values of List1:-"<<endl;
    createList(head1);
    cout<<"First list is:"<<endl;
    display(head1);
    cout<<"Enter the values of List2:-"<<endl;
    createList(head2);
    cout<<"Second list is:"<<endl;
    display(head2); 

     Node* mergedHead = mergeSortedList(head1, head2);
    cout<<"Merge Sorted list is:"<<endl;
    display(mergedHead);
    return 0;

}
