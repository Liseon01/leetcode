// brute force way
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) { 
                if (nums[i] + nums[j] == target) {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

// two pointer approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums; // 원본 배열 저장
        sort(nums.begin(), nums.end()); // nums 정렬

        int x1 = 0, x2 = nums.size() - 1;

        // 두 포인터를 이용해 합이 target인 인덱스 찾기
        while (x1 < x2) {
            int sum = nums.at(x1) + nums.at(x2);
            if (sum > target) {
                x2--;
            } else if (sum < target) {
                x1++;
            } else {
                break;
            }
        }

        // 원래 배열의 인덱스 찾기
        int i = -1, j = -1;
        for (int k = 0; k < temp.size(); k++) {
            if (temp[k] == nums[x1] && i == -1) {
                i = k;
            } else if (temp[k] == nums[x2] && k != i) { // 같은 값이어도 다른 인덱스를 찾아야 함
                j = k;
                break;
            }
        }

        return {i, j}; // 결과 반환
    }
};

//HashMap

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // 값과 인덱스를 저장하는 해시맵

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // 보완값 계산

            // 보완값이 맵에 있는지 확인
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i}; // 보완값의 인덱스와 현재 인덱스를 반환
            }

            // 현재 값을 맵에 저장
            numMap[nums[i]] = i;
        }

        return {}; // 두 수를 찾지 못한 경우(문제 조건상 발생하지 않음)
    }
};



