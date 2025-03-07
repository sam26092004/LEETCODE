/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string tmp;

    void makeString(TreeNode* root) {
        if (root == nullptr) {
            tmp += "N ";
            return;
        }

        tmp += to_string(root->val) + " "; 
        makeString(root->left);
        makeString(root->right);
    }

    string serialize(TreeNode* root) {
        tmp = ""; 
        makeString(root);
        return tmp;
    }

    TreeNode* makeTree(string& data, int& idx) {
        if (idx >= data.size())
            return nullptr; 

        if (data[idx] == 'N') {
            idx += 2; 
            return nullptr;
        }

        string s = "";
        while (idx < data.size() && data[idx] != ' ') {
            s.push_back(data[idx++]);
        }
        idx++; 

        TreeNode* Node = new TreeNode(stoi(s));
        Node->left = makeTree(data, idx);
        Node->right = makeTree(data, idx);
        return Node;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return makeTree(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));