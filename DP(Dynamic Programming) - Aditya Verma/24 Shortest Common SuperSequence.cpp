class Solution
{
    public:
    int lcs(string X,string Y){
        int n = X.size();
        int m = Y.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(X[i-1]==Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return X.size() + Y.size() - lcs(X,Y);
    }
};