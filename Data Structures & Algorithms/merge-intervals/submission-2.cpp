class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (auto &it : intervals) {
            if (!res.empty() && res.back()[1] < it[0]) {
                res.push_back(it);
            } else {
                res.back()[1] = max(it[1], res.back()[1]);
            }
        }
        return res;
    }
};