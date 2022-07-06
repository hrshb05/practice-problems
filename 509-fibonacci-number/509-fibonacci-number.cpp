class Solution {
public:
    int fib(int n) {
        long long a=0;
        int i = 0;
        int j =1;
        if(n==0)
            return i;
        for(int k =2;k<=n;k++)
        {
            a = i+j;
            i = j;
            j = a;
        }
        return j;
        
    }
};