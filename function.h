#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>

using namespace std;
void matrix_addition(int rows, int column, int **a, int **b, int**t){		//addition of matrixes
		int **sum; // result stored in this array
sum = new int*[rows]; // for rows
for (int i = 0;i<rows;i++){
	sum[i] = new int[column]; //for columns
}
		int **result; // result stored in this array
result = new int*[rows]; // for rows
for (int i = 0;i<rows;i++){
	result[i] = new int[column]; //for columns
}
   int c, d; // variables for loops
 
   for ( c = 0 ; c < rows ; c++ ) //addition carried out in these loops
      for ( d = 0 ; d < column ; d++ )
         sum[c][d] = a[c][d] + b[c][d];
   if(t != NULL){
   for ( c = 0 ; c < rows ; c++ ) //addition carried out in these loops
      for ( d = 0 ; d < column ; d++ )
         result[c][d] = sum[c][d] + t[c][d];
   }
   cout << "\n-----------------------------------------------------------\n";
 

   if(t == NULL){
	      cout << "Final Matrix is:-\n";
	     for ( c = 0 ; c < rows ; c++ ) //printing of the final matrix
   {
      for ( d = 0 ; d < column ; d++ )
         cout << sum[c][d] << "\t";
 
      cout << endl;
   }

   }
 if(t != NULL){
	 cout << "Sum of entered matrices:-\n";
   for ( c = 0 ; c < rows ; c++ ) //printing of the final matrix
   {
      for ( d = 0 ; d < column ; d++ )
         cout << result[c][d] << "\t";
 
      cout << endl;
   }
 }

}

void matrix_multiplication(int rows1, int rows2, int column1, int column2, int **a, int **b, int **t, int x){// matrix multiplication function
	int **c; // matrix in which the result would be stored of multiplication is initialized
c = new int*[rows1]; // for rows
for (int i = 0;i<rows1;i++){
	c[i] = new int[column2]; //for columns
}
	int i, j;

	// rows1 denotes number of rows in the first matrix (A)
	// rows2 denotes number of rows in the second matrix (B) 


	// column1 denotes number of columns in the first matrix (A)
	// column2 denotes number of columns in the second matrix (B)

	if (column1 == rows2)	// checks if multiplication is possible (column of first matrix equals rows of second matrix
	{

		for (i = 0; i<rows1; i++)	// till rows of first matrix
		{
			for (j = 0; j<column2; j++)	//till columns of second matrix
			{
				c[i][j] = 0;	//initializing the new array
				for (int k = 0; k<rows2; k++)	//till rows of second matrix
				{
					c[i][j] = c[i][j] + a[i][k] * b[k][j];	// calculates the matrix multiplication
				}
			}
		}

		cout << "\n-----------------------------------------------------------\n";

		cout << "\n\nMultiplication of Matrix A and Matrix B :\n\n";

		for (i = 0; i<rows1; i++)// prints the final multiplied matrix
		{
			for (j = 0; j<column2; j++)// matrix is of rows of first matrix and column of second matrix
			{
				cout << "\t" << c[i][j];
			}
			cout << "\n\n"; //new lines
		}
	}
	else
	{
		cout << "\n\nMultiplication is not possible"; //condition not matched for multiplication
	}
	if(x == 1){
      matrix_addition(rows1,column2, c, t, NULL);
	}
	
}

void matrix_subtraction(int rows, int column, int **a, int **b){		//subtraction of matrixes
    int i,j; //variables for loops
 
    cout << "\n-----------------------------------------------------------\n";
 
    cout<<"\n\nSubtraction of Matrix A and Matrix B :\n\n";
 
    for(i=0;i<rows;i++)// printing the final solution required
    {
        for(j=0;j<column;j++)
        {
            cout<<"\t"<<a[i][j]-b[i][j]; // subtracting values of B from A
        }
        cout<<"\n\n"; //new lines
    }
 
}
