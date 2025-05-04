Right Rotate an Array by D Places
🧠 Pattern:
Array Rotation

Right rotation is similar to left rotation, just in opposite direction.

Again 3 approaches: Brute, Better, Optimal (Reversal method — reversed in different segments)

✅ Problem Statement:
🔍 English:
Given an array arr[] and an integer D, rotate the array to the right by D places.

🔍 Hindi:
Ek array diya gaya hai aur ek number D, tumhe array ko right side mein D jagah rotate karna hai.

Example:

Input: arr = [1, 2, 3, 4, 5, 6, 7], D = 2  
Output: [6, 7, 1, 2, 3, 4, 5]


🥉 Brute Force Approach:
✅ Idea:
Create a temporary array

Copy last D elements to the beginning of temp

Copy 0 to N-D-1 to temp after that

Copy temp back to original array

📘 English:
Split last D and first N-D, place them correctly.

📗 Hindi:
Last D elements ko temp ke start mein daalo, fir first N-D elements ko uske baad.

🕒 Time: O(n)
🧠 Space: O(n) → ❌ Not in-place


void rightRotateByDBrute(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle d > n
    vector<int> temp(n);
    
    int k = 0;
    for(int i = n - d; i < n; i++) {
        temp[k++] = arr[i];
    }
    for(int i = 0; i < n - d; i++) {
        temp[k++] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}



🥈 Better Approach – D times 1-place right rotation
✅ Idea:
Repeat 1-place right rotate D times

Use logic from previous "right rotate by 1" solution

📘 English:
Perform right rotation one by one, total D times.

📗 Hindi:
Har bar ek right shift karo, total D bar repeat karo.

🕒 Time: O(n × D) → slow for large D
🧠 Space: O(1) → ✅ In-place
✅ C++ Code:
cpp
Copy
Edit
void rightRotateByDBetter(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    
    for(int i = 0; i < d; i++) {
        int temp = arr[n - 1];
        for(int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}
🥇 Optimal Approach – Reversal Algorithm
🔁 Logic:
Reverse last D elements

Reverse first N - D elements

Reverse entire array

📘 English:
Reverse chunks: last D, first N-D, then full

📗 Hindi:
Pehle last D reverse karo, phir first N-D, aur phir full array 


arr = [1, 2, 3, 4, 5, 6, 7], D = 2

Step 1: Reverse last 2 → [1, 2, 3, 4, 5, 7, 6]  
Step 2: Reverse first 5 → [5, 4, 3, 2, 1, 7, 6]  
Step 3: Reverse whole → [6, 7, 1, 2, 3, 4, 5]



void reverse(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rightRotateByDOptimal(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle d > n

    reverse(arr, n - d, n - 1);     // Step 1
    reverse(arr, 0, n - d - 1);     // Step 2
    reverse(arr, 0, n - 1);         // Step 3
}



| Approach    | Time     | Space | In-place | Reason to Upgrade?    |
| ----------- | -------- | ----- | -------- | --------------------- |
| Brute       | O(n)     | O(n)  | ❌        | Uses temp array       |
| Better      | O(n × D) | O(1)  | ✅        | Slow for large D      |
| **Optimal** | **O(n)** | O(1)  | ✅        | Fastest + clean logic |



🎯 Summary:
Use reversal algorithm for all rotation problems when in-place and optimal is needed.

Always use d = d % n to avoid overflow or redundant rotations.

