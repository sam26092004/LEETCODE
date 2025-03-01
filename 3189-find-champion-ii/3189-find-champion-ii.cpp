class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (edges.empty()) return (n == 1) ? 0 : -1;

        vector<int> inDegree(n, 0), outDegree(n, 0);

        for (auto& edge : edges) {
            outDegree[edge[0]]++;
            inDegree[edge[1]]++;

            
          
        }

        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                
                if (champion != -1) return -1;
                champion = i;
            }
        }

        return champion;
    }
};
