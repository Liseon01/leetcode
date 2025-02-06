class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        // 중복 제거 및 가지치기를 위해 후보 배열을 정렬합니다.
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    // 백트래킹 함수
    void backtrack(vector<int>& candidates, int remain, int start, 
                   vector<int>& combination, vector<vector<int>>& result) {
        // 남은 합이 0이면 올바른 조합이므로 결과에 추가
        if (remain == 0) {
            result.push_back(combination);
            return;
        }
        
        // 남은 합이 음수이면 더 이상 진행할 필요 없음
        if (remain < 0) {
            return;
        }
        
        // start 인덱스부터 후보 숫자들을 순회
        for (int i = start; i < candidates.size(); i++) {
            // 같은 레벨에서 중복되는 수는 건너뛰기
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            
            // 현재 후보가 남은 합보다 크면 더 이상 진행할 필요 없음 
            if (candidates[i] > remain)
                break;
            
            // 현재 숫자를 조합에 추가
            combination.push_back(candidates[i]);
            // 각 숫자는 한 번만 사용하므로 다음 인덱스부터 재귀 호출
            backtrack(candidates, remain - candidates[i], i + 1, combination, result);
            // 백트래킹: 마지막 원소 제거
            combination.pop_back();
        }
    }
};