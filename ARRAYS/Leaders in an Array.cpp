📌 Leaders in an Array
Problem:
An element is called a leader in the array if it is strictly greater than all the elements to its right side. The rightmost element is always a leader.

Example:

Input: arr = [16, 17, 4, 3, 5, 2]

Output: [17, 5, 2]

Explanation:

17 is greater than all elements to its right.

5 is greater than 2 (to its right).

2 is the rightmost element, so its always a leader.

🔍 Pattern:
This is a traversal and comparison problem where we can find the leaders by iterating from right to left and comparing each element with the maximum value encountered so far.

Brute Force Approach:
Idea: The brute force approach is to iterate through the array for each element and check if it is greater than all the elements to its right.

Time Complexity: O(n^2) (two nested loops)

Space Complexity: O(1) (no extra space)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersBruteForce(vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) leaders.push_back(arr[i]);
    }
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = leadersBruteForce(arr);
    
    cout << "Leaders in the array: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

We iterate over each element of the array and check whether it is greater than all the elements to its right. If it is, we add it to the result.

Why brute force?:

The brute force approach is simple but inefficient. It checks every element against all elements to its right, leading to a time complexity of O(n^2).

Hindi:
Hum har element ko check kar rahe hain ki kya wo apne right ke sabhi elements se bada hai. Agar hai, toh usse result mein add karte hain.

Better Approach:
Idea: Instead of checking each element with all elements to its right, we can iterate from right to left, keeping track of the maximum element we have encountered so far. If the current element is greater than this maximum, it is a leader.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(n) (for the result array)

C++ Code:

#include <iostream>
#include <vector>
using namespace std;

vector<int> leadersBetter(vector<int>& arr) {
    vector<int> leaders;
    int n = arr.size();
    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);
    
    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }
    
    // Reverse the leaders array to maintain correct order
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = leadersBetter(arr);
    
    cout << "Leaders in the array: ";
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;
    
    return 0;
}


Explanation:

We initialize maxFromRight to the rightmost element, since its always a leader.

Then, we iterate from right to left. If we find an element that is greater than maxFromRight, we add it to the leaders list and update maxFromRight.

Finally, we reverse the leaders list to return the leaders in correct order.

Why better?:

This approach significantly reduces time complexity from O(n^2) to O(n), making it much more efficient.

Hindi:
Hum rightmost element ko leader maan kar left ki taraf traverse karte hain. Agar koi element usse bada hota hai, toh wo bhi leader ban jaata hai. Finally, hum leaders ko reverse karte hain taki sahi order mein result mile.

Optimal Approach:
Idea: The better approach is already optimal because it uses only one traversal and keeps the space complexity to O(n) for storing the leaders. The space complexity for tracking the largest element is O(1), so overall, this approach is optimal.

Explanation:

The algorithm is already optimized to find the leaders in a single pass from right to left, using constant space to track the maximum element encountered so far.

Hindi:
Yeh approach already optimal hai, kyunki hum ek hi pass mein leaders nikaal lete hain aur constant space mein kaam karte hain.

Summary:
Brute Force:

Time: O(n^2) (two nested loops)

Space: O(1) (no extra space)

Explanation: Check each element against all elements to its right.

Better (Optimal):

Time: O(n) (single pass from right to left)

Space: O(n) (for storing the leaders)

Explanation: Traverse from right to left, and keep track of the maximum element encountered so far.

Interview Style Explanation:
Pattern: "This problem follows the traversal and comparison pattern. We are traversing the array from right to left to find the leaders."

Transition from Brute to Better: "The brute-force approach checks every element with all the elements to its right, leading to high time complexity. The better approach improves this by scanning the array once and using a variable to track the maximum element, making it much more efficient."