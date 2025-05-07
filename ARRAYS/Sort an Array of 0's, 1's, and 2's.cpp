
📌 Sort an Array of 0's, 1's, and 2's
This is a classic problem known as the Dutch National Flag Problem.

Problem:
Given an array containing only 0's, 1's, and 2's, sort the array in linear time.

Example:

Input: arr = [0, 1, 2, 1, 0, 2, 1, 0]

Output: [0, 0, 0, 1, 1, 1, 2, 2]

🔍 Pattern:
This problem is a partitioning problem, where we need to sort an array with a limited number of distinct elements (in this case, just 0, 1, and 2). A highly efficient approach is to use the three-pointer technique (Dutch National Flag algorithm), which partitions the array into three sections, each corresponding to one of the three values.

Brute Force Approach:
Idea: Use sorting to arrange the array in ascending order.

Time Complexity: O(n log n) (due to sorting)

Space Complexity: O(1) (if we use an in-place sorting algorithm)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    sortArray(arr);
    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}


Explanation:

We are using the sort() function from C++ Standard Library to sort the array.

This is a simple but inefficient solution for this problem since the time complexity is O(n log n).

Hindi:
Hum C++ ki built-in sort() function ka use kar rahe hain jo array ko sort kar deta hai. Yeh ek simple solution hai, lekin time complexity O(n log n) honi ki wajah se yeh inefficient hai.


Better Approach:
Idea: Use the Dutch National Flag algorithm with three pointers to sort the array in a single pass.

One pointer for 0's, one pointer for 1's, and one for 2's.

Time Complexity: O(n) (only one pass through the array)

Space Complexity: O(1) (in-place sorting)

C++ Code:


#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    
    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    sortArray(arr);
    for(int num : arr) {
        cout << num << " ";
    }
    return 0;
}


Explanation:

We initialize three pointers: low for 0's, mid for 1's, and high for 2's.

We then iterate over the array:

If arr[mid] == 0, we swap arr[low] and arr[mid], then increment both pointers.

If arr[mid] == 1, we just move the mid pointer forward.

If arr[mid] == 2, we swap arr[mid] and arr[high], then decrement high.

This approach sorts the array in a single pass with constant space.

Hindi:
Yeh Dutch National Flag algorithm ka use karta hai jisme teen pointers hote hain:

low pointer 0's ke liye

mid pointer 1's ke liye

high pointer 2's ke liye
Hum ek single pass mein array ko sort kar lete hain.

Optimal Approach:
Idea: The Dutch National Flag algorithm described above is the optimal solution for this problem. It sorts the array in O(n) time using O(1) space.

Time Complexity: O(n) (one pass through the array)

Space Complexity: O(1) (no extra space required)

Explanation:

This approach is optimal because it only requires one pass through the array, and it sorts the array in-place without needing any extra space for sorting.

Hindi:
Yeh approach already optimal hai kyunki hum sirf ek pass mein array ko sort kar rahe hain aur in-place sorting kar rahe hain bina kisi extra space ke.

Summary:
Brute Force:

Time: O(n log n)

Space: O(1)

Explanation: Use sorting to arrange elements.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Dutch National Flag algorithm (3-pointer approach).

Interview Style Explanation:
Pattern: "This is a classical problem that can be solved efficiently using the Dutch National Flag algorithm, which partitions the array based on three categories (0's, 1's, and 2's)."

Transition from Brute to Better: "Although sorting works, it is not the most efficient solution for this problem. By using the Dutch National Flag algorithm, we can solve the problem in a single pass, making it much more efficient for larger arrays."
