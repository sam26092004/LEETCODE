class Solution {
public:
    vector<int> partitionDp(string& expression, int start, int end,
                            unordered_map<string, vector<int>>& dp) {
        string key = to_string(start) + "," + to_string(end); 
        
        if (dp.find(key) != dp.end()) 
            return dp[key];

     
        string subExp = expression.substr(start, end - start + 1);
        if (all_of(subExp.begin(), subExp.end(), ::isdigit)) 
            return {stoi(subExp)}; 
        vector<int> ans;

        
        for (int idx = start; idx <= end; idx++) {
            if (expression[idx] == '+' || expression[idx] == '-' || expression[idx] == '*') {
                vector<int> left = partitionDp(expression, start, idx - 1, dp);
                vector<int> right = partitionDp(expression, idx + 1, end, dp);

                for (auto const& l : left) {
                    for (auto const& r : right) {
                        switch (expression[idx]) {
                            case '+': ans.push_back(l + r); break;
                            case '-': ans.push_back(l - r); break;
                            case '*': ans.push_back(l * r); break;
                        }
                    }
                }
            }
        }

        return dp[key] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> dp; 
        return partitionDp(expression, 0, expression.size() - 1, dp);
    }
};
