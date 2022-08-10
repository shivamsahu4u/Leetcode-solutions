class Solution {
public:
long long countBadPairs(vector<int>& a,long cnt=0) {
    unordered_map<int,long long> mp;
    int n=size(a);
    
    for(int i = 0 ; i < a.size() ; i++){
      mp[i-a[i]]++;
    }
    cout<<endl;
    for(auto it :mp){
        cnt+= (it.second * (it.second-1) / 2); // total good pairs
}
    cout<<cnt<<endl;
    return 1L*n*(n-1)/2 - cnt;
}
};  