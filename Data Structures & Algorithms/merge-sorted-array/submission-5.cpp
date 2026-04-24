class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int p = m-1;
        int q = n-1;
        for (int i=n+m-1 ; i>= 0 ; i--){
            if (q <0){
                break;
            }
             
           int x = max(nums1[p], nums2[q]);
           nums1[i] = x;

           if( x == nums1[p]){
            p--;
            if ( p<-1){
                while (q>=0){
                    nums1[i] =  nums2[q];
                    i--;
                    q--;
                }
            }
           }else{ 
            q--;
           }

           

        }
    }
};