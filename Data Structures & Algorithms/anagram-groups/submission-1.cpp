class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>> mp;
        for(string str:strs){
            string original=str;
            sort(original.begin(),original.end());
            mp[original].push_back(str);
        }


        vector<vector <string>> ans;
        for(auto it : mp){
        ans.push_back(it.second);
            
        }
        return ans;
        
    }
};
