class Solution {
private:
    int calculateWords(char letter, int t,vector<vector<int>>&dp) {
        int transitions = int('z') - int(letter) + 1;
        if (t < transitions) {
            return 1;
        }
        
        int index=int(letter)-int('a');
        if(dp[index][t]!=-1){
            return dp[index][t];
        }
       
        int left = calculateWords('a', t - transitions,dp);
        int right = calculateWords('b', t - transitions,dp);

       
        return dp[index][t]=(left + right)%1000000007;
    }

 public:
    int lengthAfterTransformations(string s, int t) {
        int words = 0;
        vector<vector<int>>dp(26,vector<int>(t+1,-1));
        for (int i = 0; i < s.length(); i++) {
            words =(words+ calculateWords(s[i], t,dp))%1000000007;
        }
        return words;
    }
};