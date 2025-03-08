class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 

        vector<int> suffixSum(n + 1, 0);
        int prefixSum = 0;

      
        for (int i = n - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }

      long long cost = LLONG_MAX;
        for (int i = 0; i < n; i++) {
        long long prevCost = (i == 0) ? 0 : (1LL*nums[i] * i) - prefixSum;
        long long nextCost = ((suffixSum[i + 1]) - (1LL*(n - i - 1) * nums[i]));
            cost = min(cost, prevCost + nextCost);

            prefixSum += nums[i]; 
        }

        return cost;
    }
};
