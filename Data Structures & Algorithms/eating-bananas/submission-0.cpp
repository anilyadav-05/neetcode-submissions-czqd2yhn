class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
                int n = piles.size();

        int st = 1;
        int end =0;
        for (int i=0; i<n; i++){
            end = max(end , piles[i]);
        }
        while(st<end){
            int mid = st + (end - st)/2;
            long long x = 0;

            for (int i=0; i<n; i++){
             x += ((piles[i]-1)/mid) +1 ;

            }
            if (x>h){
                st = mid+1;
            }else{
                end = mid ;
            }
        }

       
        
return st;
    }
};
