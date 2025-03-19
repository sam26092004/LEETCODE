class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flag=0,start=0,end=0;
        while (start <= end && end < nums.size()) {
            if (nums[start] == 0) {
                flag++;
                end = start + 2;
                if (end >= nums.size())
                    return -1;
                for (int i = start; i <= end; i++) {
                    nums[i] = nums[i] ^ 1;
                }
            }
            if(nums[start]==1){
                start++;
                end=start;
            }
        }
        return flag;
    }
};