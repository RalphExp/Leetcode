class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0; // max
        int c = 0; // current

        for (int i = 1; i < prices.size(); ++i) {
            m += max(0, prices[i] - prices[i-1]);
        }
        return m;
    }
};
