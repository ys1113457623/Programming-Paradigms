/*You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.*/

//MY SOLUTION

#include <bits/stdc++.h>
class Solution {
public:
    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector< pair <int,string> > vect;
        vector<string> ans;
        int n = names.size();
        for (int i=0; i<n; i++)
            vect.push_back( make_pair(heights[i],names[i]) );
        
        sort(vect.begin(), vect.end());
        reverse(vect.begin(), vect.end());
        
        for (int i=0; i<n; i++)
            ans.push_back(vect[i].second);
        
        return ans;
    }
};

//OPTIMAL SOLUTION
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n = names.size();
        
        for(int i=0;i<n-1;i++){
		
		    for(int j=0;j<n-1;j++){
			    if(heights[j]<heights[j+1]){
				    swap(heights[j],heights[j+1]);
				    swap(names[j],names[j+1]);
			    }
		    }
	    }
        return names;
    }
};
