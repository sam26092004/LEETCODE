class disjointSet {
public:
    vector<int> parent;
    disjointSet() {
        parent.resize(26);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    void unionByPriority(int u, int v) {
        int ultimateParent1 = findUltimateParent(u);
        int ultimateParent2 = findUltimateParent(v);
        if (ultimateParent1 == ultimateParent2)
            return;
      
        if (ultimateParent1 < ultimateParent2) {
            parent[ultimateParent2] = ultimateParent1;
        } else {
            parent[ultimateParent1] = ultimateParent2;
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        disjointSet ds;
        
        for (int i = 0; i < s1.size(); i++) {
            ds.unionByPriority(s1[i] - 'a', s2[i] - 'a');
        }

        string tmp = "";
        for (char alpha : baseStr) {
            int root = ds.findUltimateParent(alpha - 'a');
            tmp.push_back(root + 'a');
        }

        return tmp;
    }
};
