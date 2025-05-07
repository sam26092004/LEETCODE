class Solution {
private:
bool isSafe(int row,int col,vector<vector<int>>& moveTime){
    if(row>=0 && row<moveTime.size() && col>=0 && col<moveTime[0].size()){
        return true;
    }
    return false;
}
public:
 
    int minTimeToReach(vector<vector<int>>& moveTime) {

      priority_queue<pair<int, pair<int, int>>,
               vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>> time;
        vector<vector<int>>dp(moveTime.size(),vector<int>(moveTime[0].size(),INT_MAX));

        time.push({0,{0,0}});
  
        vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
        while(!time.empty()){

            pair<int,pair<int,int>>top=time.top();
            time.pop();
              int currTime=top.first;
              int row=top.second.first;
              int col=top.second.second;
           
            if(row==moveTime.size()-1 && col== moveTime[0].size()-1){
                return currTime;
            }

            for(auto direction:directions){
                int newRow=row+direction[0];
                int newCol=col+direction[1];
                if(isSafe(newRow,newCol,moveTime) && dp[newRow][newCol]>max(currTime,moveTime[newRow][newCol])+1 ){
                    int newTime=max(currTime,moveTime[newRow][newCol])+1;
                    dp[newRow][newCol]=newTime;
                    time.push({newTime,{newRow,newCol}});
                }
                
            }
            
        }
        return -1;
        
    }
};