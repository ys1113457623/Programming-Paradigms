int kthSmallest(int arr[], int l, int r, int k) {
        vector<int> ans(r+1);
        for(int i=0;i<=r;i++){
            ans[i] = arr[i];
        }
        
        make_heap(ans.begin(),ans.end());
        
        for(int i = 0 ;i<=r-k;i++){
            
            pop_heap(ans.begin(), ans.end());
	        ans.pop_back();
	        
        }
        
        return ans.front();
        
        
}

int kthSmallest(int arr[], int l, int r, int k) {

        priority_queue<int> pq;

        for(int i=0;i<k;i++){

            pq.push(arr[i]);

        }

        for(int i=k;i<=r;i++){

            if(arr[i]<pq.top()){

                pq.pop();

                pq.push(arr[i]);

            }

        }

        return pq.top();

    }

// Time complexity - O(N)