class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() != 2) {
            string tmp = "";
            for (int i = 0; i < s.size() - 1; i++) {
                int k = (s[i] - '0' + s[i + 1] - '0') % 10;
                tmp.push_back(k + '0');
            }
            s=tmp;
        }
        return s[0]==s[1];
    }
};