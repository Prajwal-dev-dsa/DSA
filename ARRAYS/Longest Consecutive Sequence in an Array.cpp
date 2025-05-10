📌 Longest Consecutive Sequence in an Array
Problem:
Given an unsorted array of integers, find the length of the longest consecutive elements sequence. The consecutive elements can be in any order, but they should form a consecutive sequence.

Example:

Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation: The longest consecutive sequence is [1, 2, 3, 4], which has length 4.

🔍 Pattern:
This is a hashing or set-based problem where we need to identify the longest sequence of consecutive numbers. We can utilize a hash set for efficient lookups.

Brute Force Approach:
Idea: One brute force way is to sort the array and then traverse it to find the longest consecutive sequence. However, sorting introduces unnecessary overhead.

Time Complexity: O(n log n) (due to sorting)

Space Complexity: O(1) (only the input array is used)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestConsecutiveBruteForce(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    sort(nums.begin(), nums.end());  // Sort the array
    
    int maxLength = 1;
    int currentLength = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i-1] + 1) {
            currentLength++;
        } else if (nums[i] != nums[i-1]) {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    return max(maxLength, currentLength);
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << longestConsecutiveBruteForce(nums) << endl;
    return 0;
}


Explanation:

We first sort the array and then find the longest sequence by comparing each element to its previous one. If the current element is one greater than the previous, we increment the length of the current sequence. Otherwise, we compare it with the maximum length found so far.

Why brute force?:

Sorting the array leads to an unnecessary O(n log n) time complexity. While the logic is simple, it could be optimized further.

Hindi:
Hum array ko sort karte hain aur phir consecutive elements ko compare karke longest sequence find karte hain.

Better Approach:
Idea: We can use a hash set to store the elements and check for consecutive numbers. For each element in the array, we can check if its the start of a sequence (i.e., num - 1 is not in the set). If it is, we extend the sequence by checking num + 1, num + 2, and so on.

Time Complexity: O(n) (one pass through the array and constant-time lookups in a set)

Space Complexity: O(n) (to store elements in the set)

C++ Code:

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutiveBetter(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());  // Insert all elements into the set
    int maxLength = 0;
    
    for (int num : numSet) {
        // Check if it's the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;
            
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }
            
            maxLength = max(maxLength, currentLength);
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << longestConsecutiveBetter(nums) << endl;
    return 0;
}


Explanation:

We store all elements in an unordered set (numSet), so lookups are O(1).

For each number, we check if its the start of a sequence by checking if num - 1 exists in the set. If it doesn't, it's the start.

Then, we keep checking num + 1, num + 2, etc., to extend the sequence and find the length.

We track and return the maximum length of any sequence we find.

Why better?:

This approach only requires one pass through the array and each lookup is done in constant time using the set, making it much more efficient.

Hindi:
Hum ek unordered set mein array ke elements ko store karte hain. Phir har element ke liye check karte hain ki kya wo sequence ka starting point hai. Agar hai, toh us sequence ko extend karte hain aur length track karte hain.

Optimal Approach:
Idea: The better approach is already optimal, as it works in O(n) time and O(n) space, making it very efficient compared to sorting-based solutions.

Explanation:

The use of a set allows us to check for consecutive numbers in constant time, and the algorithm runs in linear time relative to the size of the input.

Hindi:
Yeh approach already optimal hai, kyunki hum ek hi pass mein result nikaal lete hain aur constant time mein lookups karte hain.

Summary:
Brute Force:

Time: O(n log n) (due to sorting)

Space: O(1) (only the input array)

Explanation: Sort the array and find consecutive sequences by comparing elements.

Better (Optimal):

Time: O(n) (single pass through the array)

Space: O(n) (to store elements in the set)

Explanation: Use a set for constant-time lookups and find sequences by checking for the start of each possible sequence.

Interview Style Explanation:
Pattern: "This problem follows a sequence identification pattern, where we need to find the longest consecutive sequence in an unordered array."

Transition from Brute to Better: "The brute force approach uses sorting, which is inefficient. The better approach uses a set to track elements and identify the longest sequence in linear time."