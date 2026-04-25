class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        return st.size() != nums.size();
    }
};