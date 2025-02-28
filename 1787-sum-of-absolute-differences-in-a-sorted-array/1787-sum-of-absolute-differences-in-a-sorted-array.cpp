class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int prefixSum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
          long long suffixSum = sum - prefixSum;
            ans[i] = (i * nums[i] - prefixSum) + (suffixSum - (n - i) * nums[i]);
            prefixSum += nums[i]; 

        }
        return ans;
    }
};