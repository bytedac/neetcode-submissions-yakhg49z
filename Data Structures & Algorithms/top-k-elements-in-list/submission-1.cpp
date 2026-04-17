class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        // num, times
        for (int n : nums) freq[n]++;
        vector<vector<int>> vec(nums.size() + 1);
        for (auto& f : freq) {
            vec[f.second].push_back(f.first);
        }
        vector<int> res;
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : vec[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};