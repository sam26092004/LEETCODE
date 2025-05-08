class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> sequence;
        for (int i = 0; i < nums.size(); i++) {
            if (sequence.empty() || sequence.back() < nums[i]) {
                sequence.push_back(nums[i]);
            } else {
                auto it =
                    lower_bound(sequence.begin(), sequence.end(), nums[i]);
                    *it=nums[i];
            }
        }
        return (sequence.size()>=3)?true:false;
    }
};