class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        if (nums.size() == 1)
            return 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1])
                continue;
            else {

                operations += abs(nums[i] - nums[i - 1]) + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        int n = nums.size() - 1;
        if (nums[n] <= nums[n - 1]) {

            operations += abs(nums[n] - nums[n - 1]) + 1;
        }
        return operations;
    }
};