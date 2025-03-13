class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> differenceArray(n + 1, 0);
        for (auto const& booking : bookings) {
            differenceArray[booking[0] - 1] += booking[2];
            differenceArray[booking[1]] -= booking[2];
        }
        int flag = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            flag += differenceArray[i];
            ans.push_back(flag);
        }
        return ans;
    }
};