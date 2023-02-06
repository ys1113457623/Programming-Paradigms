class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char , char> rep;
        unordered_map <char , bool> used;
        for(int idx = 0 ; idx < s.length() ; idx++) {
            if(rep.count(s[idx])) {
                if(rep[s[idx]] != t[idx])
                    return false;
            }
            else {
                if(used[t[idx]])
                    return false;
                rep[s[idx]] = t[idx];
                used[t[idx]] = true;
            }
        }
        return true;
    }
};