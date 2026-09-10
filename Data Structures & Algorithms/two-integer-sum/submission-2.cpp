class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;

        vector<pair<int,int>> arr;

        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int sum = 0;
        while(i < j){
            sum = arr[i].first + arr[j].first;
            if(sum == target){
                return {min(arr[i].second,arr[j].second),max(arr[i].second,arr[j].second)};
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }  
        }
        return {};
    }
};
