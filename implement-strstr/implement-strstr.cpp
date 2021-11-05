class Solution {
public:
   
//Brute Force solution
//Time Complexity -- O(m*n)
int strStr(string haystack, string needle) {
	int m = haystack.size(), n = needle.size();
	for (int i = 0; i <= m - n; i++) {
		int j = 0;
		for (; j < n; j++) {
			if (haystack[i + j] != needle[j]) {
				break;
			}
		}
		if (j == n) {
			return i;
		}
	}
	return -1;
}

//KMP Algorithm
//It is used to find substring in a given string
//given string is of length n and pattern is of len m
//Time complexity -- O(n+m)
//Space Complexity -- O(m)

int kmp(string str , string pattern) {
	int n = str.size(); int m = pattern.size();
	//lps[i] could also be defined as longest prefix which is also proper suffix. We need to use properly at one place to make sure that the whole substring is not considered.
	int *arr = new int[m];

	int index = 0 , i = 1;
	arr[index] = 0;
	while (i < m) {

		if (pattern[index] == pattern[i]) {
			arr[i] = index + 1;
			index++;
			i++;
		} else {

			if (index == 0) {
				arr[i] = 0;
				i++;
			} else {
				index = arr[index - 1];
			}
		}
	}

	int p = 0, q = 0;

	while (p < n && q < m) {

		if (str[p] == pattern[q]) {
			p++;
			q++;
		} else {
			if (q != 0) {
				q = arr[q - 1];
			} else {
				p++;
			}
		}
	}
	if (q == pattern.length()) {
		return true;
	} else {
		return false;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (kmp("abcxabcdabcdabc" , "abcdabcy") == 1)
		cout << "true";
	else
		cout << "false";

	return 0;
}

};
