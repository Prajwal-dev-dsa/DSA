Longest Subarray with Sum K (Positives)
🧠 Pattern:
Sliding Window Technique

Prefix Sum Approach

Array Manipulation

✅ Problem Statement:
🔍 English:
Given an array arr[] of positive integers and a number K, find the length of the longest subarray that has a sum equal to K. The subarray can have any number of elements, but their sum should be exactly K.

🔍 Hindi:
Ek array arr[] diya gaya hai jisme positive integers hain aur ek number K diya gaya hai. Tumhe sabse lambi subarray ka length find karna hai jiska sum exactly K ho. Subarray mein koi bhi number of elements ho sakte hain, bas unka sum K hona chahiye.

Example:

Input: arr[] = [1, 2, 3, 4, 1], K = 5
Output: Length = 2 (subarray [2, 3] or [4, 1])


🥉 Brute Force Approach
✅ Idea:
Traverse through all possible subarrays of arr[].

For each subarray, calculate its sum and check if it equals K.

Keep track of the longest subarray that satisfies this condition.

📘 English:
Brute force involves generating all subarrays and checking their sum.

📗 Hindi:
Brute force mein hum sabhi subarrays generate karte hain aur unka sum check karte hain.

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


🥇 Optimal Approach – Using Sliding Window (For Positive Numbers Only)
✅ Idea:
Use two pointers (start and end) to maintain a window that represents a subarray.

Expand the window by moving end and adding the elements.

If the sum exceeds K, move the start pointer to reduce the sum until it equals K.

📘 English:
Sliding window will help keep track of the current subarrays sum and expand or contract the window efficiently.

📗 Hindi:
Sliding window ka use karke current subarray ke sum ko track karna aur window ko expand ya contract karna efficiently.

🕒 Time: O(n)
🧠 Space: O(1) → ✅ In-place
✅ C++ Code:

int longestSubarrayOptimal(vector<int>& arr, int K) {
    int maxLength = 0;
    int sum = 0;
    int start = 0;
    
    for (int end = 0; end < arr.size(); end++) {
        sum += arr[end];
        
        // Shrink the window if sum exceeds K
        while (sum > K && start <= end) {
            sum -= arr[start++];
        }
        
        // Check if current sum equals K
        if (sum == K) {
            maxLength = max(maxLength, end - start + 1);
        }
    }
    
    return maxLength;
}


| Approach    | Time     | Space | In-place | Why Upgrade?                                  |
| ----------- | -------- | ----- | -------- | --------------------------------------------- |
| Brute       | O(n^2)   | O(1)  | ❌        | Too slow for large inputs                     |
| Better      | O(n)     | O(n)  | ❌        | More efficient with a hash map                |
| **Optimal** | **O(n)** | O(1)  | ✅        | Sliding window is the most efficient solution |


🎯 Summary:
Sliding window is the most efficient method for positive integers when looking for subarrays with a given sum. It operates in linear time and constant space, which is optimal for this problem.

Prefix sum with hash map is a very effective approach, but it requires extra space.

Brute force is useful for smaller inputs, but it's not scalable for larger arrays.

