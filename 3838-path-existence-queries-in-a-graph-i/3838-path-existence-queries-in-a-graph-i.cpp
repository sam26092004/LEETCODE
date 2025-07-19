class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltimateParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int node1, int node2) {
        int ult1 = findUltimateParent(node1);
        int ult2 = findUltimateParent(node2);

        if (ult1 == ult2) {
            return;
        } else if (size[ult1] > size[ult2]) {
            parent[ult2] = ult1;
            size[ult1] += size[ult2];
        } else {
            parent[ult1] = ult2;
            size[ult2] += size[ult1];
        }
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<bool> ans;
        DisjointSet ds(n);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                ds.unionBySize(i, i - 1);
            }
        }
        for (auto const& query : queries) {
            if (ds.findUltimateParent(query[0]) ==
                ds.findUltimateParent(query[1])) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};