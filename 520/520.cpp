#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	bool detectCapitalUse(string word){
		vector<int> rr(word.size(), -1);
		int allONE = 1;
		int allZERO = 0;

		for (int i = 0 ; i < word.size() ; i++){
			if (word[i] >= 'A' && word[i] <='Z'){
				rr[i] = 1;
			} else {
				rr[i] = 0;
			}
		}
		for (int i = 1 ; i < word.size() ; i++){
			allONE = allONE & rr[i];
			allZERO = allZERO | rr[i];
		}
		if (rr[0]){
			if (allONE == 1)	
				return true;
			else if (allZERO == 0)
				return true;
			return false;
		} else {
			if (allZERO == 0)
				return true;
			return false;
		}
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("USA");
	string sb("leetcode");
	string sc("Google");
	string sd("FlaG");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	ret = sol.detectCapitalUse(sa);
	cout << ret << "\n";
	ret = sol.detectCapitalUse(sb);
	cout << ret << "\n";
	ret = sol.detectCapitalUse(sc);
	cout << ret << "\n";
	ret = sol.detectCapitalUse(sd);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
