class Solution {
public:
    static bool cmp(int& a, int& b) { return a > b; }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp);
       int  ans = INT_MIN;

        for (int i = 0; i < citations.size(); i++) {

            if (citations[i] >= i + 1) {
                ans = max(ans, i + 1);
            }
        }
        return (ans==INT_MIN)?0:ans;
    }
};