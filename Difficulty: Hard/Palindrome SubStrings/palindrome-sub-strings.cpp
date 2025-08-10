class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.length();
        int count = 0;

      
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) 
                    count++;
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expandAroundCenter(i, i);     
            expandAroundCenter(i, i + 1); 
        }

        return count;
    }
};