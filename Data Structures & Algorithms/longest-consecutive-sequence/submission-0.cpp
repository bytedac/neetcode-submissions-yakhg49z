class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());
        for (int num : store) {
            if (store.find(num - 1) == store.end()) {
                int length = 1;
                while (store.find(num + length) != store.end()) {
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};