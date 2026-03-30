class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> map;
        int l = 0;
        for (int r = 0; r < (int)s.length(); r++) {
            map[s[r]]++;
            while (map[s[r]] > 1) {
                map[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};