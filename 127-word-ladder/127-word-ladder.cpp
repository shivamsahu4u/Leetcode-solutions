class Solution {
public:
    int ladderLength(string u, string v, vector<string>& words) {
        
        unordered_map<string , bool>present;
        
        for(int i = 0 ; i < words.size() ; i++){
             present[words[i]] = true;
        }
        
        unordered_map<string , bool>visited;
        
        int count = 0;
        
        queue<string>q;
        q.push(u);
        
        while(q.size()!=0){
            
           int size = q.size();
            count++;
            for(int i = 0 ; i < size; i++){
                
                string front = q.front();
                q.pop();
                
                
                if(front == v){
                    return count;
                }else{
                    
                    for(int j = 0 ; j < front.size() ; j++){
                        
                         for(int k = 0 ; k < 26 ; k++){
                             
                             char ch = k + 'a';
                             string str = front;
                             str[j] = ch;
                             
                             if(present.count(str) && !visited[str]){
                                 q.push(str);
                                 visited[str] = true;
                             }
                         }
                    }
                }
            }
        }
        
        return 0;
    }
};