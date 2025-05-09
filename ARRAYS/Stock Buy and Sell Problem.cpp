📌 Stock Buy and Sell Problem
Problem:
You are given an array prices where prices[i] is the price of a given stock on the i-th day. You are allowed to complete at most one transaction (i.e., buy one and sell one share of the stock). You need to maximize your profit. Return the maximum profit you can achieve. If no profit can be made, return 0.

Example:

Input: prices = [7, 1, 5, 3, 6, 4]

Output: 5 (Buy on day 2 at price 1 and sell on day 5 at price 6, profit = 6 - 1 = 5)

🔍 Pattern:
This is a greedy algorithm problem, where you need to choose the optimal day to buy and sell to maximize the profit.

Brute Force Approach:
Idea: Check all possible pairs of buy and sell days, and calculate the profit for each pair. Track the maximum profit.

Time Complexity: O(n^2) (nested loops for checking every pair of days)

Space Complexity: O(1) (no extra space needed)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    
    // Check all pairs of days to buy and sell
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            max_profit = max(max_profit, prices[j] - prices[i]);
        }
    }
    
    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}


Explanation:

We use two loops: the outer loop picks the day to buy, and the inner loop picks a later day to sell. We compute the profit for each pair and update max_profit if the current profit is greater.

Hindi:
Hum do nested loops ka use karte hain: ek loop buy day ke liye aur dusra loop sell day ke liye. Har pair ka profit nikaal ke max_profit ko update karte hain.

Better Approach:
Idea: Instead of checking all pairs, we can traverse the array once, and as we go, track the minimum price so far and calculate the profit at each step.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (constant space)

C++ Code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int min_price = INT_MAX;
    
    // Traverse the array once
    for (int price : prices) {
        min_price = min(min_price, price);  // Update the minimum price
        max_profit = max(max_profit, price - min_price);  // Calculate profit at each step
    }
    
    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}

Explanation:

We maintain two variables: min_price to track the minimum price encountered so far and max_profit to store the maximum profit found.

As we iterate through the prices, we update min_price if we find a lower price and calculate the potential profit by selling at the current price.

Why better?:

This approach only requires a single pass through the array, reducing the time complexity from O(n^2) to O(n).

Hindi:
Hum ek hi pass mein array ko traverse karte hain. Hum min_price ko update karte hain agar current price se chhota koi price milta hai. Har step pe hum profit nikaalte hain aur max_profit ko update karte hain.

Optimal Approach:
Idea: The better approach itself is already optimal. We can solve this problem in O(n) time and O(1) space.

Time Complexity: O(n) (single pass through the array)

Space Complexity: O(1) (constant space)

Explanation:

This approach is optimal because it only requires one pass over the array and uses constant space, making it the most efficient way to solve the problem.

Hindi:
Yeh approach already optimal hai. Hum O(n) time mein aur constant space mein maximum profit nikaal lete hain.

Summary:
Brute Force:

Time: O(n^2)

Space: O(1)

Explanation: Use two nested loops to check every pair of buy and sell days and compute the maximum profit.

Better (Optimal):

Time: O(n)

Space: O(1)

Explanation: Traverse the array once, keeping track of the minimum price and calculating the potential profit at each step.

Interview Style Explanation:
Pattern: "This is a greedy algorithm problem where we need to track the minimum price encountered so far and calculate the potential profit at each step."

Transition from Brute to Better: "While the brute-force approach checks all possible pairs, it is inefficient for larger arrays. By keeping track of the minimum price in a single pass, we can solve the problem optimally."

