class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> current;
            vector<bool> used(nums.size(), false);
            backtrack(nums, current, used, res);
            return res;
        }
        
    private:
        void backtrack(const vector<int>& nums, vector<int>& current, 
                       vector<bool>& used, vector<vector<int>>& res) {
            if (current.size() == nums.size()) {
                res.push_back(current);
                return;
            }
            
            // 각 재귀 깊이에서 이미 처리한 숫자들을 기록하는 로컬 컨테이너
            unordered_set<int> seen;
            
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                // 현재 깊이에서 같은 숫자를 이미 사용했다면 건너뜀
                if (seen.count(nums[i])) continue;
                
                seen.insert(nums[i]);
                used[i] = true;
                current.push_back(nums[i]);
                backtrack(nums, current, used, res);
                current.pop_back();
                used[i] = false;
            }
        }
    };
    