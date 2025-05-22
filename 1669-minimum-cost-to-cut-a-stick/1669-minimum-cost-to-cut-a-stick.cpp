class Solution {
public:
    vector<vector<int>> memo;
    vector<int> cuts;

    int partitionDp(int start, int end) {
        if (start > end) return 0;

        if (memo[start][end] != -1) return memo[start][end];

        int ans = INT_MAX;

        for (int i = start; i <= end; i++) {
            int cost = cuts[end + 1] - cuts[start - 1]; 
            int left = partitionDp(start, i - 1);
            int right = partitionDp(i + 1, end);
            ans = min(ans, cost + left + right);
        }

        return memo[start][end] = ans;
    }

    int minCost(int n, vector<int>& inputCuts) {
        cuts = inputCuts;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        memo.assign(m, vector<int>(m, -1));

        return partitionDp(1, m - 2);
    }
};
