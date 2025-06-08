class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<string> numToString;
        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            numToString.push_back(to_string(i));
        }
        sort(numToString.begin(), numToString.end());
        for (int i = 0; i < numToString.size(); i++) {
            ans.push_back(stoi(numToString[i]));
        }

        return ans;
    }
};