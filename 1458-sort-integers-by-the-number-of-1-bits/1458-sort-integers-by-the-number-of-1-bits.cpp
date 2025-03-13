class Solution {
public:
    static int countBits(int a) {
        int count = 0;
        while (a) {
            count += (a & 1);
            a >>= 1;
        }
        return count;
    }

    static bool cmp(int a, int b) {
        int bit1 = countBits(a);
        int bit2 = countBits(b);
        if (bit1 == bit2)
            return a < b;
        return bit1 < bit2;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};