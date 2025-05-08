📌 Print Subarray with Maximum Subarray Sum (Extended version of Kadane’s Algorithm)
Problem:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and print the subarray itself.

Example:

Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output: [4, -1, 2, 1] (The subarray [4, -1, 2, 1] has the largest sum = 6)

🔍 Pattern:
This is an extension of Kadane's Algorithm. The idea remains the same — we need to find the maximum subarray sum. However, in addition to the sum, we also need to track the start and end indices of the subarray that contributes to this maximum sum. By doing so, we can print the actual subarray at the end.

Brute Force Approach:
Idea: We can iterate over all possible subarrays, calculate their sums, and track the subarray with the maximum sum.

Time Complexity: O(n^2) (nested loops to check all subarrays)

Space Complexity: O(1) (only a few variables to store the maximum sum and subarray)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSubArray(vector<int>& nums) {
    int max_sum = INT_MIN;
    vector<int> max_subarray;
    
    // Iterate over all possible subarrays
    for (int i = 0; i < nums.size(); i++) {
        int current_sum = 0;
        vector<int> current_subarray;
        
        for (int j = i; j < nums.size(); j++) {
            current_sum += nums[j];
            current_subarray.push_back(nums[j]);
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_subarray = current_subarray;
            }
        }
    }
    
    return max_subarray;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> result = maxSubArray(nums);
    
    cout << "Subarray with Maximum Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

We use two loops: the outer loop picks the starting point of the subarray, and the inner loop expands the subarray and computes the sum.

Whenever we find a new subarray with a larger sum, we update both the maximum sum and the subarray.

Hindi:
Hum do nested loops ka use kar rahe hain. Pehla loop subarray ke starting point ko choose karta hai, aur dusra loop us subarray ko extend karke sum nikaalta hai. Agar hum koi subarray ka sum zyada paate hain, toh hum max sum aur subarray ko update kar lete hain.

Better Approach:
Idea: Use Kadane’s Algorithm with additional variables to track the start and end indices of the subarray.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (constant space)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start = 0, end = 0, temp_start = 0;
    
    // Start from the second element
    for (int i = 1; i < nums.size(); i++) {
        if (current_sum + nums[i] < nums[i]) {
            current_sum = nums[i];
            temp_start = i;  // New subarray starts here
        } else {
            current_sum += nums[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    
    vector<int> result;
    for (int i = start; i <= end; i++) {
        result.push_back(nums[i]);
    }
    
    return result;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> result = maxSubArray(nums);
    
    cout << "Subarray with Maximum Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

Kadane's Algorithm:

We maintain max_sum (the highest sum found so far) and current_sum (the sum of the current subarray).

Additionally, we keep track of the start (start) and end (end) indices of the maximum subarray found so far.

If current_sum + nums[i] < nums[i], it means its better to start a new subarray at index i, so we update temp_start to i and reset current_sum to nums[i].

When we find a larger current_sum, we update both the max_sum and the indices (start, end).

Why better?:

This approach runs in linear time (O(n)) and uses constant space (O(1)), making it efficient compared to the brute force method.

Hindi:

Kadane’s Algorithm:

Hum max_sum aur current_sum ko maintain karte hain. Agar current_sum + nums[i] < nums[i] ho, toh iska matlab hai ki hum new subarray ko start karte hain at index i, isliye temp_start ko update karte hain.

Jab hum maximum current_sum find karte hain, tab hum max_sum aur start, end indices ko update karte hain.

Optimal Approach:
Idea: The Kadane’s Algorithm with tracking of indices is already the optimal solution.

Time Complexity: O(n) (one pass through the array)

Space Complexity: O(1) (constant space)

Explanation:

This approach is optimal because we only need one pass through the array to find the maximum subarray and the subarray itself. We maintain a constant amount of space for the necessary variables.

Hindi:
Yeh approach already optimal hai kyunki hum ek hi pass mein maximum subarray aur subarray ko nikaal lete hain. Hum sirf constant space ka use karte hain.

Summary:
Brute Force:

Time: O(n^2)

Space: O(1)

Explanation: Use two nested loops to check all subarrays and find the maximum sum subarray.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Kadane’s Algorithm with tracking of start and end indices.

Interview Style Explanation:
Pattern: "This problem is an extension of Kadane’s Algorithm, where in addition to finding the maximum sum, we also need to print the subarray that contributes to that sum."

Transition from Brute to Better: "While the brute-force approach works, it’s not efficient enough for large arrays. By leveraging Kadane’s Algorithm and adding a simple tracking mechanism for the subarray indices, we can solve this problem in linear time."