class Solution {
public:
    int minNumberOperations(vector<int>& diff) {
     
        long long result = 0;
        int prev = 0;

        for (int i = 0; i < diff.size(); i++) {
            if ((prev ^ diff[i]) < 0) {
                result += abs(diff[i]);
            } else if (abs(diff[i]) > abs(prev)) {
                result += (abs(diff[i]) - abs(prev));
            }
            prev = diff[i];
        }
        return result;
    }
};