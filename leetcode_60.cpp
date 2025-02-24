// first soultion (time exceeded problems)
class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> nums;
            for(int i = 1; i <= n; i++) {
                nums.push_back(i);
            }
            vector<vector<int>>temp = permute(nums);
            vector<int>kth = temp[k-1];
            string res;
            for (int num : kth) {
                res += to_string(num);
            }
            return res;
        }
    private:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> current;
            vector<bool> used(nums.size(), false);
            backtrack(nums, current, used, res);
            return res;
        }
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

    class Solution {
public:
    string getPermutation(int n, int k) {
        // 1부터 n까지 숫자 리스트 생성
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        
        // 팩토리얼 값 미리 계산 (0!부터 n!까지)
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        // k를 0-indexed로 변환
        k -= 1;
        string result;
        
        // 각 자리를 결정합니다.
        for (int i = n; i >= 1; i--) {
            int idx = k / factorial[i - 1];
            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);  // 사용한 숫자는 리스트에서 제거
            k %= factorial[i - 1];
        }
        
        return result;
    }
};
// second soultion 
class Solution {
    public:
        string getPermutation(int n, int k) {
            // 1부터 n까지 숫자 리스트 생성
            vector<int> nums;
            for (int i = 1; i <= n; i++) {
                nums.push_back(i);
            }
            
            // 팩토리얼 값 미리 계산 (0!부터 n!까지)
            vector<int> factorial(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                factorial[i] = factorial[i - 1] * i;
            }
            
            // k를 0-indexed로 변환
            k -= 1;
            string result;
            
            // 각 자리를 결정합니다.
            for (int i = n; i >= 1; i--) {
                int idx = k / factorial[i - 1];
                result += to_string(nums[idx]);
                nums.erase(nums.begin() + idx);  // 사용한 숫자는 리스트에서 제거
                k %= factorial[i - 1];
            }
            
            return result;
        }
    };
    