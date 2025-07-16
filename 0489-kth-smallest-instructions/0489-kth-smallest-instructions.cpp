class Solution {
public:
    int MOD = 1e9 + 7;

    long long binaryExponentiation(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }

    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int V = destination[0], H = destination[1];
        int N = V + H;

        // Precompute factorials and inverse factorials
        vector<long long> fact(N + 1, 1), invFact(N + 1, 1);
        for (int i = 1; i <= N; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[N] = binaryExponentiation(fact[N], MOD - 2);
        for (int i = N - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        string res = "";
        for (int i = 0; i < N; ++i) {
            if (H == 0) {
                res += 'V';
                V--;
            } else if (V == 0) {
                res += 'H';
                H--;
            } else {
                long long count = nCr(H + V - 1, H - 1, fact, invFact);
                if (k <= count) {
                    res += 'H';
                    H--;
                } else {
                    res += 'V';
                    V--;
                    k -= count;
                }
            }
        }

        return res;
    }
};
