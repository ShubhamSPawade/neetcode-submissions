class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i = 0, n = nums.size();
        int longest = 0, cnt = 1;

        if(n == 0) return 0;

        set<int> st(nums.begin(), nums.end());

        while(i < n){
            int next = nums[i] + 1;
            while(st.find(next) != st.end() && i < n){
                cnt++;
                next++;
            }

            longest = max(longest, cnt);
            cnt = 1;
            i++;
        }

        return max(longest, cnt);
    }
};
