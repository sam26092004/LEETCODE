class Solution {
public:
    static bool cmp1(const vector<int>& a, const vector<int>& b) {
        return (a[0] < b[0]) || (a[0] == b[0] && a[2] < b[2]);
    }
    static bool cmp2(const vector<int>& a, const vector<int>& b) {
        return (a[1] < b[1]) || (a[1] == b[1] && a[3] < b[3]);
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), cmp1);
        vector<pair<int, int>> xAxisDivisions, yAxisDivisions;

        for (const auto& rectangle : rectangles) {
            if (xAxisDivisions.empty()) {
                xAxisDivisions.emplace_back(rectangle[0], rectangle[2]);
            } else {
                auto& [x1, x2] = xAxisDivisions.back();
                if (rectangle[0] >= x2) {
                    xAxisDivisions.emplace_back(rectangle[0], rectangle[2]);
                } else {
                    x1 = min(x1, rectangle[0]);
                    x2 = max(x2, rectangle[2]);
                }
            }
        }

        sort(rectangles.begin(), rectangles.end(), cmp2);
        for (const auto& rectangle : rectangles) {
            if (yAxisDivisions.empty()) {
                yAxisDivisions.emplace_back(rectangle[1], rectangle[3]);
            } else {
                auto& [y1, y2] = yAxisDivisions.back();
                if (rectangle[1] >= y2) {
                    yAxisDivisions.emplace_back(rectangle[1], rectangle[3]);
                } else {
                    y1 = min(y1, rectangle[1]);
                    y2 = max(y2, rectangle[3]);
                }
            }
        }
        for (const auto& [first, second] : yAxisDivisions) {
            cout << "(" << first << ", " << second << ") ";
        }
        cout << endl;

        return (yAxisDivisions.size() >= 3 || xAxisDivisions.size() >= 3);
    }
};
