class Solution {
public:
    inline bool isSorted(int a, int b) { return a <= b; }

    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return true;
            }
            if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start++;
                end--;
                continue;
            }

            if(isSorted(nums[start],nums[mid])){
                if(target>=nums[start] && target<=nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                if(target>=nums[mid] && target<=nums[end]){
                    start=mid+1;
                }else{
                   end=mid-1;
                }
            }
        }
        return false;
    }
};