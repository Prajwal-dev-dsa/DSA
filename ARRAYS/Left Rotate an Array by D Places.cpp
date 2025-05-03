Left Rotate an Array by D Places
🧠 Pattern:
Array Rotation

Can be solved in:

Brute → with temp array

Better → shift one by one

Optimal → Reversal Algorithm

In-place rotation ka sahi masterclass question hai!

✅ Problem Statement:
🔍 English:
You are given an array arr[] of size n, and an integer D. Rotate the array to the left by D places.

🔍 Hindi:
Ek array diya hai size n ka aur ek number D. Tumhe array ko left side mein D jagah rotate karna hai.

Example:

Input:  arr[] = [1, 2, 3, 4, 5, 6, 7], D = 2  
Output: [3, 4, 5, 6, 7, 1, 2]
🥉 Brute Force Approach
✅ Idea:
Create a new temp array of size n

Copy elements from index D to N-1 to the front of temp

Then copy 0 to D-1 at the end of temp

Copy temp[] back into arr[]

📘 English:
Use a new array to store rotated version, then copy back.

📗 Hindi:
Ek naye array mein D ke baad wale element sabse pehle daal do. Fir 0 to D-1 wale baad mein daal do. Last mein original array ko overwrite kar do.

🕒 Time: O(n)
🧠 Space: O(n) → ❌ Not in-place
✅ C++ Code:


void leftRotateByDBrute(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> temp(n);
    
    int k = 0;
    for(int i = d; i < n; i++) {
        temp[k++] = arr[i];
    }
    for(int i = 0; i < d; i++) {
        temp[k++] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}




🥈 Better Approach – One by One Rotation (D times)
✅ Idea:
Rotate the array by one position D times

For each rotation, use the code from "Left Rotate by One"

📘 English:
Do 1-place rotation D times.

📗 Hindi:
D baar array ko 1 position left rotate karo.

⛔ Time: O(n × D) → Very slow for large D
✅ Space: O(1) → In-place



void leftRotateByDBetter(vector<int>& arr, int d) {
    int n = arr.size();
    for(int i = 0; i < d; i++) {
        int temp = arr[0];
        for(int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}


🥇 Optimal Approach – Reversal Algorithm
This is the gold-standard for interviews

🔁 Logic:
Reverse first D elements

Reverse last n - D elements

Reverse the entire array

📘 English:
Split array into two parts → reverse individually → reverse whole

📗 Hindi:
Array ke D aur n-D parts alag alag reverse karo → fir pura array reverse kar do

🔢 Example:
arr = [1,2,3,4,5,6,7], D=2

Step 1: Reverse first D: [2,1,3,4,5,6,7]
Step 2: Reverse rest: [2,1,7,6,5,4,3]
Step 3: Reverse all: [3,4,5,6,7,1,2] ✅



void reverse(vector<int>& arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotateByDOptimal(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // for cases where d > n

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}



| Approach    | Time     | Space | In-place | Why Upgrade?                            |
| ----------- | -------- | ----- | -------- | --------------------------------------- |
| Brute       | O(n)     | O(n)  | ❌        | Temp array used                         |
| Better      | O(n×D)   | O(1)  | ✅        | Slow for large D                        |
| **Optimal** | **O(n)** | O(1)  | ✅        | Fast + clean logic (Reversal Algorithm) |




🎯 Summary:
If asked to rotate in-place, go with Reversal Method.

If extra space is allowed, brute works.

Better approach is okay but inefficient for large D.