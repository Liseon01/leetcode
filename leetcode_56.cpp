class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size() <= 1) return intervals;
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> res;
            res.push_back(intervals[0]);
            
            for (int i = 1; i < intervals.size(); i++) {
                // 결과 벡터의 마지막 구간과 현재 구간 비교
                if (intervals[i][0] <= res.back()[1]) {
                    // 겹치면 병합: 끝점을 더 큰 값으로 업데이트
                    res.back()[1] = max(res.back()[1], intervals[i][1]);
                } else {
                    // 겹치지 않으면 그대로 추가
                    res.push_back(intervals[i]);
                }
            }
            
            return res;
        }
    };
    