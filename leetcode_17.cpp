class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 숫자-문자 맵 초기화
        unordered_map<char, string> numMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        // 입력이 비어 있는 경우 빈 결과 반환
        if (digits.empty()) return {};

        // 큐 초기화
        queue<string> q;
        q.push(""); // 시작점: 빈 문자열

        // 각 digit에 대해 큐를 이용해 조합 확장
        for (char digit : digits) {
            // 현재 digit에 해당하는 문자
            const string& chars = numMap[digit];
            int n = q.size(); // 현재 큐 크기
            for (int i = 0; i < n; ++i) {
                string current = q.front();
                q.pop();
                for (char c : chars) {
                    q.push(current + c);
                }
            }
        }

        // 큐의 내용을 결과 벡터로 변환
        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};