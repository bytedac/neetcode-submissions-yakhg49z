class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0], res = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i] + max(curr, 0);
            res = max(res, curr);
        }

        return res;
    }
};