class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for (auto i : nums) {
            tmp ^= i;
        }

        /* now we get a^b and tmp must not be 0 */
        /* get the highest bit of a^b */
        unsigned int h = (1 << 31);
        while (!(tmp & h)) {
            h >>= 1;
        }

        int tmp2 = 0;
        for (auto i : nums) {
            if (i & h)
                tmp2 ^= i;
        }
        return vector{tmp2, tmp2^tmp};
    }
};
