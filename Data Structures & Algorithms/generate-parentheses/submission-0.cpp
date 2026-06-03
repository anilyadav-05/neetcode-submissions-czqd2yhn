class Solution {
public:
   void helper(vector<string>& ans, string current, int open, int close, int n) {
    // base case
    if(current.length() == 2*n) {
        ans.push_back(current);
        return;
    }

    // Choice 1: add open bracket
    if(open < n)
        helper(ans, current + "(", open+1, close, n);

    // Choice 2: add close bracket
    if(close < open)
        helper(ans, current + ")", open, close+1, n);
}

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current="";

        helper( ans,current,0,0,n);

        return ans;
    }
};
