class Solution {
public:
    int n;
    vector<int> rating;
    // dp[dir][count][prev+1][idx], where dir 0 = increasing, 1 = decreasing.
    vector<vector<vector<vector<int>>>> dp;
    
    int countTeams(int count, int idx, int prev, bool inc) {
        if (count == 3) return 1;
        if (idx == n) return 0;
        int d = inc ? 0 : 1;
        if (dp[d][count][prev + 1][idx] != -1)
            return dp[d][count][prev + 1][idx];
        int take = 0;
        if (prev == -1 || (inc ? rating[prev] < rating[idx] : rating[prev] > rating[idx]))
            take = countTeams(count + 1, idx + 1, idx, inc);
        int skip = countTeams(count, idx + 1, prev, inc);
        return dp[d][count][prev + 1][idx] = take + skip;
    }
    
    int numTeams(vector<int>& ratingInput) {
        rating = ratingInput;
        n = rating.size();
        dp = vector<vector<vector<vector<int>>>>(2, 
             vector<vector<vector<int>>>(4, 
             vector<vector<int>>(n + 1, vector<int>(n + 1, -1))));
        return countTeams(0, 0, -1, true) + countTeams(0, 0, -1, false);
    }
};
