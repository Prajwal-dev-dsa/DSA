📌 Kadane's Algorithm - Maximum Subarray Sum
Problem:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output: 6 (The subarray [4, -1, 2, 1] has the largest sum = 6)

🔍 Pattern:
This is a classic dynamic programming problem, and Kadane’s Algorithm is the optimal solution for finding the maximum subarray sum in linear time.

Brute Force Approach:
Idea: Check all possible subarrays and calculate their sums to find the maximum.

Time Complexity: O(n^2) (due to nested loops for checking all subarrays)

Space Complexity: O(1) (only a variable to store the maximum sum)

C++ Code:


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = INT_MIN;
    
    // Iterate over all possible subarrays
    for (int i = 0; i < nums.size(); i++) {
        int current_sum = 0;
        for (int j = i; j < nums.size(); j++) {
            current_sum += nums[j];
            max_sum = max(max_sum, current_sum);
        }
    }
    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}


Explanation:

We use two loops: the outer loop picks the starting point of the subarray, and the inner loop expands the subarray and computes the sum. We update the max_sum whenever we encounter a larger sum.

Hindi:
Hum do nested loops ka use kar rahe hain. Pehla loop subarray ke starting point ko choose karta hai, aur dusra loop us subarray ko extend karke sum nikaalta hai. Har baar agar sum zyada hota hai toh max_sum ko update karte hain.


Better Approach:
Idea: Instead of using nested loops, we can use Kadane’s Algorithm, which is an efficient dynamic programming approach to calculate the maximum subarray sum in a single pass.

Time Complexity: O(n) (since we only need one pass over the array)

Space Complexity: O(1) (no extra space is required)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    
    // Start from the second element
    for (int i = 1; i < nums.size(); i++) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}


Explanation:

Kadane's Algorithm:

We initialize max_sum and current_sum to the first element.

As we iterate through the array, we update current_sum to be the maximum of the current element itself or the current element plus the previous current_sum. This ensures that we either start a new subarray or continue with the current subarray.

We update max_sum to be the maximum of itself and current_sum at each step.

Why better?:

This approach only needs one pass over the array, and it uses constant space. Its optimal because it maintains the running sum while tracking the maximum sum.

Hindi:

Kadanes Algorithm:

Hum max_sum aur current_sum ko pehle element pe initialize karte hain.

Har element ke liye, hum current_sum ko update karte hain ki ya toh current element khud ho, ya current element aur pehle wale current_sum ka sum ho. Isse hum decide karte hain ki new subarray shuru karna hai ya purani subarray ko extend karna hai.

Har step pe max_sum ko update karte hain.

Optimal Approach:
Idea: The Kadanes Algorithm itself is already optimal. We can solve this problem in O(n) time and O(1) space by maintaining a running sum and updating the maximum sum at each step.

Time Complexity: O(n) (one pass through the array)

Space Complexity: O(1) (constant space)

Explanation:

This approach is optimal because it gives the maximum subarray sum in linear time and constant space. This is the most efficient way to solve this problem.

Hindi:
Yeh approach already optimal hai. Hum O(n) time mein aur constant space mein maximum subarray sum nikaal sakte hain.

Summary:
Brute Force:

Time: O(n^2)

Space: O(1)

Explanation: Use two loops to check all subarrays and find the maximum sum.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Kadane’s Algorithm (one pass through the array with constant space).

Interview Style Explanation:
Pattern: "This is a classic dynamic programming problem where we can apply Kadane’s Algorithm to find the maximum subarray sum efficiently."

Transition from Brute to Better: "While the brute-force solution works, it is inefficient because it has a quadratic time complexity. Kadane’s Algorithm reduces this to linear time, making it much faster for large arrays."

