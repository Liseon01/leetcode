class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (words.empty() || s.empty()) return result;

    int wordLen = words[0].size();
    int numWords = words.size();
    int windowSize = wordLen * numWords;
    int sLen = s.size();

    unordered_map<string, int> wordCount;
    for (const string& word : words) {
        wordCount[word]++;  // words 내 각 단어의 등장 횟수 저장
    }

    for (int i = 0; i < wordLen; i++) { // 단어 크기만큼 오프셋 이동하며 검사
        int left = i, right = i, count = 0;
        unordered_map<string, int> seenWords;

        while (right + wordLen <= sLen) {
            string word = s.substr(right, wordLen);
            right += wordLen; // 윈도우 확장

            if (wordCount.find(word) != wordCount.end()) {
                seenWords[word]++;
                count++;

                while (seenWords[word] > wordCount[word]) { // 단어가 너무 많이 포함된 경우
                    string leftWord = s.substr(left, wordLen);
                    seenWords[leftWord]--;
                    count--;
                    left += wordLen; // 윈도우 왼쪽 이동
                }

                if (count == numWords) { // 모든 단어를 포함하는 경우
                    result.push_back(left);
                }
            } else { // 유효하지 않은 단어가 나온 경우
                seenWords.clear();
                count = 0;
                left = right; // 새로운 시작점 찾기
            }
        }
    }
    
    return result;
}
};