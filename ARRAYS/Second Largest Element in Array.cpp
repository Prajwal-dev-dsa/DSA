Second Largest Element in Array (Without Sorting)
🚀 Pattern:
Array Traversal

Two-pass / One-pass logic

No need for extra space

🔥 Standard interview warm-up question

✅ Proof / Intuition (Crisp Points)
Brute Force

Find max element

Traverse again to find element just less than max

Time: O(2N), Space: O(1)

Better Approach (Single Pass with Conditions)

Maintain two variables: largest, secondLargest

Traverse once:

If a[i] > largest: update both

Else if a[i] > secondLargest && a[i] != largest: update secondLargest

Time: O(N), Space: O(1)

✅ Efficient and clean

Optimal == Better in this case (Single pass is already optimal)

✅ C++ Code

// ✅ Brute Force (2 pass)
int secondLargest(vector<int>& nums) {
    int max1 = INT_MIN;
    for (int num : nums) {
        max1 = max(max1, num);
    }
    int max2 = INT_MIN;
    for (int num : nums) {
        if (num != max1)
            max2 = max(max2, num);
    }
    return max2;
}

// ✅ Optimal (1 pass)
int secondLargest(vector<int>& nums) {
    int max1 = INT_MIN, max2 = INT_MIN;
    for (int num : nums) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2 && num != max1) {
            max2 = num;
        }
    }
    return max2;
}


| Approach | Time  | Space | Key Idea                        |
| -------- | ----- | ----- | ------------------------------- |
| Brute    | O(2N) | O(1)  | Two pass: max + 2nd max         |
| Optimal  | O(N)  | O(1)  | Single pass with tracking maxes |
