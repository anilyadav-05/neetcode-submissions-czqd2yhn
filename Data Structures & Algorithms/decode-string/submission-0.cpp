class Solution {
public:
    string decodeString(string s) {
        int i=0;
        int n= s.length();
        stack<string>code;
        string word = "";
        string num = "";
        while(i<n){
            if(s[i] == ']'){
            
                int number = stoi(code.top()); code.pop();
               
                string final = code.top(); code.pop();
               
                for(int k=0; k<number; k++){
                    final += word;
                }
                word = final;
                i++;

            }
           else if(isdigit(s[i])){
            while( i<n && s[i] != '['){
                num += s[i];
                i++;
            }
            code.push(word);
            code.push(num);
            word = "";
            num = "";
            i++;
           }
           else{
           word += s[i];
           i++;
           }
        }
        
       return word;
    }
};