class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
    }
    
private:
    int findBound(vector<int>& nums, int target, bool first) {
        int left = 0, right = nums.size() - 1, result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result = mid; // 일단 위치 저장
                if (first) {
                    right = mid - 1; // 첫 번째 위치 찾기 (왼쪽 이동)
                } else {
                    left = mid + 1; // 마지막 위치 찾기 (오른쪽 이동)
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
