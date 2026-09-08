class Solution {
public:

    void solve(int index, int target,
               vector<int>& candidates,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        
        for(int i = index; i < candidates.size(); i++) {

            
            if(candidates[i] > target)
                continue;

           
            temp.push_back(candidates[i]);

            
            solve(i,
                  target - candidates[i],
                  candidates,
                  temp,
                  ans);

            
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum(
        vector<int>& candidates,
        int target
    ) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, target, candidates, temp, ans);

        return ans;
    }
};