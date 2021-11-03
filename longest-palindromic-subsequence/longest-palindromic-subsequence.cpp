class Solution {
public:
    
  /*int palim(string s , int i , int j , int **arr) {

	if (i == j) {
		return 1;
	}
	if (i > j) {
		return 0;
	}

	if (arr[i][j] != -1) {
		return arr[i][j];
	}
	if (s[i] == s[j]) {

		arr[i][j] =  2 + palim(s,  i + 1 , j - 1 , arr);
		return arr[i][j];
	} else {

		arr[i][j] =   max(palim(s , i + 1 , j , arr) , palim(s, i , j - 1 , arr));
		return arr[i][j];
	}

	arr[i][j] =  1;
	return arr[i][j];
}
*/

int longestPalindromeSubseq(string s) {

	int n = s.size();

	int arr[n][n];

	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ; j < n ; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0 ; i < n ; i++) {
		arr[i][i] = 1;
	}

	for (int i = n - 2 ; i >= 0 ; i--) {

		for (int j = i + 1 ; j < n ; j++) {

			if (s[i] == s[j]) {
				arr[i][j] = 2 + arr[i + 1][j - 1];
			} else {
				arr[i][j] = max(arr[i + 1][j] , arr[i][j - 1]);
			}
		}
	}
	return arr[0][n - 1];
	/*if (s.size() == 0 || s.size() == 1) {
		return s.size();
	}
	//converting it to memoization solution
	int **arr = new int*[s.size()];
	for (int i = 0 ; i < s.size() ; i++) {
		arr[i] = new int[s.size()];
		for (int j = 0 ; j < s.size() ; j++) {
			arr[i][j] = -1;
		}
	}
	return  palim(s , 0 , s.size() - 1 , arr);*/
}

};