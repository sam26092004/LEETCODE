class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<long long> diff(s.size(), 0);

        for (int i = 0; i < shifts.size(); i++) {
            diff[shifts[i][0]] += (shifts[i][2] == 1) ? 1 : -1;
            if (shifts[i][1] + 1 < s.size()) 
                diff[shifts[i][1] + 1] += (shifts[i][2] == 1) ? -1 : 1;
        }

        long long cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += diff[i];
            int idx = (s[i] - 'a' + cnt) % 26;
            if (idx < 0)
                idx += 26;
            s[i] = char('a' + idx);
        }

        return s;
    }
};
