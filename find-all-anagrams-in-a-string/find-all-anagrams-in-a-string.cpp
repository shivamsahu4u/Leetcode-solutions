class Solution {
public:
    vector<int> findAnagrams(string name1, string name2) {
        
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

    }
};