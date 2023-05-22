class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;

        unordered_map<int, int> hash;
        int i = 0;
        
        for (; i < min<int>(k, nums.size()); i++) {
            if (hash.count(nums[i]))
                return true;
            hash[nums[i]] = i;
        }

        for (; i < nums.size(); ++i) {
            if (hash.count(nums[i]))
                return true;

            auto it = hash.find(nums[i-k]);
            if (it != hash.end() && it->second == i-k) {
                hash.erase(it);
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
