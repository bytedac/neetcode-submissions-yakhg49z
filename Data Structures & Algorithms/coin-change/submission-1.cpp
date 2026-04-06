class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);  // 凑出amount所需的最少coin数
        dp[0]=0;  

        // coins = {1, 5, 10}, amount = 11;
        for (int i = 1; i <= amount; i++) {
            // 最后用这枚硬币
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};