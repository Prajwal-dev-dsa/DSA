📌 Majority Element (> n/2 times)
Problem:
Given an array of size n, find the element that appears more than n/2 times. You can assume that the majority element always exists in the array.

Example:

Input: nums = [3, 3, 4, 2, 4, 4, 2, 4, 4]

Output: 4 (since 4 appears 5 times, which is greater than n/2)

🔍 Pattern:
This problem can be solved efficiently using the Boyer-Moore Voting Algorithm. The main idea is to maintain a candidate and a counter as we iterate through the array. We reduce the counter when we encounter a different element and increase it when we encounter the same element. At the end, the candidate will be the majority element.

Brute Force Approach:
Idea: Count the occurrences of each element using a hash map and return the element whose count is greater than n/2.

Time Complexity: O(n) (traversing the array once) + O(n) (hashmap insertion) = O(n)

Space Complexity: O(n) (for the hashmap)

C++ Code:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count_map;
    for (int num : nums) {
        count_map[num]++;
        if (count_map[num] > nums.size() / 2) {
            return num;
        }
    }
    return -1;  // This should never be reached as per the problem statement
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}


Explanation:

We iterate through the array and maintain a count of each element in a hashmap.

If the count of an element exceeds n/2, we return that element.

Hindi:
Hum array ko iterate karte hain aur ek hashmap mein har element ka count rakhte hain. Agar kisi element ka count n/2 se zyada hota hai, toh hum us element ko return kar dete hain.

Better Approach:
Idea: Instead of using a hashmap, we can use the Boyer-Moore Voting Algorithm. This approach requires only two variables: one to store the candidate and another to count occurrences of that candidate.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (constant space)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = -1, count = 0;
    
    // First pass: Find the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Second pass: Verify the candidate
    int count_verify = 0;
    for (int num : nums) {
        if (num == candidate) count_verify++;
    }
    
    if (count_verify > nums.size() / 2) {
        return candidate;
    }
    return -1;  // This should never be reached as per the problem statement
}

int main() {
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}


Explanation:

First Pass: We use a counter to maintain a candidate. If the counter is 0, we set the current number as the candidate and increment the counter. If the current number matches the candidate, we increment the counter; otherwise, we decrement it.

Second Pass: After identifying the candidate, we verify its count in the array to ensure it appears more than n/2 times.

Why better?: This approach is optimal in terms of time and space. We only need two passes through the array and constant space for storing the candidate.

Hindi:

First Pass: Hum ek counter ka use karte hain jisme agar counter 0 ho toh hum current element ko candidate bana dete hain aur counter ko increment karte hain. Agar current element candidate ke barabar ho, toh counter ko increment karte hain, aur agar nahi ho toh counter ko decrement karte hain.

Second Pass: Candidate ko identify karne ke baad, hum uska count verify karte hain taaki ensure ho sake ki woh element n/2 se zyada baar array mein aaye ho.

Optimal Approach:
The Boyer-Moore Voting Algorithm itself is already the optimal solution for this problem.

Time Complexity: O(n) (we make two passes over the array)

Space Complexity: O(1) (constant space)

Explanation:

This is the optimal approach because we only need two passes and constant space to solve the problem. It’s both time-efficient and space-efficient.

Hindi:
Yeh approach already optimal hai kyunki hum do passes aur constant space ka use kar rahe hain solution ke liye. Yeh dono time aur space efficiency ke hisaab se sabse accha solution hai.

Summary:
Brute Force:

Time: O(n)

Space: O(n)

Explanation: Use a hashmap to count occurrences of each element and return the majority element.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Boyer-Moore Voting Algorithm with two passes (one for identifying the candidate and one for verifying it).

Interview Style Explanation:
Pattern: "This is a classical problem that can be efficiently solved using the Boyer-Moore Voting Algorithm, which is optimal both in terms of time and space."

Transition from Brute to Better: "While the brute-force approach works, it uses extra space to store counts, which is inefficient. The Boyer-Moore Voting Algorithm is a cleaner, more optimal solution since it only requires two passes through the array and constant space."