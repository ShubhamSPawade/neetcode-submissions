class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (auto i : nums) {
            mp[i]++;
        }

        vector<vector<int>> bucket(n + 1);
        for (auto i : mp) {
            int ele = i.first;
            int freq = i.second;
            bucket[freq].push_back(ele);
        }

        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (auto it : bucket[i]) {
                ans.push_back(it);
                if(ans.size() == k) break;
            }
        }

        return ans;
    }
};
