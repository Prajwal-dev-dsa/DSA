Find the Union of Two Arrays
🧠 Pattern:
Set Theory → Union of two sets

Array Manipulation

Focus on handling duplicates and returning a unique set of elements from two arrays.

✅ Problem Statement:
🔍 English:
Given two arrays arr1[] and arr2[] of sizes n and m, find the union of these two arrays. The union should contain all distinct elements from both arrays.

🔍 Hindi:
Do arrays arr1[] aur arr2[] diye gaye hain, jinke sizes n aur m hain. Tumhe unka union nikalna hai, jisme dono arrays ke sare distinct elements ho.

Example:

Input: arr1[] = [1, 2, 3, 4, 5], arr2[] = [1, 2, 3, 6, 7]  
Output: Union = [1, 2, 3, 4, 5, 6, 7]


🥉 Brute Force Approach
✅ Idea:
Take all elements of arr1[] and add them to a temporary array.

Then, add elements of arr2[] to this temporary array, skipping duplicates.

Finally, return the temporary array as the result.

📘 English:
Concatenate both arrays, then eliminate duplicates.

📗 Hindi:
Donon arrays ko concatenate karo aur phir duplicates ko remove karo.

🕒 Time: O(n + m)
🧠 Space: O(n + m) → ❌ Not in-place
✅ C++ Code:

void unionOfArraysBrute(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result = arr1;
    
    for (int i = 0; i < arr2.size(); i++) {
        // Check if arr2[i] already exists in result
        bool found = false;
        for (int j = 0; j < result.size(); j++) {
            if (arr2[i] == result[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(arr2[i]);
        }
    }
    
    // Printing the union of two arrays
    for (int num : result) {
        cout << num << " ";
    }
}


🥈 Better Approach – Using Hash Set for Uniqueness
✅ Idea:
Use a hash set to store the unique elements of both arrays.

Insert all elements of both arrays into the hash set.

The hash set automatically eliminates duplicates.

📘 English:
Use a hash set to store elements, ensuring uniqueness automatically.

📗 Hindi:
Ek hash set use karo, jisme unique elements store honge aur duplicates automatically remove ho jayenge.

🕒 Time: O(n + m)
🧠 Space: O(n + m) → Still not in-place, but optimized with hash set
✅ C++ Code:

#include <unordered_set>

void unionOfArraysBetter(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> resultSet;
    
    // Add elements of arr1[] to the set
    for (int i = 0; i < arr1.size(); i++) {
        resultSet.insert(arr1[i]);
    }
    
    // Add elements of arr2[] to the set
    for (int i = 0; i < arr2.size(); i++) {
        resultSet.insert(arr2[i]);
    }
    
    // Printing the union of two arrays
    for (auto num : resultSet) {
        cout << num << " ";
    }
}


🥇 Optimal Approach – Sorting + Two Pointers (In-place)
This is the most efficient solution when we need to work in-place.

✅ Idea:
Sort both arrays first.

Use two pointers to traverse both arrays simultaneously, picking distinct elements from both arrays.

This avoids duplicate elements and keeps the result sorted.

📘 English:
Sort both arrays and use two pointers to pick elements without duplication.

📗 Hindi:
Pehle dono arrays ko sort karo aur fir two pointers ka use karte hue distinct elements ko select karo.

🕒 Time: O(n log n + m log m) (due to sorting)
🧠 Space: O(1) → ✅ In-place
✅ C++ Code:


void unionOfArraysOptimal(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    int i = 0, j = 0;
    
    // Print union of two sorted arrays
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                cout << arr1[i] << " ";
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (j == 0 || arr2[j] != arr2[j - 1]) {
                cout << arr2[j] << " ";
            }
            j++;
        } else {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                cout << arr1[i] << " ";
            }
            i++;
            j++;
        }
    }
    
    // Handle remaining elements of arr1
    while (i < n) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            cout << arr1[i] << " ";
        }
        i++;
    }
    
    // Handle remaining elements of arr2
    while (j < m) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            cout << arr2[j] << " ";
        }
        j++;
    }
}


| Approach    | Time                     | Space    | In-place | Why Upgrade?                                   |
| ----------- | ------------------------ | -------- | -------- | ---------------------------------------------- |
| Brute       | O(n × m)                 | O(n + m) | ❌        | Duplicate checking is slow and inefficient     |
| Better      | O(n + m)                 | O(n + m) | ❌        | Uses extra space but optimized with hash set   |
| **Optimal** | **O(n log n + m log m)** | O(1)     | ✅        | Fastest in terms of time complexity + in-place |


🎯 Summary:
Hash set works well for eliminating duplicates but uses extra space.

Sorting + Two pointers is the optimal solution when we want in-place processing, especially for larger arrays.

