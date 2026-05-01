class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int boat = 0;
        int r = p.size()-1;

      sort(p.begin(),p.end());
      int l=0;
      while(r>=l){
        if (r == l){
            boat ++;
            break;
        }
        if (p[r]+p[l] <= limit){
            boat ++;
            l++;
            r--;
        }else{
            boat ++;
            r--;
        }
      }

return boat;
    }
};