class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return; // 원소가 1개 이하이면 그대로 리턴

        // 1. 뒤에서부터 탐색하며, nums[i] < nums[i+1]를 만족하는 첫번째 인덱스 i (pivot)를 찾음.
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // 2. pivot이 존재하지 않으면(내림차순이라면) 전체를 오름차순으로 정렬(역순으로 뒤집기)하고 종료.
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // 3. pivot 이후 구간에서 pivot보다 큰 수 중 가장 작은 수 (오른쪽 끝부터 찾으면 됨)를 찾음.
        int swapIndex = -1;
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swapIndex = i;
                break;
            }
        }
        
        // 4. pivot과 swapIndex의 원소를 교환.
        swap(nums[pivot], nums[swapIndex]);
        
        // 5. pivot 이후의 수열을 오름차순으로 정렬(역순으로 뒤집기)하여 마무리.
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
