📌 Two Sum Problem
Problem:
Given an array of integers, return the indices of the two numbers such that they add up to a specific target.

Example:

Input: nums = [2, 7, 11, 15], target = 9

Output: [0, 1] (because nums[0] + nums[1] == 9)

🔍 Pattern:
This problem follows a "Hashmap-based" pattern. The key idea is to use a hashmap to store the elements we've seen so far. For each new element, we check if the complement (i.e., target - current number) exists in the hashmap. This lets us find the answer in linear time, which is the optimal solution.

Hindi:
Yeh problem "Hashmap-based" approach ko follow karti hai. Hum hashmap ka use karte hain jisme hum ab tak ke elements store karte hain. Har naye element ke liye, hum check karte hain ki uska complement (matlab target - current number) hashmap mein hai ya nahi. Isse hum linear time mein answer nikal sakte hain.

Brute Force Approach:
Idea: Check every pair of numbers and see if they sum to the target.

Time Complexity: O(n^2) (nested loops, checking all pairs)

Space Complexity: O(1) (no extra space used)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]";
    return 0;
}


Explanation:

Hum do nested loops ka use kar rahe hain jisme hum har pair ko check karte hain.

Agar kisi pair ka sum target ke barabar hota hai, toh us pair ke indices return karte hain.

Hindi:
Hum nested loops ke through har pair ko check karte hain. Agar koi pair ka sum target ke barabar ho, toh unke indices return karte hain.


Better Approach:
Idea: Use a hashmap to store the elements we've seen so far. For each number, check if the complement exists in the hashmap. If it does, return the pair.

Time Complexity: O(n) (only one pass through the array)

Space Complexity: O(n) (extra space for the hashmap)

C++ Code:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;  // stores number and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]";
    return 0;
}


Explanation:

We iterate through the array once. For each number, we calculate its complement (i.e., target - current number).

We check if this complement already exists in the hashmap. If it does, we return the indices of the two numbers (the current number and its complement).

If it doesn’t exist, we store the current number and its index in the hashmap.

Hindi:
Hum array ko ek baar iterate karte hain. Har number ke liye, uska complement (i.e., target - current number) calculate karte hain. Fir check karte hain ki kya woh complement hashmap mein hai. Agar hai, toh dono numbers ke indices return karte hain. Agar nahi hai, toh current number aur uska index hashmap mein store kar lete hain.

Optimal Approach:
Idea: The better approach is already optimal in terms of both time and space. We are using O(n) time complexity and O(n) space complexity, and there is no way to improve this further without violating the problem constraints.

Time Complexity: O(n) (one pass through the array)

Space Complexity: O(n) (space for the hashmap)

Explanation:

The hashmap-based solution is optimal in both time and space. We make only one pass through the array and store at most n elements in the hashmap. This is the most efficient solution for this problem.

Hindi:
Jo hashmap-based solution hai, wo already optimal hai. Hum sirf ek baar array ko traverse karte hain aur hashmap mein n elements store karte hain. Yeh sabse efficient solution hai is problem ke liye.

Summary:
Brute Force:

Time: O(n^2)

Space: O(1)

Explanation: Nested loops check every pair for the sum.

Better (Optimal):

Time: O(n)

Space: O(n)

Explanation: Hashmap stores elements seen so far and checks for complement.

Interview Style Explanation:
Pattern: "This problem is a great example of using a hashmap to achieve an optimal solution. Instead of checking all pairs, we store elements as we go, and check if the complement exists in constant time."

Transition from Brute to Better: "While brute force works fine, its time complexity is quadratic, which is inefficient for large arrays. Using a hashmap reduces the time complexity to linear, making the solution much more efficient for larger inputs."