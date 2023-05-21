class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0; // max
        int c = 0; // current

        for (int i = 1; i < prices.size(); ++i) {
            c += prices[i] - prices[i-1];
            if (c < 0)
                c = 0;
            m = max(m, c); 
        }
        return m;
    }
};
