
class Solution {
public:
    vector<string> letterCombinations(string digits) {
            if (digits.empty()) {
                        return {};
                                }

                                        vector<string> phone = {
                                                    "", "", "abc", "def", "ghi",
                                                                "jkl", "mno", "pqrs", "tuv", "wxyz"
                                                                        };

                                                                                vector<string> ans;
                                                                                        string temp = "";

                                                                                                solve(0, digits, phone, temp, ans);

                                                                                                        return ans;
                                                                                                            }

                                                                                                                void solve(int index, string &digits,
                                                                                                                               vector<string> &phone,
                                                                                                                                              string &temp,
                                                                                                                                                             vector<string> &ans) {

                                                                                                                                                                     // Base case
                                                                                                                                                                             if (index == digits.length()) {
                                                                                                                                                                                         ans.push_back(temp);
                                                                                                                                                                                                     return;
                                                                                                                                                                                                             }

                                                                                                                                                                                                                     // Get letters for current digit
                                                                                                                                                                                                                             string letters = phone[digits[index] - '0'];

                                                                                                                                                                                                                                     // Try each letter
                                                                                                                                                                                                                                             for (char ch : letters) {
                                                                                                                                                                                                                                                         temp.push_back(ch);

                                                                                                                                                                                                                                                                     solve(index + 1, digits, phone, temp, ans);

                                                                                                                                                                                                                                                                                 temp.pop_back();
                                                                                                                                                                                                                                                                                         }
                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                             };
                                                                                                                                                                                                                                                                                             