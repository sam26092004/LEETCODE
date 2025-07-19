class Trie {
public:
    char data;
    bool isTerminal;
    vector<Trie*> neighbor;

    Trie(char val) : data(val), isTerminal(false), neighbor(27, nullptr) {}
};
class Solution {
private:
    void insertion(string str, Trie* node, vector<string>& ans) {
        Trie* root = node;
        for (int i = 0; i < str.length(); i++) {

            if (str[i] == '/') {
                if (root->neighbor[26] == nullptr) {
                    root->neighbor[26] = new Trie('/');
                    root = root->neighbor[26];
                    continue;
                } else {
                    root = root->neighbor[26];
                    continue;
                }
            }
            Trie* nextNode = root->neighbor[int(str[i]) - int('a')];
            if (nextNode != nullptr && nextNode->isTerminal &&(i==str.length()-1|| str[i+1]=='/')) {
                return;
            }
            int index = str[i] - 'a';
            if (nextNode == nullptr) {

                root->neighbor[index] = new Trie(str[i]);
            }
            root = root->neighbor[index];
        }
        root->isTerminal = true;
        ans.push_back(str);
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = new Trie('#');
        vector<string> ans;
        sort(folder.begin(), folder.end());

        for (int i = 0; i < folder.size(); i++) {
            insertion(folder[i], root, ans);
        }
        return ans;
    }
};