class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<int> lis;
        for (const auto& envelope : envelopes) {
            int height = envelope[1];
            auto it = lower_bound(lis.begin(), lis.end(), height);
            if (it == lis.end()) {
                lis.push_back(height); 
            } else {
                *it = height; 
            }
        }
        return lis.size();
    }
};