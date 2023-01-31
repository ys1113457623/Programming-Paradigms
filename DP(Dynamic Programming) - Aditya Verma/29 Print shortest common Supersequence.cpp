
class Solution{
    public:
    string lcs(string str1,string str2){
        int n = str1.size();
        int m = str2.size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        string ans = "";
        int i = n;
        int j = m;

    string s;
            int i=m,j=n;
            while(i>0 && j>0){
                
                if(str1[i-1]==str2[j-1]){
                    s.push_back(str1[i-1]);
                    i--;
                    j--;
                }
                else{
                    
                    if(dp[i-1][j]>dp[i][j-1]){
                        s.push_back(str1[i-1]);
                        i--;
                    }
                    else{
                        s.push_back(str2[j-1]);
                        j--;
                    }
                }
            }
            
            while(i>0){
                s.push_back(str1[i-1]);
                i--;
            }
            while(j>0){
                s.push_back(str2[j-1]);
                j--;
            }
            
            reverse(s.begin(), s.end());
            return s;
    }
}