📌 Rearrange the Array in Alternating Positive and Negative Items
Problem:
Given an array of integers, rearrange the array such that positive and negative numbers are arranged in an alternating pattern. For example, the positive numbers should come at odd indices, and the negative numbers should come at even indices. If there are more positive or negative numbers, the remaining elements should be placed in the remaining slots, but maintaining the alternating pattern as much as possible.

Example:

Input: arr = [1, 2, 3, -4, -1, 4]

Output: [1, -4, 3, -1, 2, 4]

🔍 Pattern:
This problem can be solved using a two-pointer approach. The key observation is that you can segregate the positive and negative numbers first and then arrange them in alternating order.

Brute Force Approach:
Idea: A simple brute force approach could involve segregating the positive and negative numbers into two separate lists and then merging them alternatively. This can be done in two passes through the array.

Time Complexity: O(n) (one pass to segregate, one pass to merge)

Space Complexity: O(n) (additional space for storing segregated numbers)

C++ Code:


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> rearrangeArray(vector<int>& arr) {
    vector<int> pos, neg;
    
    // Segregate positive and negative numbers
    for (int num : arr) {
        if (num >= 0) pos.push_back(num);
        else neg.push_back(num);
    }
    
    // Create a new array with alternating positive and negative numbers
    vector<int> result;
    int i = 0, j = 0;
    bool posTurn = true;
    while (i < pos.size() && j < neg.size()) {
        if (posTurn) {
            result.push_back(pos[i++]);
        } else {
            result.push_back(neg[j++]);
        }
        posTurn = !posTurn; // Alternate between positive and negative
    }
    
    // If any positives or negatives are left, add them to the result
    while (i < pos.size()) result.push_back(pos[i++]);
    while (j < neg.size()) result.push_back(neg[j++]);
    
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};
    vector<int> result = rearrangeArray(arr);
    
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

First, we segregate the positive and negative numbers into separate lists (pos and neg).

Then, we merge them alternately into the result array, starting with the positive number. If one list runs out, we add the remaining elements from the other list.

Why brute force?:

It works, but it uses extra space to store the positive and negative numbers separately and makes multiple passes through the array.

Hindi:
Pehle hum positive aur negative numbers ko segregate karte hain, phir unko alternate order mein merge karte hain. Agar koi list khatam ho jaati hai, toh baaki elements ko result mein add kar dete hain.

Better Approach:
Idea: We can rearrange the elements in the original array without using extra space. We can maintain two pointers — one for the positive numbers and one for the negative numbers — and place them alternately in the array.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (no extra space required)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rearrangeArray(vector<int>& arr) {
    int n = arr.size();
    
    // First, we'll segregate the positive and negative numbers in the array
    int posIdx = 0, negIdx = 1;
    
    while (posIdx < n && negIdx < n) {
        // Find the next positive number
        while (posIdx < n && arr[posIdx] < 0) {
            posIdx += 2;
        }
        
        // Find the next negative number
        while (negIdx < n && arr[negIdx] >= 0) {
            negIdx += 2;
        }
        
        // If both indexes are valid, swap the elements
        if (posIdx < n && negIdx < n) {
            swap(arr[posIdx], arr[negIdx]);
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, -4, -1, 4};
    rearrangeArray(arr);
    
    cout << "Rearranged Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

We use two pointers, posIdx and negIdx, to track where the next positive and negative elements should go.

We iterate over the array and adjust the pointers to find positive and negative numbers in the wrong places, swapping them to their correct positions.

Why better?:

This approach avoids the extra space used in the brute force solution and rearranges the elements in place using constant space.

Hindi:
Hum two pointers ka use kar rahe hain: ek positive numbers ke liye (posIdx) aur ek negative numbers ke liye (negIdx). Jab bhi ek galat jagah par number milta hai, toh hum unhe swap kar dete hain.

Optimal Approach:
Idea: The better approach is already optimal since it rearranges the array in O(n) time and O(1) space.

Explanation:

We achieve optimal performance by rearranging the elements in a single pass using two pointers, without the need for additional space or extra passes.

Hindi:
Yeh approach already optimal hai, kyunki hum ek hi pass mein array ko rearrange kar lete hain bina kisi extra space ke.

Summary:
Brute Force:

Time: O(n)

Space: O(n)

Explanation: Use two separate arrays for positive and negative numbers and then merge them alternately.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Rearrange the array in place using two pointers, maintaining the alternating pattern.

Interview Style Explanation:
Pattern: "This is a two-pointer problem where we segregate positive and negative numbers and then rearrange them alternately."

Transition from Brute to Better: "The brute-force approach is simple but requires extra space. The better approach uses the original array and rearranges the elements in place to optimize space usage."