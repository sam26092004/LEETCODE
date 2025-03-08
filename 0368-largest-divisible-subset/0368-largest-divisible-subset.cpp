class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();

       
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

      
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int prev = idx - 1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || nums[idx] % nums[prev] == 0) {
                    take = 1 + dp[idx + 1][idx + 1]; 
                }
                int notTake = dp[idx + 1][prev + 1];
                dp[idx][prev + 1] = max(take, notTake);
            }
        }

       
        vector<int> result;
        int idx = 0, prev = -1;

        while (idx < n) {
            if ((prev == -1 || nums[idx] % nums[prev] == 0) &&
                dp[idx][prev + 1] == 1 + dp[idx + 1][idx + 1]) {
                result.push_back(nums[idx]);
                prev = idx;
            }
            idx++;
        }

        return result;
    }
};
