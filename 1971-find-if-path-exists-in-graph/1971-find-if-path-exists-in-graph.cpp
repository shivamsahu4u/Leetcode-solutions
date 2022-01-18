class Solution {
public:
    
    bool path(int s , int d , vector<int>arr[] , vector<int>&vis){
        cout<<"Dgd";
        if(s == d){
            cout<<"SDgdg";
            return true;
        }
        
        vis[s] = true;
        
        for(auto it : arr[s]){
            
            if(vis[it] == false){
                
                if(path(it , d , arr , vis)){
                    cout<<"ji000000";
                    return true;
                }
            }
        }
        
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        
//         array of vectors
        vector<int>arr[n];
        
        
        ///Bi direction case
        for(int i = 0 ; i < edges.size() ; i++){
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            arr[u].push_back(v);
            arr[v].push_back(u);
        }
        
        //initialised with 0
        vector<int>v(n , 0);
        
        if(path(s , d , arr , v))
        return true;
        
        return false;
        
    }
};