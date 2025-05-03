🔶 Remove Duplicates from Sorted Array
🧠 Pattern:
Two Pointer Technique

Since array is sorted → duplicates will always be consecutive

In-place array manipulation — no extra space

Very common in LeetCode interviews (easy-medium)

✅ Interview Explanation:
🔍 Problem Statement (in short):
Sorted array diya gaya hai. Duplicate elements ko remove karna hai without using extra space, aur unique elements ko starting mein rakhna hai. Return karna hai kitne unique elements hai.

🔎 Real-life Analogy:
Socho ki ek shelf mein books sorted hain, aur kuch baar same book repeat ho gayi hai. Tumhe har unique book ek baar rakhni hai — duplicates hata ke.

💡 Brute Force Approach (Not valid in interviews)
🔴 Why not suitable:
Extra space use karta hai (set ya vector)

Interview mein in-place operation maanga gaya hai

✅ Better / Optimal Approach: Two Pointer Technique
✅ English Explanation:
Initialize two pointers:

i = 0 (points to index of last unique element)

Start from j = 1 (exploring the rest of the array)

For every element arr[j]:

If it's not equal to arr[i] (means it's a new unique element):

Move i one step ahead

Put arr[j] in arr[i] (overwrite the duplicate)

After loop, the number of unique elements will be i + 1

✅ Hindi Explanation:
i pointer rakho jahan tak unique elements store karte ho.

j pointer se traverse karo array.

Jab bhi arr[j] alag mile arr[i] se:

i++ karo (next unique index pe jao)

arr[i] = arr[j] karo (unique element rakh do)

Aise karte karte start mein saare unique elements aajayenge.

i + 1 hi total unique elements honge.


Input:  [1,1,2,2,3,3,4]
i = 0
j = 1 to 6

Step-by-step:
j=1 → arr[1]==arr[0] → skip
j=2 → arr[2]!=arr[0] → i=1, arr[1]=arr[2] → [1,2,...]
j=3 → arr[3]==arr[1] → skip
j=4 → arr[4]!=arr[1] → i=2, arr[2]=arr[4] → [1,2,3,...]
...and so on

Final array: [1,2,3,4,...], return 4



int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;

    int i = 0;
    for(int j = 1; j < n; j++) {
        if(nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // Total number of unique elements
}




| Approach    | Time       | Space | Key Idea                 |
| ----------- | ---------- | ----- | ------------------------ |
| Brute (Set) | O(N log N) | O(N)  | Use Set to store uniques |
| Optimal     | O(N)       | O(1)  | Two pointer technique    |




📚 Extra Notes:
Question ka follow-up hota hai: "Modify array in-place and return the length" — toh tum only length return karte ho, actual array modify ho jata hai.

LeetCode version: Remove Duplicates from Sorted Array
