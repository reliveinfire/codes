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
	vector<int> findAnagrams(string s, string p){
		int table[26] = {0};
		vector<int> result;
		if (p.size() > s.size() || s.empty() || p.empty())
			return result;
		for (int i = 0 ; i < p.size() ; i++){
			table[ p[i] - 'a']++;
		}
		
		for (int i = 0, j= p.size()-1 ; j< s.size(); i++,j++){
			if (i == 0){
				for (int k = i ; k <= j ; k++){
					table[ s[k] - 'a' ]--;
				}
			} else {
				table[s[j] - 'a']--;
				table[s[i-1] - 'a']++;
			}
			if (checkAll(table)){
				result.push_back(i);
			}
		}
		return result;	
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
	vector<int >ret;
#define case2
#ifdef case1
	string as("cbaebabacd");
	string ap("abc");
#endif
#ifdef case2
	string as("abab");
	string ap("ab");
#endif
	Solution sol;
	ret = sol.findAnagrams(as,ap);
	for (int i = 0 ; i < ret.size() ; i++){
		cout << ret[i] <<" ";
	}

	cout  << "\n";

	return 0;
}
