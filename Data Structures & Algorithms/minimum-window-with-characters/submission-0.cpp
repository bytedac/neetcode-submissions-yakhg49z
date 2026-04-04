class Solution {
public:
  string minWindow(string s, string t) {
    if (t.empty())
      return "";

    unordered_map<char, int> countT, window;
    for (char c : t) {
      countT[c]++;
    }

    int have = 0, need = countT.size();
    // 记录l和r的index
    pair<int, int> res = {-1, -1};
    int resLen = INT_MAX;
    int l = 0;

    for (int r = 0; r < s.length(); r++) {
      char c = s[r];
      window[c]++;

      // 如果window里这个char的size和countT中符合，说明这个char符合
      if (countT.count(c) && window[c] == countT[c]) {
        have++;
      }

      // 当所有char都符合后
      while (have == need) {
        if ((r - l + 1) < resLen) {
          resLen = r - l + 1;
          res = {l, r};
        }

        window[s[l]]--;
        if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
          have--;
        }
        l++;
      }
    }

    return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
  }
};