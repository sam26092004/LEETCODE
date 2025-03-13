class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> differenceArray(nums.size(), 0);

        for (auto const& query : queries) {
            differenceArray[query[0]]--;
            if (query[1] + 1 < nums.size())
                differenceArray[query[1] + 1]++;
        }
        int flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            flag += differenceArray[i];
            if (nums[i] != 0)
                nums[i] += flag;
        }
        if (all_of(nums.begin(), nums.end(), [](int x) { return x <= 0; }))
            return true;

        return false;
    }
};