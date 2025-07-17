class Solution {
public:
    vector<int> nodes_in_subtree;
    void DFS2(int node, unordered_map<int, list<int>>& adjList, int prev,
              vector<int>& ans,int n) {

        if (prev != -1) {
            ans[node] = ans[prev] + n - 2 * (nodes_in_subtree[node] + 1);
        }
        for (auto const& neighbor : adjList[node]) {
            if (neighbor != prev) {
                DFS2(neighbor, adjList, node, ans,n);
            }
        }
    }
   int  dfs(int node, unordered_map<int, list<int>>& adjList, int prev,
             int dist, vector<int>& distances) {
        distances[node] = dist;
        int nodes = 0;
        for (auto const& neighbor : adjList[node]) {
            if (neighbor != prev) {
                nodes +=
                    (1 + dfs(neighbor, adjList, node, dist + 1, distances));
            }
        }
        return nodes_in_subtree[node] = nodes;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        unordered_map < int, list < int >> adjList;
        nodes_in_subtree.resize(n, 0);
        for (auto const& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> distances(n, 0);
        dfs(0, adjList, -1, 0,distances);
        vector<int> ans(n, 0);
        ans[0] = accumulate(distances.begin(), distances.end(), 0);
        DFS2(0, adjList, -1, ans,n);
        return ans;
    }
};