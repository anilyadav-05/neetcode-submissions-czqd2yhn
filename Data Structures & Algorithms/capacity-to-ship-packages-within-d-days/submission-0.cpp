class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
      int st = INT_MIN, end = 0;   
       for( int i : weights){
         st = max( st, i);
      }
      for( int i : weights){
        end += i;
      }
      while(st<=end){
        int mid = st +(end - st)/2;
        int day = 0;
        int load = 0;
        for( int i : weights){

          if(load + i > mid){
            day++;
            load = 0;
          }
          load += i;
      }
      day++;

      if(day > days){
        st = mid+1;
      }else{
        end = mid - 1;
      }
      }
      return st;

    }
};