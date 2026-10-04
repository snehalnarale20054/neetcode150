class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right=numbers.size()-1;

        while(left<right){
            int sum=numbers[left]+numbers[right];

            if(sum==target){
                //return{left + 1, right + 1 };

                vector<int> ans;
                // Store the 1-indexed position of the first number
                ans.push_back(left+1);

                // Store the 1-indexed position of the 2nd number
                ans.push_back(right+1);
                return ans;
            }
            else if(sum<target){
                left++;

            }
            else{
                right--;
            }

        }
        return {};
        
    }
};
