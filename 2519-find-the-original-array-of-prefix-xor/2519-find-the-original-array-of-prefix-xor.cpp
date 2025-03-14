class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n, 0);
        pref.insert(pref.begin(), 0);

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = pref[i+1] ^ pref[i];
        }

        return ans;
    }
};