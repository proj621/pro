#include<iostream>
using namespace std;
const int size= 100;
//for merge sort
void merge(int arr[], int first, int mid , int last){
    int temp[last-first+1];
    int k=0;
    int left=first;
    int right=mid+1;
    while (left<=mid && right<=last)
    {
    if(arr[left]<= arr[right]){
        temp[k++]=arr[left++];
        
    }else{
        temp[k++]=arr[right++];
        
    }
    
    }
    while(left<=mid){
        temp[k++]=arr[left++];
    
    }
    while(right<=last){
        temp[k++]=arr[right++];
        
    }
    for(int i=0; i<(last-first+1);i++){
       arr[first+i]=temp[i];
    }
    

}


void mergeSort(int arr[], int first , int last)
{
    if (first>=last){
        return ;
    }   
        int mid =(first + last) / 2;
        mergeSort(arr, first , mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
}

// for quick sort
int partition(int arr[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] >= pivot && j > low)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high){
        return;
    }
    
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    
}

// display function for sorted array
void display(int arr[], int n){
    cout<<"Sorted Array Elements: ";
   for(int i=0; i<n; i++){
   cout<<arr[i]<<" ";
   }
}

// menu list function
void menu(){
    cout<<"Chose Sorting Method:"<<endl;
    cout<<"1. MergeSort"<<endl;
    cout<<"2. QuickSort"<<endl;
    cout<<"3. Exit"<<endl;
}

// main function
int main(){
int n;
cout<<"Enter the size of arrray: ";
cin>>n;
int arr[size];
cout<<"Enter "<<n<<" elements: ";
for(int i=0; i<n; i++){
    cin>>arr[i];
}
cout<<"Entered elements: ";
for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
}
cout<<endl;
int choice;
do{
    menu();
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        mergeSort(arr,0,n-1);
        cout << "Array sorted using Merge Sort"<<endl;
        display(arr,n);
        cout<<endl;
        break;
        }

    case 2:{
        quickSort(arr,0,n-1);
        cout<<"Array sorted using Quick Sort"<<endl;
        display(arr,n);
        cout<<endl;
    
        break;  
    }
    case 3:{
        cout<<"Exiting"<<endl; 
        break;  
    }     
    default:
    {
       cout<<"Invalid choice!!"<<endl;
       break;
    }

    }

    } while(choice!=3);







    return 0;
}