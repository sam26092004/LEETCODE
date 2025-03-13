class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int start = 0, end = queries.size() - 1, k = -1;
      if (all_of(nums.begin(), nums.end(),
                       [](int x) { return x == 0; })){
            return 0;
                       }

        while (start <= end) {
            int mid = start + (end - start) / 2;

            vector<int> differenceArray(nums.size() + 1, 0);
            for (int i = 0; i <= mid; i++) {
                differenceArray[queries[i][0]] += queries[i][2];
                differenceArray[queries[i][1] + 1] -= queries[i][2];
            }

            vector<int> temp(nums);
            int flag = 0;
            for (int i = 0; i < temp.size(); i++) {
                flag += differenceArray[i];

                temp[i] -= flag;
                if (temp[i] <= 0)
                    temp[i] = 0;
            }

            if (all_of(temp.begin(), temp.end(),
                       [](int x) { return x == 0; })) {
                k = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return (k + 1) ? k + 1 : -1;
    }
};
