class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> current;
            vector<bool> used(nums.size(), false);
            backtrack(nums, current, used, res);
            return res;
        }
    private:
        void backtrack (const vector<int> &nums, vector<int>& current, 
                    vector<bool>& used, vector<vector<int>>& res ) {
            if(current.size() == nums.size()) {
                res.push_back(current);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if(!used[i]){
                    used[i] = true;
                    current.push_back(nums[i]);
                    backtrack(nums, current, used, res);
                    current.pop_back();
                    used[i] = false;
                }
            }
        }
    
    };