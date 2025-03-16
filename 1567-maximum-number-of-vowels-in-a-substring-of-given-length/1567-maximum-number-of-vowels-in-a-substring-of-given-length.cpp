class Solution {
public:
    int maxVowels(string s, int k) {
        int start = 0;
        int count = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' ||
                s[i] == 'e')
                count++;
            if (i + 1 >= k) {
                ans = max(count, ans);
                if (s[start] == 'a' || s[start] == 'u' || s[start] == 'o' ||
                    s[start] == 'i' || s[start] == 'e') {
                    count--;
                }
                start++;
            }
        }
        return ans;
    }
};