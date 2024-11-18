#include<iostream>
using namespace std;
//display the sparse matrix
void display_matrix(int matrix[][10],int rows, int cols){
    for(int i=0; i<rows; i++){
        cout<<"[";
        for(int j=0; j<cols;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<"]"<<endl;
    }
}

// display th sparse array
void display_sparse(int matrix[][3], int rows, int cols){
    for(int i=0; i<rows; i++){
        cout<<"[";
        for(int j=0; j<cols;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<"]"<<endl;
    }

}

//check is this sparse array or not
int isSparseMatrix(int matrix[][10], int rows, int cols){
    int nonZerocount=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols;j++){
            if(matrix[i][j]!=0){
                nonZerocount++;
            }
        }
    }    
    int size=rows*cols;
    cout<<"The non zero elements in the sparse matrix are "<<nonZerocount<<endl;
    if(nonZerocount<size/4){
        cout<<"It is a sparse matrix"<<endl;
        return nonZerocount;

    }
    else {
        cout<<"It is not a sparse matrix"<<endl;
        return -1;
    }
}

 
//convert to sparse array
void sparse_array(int matrix[][10],int sparse[][3], int rows, int cols,int nonZerocount){
   sparse[0][0]=rows;
   sparse[0][1]=cols;
   sparse[0][2]=nonZerocount;
   int x=1;
   for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        if(matrix[i][j]!=0){
            sparse[x][0]=i;
            sparse[x][1]=j;
            sparse[x][2]=matrix[i][j];
            x++;
        }
     }
   }
}

int main(){
    int rows;
    int cols;
    cout<<"Enter the number of rows:";
    cin>>rows;
    cout<<"Enter the number of columns:";
    cin>>cols;
    int matrix[10][10];//declare the size of sparse matrix
    int sparse[15][3];//declare the size of sparse array
    cout<<"Enter the matrix elements:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"matrix["<<i<<"]["<<j<<"]:";
            cin>>matrix[i][j];//user input values
        } 
    }
    cout<<"Display the array matix:"<<endl;
    display_matrix(matrix,rows,cols);
    int nonZerocount= isSparseMatrix(matrix,rows,cols);

    
    if(nonZerocount!=-1){
    sparse_array(matrix,sparse,rows,cols,nonZerocount);
    cout<<"Now display the sparse array:"<<endl;
    display_sparse(sparse,nonZerocount+1,3);
    }

    return 0;
}