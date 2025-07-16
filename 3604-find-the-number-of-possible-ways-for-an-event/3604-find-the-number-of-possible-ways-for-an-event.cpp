class Solution {
public:
    const int MOD = 1e9 + 7;

   
    long long modPow(long long x, long long y) {
        long long result = 1;
        x %= MOD;
        while (y > 0) {
            if (y & 1) result = (result * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return result;
    }

   
    void precomputeFactorials(int maxN, vector<long long>& fact, vector<long long>& invFact) {
        fact[0] = 1;
        for (int i = 1; i <= maxN; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[maxN] = modPow(fact[maxN], MOD - 2);  
        for (int i = maxN - 1; i >= 0; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    
    long long comb(int n, int r, vector<long long>& fact, vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }

  
    void precomputeStirling(int n, vector<vector<long long>>& stirling) {
        stirling[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                stirling[i][j] = (stirling[i - 1][j - 1] + (j * stirling[i - 1][j]) % MOD) % MOD;
            }
        }
    }

    int numberOfWays(int n, int x, int y) {
        int maxN = max(n, x);  
        vector<long long> fact(maxN + 1), invFact(maxN + 1);
        precomputeFactorials(maxN, fact, invFact);

        vector<vector<long long>> stirling(n + 1, vector<long long>(n + 1, 0));
        precomputeStirling(n, stirling);

        long long totalWays = 0;
        for (int k = 1; k <= min(n, x); ++k) {
            long long s = stirling[n][k];        
            long long c = comb(x, k, fact, invFact); 
            long long perm = fact[k];            
            long long scoreWays = modPow(y, k);  

            long long currentWays = (((s * c) % MOD * perm) % MOD * scoreWays) % MOD;
            totalWays = (totalWays + currentWays) % MOD;
        }

        return (int)totalWays;
    }
};
