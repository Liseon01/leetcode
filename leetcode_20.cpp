class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool res;
        map<char, char> pair = {
           {'(', ')'}, 
           {'{', '}'}, 
           {'[' ,']'} 
        };
        for(int i=0; i< s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(pair[st.top()] != s[i]){
                st.push(s[i]);
            }
            else if(pair[st.top()] == s[i]){
                st.pop();
            }
        }
        if(st.empty()){
            res = true;
        }
        else{
            res = false;
        }
        return res;
    }
};