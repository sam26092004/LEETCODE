class Solution {
public:
    void generateSubsequence(int prev, int idx, set<vector<int>>& ans,
                             vector<int>& tmp, vector<int>& nums) {
        if (idx == nums.size()) {
            if (tmp.size() > 1) {
                ans.insert(tmp);
            }
            return;
        }
        if (nums[idx] >= prev) {
            tmp.push_back(nums[idx]);
            generateSubsequence(nums[idx], idx + 1, ans, tmp, nums);
            tmp.pop_back();
        }
        
        generateSubsequence(prev, idx + 1, ans, tmp, nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int prev = INT_MIN;
        set<vector<int>> ans;
        vector<int> tmp;
        generateSubsequence(prev, 0, ans, tmp, nums);
        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};