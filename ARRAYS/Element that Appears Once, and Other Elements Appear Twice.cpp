Find the Element that Appears Once, and Other Elements Appear Twice
🧠 Pattern:
XOR Properties

Array Manipulation

Focus on detecting duplicates and unique elements using efficient bitwise operations.

✅ Problem Statement:
🔍 English:
Given an array arr[] of n elements, where every element appears twice except for one element which appears only once, find that unique element. You must solve the problem in O(n) time and O(1) space.

🔍 Hindi:
Ek array arr[] diya gaya hai jisme n elements hain, jisme har element do baar aata hai, bas ek element jo sirf ek baar aata hai. Tumhe wo unique element find karna hai. Ye problem tumhe O(n) time aur O(1) space mein solve karni hai.

Example:

Input: arr[] = [4, 3, 5, 5, 3, 4, 7]
Output: Unique element = 7


🥉 Brute Force Approach
✅ Idea:
Use a hash map or dictionary to count occurrences of each element.

The element that appears only once will have a count of 1.

📘 English:
Use a hash map to count occurrences, then find the element with count 1.

📗 Hindi:
Ek hash map use karo, jisme elements ke occurrences ko count karo. Jo element ek baar aayega, uska count 1 hoga.

🕒 Time: O(n)
🧠 Space: O(n) → ❌ Extra space used
✅ C++ Code:

#include <unordered_map>

int findUniqueElementBrute(vector<int>& arr) {
    unordered_map<int, int> countMap;
    
    for (int i = 0; i < arr.size(); i++) {
        countMap[arr[i]]++;
    }
    
    for (auto& pair : countMap) {
        if (pair.second == 1) {
            return pair.first;
        }
    }
    
    return -1; // This should never happen
}


🥈 Better Approach – Using XOR
✅ Idea:
XOR all the elements in the array.

All elements that appear twice will cancel out (because x ^ x = 0).

The remaining value will be the element that appears only once.

📘 English:
Use XOR to eliminate duplicates and leave only the unique element.

📗 Hindi:
XOR ka use karo taaki duplicate elements cancel ho jayein aur jo unique element hai wo bacha rahe.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place (No extra space used)
✅ C++ Code:

int findUniqueElementOptimal(vector<int>& arr) {
    int unique = 0;
    
    // XOR all elements
    for (int i = 0; i < arr.size(); i++) {
        unique ^= arr[i];  // XOR operation
    }
    
    return unique; // The remaining value will be the unique element
}


| Approach    | Time     | Space | In-place | Why Upgrade?                                            |
| ----------- | -------- | ----- | -------- | ------------------------------------------------------- |
| Brute       | O(n)     | O(n)  | ❌        | Uses extra space (hash map or dictionary)               |
| **Optimal** | **O(n)** | O(1)  | ✅        | XOR allows solving in constant space with a single pass |


🎯 Summary:
XOR approach is the most optimal because it doesn't require any extra space and works efficiently in O(n) time. It is a classic example of utilizing bitwise operations for problem-solving.

