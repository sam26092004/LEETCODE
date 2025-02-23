/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(root==nullptr) return root;
        queue<Node*>nodes;
        nodes.push(root);
        nodes.push(nullptr);
        while(!nodes.empty()){
            Node* top=nodes.front();
            nodes.pop();
            if(top==nullptr){
                if(!nodes.empty()){
                    nodes.push(nullptr);
                }
            }else{
                top->next=nodes.front();
                if(top->left!=nullptr){
                  nodes.push(top->left);
                }
                if(top->right!=nullptr){
                    nodes.push(top->right);
                }
            }
        }
        return root;
        
    }
};