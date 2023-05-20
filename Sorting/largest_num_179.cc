class Solution {
public:

    static bool special_compare(const string& s1, const string& s2) {
        int i = 0;
        while (i < min(s1.size(), s2.size())) {
            if (s1[i] > s2[i])
                return true;
            if (s1[i] < s2[i])
                return false;
            ++i;
        }

        if (i == s1.size()) {
            if (i == s2.size()) 
                /* if 2 strings are equal, always return false 
                 * (otherwise std::sort will get error) */
                return false;

            return special_compare(s1, s2.substr(i));
        }
        return special_compare(s1.substr(i), s2);
    }


    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto n : nums) {
            v.push_back(to_string(n));
        }

        sort(v.begin(), v.end(), special_compare);

        string res = "";
        if (v[0] == "0")
            return "0";

        for (auto &s : v) {
            res += s;
        }
        return res;
    }
};
