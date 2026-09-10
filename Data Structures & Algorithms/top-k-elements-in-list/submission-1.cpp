class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);//So when nums.size() = 6, the maximum frequency can be:6 (5,5,5,5,5,5)


        for(auto it:mp){
            int number=it.first;
            int frequency=it.second;

            bucket[frequency].push_back(number); 
        }
        vector<int> ans;
        for(int i=nums.size();i>=1 && ans.size()<k;i--){
            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    break;
                }
            }

        }
        return ans;
    }
};
