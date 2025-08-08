#include <iostream>
using namespace std;

const int MAX = 5;
void mul(int A[MAX][MAX], int B[MAX][MAX], int col, int row) {
    int result[MAX][MAX] = {0};  
    
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            //result[i][j] = 0;
            for(int k = 0; k < col; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            B[i][j] = result[i][j];
        }
    }
}

// Matrix Exponentiation function
void Matrix_Exponentiation(int M[MAX][MAX], int col, int row, int power) {
    int I[MAX][MAX] = {0}; 
    

    // Initialize identity matrix
   /* for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == j) I[i][j] = 1;
            else I[i][j] = 0;
        }
    } */
    
    for(int i=0;i<row;i++)
        I[i][i]=1;

   
    while(power) {
        if(power % 2 != 0) {
           
            mul(M,I,col, row);  // I = I * base
            power--;
        }
        else {
            mul(M,M,col, row);  // base = base * base
            power /= 2;
        }
    }
    
    for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			M[i][j]=I[i][j];
		}
	}  

}

int main() {
    int row, col, power;
    cout << "Enter Matrix Row Size: ";
    cin >> row;
    cout << "Enter Matrix Column Size: ";
    cin >> col;
    cout << "Enter Power: ";
    cin >> power;

    int M[MAX][MAX];  
    
    // Input the matrix elements
    cout << "Enter Matrix:\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> M[i][j];
        }
    }
    
    // Perform matrix exponentiation
    Matrix_Exponentiation(M, col, row, power);
    
    // Output the result matrix
    cout << "Resultant Matrix:\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
