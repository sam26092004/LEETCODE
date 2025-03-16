class Solution {
public:
    bool isPossible(long long time, vector<int>& ranks, int n) {
        for (int rank : ranks) {
            long long cars = sqrt(time / rank);
            n -= cars;
            if (n <= 0) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        long long maxRank =ranks.back();
        long long maxTime = maxRank * (long long) cars * cars; 

        long long start = 0, end = maxTime, ans = -1;
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            if (isPossible(mid, ranks, cars)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
