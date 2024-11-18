#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_SIZE 100

// Maximum element function
int max_Ele(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

// Swap function
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Max-heapify function
void max_heapify(int arr[], int n, int i){
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

// Count Sort function
void countSort(int arr[], int n){
    int max = max_Ele(arr, n);
    int count[max + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] = count[i] + count[i - 1];
    }

    int b[n];
    for (int i = n - 1; i >= 0; i--) {
        int j = arr[i];
        count[j]--;
        b[count[j]] = j;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = b[i];
    }
}

// Radix Sort helper function to sort by individual digits
void countSortByDigit(int arr[], int n, int pos){
    int b[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int j = (arr[i] / pos) % 10;
        b[--count[j]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = b[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n){
    int max = max_Ele(arr, n);

    for (int pos = 1; max / pos > 0; pos *= 10) {
        countSortByDigit(arr, n, pos);
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n)
{
    float buckets[n][n];  

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buckets[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;  
        int j = 0;
        while (buckets[index][j] != -1) {
            j++;
        }
        buckets[index][j] = arr[i];
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (buckets[i][j] != -1) {
            j++;
        }
        sort(buckets[i], buckets[i] + j);  

        for (int m = 0; m < j; m++) {
            arr[k++] = buckets[i][m];
        }
    }
}

// Display function for sorted array
void display(int arr[], int n){
    cout << "Sorted Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Menu list function
void menu() {
    cout << "Choose Sorting Method:" << endl;
    cout << "1. HeapSort" << endl;
    cout << "2. CountSort" << endl;
    cout << "3. RadixSort" << endl;
    cout << "4. BucketSort" << endl;
    cout << "5. Exit" << endl;
}

// Main function
int main(){
    int choice;
    do {
        menu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the size of array: ";
                cin >> n; 
    
                int arr[MAX_SIZE];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) {
                  cin >> arr[i];
                   }
                 cout << endl;
                heapSort(arr, n);
                cout << "Array sorted using HeapSort" << endl;
                display(arr, n);
                break;
            }
            case 2: {
                 int n;
                cout << "Enter the size of array: ";
                cin >> n; 
    
                int arr[MAX_SIZE];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) {
                  cin >> arr[i];
                   }
                 cout << endl;
                countSort(arr, n);
                cout << "Array sorted using CountSort" << endl;
                display(arr, n);
                break;
            }
            case 3: {
                int n;
                cout << "Enter the size of array: ";
                cin >> n; 
    
                int arr[MAX_SIZE];
                cout << "Enter " << n << " elements: ";
                for (int i = 0; i < n; i++) {
                  cin >> arr[i];
                   }
                 cout << endl;
                radixSort(arr, n);
                cout << "Array sorted using RadixSort" << endl;
                display(arr, n);
                break;
            }
            case 4: {
                int n;
                cout << "Enter the size of array: ";
                cin >> n; 
                float floatArr[n];
                cout << "Enter " << n << " elements between 0 and 1: ";
                for (int i = 0; i < n; i++) {
                    cin >> floatArr[i];
                }
                bucketSort(floatArr, n);
                cout << "Array sorted using BucketSort" << endl;
                cout << "Sorted Array Elements: ";
                for (int i = 0; i < n; i++) {
                    cout << floatArr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 5: {
                cout << "Exiting" << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
       
    } while (choice != 5);

    return 0;
}
