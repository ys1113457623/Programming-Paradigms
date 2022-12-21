/*1299. Replace Elements with Greatest Element on Right Side
Easy
1.7K
181
Companies
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int gr=INT_MIN;
        int temp=arr[arr.size()-1];
        for(int i=arr.size()-1; i>0; i--) {            
            gr = max(gr, temp);
            temp=arr[i-1];
            arr[i-1]=gr;
        }
        arr[arr.size()-1]=-1;
        return arr;
    }
};

//OPTIMAL SOLUTION

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int arrl=arr.size();
        vector<int>res(arrl);
        int greatest=-1;
        for(int a=arrl-1;a>=0;a--)
        {
            res[a]=greatest;
            if(greatest<arr[a])
                 greatest=arr[a];
        }
        return res;
    }
};