class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> costs(26, vector<int>(26, INT_MAX));
        
        for (int i = 0; i < changed.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            costs[from][to] = min(costs[from][to], cost[i]);
        }
        
        for (int i = 0; i < 26; ++i) costs[i][i] = 0;
        
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (costs[i][k] != INT_MAX && costs[k][j] != INT_MAX)
                        costs[i][j] = min(costs[i][j], costs[i][k] + costs[k][j]);
                }
            }
        }

        long long sum = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (from == to) continue;
            if (costs[from][to] == INT_MAX) return -1;
            sum += costs[from][to];
        }

        return sum;
    }
};
