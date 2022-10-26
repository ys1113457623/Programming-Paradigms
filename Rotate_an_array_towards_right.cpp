/*
189. Rotate Array
Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

 

Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

 

Follow up:

    Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
    Could you do it in-place with O(1) extra space?


*/

// CPP program to illustrate
// std::reverse() function of STL
class Solution {
private:
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); 
        if(k < 0){ 
            k += nums.size();
        }
        int n=nums.size();
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
    }
    // void rotate(vector<int>& nums, int k) {
    //     // roatating nth time will results into original array
    //     // and so on so, 1 2 3 4 after rotating 4th time will be 1 2 3 4 only and so on...
    //     k = k % nums.size();
    //     // k -> 0 <= k < n
    //     reverse(nums.end()-k, nums.end()-1);
    //     // 1 2 3 4 5 6 7 -> 7 6 5 4 3 2 1
    //     reverse(nums.begin(), nums.end() - k-1);
    //     // 7 6 5 4 3 2 1 -> 5 6 7 4 3 2 1
    //     reverse(nums.begin(), nums.end()-1);
    //     // 5 6 7 4 3 2 1 -> 5 6 7 1 2 3 4 (ANS)
    // }
};


