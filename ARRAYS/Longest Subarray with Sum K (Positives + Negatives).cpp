Longest Subarray with Sum K (Positives + Negatives)
🧠 Pattern:
Prefix Sum Approach

Hash Map for Optimization

This problem requires handling both positive and negative numbers in the array.

✅ Problem Statement:
🔍 English:
Given an array arr[] of integers (which may include both positive and negative numbers) and a number K, find the length of the longest subarray whose sum is equal to K. The subarray can contain both positive and negative elements.

🔍 Hindi:
Ek array arr[] diya gaya hai jisme positive aur negative dono types ke numbers ho sakte hain, aur ek number K diya gaya hai. Tumhe wo longest subarray find karna hai jiska sum exactly K ho. Subarray mein positive aur negative dono elements ho sakte hain.

Example:

Input: arr[] = [1, -1, 5, -2, 3], K = 3
Output: Length = 4 (subarray [1, -1, 5, -2])


🥉 Brute Force Approach
✅ Idea:
Generate all possible subarrays.

For each subarray, calculate its sum and check if it equals K.

Keep track of the longest subarray that satisfies this condition.

📘 English:
Brute force involves generating all subarrays and checking their sum.

📗 Hindi:
Brute force mein sabhi subarrays generate karte hain aur unka sum check karte hain.

🕒 Time: O(n^2)
🧠 Space: O(1) → ❌ Inefficient for large arrays
✅ C++ Code:


int longestSubarrayBrute(vector<int>& arr, int K) {
    int maxLength = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            if (sum == K) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    
    return maxLength;
}



🥈 Better Approach – Using Prefix Sum with Hash Map
✅ Idea:
Traverse the array while maintaining a running sum (prefixSum).

For each element, calculate the prefixSum and check if there exists a previous prefixSum such that the difference between the two equals K.

Use a hash map to store the first occurrence of each prefixSum value.

📘 English:
Maintain a running sum and use a hash map to find the length of the subarray in constant time.

📗 Hindi:
Running sum maintain karo aur hash map ka use karo, jisse subarray ka length constant time mein find ho sake.

🕒 Time: O(n)
🧠 Space: O(n) → Optimized in time complexity
✅ C++ Code:


#include <unordered_map>

int longestSubarrayBetter(vector<int>& arr, int K) {
    unordered_map<int, int> prefixSumMap;
    int maxLength = 0;
    int prefixSum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        
        if (prefixSum == K) {
            maxLength = i + 1;
        }
        
        if (prefixSumMap.find(prefixSum - K) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[prefixSum - K]);
        }
        
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }
    
    return maxLength;
}



| Approach    | Time     | Space | In-place | Why Upgrade?                                       |
| ----------- | -------- | ----- | -------- | -------------------------------------------------- |
| Brute       | O(n^2)   | O(1)  | ❌        | Too slow for large inputs                          |
| **Better**  | **O(n)** | O(n)  | ❌        | Efficient using a hash map                         |
| **Optimal** | **O(n)** | O(1)  | ✅        | Using a sliding window and prefix sum in O(n) time |


🎯 Summary:
Prefix sum with hash map is the most efficient for handling this problem because it reduces the problem to linear time complexity and avoids unnecessary nested loops.

Brute force is good for small arrays but becomes inefficient as the array size increases.

Optimal solution using a sliding window and prefix sum can be adapted to handle both positive and negative numbers, maintaining efficiency.
