class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        //we can use max priority queue for finding maximum distance between any two nodes
        
        vector<pair<int,double>>arr[n];
        int i = 0;
        for(auto path : edges){
            
            arr[path[0]].push_back(make_pair(path[1] , succProb[i]));
            arr[path[1]].push_back(make_pair(path[0] , succProb[i]));
            i++;
        }
        
        priority_queue<pair<double , int>>q;
        q.push(make_pair( 1.0 , start));
        vector<double>ans(n , 0);
        ans[start] = 1;
      
        
        vector<bool>visited(n ,false);
        while(q.size() != 0){
           
                
                pair<double , int>front = q.top();
                q.pop();
                visited[front.second] = true;
                
                for(auto it : arr[front.second]){
                    
                  
                    if(!visited[it.first] && front.first*it.second > ans[it.first]){
                      
                        ans[it.first] = front.first*it.second;
                        q.push(make_pair(ans[it.first] , it.first));
                    }
                }
            
        }
        return ans[end];
    }
};