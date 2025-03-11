/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr){
            return {};
        }
        queue<Node*> nodes;
        nodes.push(root);
        nodes.push(nullptr);
        vector<vector<int>> ans;
        vector<int> tmp;

        while (!nodes.empty()) {
            Node* top = nodes.front();
            nodes.pop();
            if (top == nullptr) {
                ans.push_back(tmp);
                if (!nodes.empty()) {
                    nodes.push(nullptr);
                    tmp.clear();
                }
                continue;
            }
            tmp.push_back(top->val);
            for (auto const& child : top->children) {
                nodes.push(child);
            }
        }
        return ans;
    }
};