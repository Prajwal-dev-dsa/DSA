📌 Next Permutation
Problem:
Given an array of integers, implement an algorithm to generate the next lexicographically greater permutation of the given array. If such a permutation does not exist, rearrange the array into the lowest possible order (i.e., sorted in ascending order).

Example:

Input: nums = [1, 2, 3]

Output: [1, 3, 2] (next permutation is achieved by swapping 2 and 3)

Input: nums = [3, 2, 1]

Output: [1, 2, 3] (no next permutation exists, so we return the lowest order)

🔍 Pattern:
This is a next permutation problem, which can be solved using the lexicographical order algorithm. The main steps involve finding the next larger permutation of numbers by swapping elements, and if no such permutation exists, rearranging the array into the smallest possible permutation.

Brute Force Approach:
Idea: The brute force solution involves generating all permutations and selecting the next greater permutation. This can be done by using the next_permutation() function in C++, but generating all permutations first is inefficient.

Time Complexity: O(n!) (generating all permutations)

Space Complexity: O(n) (to store permutations)

C++ Code (using next_permutation from STL):


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    // Generate the next permutation using STL
    if (!next_permutation(nums.begin(), nums.end())) {
        sort(nums.begin(), nums.end());  // If no next permutation, sort the array
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    
    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

next_permutation(nums.begin(), nums.end()) generates the next permutation in lexicographical order. If no next permutation exists (i.e., the array is in descending order), we return the smallest permutation by sorting the array.

Why brute force?:

This uses a built-in STL function, but generating all permutations and finding the next permutation is highly inefficient.

Hindi:
Hum STL ka next_permutation function use kar rahe hain, jo next lexicographically greater permutation de deta hai. Agar next permutation nahi milta, toh array ko sort karte hain.

Better Approach:
Idea: A more efficient approach involves finding the first decreasing element from the right end of the array, swapping it with the next larger element, and then reversing the part after the swapped element to get the next permutation in lexicographical order.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (constant space)

Steps:

Find the largest index i such that nums[i] < nums[i + 1]. If no such i exists, the array is the highest permutation, so we reverse it.

Find the largest index j such that nums[j] > nums[i]. Swap nums[i] and nums[j].

Reverse the sequence from i + 1 to the end to get the smallest lexicographical order for that part.

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    
    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }
    
    // If we find a decreasing element
    if (i >= 0) {
        // Step 2: Find the element to swap with
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    
    // Step 3: Reverse the sequence after the swapped element
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    
    cout << "Next Permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

We start from the second last element and find the first element that is smaller than the next element. This is the element that needs to be swapped to get the next permutation.

Then we find the smallest element that is greater than the element found in step 1 and swap them.

Finally, we reverse the portion of the array after the swapped element to get the smallest possible lexicographical order.

Why better?:

This approach only requires one pass through the array and uses constant space, making it much more efficient than generating all permutations.

Hindi:
Hum pehle array ke right se left ki taraf jaate hain aur pehla decreasing element dhundhte hain. Phir us element ko next greater element ke saath swap karte hain. Last mein, hum uske baad ke elements ko reverse kar dete hain, taki smallest lexicographical order mile.

Optimal Approach:
Idea: The better approach is already optimal as it efficiently computes the next permutation in O(n) time and O(1) space.

Explanation:

This approach is optimal because it only requires one pass through the array and uses constant space, without needing to generate all permutations or sort the array.

Hindi:
Yeh approach already optimal hai. Hum ek hi pass mein next permutation nikaal lete hain aur constant space mein kaam karte hain.

Summary:
Brute Force:

Time: O(n!) (generating all permutations)

Space: O(n) (to store permutations)

Explanation: Use the built-in STL next_permutation function or generate all permutations and select the next one.

Better (Optimal):

Time: O(n) (single pass through the array)

Space: O(1) (constant space)

Explanation: Find the next lexicographical permutation by swapping elements and reversing the sequence after the swap.

Interview Style Explanation:
Pattern: "This problem follows the lexicographical ordering pattern, where we are finding the next greater permutation of the array."

Transition from Brute to Better: "The brute-force approach generates all permutations, which is highly inefficient. The better approach optimizes this by directly finding the next permutation in a single pass."

