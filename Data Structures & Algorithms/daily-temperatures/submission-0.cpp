class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans;
        stack<int>s;
       
       reverse(temp.begin(), temp.end());

       for(int i=0; i<temp.size(); i++){
        while(s.size()>0 && temp[i] >= temp[s.top()]) s.pop();
        if(s.empty())  ans.push_back(0);
         else ans.push_back(i - s.top());

         s.push(i);

       }
       reverse(ans.begin() , ans.end());
     return ans;
     
    }
};
