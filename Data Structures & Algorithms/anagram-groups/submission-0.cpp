class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(string str : strs){
            string word = str;
            sort(word.begin(), word.end());
            mp[word].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
