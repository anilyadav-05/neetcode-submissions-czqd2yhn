class Solution {
private:
   
    bool checkPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
   
        bool validPalindrome(string s) {
        int i = 0;
        int n = s.length() - 1;
        
        while (i < n) {
            if (s[i] != s[n]) {
                
                return checkPalindrome(s, i + 1, n) || checkPalindrome(s, i, n - 1);
            }
            i++;
            n--;
        }
        
        return true;
        }
};