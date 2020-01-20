// C++ program to find the inverse of Matrix. 

#include <iostream> 
#include <vector> 
using namespace std; 

// Function to Print matrix. 
void PrintMatrix(float ar[][20], int n, int m) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) { 
			cout << ar[i][j] << " "; 
		} 
		printf("\n"); 
	} 
	return; 
} 

// Function to Print inverse matrix 
void PrintInverse(float ar[][20], int n, int m) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = n; j < m; j++) { 
			printf("%.3f ", ar[i][j]); 
		} 
		printf("\n"); 
	} 
	return; 
} 

// Function to perform the inverse operation on the matrix. 
void InverseOfMatrix(float matrix[][20], int order) 
{ 
	// Matrix Declaration. 

	float temp; 

	// PrintMatrix function to print the element 
	// of the matrix. 
	printf("=== Matrix ===\n"); 
	PrintMatrix(matrix, order, order); 

	// Create the augmented matrix 
	// Add the identity matrix 
	// of order at the end of original matrix. 
	for (int i = 0; i < order; i++) { 

		for (int j = 0; j < 2 * order; j++) { 

			// Add '1' at the diagonal places of 
			// the matrix to create a identity matirx 
			if (j == (i + order)) 
				matrix[i][j] = 1; 
		} 
	} 

	// Interchange the row of matrix, 
	// interchanging of row will start from the last row 
	for (int i = order - 1; i > 0; i--) { 

		// Swapping each and every element of the two rows 
		// if (matrix[i - 1][0] < matrix[i][0]) 
		// for (int j = 0; j < 2 * order; j++) { 
		// 
		//	 // Swapping of the row, if above 
		//	 // condition satisfied. 
		// temp = matrix[i][j]; 
		// matrix[i][j] = matrix[i - 1][j]; 
		// matrix[i - 1][j] = temp; 
		// } 

		// Directly swapping the rows using pointers saves time 

		if (matrix[i - 1][0] < matrix[i][0]) { 
			float* temp = matrix[i]; 
			matrix[i] = matrix[i - 1]; 
			matrix[i - 1] = temp; 
		} 
	} 

	// Print matrix after interchange operations. 
	printf("\n=== Augmented Matrix ===\n"); 
	PrintMatrix(matrix, order, order * 2); 

	// Replace a row by sum of itself and a 
	// constant multiple of another row of the matrix 
	for (int i = 0; i < order; i++) { 

		for (int j = 0; j < order; j++) { 

			if (j != i) { 

				temp = matrix[j][i] / matrix[i][i]; 
				for (int k = 0; k < 2 * order; k++) { 

					matrix[j][k] -= matrix[i][k] * temp; 
				} 
			} 
		} 
	} 

	// Multiply each row by a nonzero integer. 
	// Divide row element by the diagonal element 
	for (int i = 0; i < order; i++) { 

		temp = matrix[i][i]; 
		for (int j = 0; j < 2 * order; j++) { 

			matrix[i][j] = matrix[i][j] / temp; 
		} 
	} 

	// print the resultant Inverse matrix. 
	printf("\n=== Inverse Matrix ===\n"); 
	PrintInverse(matrix, order, 2 * order); 

	return; 
} 

// Driver code 
int main() 
{ 
	int order; 

	// Order of the matrix 
	// The matrix must be a square a matrix 
	order = 3; 
	float matrix[20][20] = { { 5, 7, 9 }, 
							{ 4, 3, 8 }, 
							{ 7, 5, 6 }, 
							{ 0 } }; 

	// Get the inverse of matrix 
	InverseOfMatrix(matrix, order); 

	return 0; 
} 
