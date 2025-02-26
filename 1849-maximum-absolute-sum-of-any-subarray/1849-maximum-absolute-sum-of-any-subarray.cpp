class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN;
        int sum = 0;
        int maxPositive = 0;
        int minNegative = 0;
        for (auto num : nums) {
            sum += num;
            if (sum > 0) {
                ans=max(ans,sum-minNegative);
                maxPositive=max(sum,maxPositive);
            }else{
                ans=max(ans,abs(sum-maxPositive));
                minNegative=min(minNegative,sum);
            }
        }
        return ans;
    }
};