class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        sort(arr.begin(), arr.end());
        while (i < j) {
            int sum = arr[i].first + arr[j].first;

            if (sum == target) {
                vector<int> ans = {arr[i].second, arr[j].second};
                sort(ans.begin(), ans.end());
                return ans;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return {-1, -1};
    }
};
