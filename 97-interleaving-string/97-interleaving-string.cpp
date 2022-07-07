int dp[101][101];
class Solution {
public:
    bool helpme(string &s1, string &s2,int i,int j,string &s3,int &n,int &m,int &nm)
        {
            if((i+j)==nm)
                return true;
            if(dp[i][j]!=-1)
                return dp[i][j];
            bool first=false;
            bool second=false;
            if(i<n and s1[i]==s3[i+j])
                first= helpme(s1,s2,i+1,j,s3,n,m,nm);
            if(j<m and s2[j]==s3[i+j])
                second= helpme(s1,s2,i,j+1,s3,n,m,nm);
            if(first or second)
                return dp[i][j]= true;
            return dp[i][j]=false;
        }
    bool isInterleave(string s1, string s2, string s3) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n=s1.length();
            int m=s2.length();
            int nm=s3.length();
            memset(dp,-1,sizeof(dp));
            if(n+m==nm)  
               return helpme(s1,s2,0,0,s3,n,m,nm);
            return false;
    }
};