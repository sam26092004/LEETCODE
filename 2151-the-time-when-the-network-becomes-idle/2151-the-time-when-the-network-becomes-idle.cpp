class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        unordered_map<int, list<int>> adjList;

      
        for (auto const& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        
        vector<int> timing(n, 0);
        vector<bool> visited(n, false);
        queue<pair<int, int>> nodes;
        nodes.push({0, 0});

        while (!nodes.empty()) {
            auto [top, time] = nodes.front();
            nodes.pop();
            timing[top] = time;
            visited[top] = true;
            for (auto const& neighbor : adjList[top]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    nodes.push({neighbor, time + 1});
                }
            }
        }

        
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int totalTime = 2 * timing[i]; 
            int lastSentTime = (totalTime - 1) / patience[i] * patience[i];
            ans = max(ans, totalTime + lastSentTime);
        }

        return ans + 1;  
    }
};
