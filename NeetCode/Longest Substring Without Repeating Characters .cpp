class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char, int>mp;

        int ans=0;

        for(int i=0, j=0; j<n; j++){
            if(mp[s[j]]>0){
                i=max(i, mp[s[j]]);
            }
            ans=max(ans, j-i+1);
            mp[s[j]]=j+1;
        }

        return ans;
    }
};