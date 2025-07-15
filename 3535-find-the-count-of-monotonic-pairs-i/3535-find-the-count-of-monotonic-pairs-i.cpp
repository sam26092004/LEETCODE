class Solution {
public:
    int MOD = 1e9 + 7;
    int maxNum; 
    vector<vector<vector<int>>> dp;

    int generateArrays(vector<int>& nums, int idx, int prev1, int prev2) {
        if (idx == nums.size()) return 1;

       
        int p2 = (prev2 == INT_MAX) ? maxNum + 1 : prev2;

        if (dp[idx][prev1][p2] != -1)
            return dp[idx][prev1][p2];

        int arrays = 0;
        for (int i = prev1; i <= nums[idx]; i++) {
            if (i >= prev1 && nums[idx] - i <= prev2) {
                arrays = (arrays + generateArrays(nums, idx + 1, i, nums[idx] - i)) % MOD;
            }
        }

        return dp[idx][prev1][p2] = arrays;
    }

    int countOfPairs(vector<int>& nums) {
        maxNum = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        
        dp.assign(n + 1, vector<vector<int>>(maxNum + 1, vector<int>(maxNum + 2, -1)));

        return generateArrays(nums, 0, 0, INT_MAX);
    }
};
