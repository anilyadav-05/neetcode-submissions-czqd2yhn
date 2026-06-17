class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int i = 0;
     
        while(i<s.length()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' ){
                st.push(s[i]);
                i++;
                continue;
            } 
            if(s[i] == ')') s[i] = '(';
            if( s[i] == '}')s[i] = '{';
            if(s[i] == ']') s[i] = '[' ;
            if(st.empty() || st.top() != s[i]) return 0;
            st.pop();
           
            i++;
        }
        if(st.empty()) return 1;
        return 0;
    }
};
