class Solution {
public:
    long long calculate(int x) {
        if (x < 0)
            return 0;
        return ((long long)x * (x - 1)) / 2;
    }
    long long distributeCandies(int n, int limit) {
        long long total_distributions = calculate(n + 2);
        return total_distributions - 3 * calculate(n - (limit + 1) + 2) +
               3 * calculate(n - (limit + 1) * 2 + 2) -
               calculate(n - (limit + 1) * 3 + 2);
    }
};