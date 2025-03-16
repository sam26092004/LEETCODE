class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return {};
        vector<int> tmp1(26, 0), tmp2(26, 0);
        for (int i = 0; i < p.size(); i++) {
            int idx = p[i] - 'a';
            tmp1[idx]++;
        }
        for (int i = 0; i < p.size(); i++) {
            int idx = s[i] - 'a';
            tmp2[idx]++;
        }
        int start = 0;
        vector<int> ans;
        for (int j = p.size(); j < s.size(); j++) {
            if (tmp1 == tmp2) {
                ans.push_back(start);
            }
            int idx = s[start++] - 'a';
            tmp2[idx]--;
            idx = s[j] - 'a';
            tmp2[idx]++;
        }
        if (tmp1 == tmp2)
            ans.push_back(start);
        return ans;
    }
};