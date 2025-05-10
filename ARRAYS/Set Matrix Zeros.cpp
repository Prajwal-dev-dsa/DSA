📌 Set Matrix Zeros
Problem:
You are given an m x n matrix, and you need to set the entire row and column to 0 if an element in the matrix is 0. Do this in place without using extra space for another matrix.

Example:

Input:


matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
]
Output:


matrix = [
    [1, 0, 1],
    [0, 0, 0],
    [1, 0, 1]
]


🔍 Pattern:
This is a matrix manipulation problem. The challenge is to handle the modification of rows and columns without using extra space.

Brute Force Approach:
Idea: The brute force approach is simple: We can iterate through the matrix to find all the positions of 0s and then modify the corresponding rows and columns. However, we would need extra space to keep track of which rows and columns need to be set to 0.

Time Complexity: O(m * n) (two nested loops to traverse the matrix)

Space Complexity: O(m + n) (space for storing row and column indices)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

void setZeroesBruteForce(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> rowZero(m, 0), colZero(n, 0);
    
    // Store which rows and columns should be zeroed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }
    
    // Set the elements to 0 based on row and column indices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rowZero[i] == 1 || colZero[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    setZeroesBruteForce(matrix);
    
    // Print modified matrix
    for (auto row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}


Explanation:

We first create two arrays rowZero and colZero to track which rows and columns need to be set to zero.

After identifying the rows and columns that contain 0s, we iterate through the matrix again and set the corresponding rows and columns to zero.

Why brute force?:

This solution requires extra space (O(m + n)) for tracking rows and columns, which is inefficient.

Hindi:
Hum pehle identify karte hain ki kis row aur column mein zero hai, phir un rows aur columns ko zero kar dete hain. Iske liye humne extra space use kiya hai jo brute force approach ka part hai.

Better Approach:
Idea: Instead of using extra space for row and column indices, we can use the first row and the first column of the matrix itself to store the information. This reduces the space complexity to O(1). We use the first row and column to mark which rows and columns need to be zeroed, and then process the rest of the matrix accordingly.

Time Complexity: O(m * n) (two nested loops to traverse the matrix)

Space Complexity: O(1) (no extra space for rows and columns)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

void setZeroesBetter(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;
    
    // Check if the first row has any zero
    for (int i = 0; i < n; i++) {
        if (matrix[0][i] == 0) {
            firstRowZero = true;
            break;
        }
    }
    
    // Check if the first column has any zero
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    
    // Use first row and first column to mark zeros
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Set matrix cells to zero based on marks in first row and column
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set first row and first column to zero if needed
    if (firstRowZero) {
        for (int i = 0; i < n; i++) {
            matrix[0][i] = 0;
        }
    }
    
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    setZeroesBetter(matrix);
    
    // Print modified matrix
    for (auto row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}


Explanation:

First, we check if the first row or first column contains any 0s, because we will be using these to mark the rows and columns that need to be set to 0.

Then, we mark the rows and columns in the first row and column.

After that, we use the marks to set the rest of the matrix elements to 0.

Finally, we set the first row and first column to 0 if needed.

Why better?:

This approach eliminates the need for extra space and modifies the matrix in place, making it much more efficient.

Hindi:
Hum matrix ke pehle row aur column ko use karte hain zero mark karne ke liye. Isse hum extra space ki zarurat nahi padti aur matrix ko in-place modify karte hain.

Optimal Approach:
Idea: The better approach is already optimal. It modifies the matrix in place without using extra space (O(1) space complexity) and runs in linear time (O(m * n)).

Hindi:
Yeh approach already optimal hai, kyunki hum matrix ko in-place modify karte hain aur koi extra space nahi use karte.

Summary:
Brute Force:

Time: O(m * n) (two nested loops)

Space: O(m + n) (for row and column tracking arrays)

Explanation: Use extra space to track rows and columns that need to be zeroed.

Better (Optimal):

Time: O(m * n) (two nested loops)

Space: O(1) (no extra space)

Explanation: Use the first row and column to mark rows and columns to be zeroed, and then modify the matrix in place.

Interview Style Explanation:
Pattern: "This problem follows the matrix manipulation pattern, where we need to modify elements in place based on certain conditions."

Transition from Brute to Better: "The brute force approach uses extra space to track rows and columns, which is inefficient. The better approach optimizes this by using the first row and column of the matrix itself to mark zeros, reducing space complexity."