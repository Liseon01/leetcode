class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int left = 0, right = nums.size() - 1;
        while(right >= left) {
            int mid = left + (right - left) / 2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right + 1;
    }
};