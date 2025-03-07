class Solution {
public:
    long long maxPoints(int idx, vector<vector<int>>& questions,
                        vector<long long>& dp) {
        if (idx >= questions.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        long long take = 0;
        take = questions[idx][0] + maxPoints(idx + questions[idx][1] + 1, questions, dp);

       long long notTake = maxPoints(idx + 1, questions, dp);
        return dp[idx] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        return maxPoints(0,questions,dp);
    }
};