class Solution {
public:
    
    // -- Time complexity is O(n*26)
    // -- Space complexity is O(26) + o(26)
    vector<int> findAnagrams(string s, string p) {
	vector<int> goal(26), cur(26), res;
    //since it will contain only characters , so delaraing the vector of characters    
        
	for(char c : p) goal[c - 'a']++;
    //putting the characters in the goal vector
    
	for(int i = 0; i < s.size(); i++) {
		cur[s[i] - 'a']++;
		if(i >= p.size()) cur[s[i - p.size()] - 'a']--;
		
        //here we are comparing two vectors with its values , so its O(26)
        if(cur == goal) res.push_back(i - p.size() + 1);
	}
        
        
	return res;
}
    
    
   /* vector<int> findAnagrams(string name1, string name2) {
        
       vector<int>ans;
	int n = name1.size();
	int m = name2.size();
        
       if(n == 0){
           return ans;
       } 
	int count = 0;
	unordered_map<char , int>pattern;
	unordered_map<char , int>main;

	for (int i = 0 ; i < m ; i++) {
		if (pattern.count(name2[i]) == 0) {
			pattern[name2[i]] = 1;
		} else {
			pattern[name2[i]]++;
		}

		if (main.count(name1[i]) == 0) {
			main[name1[i]] = 1;
		} else {
			main[name1[i]]++;
		}
	}

     
	if (main == pattern) {
		count++;
        ans.push_back(0);
		
	}

	for (int i = m ; i < n ; i++) {
	
		int index = i - m;
		

		if (main[name1[index]] > 1) {
			main[name1[index]]--;
		} else {
			main.erase(name1[index]);
		}

		if (main.count(name1[i]) == 0)
			main[name1[i]] = 1;
		else
			main[name1[i]]++;
		
		if (pattern == main) {
			count++;
            ans.push_back(index+1);
			
		}
		
	}

	return ans;

    }*/
};
