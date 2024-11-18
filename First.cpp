#include<iostream> // header file 
using namespace std; // standard library
const int MAX_SIZE=100;
// display the menu
void displayMenu(){
    cout<<"MENU:"<<endl;
    cout<<"1. Traverse the array"<<endl;
    cout<<"2. Insert at the beginning"<<endl;
    cout<<"3. Insert at a specific location"<<endl;
    cout<<"4. Insert at the end"<<endl;
    cout<<"5. Delete from the beginning"<<endl;
    cout<<"6. Delete from a specific location"<<endl;
    cout<<"7. Delete from the end"<<endl;
    cout<<"8. Linear search"<<endl;
    cout<<"9. Binary search using recursion"<<endl;
    cout<<"10. Insertion sort"<<endl;
    cout<<"11. Exit"<<endl;

}

//Traverse the array
void traverse(int arr[], int& n){
    cout<<"Array:";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Insert at the beginning
void insertAtBeg(int arr[], int& n, int value){
    if(n>=1){
        
    for(int i=n; i>0; i--){
        arr[i]=arr[i-1];
    }
}
    arr[0]=value;
    n++;

}

//Insert at a specific location
void insertAtPos(int arr[],int& n, int value, int pos){
    
    if(pos<0 || pos>n){
        cout<<"Invalid position!!"<<endl;
        return;
    }
     if(n>= MAX_SIZE){
        cout<<"Array is full!!!"<<endl;
        return;
    }

    for(int i=n; i>pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    n++;
}

//Insert at the end
void insertAtEnd(int arr[], int& n, int value){
    if(n>=MAX_SIZE){
        cout<<"Array is full!!"<<endl;
        return;
    }
    arr[n]=value;
    n++;
}

//Delete from the beginning
void deleteAtBeg(int arr[], int& n){
    if(n==0){
        cout<<"Array is empty!!"<<endl;
        return;
    }
    for(int i=0; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
}

// Delete from a specific location
void deleteAtPos(int arr[], int& n, int pos){
    if(pos<0 || pos>n){
        cout<<"Invalid position!!"<<endl;
        return;
    }
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

}

//Delete from the end
void deleteAtEnd(int& n){
    if(n==0){
        cout<<"Array is Empty!!"<<endl;
        return;
    }
    n--;
}

//Linear search
int linearSearch(int arr[], int& n, int key){

    for(int i=0; i<n; i++){
        if(arr[i]==key){
            cout<<"key value found at "<<i<<endl;
            return i;
            
        }
    }
    cout<<"key value not found"<<endl;
    return -1;
    
}

//Binary search using recursion
int binarySearch(int arr[], int low, int high, int key){
    if(low>high){
        cout<<"key value not found"<<endl;
        return -1;
    
    }
    int mid=low+(high-low)/2;
    if(arr[mid]==key){
         cout<<"key value found at "<<mid<<endl;
          return mid;
        
    }
    else if (arr[mid]<key){
        return binarySearch(arr,mid+1,high,key);
    }
    else {
        return binarySearch(arr,low,mid-1,key);
    }
}

//Insertion sort
void insertionSort(int arr[],int& n){
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key; 
    }

}

//main function
int main(){
int n;
cout<<"Enter the size of the array: ";
cin>>n; // initial size of array
int arr[MAX_SIZE]; 

cout<<"Enter "<<n<<" elements: ";

for(int i=0;i<n;i++){
    cin>>arr[i]; //inputing elements from user
}

int choice;
do{
    displayMenu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        traverse(arr,n);
        break;
    case 2:
        int value;
        cout<<"Enter the value to be insert: ";
        cin>>value;
        insertAtBeg(arr,n,value);    
        traverse(arr,n);
        break;  
    case 3:
        int val;
        int pos;
        cout<<"Enter the value to be insert: ";
        cin>>val;
        cout<<"Enter the position: ";
        cin>>pos;
        insertAtPos(arr,n,val,pos);  
        traverse(arr,n);  
        break;  
    case 4:
        int v;
        cout<<"Enter the value to be insert: ";
        cin>>v;
        insertAtEnd(arr,n,v); 
        traverse(arr,n);   
        break;      
    case 5:
        deleteAtBeg(arr,n);  
        traverse(arr,n);  
        break; 
    case 6:
        int posi;
        cout<<"Enter the position: ";
        cin>>posi;
        deleteAtPos(arr,n,posi);   
        traverse(arr,n); 
        break;           
    case 7:
        deleteAtEnd(n);   
        traverse(arr,n); 
        break;  
    case 8:
        int key;
        cout<<"Enter the value of  key: ";
        cin>>key;
        traverse(arr,n);
        linearSearch(arr,n,key);    
        break;     
    case 9:
        insertionSort(arr,n);
        int ke;
        cout<<"Enter the value of key: ";
        cin>>ke;
        traverse(arr,n);
        binarySearch(arr,0,n-1,ke);    
        break;    
    case 10:
        insertionSort(arr,n);  
        traverse(arr,n);  
        break;   
    case 11:
       cout<<"Exiting"<<endl;  
        break;             
    default:
       cout<<"Invalid choice!!";
       break;
    }
    }while(choice!=11);



    return 0;

} 