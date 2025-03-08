class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int start = 0, end = skill.size() - 1;
        long long chemistry = 0;
        int mid=start+(end-start)/2;
        int middleSum=skill[mid]+skill[mid+1];
        while (start <= end) {
            if(middleSum!=(skill[start]+skill[end])) return -1;
            long long product = 1LL * skill[start++] * skill[end--];
            chemistry += product;
        }
        return chemistry;
    }
};