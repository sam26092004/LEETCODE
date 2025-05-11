class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        unordered_map<int, list<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            adjList[from].push_back({to, weight});
        }

        int ans = INT_MIN;
        queue<tuple<int, int, int>> q; // node, totalWeight, edgesUsed
        set<tuple<int, int, int>> visited;

        // Initialize queue with all nodes
        for (int i = 0; i < n; ++i) {
            q.push({i, 0, 0});
            visited.insert({i, 0, 0});
        }

        while (!q.empty()) {
            auto [node, totalWeight, edgesUsed] = q.front();
            q.pop();

            if (edgesUsed == k && totalWeight < t) {
                ans = max(ans, totalWeight);
                continue;
            }

            if (edgesUsed < k) {
                for (const auto& [nextNode, edgeWeight] : adjList[node]) {
                    int newWeight = totalWeight + edgeWeight;
                    int newEdgesUsed = edgesUsed + 1;

                    if (newWeight < t) {
                        auto newState = make_tuple(nextNode, newWeight, newEdgesUsed);
                        if (visited.find(newState) == visited.end()) {
                            q.push(newState);
                            visited.insert(newState);
                        }
                    }
                }
            }
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};
