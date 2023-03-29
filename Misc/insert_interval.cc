/* LC: 57*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        // newInterval is the only one to return
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }

        // first insert those less than newInterval and not intersect
        int i;
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0])
                result.push_back(intervals[i]);
            else
                break;
        }

        // case1: newInterval is the largest one
        // newInterval[0] > intervals[size-1][1] 
        if (i == intervals.size()) {
            result.push_back(newInterval);
            return result;
        }

        // case2: newInterval lies in the middle of 2 other intervals
        // see if interval[i] intersect newInterval
        if (intervals[i][0] > newInterval[1]) {
            // not intersect
            result.push_back(newInterval);
            for (; i < intervals.size(); ++i)
                result.push_back(intervals[i]);
            return result;
        }

        // intervals[i][0] <= newInterval[1]
        // case 3: newInterval intersect interval[i]
        vector<int> v{0, 0};
        v[0] = min(intervals[i][0], newInterval[0]);

        int j = i + 1;
        for (; j < intervals.size(); ++j) {
            if (intervals[j][0] > newInterval[1])
                break;
        }

        v[1] = max(newInterval[1], intervals[j-1][1]);
        result.push_back(v);

        for (; j < intervals.size(); ++j) {
            result.push_back(intervals[j]);
        }

        return result;
    }
};
