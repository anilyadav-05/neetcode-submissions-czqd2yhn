/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
          int st = 1, end = n;

        while (st<=end){
            int num = st + (end-st)/2;

            if(guess( num) == 1 ){
               st = num +1;
            }else if(guess( num) == -1){
                 end = num -1;
            }else{
                return num;
            }
        }
        
    }
};