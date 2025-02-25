class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long prefix = 0;
        long long ans = 0;
        long long evenCount = 1; 
        long long oddCount = 0;
        
        for (int num : arr) {
            prefix += num;
            if (prefix % 2 == 0) {
                ans = (ans + oddCount) % mod;
                evenCount++;
            } else {
                ans = (ans + evenCount) % mod;
                oddCount++;
            }
        }
        return ans;
    }
};
