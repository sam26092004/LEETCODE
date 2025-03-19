class Solution {
public:
    int dp[10][2][10][10][21];
    int beautifulIntegers(int pos, int tight, int evens, int odds,
                          long long sum, vector<int>& nums, int k) {
        if (pos == nums.size()) {
            if (sum == 0)
                return 0;
            return (evens == odds && sum % k == 0) ? 1 : 0;
        }
        if (dp[pos][tight][evens][odds][sum % k] != -1)
            return dp[pos][tight][evens][odds][sum % k];

        int res = 0;
        int limit = (tight) ? nums[pos] : 9;
        for (int digit = 0; digit <= limit; digit++) {
            long long newSum = sum * 10 + digit;
            if (newSum == 0) {
                res += beautifulIntegers(pos + 1, tight & (digit == limit),
                                         evens, odds, newSum, nums, k);
            } else {
                res += beautifulIntegers(pos + 1, tight & (digit == limit),
                                         evens + ((digit % 2 == 0) ? 1 : 0),
                                         odds + ((digit % 2 == 1) ? 1 : 0),
                                         newSum, nums, k);
            }
        }
        return dp[pos][tight][evens][odds][sum % k] = res;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp, -1, sizeof(dp));
        low--;
        vector<int> nums1, nums2;

        while (high > 0) {
            nums1.push_back(high % 10);
            high /= 10;
        }
        while (low > 0) {
            nums2.push_back(low % 10);
            low /= 10;
        }

        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        int x = beautifulIntegers(0, 1, 0, 0, 0, nums1, k);
        memset(dp, -1, sizeof(dp));
        int y = beautifulIntegers(0, 1, 0, 0, 0, nums2, k);
        return x - y;
    }
};
