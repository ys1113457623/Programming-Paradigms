/*
1572. Matrix Diagonal Sum
Easy

1593

23

Add to List

Share
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.*/

//MY SOLUTION

class Solution {
public:
    int getprimarySum(vector<vector<int>>& mat){
        int primarySum=0;
        for(int i=0;i<mat.size();i++){
            primarySum = primarySum+mat[i][i];
        }
        cout<<primarySum<<endl;
        return primarySum;
    }
    int getsecondarySum(vector<vector<int>>& mat){
        int secondarySum=0;
        for(int i=0;i<mat.size();i++){
            secondarySum = secondarySum+mat[i][mat.size()-i-1];
        }
        cout<<secondarySum<<endl;
        return secondarySum;
    }
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size()==1){
            return mat[0][0];
        }
        if(mat.size()%2!=0){
            
            return getprimarySum(mat)+getsecondarySum(mat)-mat[mat.size()/2][mat.size()/2];
        }
        else{
            return getprimarySum(mat)+getsecondarySum(mat);
        }

        
    }
};

//OPTIMAL SOLUTION
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        // side length
        int n = mat.size();
        
        // mid point index
        int mid = n / 2;
        
        // summation of diagonal element
        int summation = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            
            // primary diagonal
            summation += mat[i][i];
            
            // secondary diagonal
            summation += mat[n-1-i][i];
        }
        
        
        if( n % 2 == 1 ){
            
            // remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid];
        }
        
        return summation;
    }
};