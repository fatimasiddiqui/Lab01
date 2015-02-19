//Libraries
#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>
#include"function.h" // the header file which includes the functions

using namespace std; //for cout and cin and endl etc


int main(){
	ifstream matrix("sample.txt"); //create a stream to file
	if (matrix.is_open()){ //opening the file

	}
	else{
		cout << "error opening file!"; //error if not opening the file
	}
	//declaration and initialization of variables
	int number;
	string linebuffer;
	int rows1 = 0;
	int column1 = 0;
	
	if (matrix && getline(matrix , linebuffer)!= 0){ // getting the number of rows of first matrix from file
		rows1 = stoi(linebuffer);
		//cout<<rows1;
	}
if (matrix && getline(matrix , linebuffer)!= 0){ //getting the number of columns of first matrix
		column1 = stoi(linebuffer);
		//cout<<column1;
	}
int **matrix1; //declaration of a 2D array
matrix1 = new int*[rows1]; //rows of the array
for (int i = 0;i<rows1;i++){
	matrix1[i] = new int[column1];  //columns of the array
}
for(int i = 0; i<rows1; i++){ //getting the whole matrix, storing it in the 2D array
	int column =  0;
	if(matrix && getline(matrix , linebuffer) != 0){ //each line from file
			for(unsigned int j = 0; j<linebuffer.length(); j++) { //parsing the string (line) taken from file
			char c = linebuffer[j]; //this is your character
			if(c != ' '){ //excluding spaces between matrix numbers
			matrix1[i][column] = c - '0';   //converting characters in string to numbers
			column++;      // to manage columns in the array
			if(column > column1){ //satisfying the number of columns required
				break;
			}
			}
}
	}
}
//initializing rows and columns for the second matrix
int rows2 = 0;
int column2 = 0;
if (matrix && getline(matrix , linebuffer)!= 0){		//get each line from file
		rows2 = stoi(linebuffer);              // getting the number of rows for the second matrix
	}
if (matrix && getline(matrix , linebuffer)!= 0){ //each line from file
		column2 = stoi(linebuffer);             // the number of columns in the second matrix
	}
//declaration of the second matrix
int **matrix2;
matrix2 = new int*[rows2]; //rows 
for (int i = 0;i<rows2;i++){
	matrix2[i] = new int[column2]; //columns
}
for(int i = 0; i<rows2; i++){ //Now getting the whole second matrix in the array
	int column =  0;
	if(matrix && getline(matrix , linebuffer) != 0){ //read each line
			for(unsigned int j = 0; j<linebuffer.length(); j++) {  //till string length to get each character
			char c = linebuffer[j]; //this is your character
			if(c != ' '){    //excluding spaces between matrix numbers
			matrix2[i][column] = c - '0'; //converting characters to numbers
			column++;     //to manage columns of array
			if(column > column2){  //satisfying the number of columns specified 
				break;
			}
			}
}
	}
}
int rows3 = 0;
int column3 = 0;
if (matrix && getline(matrix , linebuffer)!= 0){		//get each line from file
		rows3 = stoi(linebuffer);              // getting the number of rows for the second matrix
	}
if (matrix && getline(matrix , linebuffer)!= 0){ //each line from file
		column3 = stoi(linebuffer);             // the number of columns in the second matrix
	}
int **matrix3;
matrix3 = new int*[rows3]; //rows 
for (int i = 0;i<rows3;i++){
	matrix3[i] = new int[column3]; //columns
}
for(int i = 0; i<rows3; i++){ //Now getting the whole third matrix in the array
	int column =  0;
	if(matrix && getline(matrix , linebuffer) != 0){ //read each line
			for(unsigned int j = 0; j<linebuffer.length(); j++) {  //till string length to get each character
			char c = linebuffer[j]; //this is your character
			if(c != ' '){    //excluding spaces between matrix numbers
			matrix3[i][column] = c - '0'; //converting characters to numbers
			column++;     //to manage columns of array
			if(column > column3){  //satisfying the number of columns specified 
				break;
			}
			}
}
	}
}



                 //printing all matrixes naming the first one "A" and the second one "B" and the third one "C"
 cout<<"\n\nMatrix A :\n\n";
 
    for(int i=0;i<rows1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            cout<<"\t"<<matrix1[i][j];
        }
        cout<<"\n\n";
    }
	 cout<<"\n\nMatrix B :\n\n";
 
    for(int i=0;i<rows2;i++)
    {
        for(int j=0;j<column2;j++)
        {
            cout<<"\t"<<matrix2[i][j];
        }
        cout<<"\n\n";  //new lines
    }
	 cout<<"\n\nMatrix C :\n\n";
 
    for(int i=0;i<rows3;i++)
    {
        for(int j=0;j<column3;j++)
        {
            cout<<"\t"<<matrix3[i][j];
        }
        cout<<"\n\n";	//new lines
    }

int option; //option for switch
while(1){  //until the user quits
cout<<"\n\nMatrix Operation Options :)";			//some console displaying
cout<<"\n\n";
cout<<"Matrix are taken from the file :)";
cout<<"\n\n";
cout<<"For Addition of 3 matrices Press 1.\n\n For Subtraction of two matrices Press 2.\n\n For Multiplication of 2 matrices Press 3.\n\n For Multiplication and Addition Press 4.\n\n To Exit Press 5.\n\n"; //asks user for the operation perform on matrices
cout<<"\n\n";
cin>>option; //takes the user input

switch(option){ //switch to perform the operations on matrices
case 1: //case for addition
	if(rows1 != rows2 || rows1!=rows3 || rows2 != rows3 || column1 != column2 || column1 !=column3 || column2 != column3){ //rows and columns for both matrices must match
		cout<<"Rows or Columns are not same :)";
		cout<<"\n\n";  //new lines
		break;          //break to not continue in the same 
	}
	else{
		matrix_addition(rows1,column1, matrix1, matrix2,matrix3); //calling multiplication function
	}
	break;  //not continue to case 2
case 2:  //case for subtraction
	if(rows1 != rows2 || column1 != column2){		//rows and columns for both matrices must match
		cout<<"Rows or Columns are not same :)";
		cout<<"\n\n";				//new lines
		break;					// to not continue to case 3
	}
	else{
		matrix_subtraction(rows1,column1, matrix1, matrix2);		//calling the subtraction matrices function
	}
	break;				//to not contunue to case 3
case 3:				//case for multiplication
	if(rows2 != column1){			// numbers of columns of first matrix must equal the number of rows in the second matrix for multiplication
		cout<<"Column of first matrix does not match row of second matrix :)";		//some condole displaying
		cout<<"\n\n";
		cout<<"Hence Multiplication is not possible :)";
		cout<<"\n\n";
		break;		
	}
	else{
		matrix_multiplication(rows1,rows2,column1,column2, matrix1, matrix2,matrix3, 0);		//calling the multiplication function for matrices
	}
	break;
case 4:// case for multiplication and addition
	if(rows2 != column1){ //multiplication condition check
		cout<<"Column of first matrix does not match row of second matrix :)";
	}
	else{
		if (rows1 != rows3 || column2 != column3){ //addition check
			cout<<"Addition is not possible because the multiplied matrix rows or columns is not equal to the third matrix :)";
			break; // out of the if and for
		}
		else{
             matrix_multiplication(rows1,rows2,column1,column2, matrix1, matrix2,matrix3, 1); //calling the matrix multiplication function
		}
	}
	break;

}
if(option == 5){  //to exit the while loop
	break;
}
}
delete[] matrix1;  //deleting matrix1
delete[] matrix2;	//deleting matrix2
delete[] matrix3; //deleting matrix3
	return 0;
}