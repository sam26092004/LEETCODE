class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<long long> diff(s.size(), 0);
        
        for (int i = 0; i < shifts.size(); i++) {
            diff[0] += shifts[i];
            if (i + 1 < shifts.size()) 
                diff[i + 1] -= shifts[i];
        }

        long long cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt += diff[i];
            int idx = (s[i] - 'a' + cnt) % 26; 
            if (idx < 0) idx += 26; 
            s[i] = char('a' + idx); 
        }
        
        return s;
    }
};
