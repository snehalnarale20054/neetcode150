class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int num:nums){
            if(s.find(num)!=s.end()){ // it checks the duplicate elemnts from start to end. s.end= out of set
                return true;
            }
            s.insert(num);
        }
        return false;





        
    }
};