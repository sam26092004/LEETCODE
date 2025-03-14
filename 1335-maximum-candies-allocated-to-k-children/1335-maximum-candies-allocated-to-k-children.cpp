class Solution {
public:
    bool isPossible(int mid, vector<int>& candies, long long k) {
        if (mid == 0)
            return 1;
        for (auto const& candy : candies) {
            int child = 0;

            child = candy / mid;
            k -= child;
            if (k <= 0) {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {

        int maxCandy = *max_element(candies.begin(), candies.end());
        int start = 0, end = maxCandy, ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isPossible(mid, candies, k)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};