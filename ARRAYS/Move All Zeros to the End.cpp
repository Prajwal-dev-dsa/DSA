Move All Zeros to the End of the Array (Maintain Order)
🧠 Pattern:
Array Manipulation

Rearrange Elements

Similar to partitioning but for zeros

Focus on keeping the relative order of non-zero elements intact

✅ Problem Statement:
🔍 English:
Given an array arr[], you need to move all zeros to the end of the array while maintaining the relative order of non-zero elements.

🔍 Hindi:
Ek array arr[] diya gaya hai. Tumhe sare zeros ko end mein move karna hai, lekin non-zero elements ka order waise ka waise rehna chahiye.


Input: arr[] = [0, 1, 0, 3, 12]
Output: arr[] = [1, 3, 12, 0, 0]


🥉 Brute Force Approach
✅ Idea:
Create a new temporary array

Copy all non-zero elements to the temp array

Fill remaining space with zeros

📘 English:
New array banalo aur non-zero elements ko copy karo. Baaki space mein zeros fill karo.

📗 Hindi:
Ek naya array banayein, usmein pehle non-zero elements daalein aur baad mein zeros daalein.

🕒 Time: O(n)
🧠 Space: O(n) → ❌ Not in-place
✅ C++ Code:



void moveZeroesBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    int k = 0;

    // Copy non-zero elements to temp
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[k++] = arr[i];
        }
    }
    
    // Fill remaining space with zeros
    for (int i = k; i < n; i++) {
        temp[i] = 0;
    }
    
    // Copy temp back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}



🥈 Better Approach – One Pass Solution (In-place)
✅ Idea:
Use two pointers: one for traversing the array and one for placing non-zero elements at the correct position.

Maintain an index lastNonZeroFoundAt for placing non-zero elements.

When a non-zero element is encountered, swap it with the element at lastNonZeroFoundAt and increment that index.

📘 English:
Use one pass with two pointers to directly swap non-zero elements to their positions.

📗 Hindi:
Ek pass mein two pointers use karke non-zero elements ko unke sahi position pe daalna.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place
✅ C++ Code:


void moveZeroesBetter(vector<int>& arr) {
    int n = arr.size();
    int lastNonZeroFoundAt = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap arr[i] with arr[lastNonZeroFoundAt]
            swap(arr[i], arr[lastNonZeroFoundAt]);
            lastNonZeroFoundAt++;
        }
    }
}


🥇 Optimal Approach – No Extra Space, One Pass with Conditional Logic
Same as the better approach, but we optimize further with early exit conditions.

✅ Idea:
We don’t need to swap every time — just move the non-zero element to the next available position as soon as we encounter it.

📘 English:
We can further avoid unnecessary swaps by directly placing non-zero elements without constantly swapping back and forth.

📗 Hindi:
Jab bhi non-zero element mile, turant usse sahi jagah pe daal do bina baar-baar swap kare.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place
✅ C++ Code:

void moveZeroesOptimal(vector<int>& arr) {
    int n = arr.size();
    int lastNonZeroFoundAt = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Directly put arr[i] at the last non-zero position
            if (i != lastNonZeroFoundAt) {
                arr[lastNonZeroFoundAt] = arr[i];
                arr[i] = 0;
            }
            lastNonZeroFoundAt++;
        }
    }
}



| Approach    | Time     | Space | In-place | Why Upgrade?                                |
| ----------- | -------- | ----- | -------- | ------------------------------------------- |
| Brute       | O(n)     | O(n)  | ❌        | Extra space used                            |
| Better      | O(n)     | O(1)  | ✅        | More efficient with 2-pointer technique     |
| **Optimal** | **O(n)** | O(1)  | ✅        | Avoid unnecessary swaps by direct placement |



🎯 Summary:
Use the better approach for most cases where you're allowed in-place modifications.

Optimal approach is for scenarios where minimizing operations further is necessary.

