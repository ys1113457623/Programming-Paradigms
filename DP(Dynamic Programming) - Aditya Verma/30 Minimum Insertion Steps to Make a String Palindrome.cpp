
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/888655146/

//Aditya Verma Solution


class Solution {
public:
    int lcs(string s, string rs){
        int n = s.size();
        int m = rs.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==rs[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[n][m];
    }
    int lps(string s){
        string rs = s;
        reverse(rs.begin(),rs.end());
        return lcs(s,rs);
    }
    int minInsertions(string s) {
        return s.size()-lps(s);
    }
};

class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int d=1;d<n;d++){
            for(int l=0,r=d;r<n;l++,r++){
                if(s[l]==s[r])
                    dp[l][r]=dp[l+1][r-1];
                else
                    dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
            }
        }
        return dp[0][n-1];
        
    }
};

//Best Solution Available
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];
    }