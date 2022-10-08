class Solution {
public:
    int calcSum(vector<int>& arr, int n, int k)
{
  
    // Loop to consider every
    // subarray of size K
    int sum = 0;
    for (int i = 0; i <= n - k; i++) {
          
        // Initialize sum = 0
        
  
        // Calculate sum of all elements
        // of current subarray
        for (int j = i; j < k + i; j++)
            sum += arr[j];
  
        // Print sum of each subarray
        // cout << sum << " ";
    }
    return sum;
}
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        for(int i=1;i<=arr.size();i=i+2){
            sum = sum+calcSum(arr,arr.size(),i);
        }
        
        return sum;
    }
};