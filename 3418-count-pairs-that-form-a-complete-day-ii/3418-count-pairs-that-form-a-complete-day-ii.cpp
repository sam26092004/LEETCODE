class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        map<int, int> modulo;
        long long cnt = 0;
        for (auto const& hour : hours) {
            int mod = hour % 24;
            int remMod = (mod == 0) ? 0 : 24 - mod;
            cnt += modulo[remMod];
            modulo[mod]++;
        }
        return cnt;
    }
};