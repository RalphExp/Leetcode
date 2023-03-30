/* LC 322: Solution1 */
class Solution1 {
public:
    void coinChange(vector<int>& coins, int cur, int idx, int amount) {
        if (idx >= coins.size())
            return;

        if (coins[idx] == amount) {
            min_ = min(min_, cur+1);
            return;
        }

        // try to prune the searching branch
        if (min_ > cur) {
            // #case1 skip the current value, also 
            coinChange(coins, cur+1, idx, amount-coins[idx]);
            // #case2 choose the current value
            coinChange(coins, cur, idx+1, amount);
        }  
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        sort(coins.begin(), coins.end(), std::greater<int>());
        min_ = amount + 1;
        coinChange(coins, 
            0/* cur */, 
            0/* index*/,
            amount);
        return min_ == amount + 1 ? -1 : min_;
    }

private:
    int min_;
};

/* Solution2: DP base on the amount!!! */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount)
            return 0;

        vector<long> dp(amount+1, 0x7fffffff /*INT_MAX*/);
        dp[0] = 0;

        for (int i = 0; i < dp.size(); ++i) {
            int tmp = dp[i];
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0) {
                    tmp = min<long>(tmp, 1 + dp[i-coins[j]]);
                }
            }
            dp[i] = tmp;
        } 

        return dp[amount] == 0x7fffffff ? -1 : dp[amount];
    }
};
