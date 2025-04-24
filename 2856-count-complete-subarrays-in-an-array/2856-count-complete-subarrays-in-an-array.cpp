class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int start = 0;
        int cnt = 0;
        unordered_map<int, int> freq;

        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            while (freq.size() > k) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);
                }
                start++;
            }
            cnt += (end - start + 1);
        }
        return cnt;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        return atMostKDistinct(nums, totalDistinct) - atMostKDistinct(nums, totalDistinct - 1);
    }
};
