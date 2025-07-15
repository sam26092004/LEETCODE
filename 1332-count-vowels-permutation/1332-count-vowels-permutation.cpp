class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    // Mapping vowels to indices: '#'→5, 'a'→0, 'e'→1, 'i'→2, 'o'→3, 'u'→4
    int getIndex(char c) {
        switch (c) {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default:  return 5; // for '#' (initial case)
        }
    }

  long long possibleString(int idx, int n, char prev) {
        int p = getIndex(prev);
        if (idx == n) return 1;
        if (dp[idx][p] != -1) return dp[idx][p];

        long long strings = 0;
        if (prev == '#') {
            strings = (possibleString(idx + 1, n, 'a') +
                       possibleString(idx + 1, n, 'e') +
                       possibleString(idx + 1, n, 'i') +
                       possibleString(idx + 1, n, 'o') +
                       possibleString(idx + 1, n, 'u')) % MOD;
        } else if (prev == 'a') {
            strings = possibleString(idx + 1, n, 'e') % MOD;
        } else if (prev == 'e') {
            strings = (possibleString(idx + 1, n, 'a') +
                       possibleString(idx + 1, n, 'i')) % MOD;
        } else if (prev == 'i') {
            strings = (possibleString(idx + 1, n, 'a') +
                       possibleString(idx + 1, n, 'e') +
                       possibleString(idx + 1, n, 'o') +
                       possibleString(idx + 1, n, 'u')) % MOD;
        } else if (prev == 'o') {
            strings = (possibleString(idx + 1, n, 'i') +
                       possibleString(idx + 1, n, 'u')) % MOD;
        } else if (prev == 'u') {
            strings = possibleString(idx + 1, n, 'a') % MOD;
        }

        return dp[idx][p] = strings;
    }

    int countVowelPermutation(int n) {
        dp.assign(n, vector<int>(6, -1)); // 6 = 5 vowels + '#' initial state
        return possibleString(0, n, '#');
    }
};
