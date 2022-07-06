class Solution {
public:
    int reverse(int x) {
        int g =0;
        // int rev = 0;/
        int h = x;
        if(h == INT_MIN)
            return 0;
        if(h<0)
        {
            g =1;
            h = -h;
        }
        
        int rev = h%10;
            h /=10;
        while(h>0)
        {
            
            if(rev > INT_MAX/10)
                return 0;
            rev = rev*10 +h%10;
            h/=10;
        }
        if(g==1)
            return -rev;
        return rev;
    }
};