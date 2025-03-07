class Solution {
public:
    int mod = 1e9 + 7;

    int possibleArrays(int idx, string& s, int k, vector<int>& dp) {
        if (idx == s.size())
            return 1;
        if (dp[idx] != -1)
            return dp[idx];
        if (s[idx] == '0')
            return 0;  

        long long num = 0; 
        int ways = 0;

        for (int i = idx; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');  
            if (num > k) break; 

            ways = (ways + possibleArrays(i + 1, s, k, dp)) % mod;
        }

        return dp[idx] = ways;
    }

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        return possibleArrays(0, s, k, dp);
    }
};
