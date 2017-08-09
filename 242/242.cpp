#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	bool isAnagram(string s, string t){
		int table[26] = {0};
		if (s.size() != t.size())
			return false;
		if (s.empty() && t.empty())
			return true;

		for (int i = 0 ; i < s.size() ; i++){
			table[ s[i] - 'a']++;
		}
		
		for (int i = 0 ; i < t.size() ; i++){
			table[ t[i] - 'a']--;
		}
		return checkAll(table);
	}

	bool checkAll(int table[]){
		for (int i = 0 ; i < 26 ; i++){
			if (table[i] != 0)
				return false;
		}
		return true;
	}

};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
#define case2
#ifdef case1
	string as("anagram");
	string ap("nagaram");
#endif
#ifdef case2
	string as("rat");
	string ap("car");
#endif
	Solution sol;
	cout << sol.isAnagram(as,ap) << endl;


	return 0;
}
