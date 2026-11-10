
class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
                   vector<int>& ds, vector<vector<int>>& ans) {

                           if (target == 0) {
                                       ans.push_back(ds);
                                                   return;
                                                           }

                                                                   for (int i = index; i < candidates.size(); i++) {

                                                                               // Skip duplicate elements at the same level
                                                                                           if (i > index && candidates[i] == candidates[i - 1])
                                                                                                           continue;

                                                                                                                       // Since array is sorted, no need to check further
                                                                                                                                   if (candidates[i] > target)
                                                                                                                                                   break;

                                                                                                                                                               ds.push_back(candidates[i]);

                                                                                                                                                                           // Move to i + 1 because each element can be used once
                                                                                                                                                                                       solve(i + 1, candidates, target - candidates[i], ds, ans);

                                                                                                                                                                                                   ds.pop_back();
                                                                                                                                                                                                           }
                                                                                                                                                                                                               }

                                                                                                                                                                                                                   vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

                                                                                                                                                                                                                           vector<vector<int>> ans;
                                                                                                                                                                                                                                   vector<int> ds;

                                                                                                                                                                                                                                           sort(candidates.begin(), candidates.end());

                                                                                                                                                                                                                                                   solve(0, candidates, target, ds, ans);

                                                                                                                                                                                                                                                           return ans;
                                                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                                               };
                                                                                                                                                                                                                                                               