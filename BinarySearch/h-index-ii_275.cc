class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations[citations.size()-1] == 0)
            return 0;

        int left = 0;
        int right = citations.size()-1;
        int mid;

        while (left < right) {
            mid = (left + right) / 2;
            if (citations[mid] >= citations.size()-mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return citations.size()-right;
    }
};
