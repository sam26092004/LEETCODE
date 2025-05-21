class Solution {
private:
    void setColZero(int col, vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
    };
    void setRowZero(int row, vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
        }
    };

public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> nodes;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    nodes.push({i, j});
                }
            }
        }
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;

        while (!nodes.empty()) {
            pair<int,int>top=nodes.front();
            nodes.pop();
            if(!row[top.first]){
                row[top.first]=true;
              setRowZero(top.first,matrix);

            }
            if(!col[top.second]){
                col[top.second]=true;
              setColZero(top.second,matrix);

            }
        }
        return;
    }
};