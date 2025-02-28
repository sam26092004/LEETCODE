class Solution {
public:
    inline bool isSorted(int a, int b) { return a <= b; }
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            ans = min(ans, nums[mid]);
            if (nums[mid] == nums[start] && nums[end] == nums[mid]) {
                start++;
                end--;
                continue;
            }

            if (isSorted(nums[start], nums[mid])) {
                ans = min(ans, nums[start]);
                start = mid + 1;
            } else {
                ans = min(ans, nums[mid + 1]);
                end = mid - 1;
            }
        }
        return ans;
    }
};