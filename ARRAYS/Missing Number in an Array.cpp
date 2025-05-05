Find the Missing Number in an Array
🧠 Pattern:
Mathematical Approach

Sum Formula

XOR Approach

The problem tests your ability to detect missing elements efficiently.

✅ Problem Statement:
🔍 English:
Given an array arr[] of n-1 elements in the range of 1 to n, find the missing element in the array. The array contains distinct numbers and is missing exactly one element.

🔍 Hindi:
Ek array arr[] diya gaya hai jisme n-1 elements hain aur wo elements 1 se n ke range mein hain. Tumhe wo missing element find karna hai jo array mein nahi hai. Array mein sab elements distinct hain.

Example:

Input: arr[] = [1, 2, 4, 5, 6]
Output: Missing element = 3


🥉 Brute Force Approach
✅ Idea:
Create an array of size n where every element is initially set to 0.

Traverse the given array and mark the corresponding indices as present.

The index which is not marked will represent the missing element.

📘 English:
Create an auxiliary array and mark the present elements.

📗 Hindi:
Ek extra array banao, aur present elements ko mark kar do. Jo index mark nahi hoga, wo missing element hoga.

🕒 Time: O(n)
🧠 Space: O(n) → ❌ Extra space used
✅ C++ Code:

int findMissingElementBrute(vector<int>& arr, int n) {
    vector<int> present(n + 1, 0); // Helper array to track presence of elements
    
    // Mark elements present in the array
    for (int i = 0; i < arr.size(); i++) {
        present[arr[i]] = 1;
    }
    
    // Find the missing element
    for (int i = 1; i <= n; i++) {
        if (present[i] == 0) {
            return i;
        }
    }
    return -1; // No missing element (although not expected)
}


🥈 Better Approach – Using Sum Formula
✅ Idea:
Calculate the sum of the first n natural numbers:
Sum = n * (n + 1) / 2

Subtract the sum of elements in the given array from this sum.

The result will be the missing number.

📘 English:
Use the formula for the sum of the first n natural numbers and subtract the sum of elements in the array.

📗 Hindi:
Pehle n natural numbers ka sum formula laga lo aur fir array ka sum subtract kar do.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place (No extra space used)
✅ C++ Code:


int findMissingElementBetter(vector<int>& arr, int n) {
    int totalSum = n * (n + 1) / 2; // Sum of first n numbers
    int arraySum = 0;
    
    // Calculate sum of elements in the array
    for (int i = 0; i < arr.size(); i++) {
        arraySum += arr[i];
    }
    
    return totalSum - arraySum; // The missing element
}


🥇 Optimal Approach – Using XOR
✅ Idea:
XOR all the numbers from 1 to n.

XOR all the elements in the given array.

XOR of both results will give the missing element, because XOR of identical numbers cancels out.

📘 English:
Use XOR properties to cancel out the elements and find the missing number.

📗 Hindi:
XOR ka use karo, jo elements match karenge wo cancel ho jayenge aur missing element mil jayega.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place (No extra space used)
✅ C++ Code:


int findMissingElementOptimal(vector<int>& arr, int n) {
    int xorTotal = 0;
    int xorArr = 0;
    
    // XOR all numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorTotal ^= i;
    }
    
    // XOR all elements in the array
    for (int i = 0; i < arr.size(); i++) {
        xorArr ^= arr[i];
    }
    
    // The result will be the missing element
    return xorTotal ^ xorArr;
}


| Approach    | Time     | Space | In-place | Why Upgrade?                                                                  |
| ----------- | -------- | ----- | -------- | ----------------------------------------------------------------------------- |
| Brute       | O(n)     | O(n)  | ❌        | Uses extra space                                                              |
| Better      | O(n)     | O(1)  | ✅        | Efficient and easy to understand                                              |
| **Optimal** | **O(n)** | O(1)  | ✅        | XOR eliminates the need for extra space and gives the answer in a single pass |



🎯 Summary:
Sum Formula is a simple and effective approach, very intuitive.

XOR approach is the most optimal when you want to avoid extra space completely, and it is especially efficient when you're dealing with large data.

