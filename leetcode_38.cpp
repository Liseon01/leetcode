// my solution
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string res = "1";
        for(int i = 1; i < n; i++) {
            res = RLE(res);
        }
        return res;
    }
private:
    string RLE(string &s) {
        string res;
        int cnt = 1;
        for (int i = 0; i < s.size(); i++) {
            if(i == s.size() - 1 || s[i] != s[i + 1]) {
                res += to_string(cnt) + s[i];
                cnt = 1;
            }
            else {
                cnt ++;
            }
        }
        return res;
    }
};

// optimal solution

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; ++i) {
            string temp;
            // 현재 result의 길이를 고려하여 최대 2배 길이로 예약
            temp.reserve(result.size() * 2);
            int len = result.size();
            int j = 0;
            
            while (j < len) {
                char currentChar = result[j];
                int count = 0;
                // 같은 숫자가 연속되는 개수 세기
                while (j < len && result[j] == currentChar) {
                    ++count;
                    ++j;
                }
                // count가 한 자릿수임을 가정하여 문자로 변환
                temp.push_back('0' + count);
                temp.push_back(currentChar);
            }
            
            // 새로운 문자열이 result가 됨 (move로 불필요한 복사 줄이기)
            result = move(temp);
        }
        
        return result;
    }
};


