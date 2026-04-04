class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c: t) {
            countT[c]++;
        }

        int resLen = INT_MAX;
        int have = 0, l = 0, res = -1, need = countT.size();
        for (int r = 0; r < s.length(); r++) {
            window[s[r]]++;
            if (countT.count(s[r]) && window[s[r]] == countT[s[r]]) {
                have++;
            }

            while (have == need) {
                if (resLen > (r - l + 1)) {
                    resLen = r - l + 1;
                    res = l;
                }
                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res, resLen);
    }
};