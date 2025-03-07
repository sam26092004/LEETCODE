class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start = 0, end = citations.size()-1;
        int n = citations.size();
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (citations[mid] >= n - mid) {
                ans = n - mid;
                end = mid - 1;
            } else  {
            start = mid + 1;
            }
        }

        return (ans==-1)?0:ans;
    }
};