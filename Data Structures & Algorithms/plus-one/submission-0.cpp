class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        
        // Start from the last digit and move towards the first
        for(int i=digits.size()-1;i>=0;i--){

            // If the digit is less than 9, increment it and return
            if(digits[i]<9){
                digits[i]++;
                 return digits;
                
              }
             
              // If the digit is 9, change it to 0 and carry 1
               digits[i]=0;
           

        }
         // If all digits are 9, insert 1 at the beginning
         digits.insert(digits.begin(),1);

         return digits;

        
    }
    
};
