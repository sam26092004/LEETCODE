class Solution {
public:
    int counter(int target, vector<pair<int, int>>& nums) {
        int start = 0, end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid].first < target) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans + 1;
    }

    void mergeArray(int start, int end, vector<pair<int, int>>& nums,
                    vector<int>& countArray) {
        if (start == end) {
            return;
        }

        int mid = start + (end - start) / 2;
        vector<pair<int, int>> arr1(nums.begin() + start,
                                    nums.begin() + mid + 1);
        vector<pair<int, int>> arr2(nums.begin() + mid + 1,
                                    nums.begin() + end + 1);

        for (int i = 0; i < arr1.size(); i++) {
            int count = counter(arr1[i].first, arr2);
            countArray[arr1[i].second] += count;
        }

        int i = 0, j = 0, idx = start;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i].first <= arr2[j].first) {
                nums[idx++] = arr1[i++];
            } else {
                nums[idx++] = arr2[j++];
            }
        }
        while (i < arr1.size()) {
            nums[idx++] = arr1[i++];
        }
        while (j < arr2.size()) {
            nums[idx++] = arr2[j++];
        }
    }

    void mergeSort(int start, int end, vector<pair<int, int>>& nums,
                   vector<int>& ans) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(start, mid, nums, ans);
        mergeSort(mid + 1, end, nums, ans);
        mergeArray(start, end, nums, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        vector<int> ans(nums.size(), 0);
        mergeSort(0, nums.size() - 1, arr, ans);
        return ans;
    }
};
