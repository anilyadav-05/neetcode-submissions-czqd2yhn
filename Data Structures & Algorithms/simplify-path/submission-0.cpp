class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int i = 0;
        int n = path.size();

        while(i < n) {
            // skip slashes
            while(i < n && path[i] == '/') i++;
            
            // collect the token
            string token = "";
            while(i < n && path[i] != '/') {
                token += path[i];
                i++;
            }

            if(token == "" || token == ".") continue;
            else if(token == "..") {
                if(!s.empty()) s.pop();
            }
            else s.push(token);
        }

        string result = "";
        while(!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }

        return result.empty() ? "/" : result;
    }
};