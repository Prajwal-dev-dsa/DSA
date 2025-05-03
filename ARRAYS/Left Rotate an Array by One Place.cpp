Left Rotate an Array by One Place
🧠 Pattern:
Array Manipulation

No need of extra space (if asked in-place)

Very basic yet fundamental for rotations / circular shifts

💡 Forms base for rotating by D places

✅ Interview Explanation:
🔍 Problem Statement (Short):
Ek array diya gaya hai, humein use left rotate karna hai 1 position se.
Example:
Input: [1, 2, 3, 4, 5] → Output: [2, 3, 4, 5, 1]

🔎 Real-life Analogy:
Soch ek queue mein log khade hain. First person ko hattake end mein bhejna hai — ek circular left shift.

🔴 Brute Force Approach:
✅ Idea:
Create a temporary array of size n

Copy elements from index 1 to n-1 to temp[0 to n-2]

Put arr[0] in temp[n-1]

⛔ Problem:
Extra space used: O(n)

Not valid if asked in-place

✅ Optimal (In-place rotation)
✅ English:
Store arr[0] in a temporary variable.

Left shift all elements one by one:

arr[i] = arr[i+1]

Put the stored value at the end (arr[n-1] = temp)

✅ Hindi:
arr[0] ko ek temporary variable mein store karo.

for loop se baaki sabko ek index left shift karo.

Last index pe temp value daal do.


Input:  [10, 20, 30, 40]
Step 1: temp = 10
Step 2: Shift:
        arr[0] = arr[1] → 20
        arr[1] = arr[2] → 30
        arr[2] = arr[3] → 40
Step 3: arr[3] = temp → 10
Output: [20, 30, 40, 10]




void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;

    int temp = arr[0];
    for(int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}




| Approach | Time | Space | In-place? | Notes                  |
| -------- | ---- | ----- | --------- | ---------------------- |
| Brute    | O(n) | O(n)  | ❌         | Uses temp array        |
| Optimal  | O(n) | O(1)  | ✅         | One shift and temp var |
