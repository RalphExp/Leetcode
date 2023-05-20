class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        int i = 0;
        while (i < nums.size()-2) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                // printf("i: %d, j: %d, k: %d\n", i, j, k);

                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == 0) {
                    // printf("found[X]: i: %d, j: %d, k: %d\n", i, j, k);
                    res.push_back({nums[i], nums[j], nums[k]});
                } 
                
                if (tmp <= 0) {
                    do ++j; while (nums[j] == nums[j-1] && j < k);
                } else {
                    do --k; while (nums[k] == nums[k+1] && j < k);
                }
            }
            do ++i; while (nums[i] == nums[i-1] && i < nums.size()-2);
        }
        return res;
    }
};
