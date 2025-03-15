class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if (bitC == 1) {
                if (bitA == 0 && bitB == 0)
                    flips++;
            } else {
                flips += (bitA + bitB);
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};
