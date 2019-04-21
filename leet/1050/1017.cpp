class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) { return "0"; }
        string ans = ""; 
        while (n != 0) {
            int r = n % (-2);
            n /= -2; 
            if (r < 0) {
                r += 2;
                ++n;
            }   

            ans = move(to_string(r) + move(ans));
        }   
        return ans;
    }   
};
