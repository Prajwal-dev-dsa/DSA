Right Rotate an Array by One Place
🧠 Pattern:
Array Manipulation

Similar to left rotation, but shift happens in opposite direction

Ye bhi D-place rotation ke foundation mein aata hai

💡 Focus on last element → shift everything to right → insert last at front

✅ Interview Explanation:
🔍 Problem Statement (Short):
Ek array diya hai, humein use right rotate karna hai ek position se.
Example:
Input: [1, 2, 3, 4, 5] → Output: [5, 1, 2, 3, 4]

🔎 Real-life Analogy:
Soch ek circular line hai. Last person ko sabse pehle bhejna hai — right circular shift.

🔴 Brute Force Approach:
✅ Idea:
Make a temp array

Copy arr[n-1] into temp[0]

Copy original arr[0] to arr[n-2] to temp[1] to temp[n-1]

Copy temp back to original array

⛔ Problem:
Extra space used → O(n)

Interview mein mostly reject hota hai due to in-place constraint

✅ Optimal In-place Approach
✅ English:
Save arr[n-1] in a temporary variable.

Traverse array from end to start:

For each i, do arr[i] = arr[i-1]

Finally assign arr[0] = temp

✅ Hindi:
arr[n-1] ko temp variable mein store karo.

for loop use karo n-1 se 1 tak — sabko ek position right shift karo.

arr[0] = temp assign karo.




Input: [10, 20, 30, 40]
temp = 40
Step-by-step:
arr[3] = arr[2] → 30
arr[2] = arr[1] → 20
arr[1] = arr[0] → 10
arr[0] = temp → 40

Output: [40, 10, 20, 30]




void rightRotateByOne(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;

    int temp = arr[n - 1];
    for(int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}



| Approach | Time | Space | In-place? | Notes                 |
| -------- | ---- | ----- | --------- | --------------------- |
| Brute    | O(n) | O(n)  | ❌         | Uses temp array       |
| Optimal  | O(n) | O(1)  | ✅         | Right shift with temp |
