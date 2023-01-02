

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> hmap;

    for(int i=0;i<n;i++){
        hmap[a1[i]]++;
    }

    for(int j=0;j<m;j++){
        if(hmap[a2[i]]){
            hmap[a2[i]]--;
            countinue;
        }
        else{
            return "No";
        }
    }

    return false;
}