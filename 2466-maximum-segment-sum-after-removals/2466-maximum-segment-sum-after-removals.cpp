class DisjointSet {
public:
    vector<long long> parent, sum;
    long long maxSum = 0;

    DisjointSet(int n, vector<int>& nums) {
        parent.resize(n);
        sum.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sum[i] = 0; 
        }
    }

    int findUltimateParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int node1, int node2) {
        int ultP1 = findUltimateParent(node1);
        int ultP2 = findUltimateParent(node2);

        if (ultP1 == ultP2)
            return;

        if (sum[ultP1] >= sum[ultP2]) {
            parent[ultP2] = ultP1;
            sum[ultP1] += sum[ultP2];
            maxSum = max(maxSum, static_cast<long long>(sum[ultP1]));
        } else {
            parent[ultP1] = ultP2;
            sum[ultP2] += sum[ultP1];
            maxSum = max(maxSum, static_cast<long long>(sum[ultP2]));
        }
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        DisjointSet disjointset(n, nums);
        unordered_map<int, bool> isAlive;
        vector<long long> ans(n, 0);

        
        for (int i = 0; i < n; i++) {
            isAlive[i] = false;
            disjointset.sum[i] = 0;  
        }

      
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = disjointset.maxSum; 

            int node = removeQueries[i];
            isAlive[node] = true;
            disjointset.sum[node] = nums[node];
            disjointset.maxSum = max(disjointset.maxSum, static_cast<long long>(nums[node])); 

           
            if (node - 1 >= 0 && isAlive[node - 1]) {
                disjointset.unionBySize(node, node - 1);
            }
            if (node + 1 < n && isAlive[node + 1]) {
                disjointset.unionBySize(node, node + 1);
            }
        }

        return ans;
    }
};
