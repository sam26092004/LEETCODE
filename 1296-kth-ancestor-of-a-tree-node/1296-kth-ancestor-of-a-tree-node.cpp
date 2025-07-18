class TreeAncestor {
public:
    int rows;
    vector<vector<int>> ancestors;
    unordered_map<int, list<int>> adjList;

    TreeAncestor(int n, vector<int>& parent) {
        
        this->rows = ceil(log2(n));
        ancestors.assign(rows + 1, vector<int>(n, -1));

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) continue;
            adjList[parent[i]].push_back(i); 
        }
        buildTable(0,-1);
    }

    void buildTable(int node, int parent) {
        ancestors[0][node] = parent;

      
        for (int i = 1; i <= rows; i++) {
            int prev = ancestors[i - 1][node];
            if (prev != -1)
                ancestors[i][node] = ancestors[i - 1][prev];
        }

        
        for (auto const& child : adjList[node]) {
            buildTable(child, node);
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = rows; i >= 0; i--) {
            if (k & (1 << i)) {
                if (node == -1) break; 
                node = ancestors[i][node];
            }
        }
        return node;
    }
};
