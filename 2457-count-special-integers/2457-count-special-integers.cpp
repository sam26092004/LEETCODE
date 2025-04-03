class Solution {
public:
string str;

    int numbersWithUniqueDigits(int idx, int bitmask, int tight, vector<vector<vector<int>>>& dp) {
        if (idx == str.size())
            return 1; 
        
        if (dp[idx][tight][bitmask] != -1)
            return dp[idx][tight][bitmask];

        int limit = (tight) ? str[idx] - '0' : 9;
        int count = 0;

        for (int digit = 0; digit <= limit; digit++) {
            if (bitmask == 0 && digit == 0)
                count += numbersWithUniqueDigits(idx + 1, bitmask, tight && (digit == limit), dp);
            else if ((bitmask & (1 << digit)) == 0) {
                count += numbersWithUniqueDigits(idx + 1, bitmask | (1 << digit), tight && (digit == limit), dp);
            }
        }

        return dp[idx][tight][bitmask] = count;
    }

    int countSpecialNumbers(int n) {
       
        str = to_string(n);

        vector<vector<vector<int>>> dp(str.size(), vector<vector<int>>(2, vector<int>(1024, -1)));
        return numbersWithUniqueDigits(0, 0, 1, dp)-1;
        
    }
};