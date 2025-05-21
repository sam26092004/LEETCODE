class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        unordered_map<int, list<int>> adjList;
        vector<int> degree(n, 0);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
                visited[i] = 1;
            }
        }

        int remaining = n;
        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;
            for (int i = 0; i < sz; ++i) {
                int top = q.front(); q.pop();
                for (auto const& neighbor : adjList[top]) {
                    if (!visited[neighbor]) {
                        degree[neighbor]--;
                        if (degree[neighbor] == 1) {
                            q.push(neighbor);
                            visited[neighbor] = 1;
                        }
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
