/*
2006. Count Number of Pairs With Absolute Difference K
Easy

948

21

Add to List

Share
Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
Example 2:

Input: nums = [1,3], k = 3
Output: 0
Explanation: There are no pairs with an absolute difference of 3.
Example 3:

Input: nums = [3,2,1,5,4], k = 2
Output: 3
Explanation: The pairs with an absolute difference of 2 are:
- [3,2,1,5,4]
- [3,2,1,5,4]
- [3,2,1,5,4]
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
1 <= k <= 99*/


//MY SOLUTION

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){

                if(abs(nums[i]-nums[j])==k){
                    count++;
                }
            }
        }
        
        return count;
    }
};

//OPTIMAL SOLUTION - HASH MAP
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        for(auto j= 1;j<nums.size();j++){
            
            if(i<j){
                if(nums[i]-nums[j]==k||nums[j]-nums[i]==k){
                    count++;
                    
                }
            }
            if(j==nums.size()-1){
                i++;
                j = i;
                
            }
        }
        return count;
    }
};