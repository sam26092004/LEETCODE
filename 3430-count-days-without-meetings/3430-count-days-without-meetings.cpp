class Solution {
public:
    int countDays(int n, vector<vector<int>>& meetings) {
        if (meetings.empty()) return n;

        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge overlapping intervals
        vector<pair<int, int>> merged;
        int start = meetings[0][0];
        int end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end) {
                end = max(end, meetings[i][1]); // merge
            } else {
                merged.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        merged.push_back({start, end}); // don't forget last

        // Step 3: Count free days between merged intervals
        int freeDays = 0;

        // Days before the first meeting
        if (merged[0].first > 1)
            freeDays += merged[0].first - 1;

        // Days between meetings
        for (int i = 1; i < merged.size(); ++i) {
            freeDays += merged[i].first - merged[i - 1].second - 1;
        }

        // Days after the last meeting
        if (merged.back().second < n)
            freeDays += n - merged.back().second;

        return freeDays;
    }
};
