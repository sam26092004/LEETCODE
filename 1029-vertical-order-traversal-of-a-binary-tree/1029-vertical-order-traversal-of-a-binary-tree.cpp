/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first || ( a.first == b.first && a.second<b.second);
    }
    void traversal(TreeNode* root, int dist, int level,
                   map<int, vector<pair<int, int>>>& distances) {
        if (root == nullptr)
            return;
        traversal(root->left, dist - 1, level + 1, distances);
        distances[dist].push_back({level, root->val});
        traversal(root->right, dist + 1, level + 1, distances);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> tmp;
        map<int, vector<pair<int, int>>> distances;
        traversal(root, 0, 0, distances);
        for (auto dist : distances) {
            vector<pair<int, int>> nodes = dist.second;
            sort(nodes.begin(), nodes.end(), cmp);
            for (auto const& node : nodes) {
                tmp.push_back(node.second);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};