class Solution {
public:
    int mySqrt(int x) {
        if(x<1) return 0;
        if(x==1) return 1;

        long long st = 2, end = x/2;
        while(st<=end){
            long long mid = st + (end - st)/2;
            
            if(mid*mid > x){
                end = mid -1 ;
            }else if(mid*mid < x){
                st = mid +1;
            }else{
                return (int)mid;
            }
        }
        return (int)end;
    }
};