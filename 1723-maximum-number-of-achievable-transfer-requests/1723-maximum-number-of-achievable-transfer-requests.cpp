class Solution {
public:
    unordered_map<int, int> request;

    int maxRequest(vector<vector<int>>& requests, int idx) {
        if (idx == requests.size()) {
        
            for (auto& [_, val] : request) {
                if (val != 0) return -100;
            }
            return 0;
        }

     
        int from = requests[idx][0];
        int to = requests[idx][1];
        request[from]--;
        request[to]++;
        int take = 1 + maxRequest(requests, idx + 1);
       
        request[from]++;
        request[to]--;

      
        int notTake = maxRequest(requests, idx + 1);

        return max(take, notTake);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
       
        return maxRequest(requests, 0);
    }
};
