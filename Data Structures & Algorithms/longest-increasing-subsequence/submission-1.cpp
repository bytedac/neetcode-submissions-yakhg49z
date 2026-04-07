class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            // find first element >= num in tails
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {   // didnt find 
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};