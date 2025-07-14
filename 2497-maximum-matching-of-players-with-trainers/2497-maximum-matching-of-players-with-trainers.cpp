class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int flag1 = 0, flag2 = 0;
        while (flag1 < players.size() && flag2 < trainers.size()) {
            if (players[flag1] <= trainers[flag2]) {
                flag1++;
                flag2++;
            }else{
                flag2++;
            }
        }
        return flag1;
    }
};