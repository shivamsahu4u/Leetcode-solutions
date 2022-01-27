class Solution {
public:
    
    void dfs(int u , vector<int> arr[] , vector<bool>&visited){
        
          visited[u] = true;
        
         for(auto it : arr[u]){
             
              if(!visited[it]){
                  
                   dfs(it , arr , visited);
              }
         }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      
        //room 0 is open
        // goal - visit to all rooms , open first
        //check if we can visit all vertices by using dfs
        //time O(V+E)
        
        vector<int>arr[rooms.size()];
        vector<bool>visited(rooms.size() , false);
              
       for(int i = 0 ; i < rooms.size() ; i++){
           
              for(int j = 0 ; j < rooms[i].size() ; j++){
                  
                   arr[i].push_back(rooms[i][j]);
              }
       } 
        
        dfs(0 , arr, visited);
              
        for(int i = 0 ; i  < rooms.size() ; i++){
            
            if(visited[i] == false){
                return false;
            }
        }
        
        return true;
    }
};