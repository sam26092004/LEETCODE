class Solution {
public:
    int n;
    vector<int> rating;
    // dpInc[count][prev+1][idx] for increasing sequences
    vector<vector<vector<int>>> dpInc;
    // dpDec[count][prev+1][idx] for decreasing sequences
    vector<vector<vector<int>>> dpDec;
    
    int increasingSeq(int count, int idx, int prev) {
        if (count == 3) return 1;
        if (idx == n) return 0;
        if (dpInc[count][prev + 1][idx] != -1)
            return dpInc[count][prev + 1][idx];
        int take = 0;
        if (prev == -1 || rating[prev] < rating[idx])
            take = increasingSeq(count + 1, idx + 1, idx);
        int notTake = increasingSeq(count, idx + 1, prev);
        return dpInc[count][prev + 1][idx] = take + notTake;
    }
    
    int decreasingSeq(int count, int idx, int prev) {
        if (count == 3) return 1;
        if (idx == n) return 0;
        if (dpDec[count][prev + 1][idx] != -1)
            return dpDec[count][prev + 1][idx];
        int take = 0;
        if (prev == -1 || rating[prev] > rating[idx])
            take = decreasingSeq(count + 1, idx + 1, idx);
        int notTake = decreasingSeq(count, idx + 1, prev);
        return dpDec[count][prev + 1][idx] = take + notTake;
    }
    
    int numTeams(vector<int>& ratingInput) {
        rating = ratingInput;
        n = rating.size();
        dpInc = vector<vector<vector<int>>>(4, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        dpDec = vector<vector<vector<int>>>(4, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        
        int incCount = increasingSeq(0, 0, -1);
        int decCount = decreasingSeq(0, 0, -1);
        return incCount + decCount;
    }
};
