/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
// #include<vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n==0) return 0;
        vector<int> small(n);
        vector<int> large(n);
        small[0] = prices[0];
        for (int i = 1; i < n; i++)
        {
            small[i] = min(small[i-1],prices[i]);
            /* code */
        }
        large[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i-- ){
            large[i] = max(large[i+1], prices[i]);
        }

        int maxProfit  = 0;
        for(int i = 0; i < n; i++){
            maxProfit = max(maxProfit, large[i]-small[i]);
        }

        return maxProfit;
        
    }
};
// @lc code=end

