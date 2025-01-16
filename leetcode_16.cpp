class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int num = nums[i];
            int left = i+1, right =nums.size() - 1;
            while (left < right){
                int sum = num + nums[left] + nums[right];
                if(sum > target) right --;
                else if(sum < target) left ++;
                else return target;

                if(abs(sum - target) < abs(res - target)) res = sum;
            }
        }
        return res;
    }
};