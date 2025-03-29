class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);  // Initialize size to 1
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUltimateParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);  // Path compression
    }
    bool unionBySize(int node1, int node2) {
        int ultParent1 = findUltimateParent(node1);
        int ultParent2 = findUltimateParent(node2);

        if (ultParent1 == ultParent2) return false;

        if (size[ultParent1] >= size[ultParent2]) {
            parent[ultParent2] = ultParent1;
            size[ultParent1] += size[ultParent2];
        } else {
            parent[ultParent1] = ultParent2;
            size[ultParent2] += size[ultParent1];
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet AliceDisjointset(n), BobDisjointset(n);
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];  
        });

        int cnt = 0;
        int aliceEdge = 0, bobEdge = 0;

        for (auto const& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            
            if (type == 3) { 
                bool usedByAlice = AliceDisjointset.unionBySize(u, v);
                bool usedByBob = BobDisjointset.unionBySize(u, v);
                if (usedByAlice) aliceEdge++;
                if (usedByBob) bobEdge++;
                if (!usedByAlice && !usedByBob) cnt++;  
            } 
            else if (type == 1) {  
                if (AliceDisjointset.unionBySize(u, v)) aliceEdge++;
                else cnt++;  
            } 
            else { 
                if (BobDisjointset.unionBySize(u, v)) bobEdge++;
                else cnt++;  
            }
        }

        // Check if Alice and Bob each form a spanning tree
        if (aliceEdge < n - 1 || bobEdge < n - 1) return -1;

        return cnt;  // Number of redundant edges removed
    }
};
