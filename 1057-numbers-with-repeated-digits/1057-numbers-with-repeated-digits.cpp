class Solution {
public:
    int dp[10][2][1024];

    int countUniqueDigitNumbers(int pos, vector<int>& nums, int tight,
                                int bitmask) {
        if (pos == nums.size())
            return (bitmask == 0) ? 0 : 1;

        if (dp[pos][tight][bitmask] != -1)
            return dp[pos][tight][bitmask];

        int res = 0;
        int limit = (tight) ? nums[pos] : 9;

        for (int digit = 0; digit <= limit; digit++) {
            if((bitmask & (1<<digit))==0){
                if (bitmask == 0 && digit == 0) {
                    res += countUniqueDigitNumbers(
                        pos + 1, nums, tight & (digit == limit), bitmask);
                } else {
                    res += countUniqueDigitNumbers(pos + 1, nums,
                                                   tight & (digit == limit),
                                                   bitmask | (1 << digit));
                }
            }
        }

        return dp[pos][tight][bitmask] = res;
    }

    int numDupDigitsAtMostN(int N) {
        vector<int> nums;
        int n = N;

        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());

        memset(dp, -1, sizeof(dp));

        int uniqueNumbers = countUniqueDigitNumbers(0, nums, 1, 0);
        return N - uniqueNumbers;
    }
};
