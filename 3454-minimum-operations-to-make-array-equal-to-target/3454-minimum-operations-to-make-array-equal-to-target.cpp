class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long result = 0;
        int prev = 0;
        vector<int> diff;
        for (int i = 0; i < nums.size(); i++) {
            diff.push_back(target[i] - nums[i]);
        }
        for (int i = 0; i < diff.size(); i++) {
            if ((prev ^ diff[i]) < 0) {
                result+=abs(diff[i]);
            }else if(abs(diff[i])>abs(prev)){
                result+=(abs(diff[i])-abs(prev));
            }
            prev=diff[i];
        }
        return result;
    }
};