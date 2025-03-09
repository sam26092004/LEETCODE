
class Solution {
public:
    bool canCross(int day, int row, int col, vector<vector<int>>& days,
                  vector<vector<int>>& directions) {

        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<int, int>> q;

        
        for (int i = 0; i < col; i++) {
            if (days[0][i] > day) {
                q.push({0, i});
                visited[0][i] = 1;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == row - 1) return true; 

            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    !visited[nr][nc] && days[nr][nc] > day) {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return false; 
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> days(row, vector<int>(col, INT_MAX));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

     
        for (int i = 0; i < cells.size(); i++) {
            days[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
        }

        int start = 1, end = cells.size();
        int ans = 0;

       
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canCross(mid, row, col, days, directions)) {
                ans = mid;     
                start = mid + 1;
            } else {
                end = mid - 1;   
            }
        }

        return ans;
    }
};