Maximum Consecutive Ones
🧠 Pattern:
Sliding Window / Two Pointers

Greedy Approach

✅ Problem Statement:
🔍 English:
Given a binary array arr[] consisting of only 1s and 0s, find the maximum number of consecutive 1s in the array. You need to solve the problem in O(n) time and O(1) space.

🔍 Hindi:
Ek binary array arr[] diya gaya hai jisme sirf 1s aur 0s hain. Tumhe array me consecutive 1s ka maximum count find karna hai. Tumhe O(n) time aur O(1) space mein solve karna hai.

Example:

Input: arr[] = [1, 0, 1, 1, 0, 1, 1, 1]
Output: Maximum consecutive 1s = 3


🥉 Brute Force Approach
✅ Idea:
Use two nested loops: one for iterating through the array and another for counting the consecutive 1s starting at each index.

Keep track of the maximum count of consecutive 1s.

📘 English:
Use two loops: one to iterate over the array, and the other to count consecutive 1s starting at each position.

📗 Hindi:
Do loops ka use karo: ek loop array ko iterate karega, aur doosra loop consecutive 1s ko count karega.

🕒 Time: O(n^2)
🧠 Space: O(1) → ✅ No extra space used
✅ C++ Code:

int findMaxConsecutiveOnesBrute(std::vector<int>& arr) {
    int maxCount = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] == 1) {
                count++;
            } else {
                break;  // Stop as soon as a 0 is encountered
            }
        }
        maxCount = std::max(maxCount, count);
    }
    
    return maxCount;
}


🥈 Better Approach – One Pass with Counting
✅ Idea:
Iterate through the array.

Keep a counter to count the consecutive 1s.

If a 1 is encountered, increment the counter.

If a 0 is encountered, reset the counter to 0.

Track the maximum counter value during the iteration.

📘 English:
Use a single loop to iterate over the array. If a 1 is found, increment the counter; if a 0 is found, reset it. Track the maximum count of 1s during the loop.

📗 Hindi:
Ek loop ka use karo array ke andar. Agar 1 mile toh counter ko increment karo, agar 0 mile toh reset kar do. Maximum count ko track karte jao.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place (No extra space used)
✅ C++ Code:


int findMaxConsecutiveOnesBetter(std::vector<int>& arr) {
    int maxCount = 0, count = 0;
    
    // Iterate through the array
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            count++;  // Increment count for consecutive 1s
        } else {
            count = 0;  // Reset count if 0 is encountered
        }
        
        maxCount = std::max(maxCount, count);  // Track max count
    }
    
    return maxCount;
}


| Approach   | Time     | Space | In-place | Why Upgrade?                 |
| ---------- | -------- | ----- | -------- | ---------------------------- |
| Brute      | O(n^2)   | O(1)  | ✅        | Inefficient for large arrays |
| **Better** | **O(n)** | O(1)  | ✅        | Efficient, works in one pass |


🎯 Summary:
One-pass approach is the optimal solution, which works in O(n) time and O(1) space.

Brute force is inefficient for large arrays because it takes O(n^2) time.

