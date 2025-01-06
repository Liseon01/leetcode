class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2); // nums1이 항상 작은 배열이 되도록 설정
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int total = m + n;
        int half = total / 2;

        while (left <= right) {
            int n1_half = (left + right) / 2;
            int n2_half = half - n1_half;

            int n1_left_max = (n1_half > 0) ? nums1[n1_half - 1] : INT_MIN;
            int n1_right_min = (n1_half < m) ? nums1[n1_half] : INT_MAX;
            int n2_left_max = (n2_half > 0) ? nums2[n2_half - 1] : INT_MIN;
            int n2_right_min = (n2_half < n) ? nums2[n2_half] : INT_MAX;

            // 조건에 맞는 분할인지 확인
            if (n1_left_max <= n2_right_min && n2_left_max <= n1_right_min) {
                // 중앙값 계산
                if (total % 2 == 0) {
                    return (max(n1_left_max, n2_left_max) + min(n1_right_min, n2_right_min)) / 2.0;
                } else {
                    return min(n1_right_min, n2_right_min);
                }
            } else if (n1_left_max > n2_right_min) {
                right = n1_half - 1; // nums1에서 더 왼쪽으로 이동
            } else {
                left = n1_half + 1; // nums1에서 더 오른쪽으로 이동
            }
        }

        throw invalid_argument("Input arrays are not valid.");
    }
};
