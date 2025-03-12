class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> modulo;

        int cnt = 0;
        for (int i = 0; i < time.size(); i++) {
            int mod = time[i] % 60;
            int remMod = (mod == 0) ? 0 : 60 - mod;

            cnt += modulo[remMod];
            modulo[mod]++;
        }
        return cnt;
    }
};