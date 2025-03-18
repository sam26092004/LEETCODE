class Solution {
public:
    void nullify(vector<int>& bits, int nums) {
        for (int i = 0; i < 32; i++) {
            if (nums & (1 << i)) {
                bits[i]--;
            }
        }
    }
    void modify(vector<int>& bits, int nums) {
        for (int i = 0; i < 32; i++) {
            if (nums & (1 << i)) {
                bits[i]++;
            }
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bits(32, 0);
        int ans = -1;
        int start = 0, end = 0;
        while (end < nums.size()) {
            modify(bits, nums[end++]);
            while (start < end && !all_of(bits.begin(), bits.end(),
                                          [](int x) { return x <= 1; })) {
                nullify(bits, nums[start++]);
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};