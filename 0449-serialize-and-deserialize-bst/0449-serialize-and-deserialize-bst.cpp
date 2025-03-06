class Codec {
public:
    string tmp = "";
    int idx = 0;

    void construction(TreeNode* root) {
        if (root == nullptr) {
            tmp += "N "; 
            return;
        }
        tmp += to_string(root->val) + " ";
        construction(root->left);
        construction(root->right);
    }

    string serialize(TreeNode* root) {
        tmp = ""; 
        construction(root);
        return tmp;
    }

    TreeNode* deserialize(string data) {
        if (idx >= data.size()) return nullptr;

        if (data[idx] == 'N') {
            idx += 2;  
            return nullptr;
        }

        string num = "";
        while (idx < data.size() && data[idx] != ' ') {
            num.push_back(data[idx++]);
        }
        idx++; 

        TreeNode* node = new TreeNode(stoi(num));
        node->left = deserialize(data);
        node->right = deserialize(data);
        return node;
    }
};
