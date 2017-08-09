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
		int findSubstringInWraproundString(string p){
			int alphaCount[26] = {0};
			int ret = 0;
			if (p.empty())
				return ret;
			if (p.size() == 1)
				return 1;
			int count;
			char start;
			for (int i = p.size() - 1 ; i >= 0 ; i--){
				if (i== p.size() - 1){
					start = p[i];
					count = 1;
				} else {
					if ((p[i]+1 - 'a') % 26 == (p[i+1] - 'a')){
						count++;
					} else {
						while(count > 0){
							alphaCount[start-'a'] = max(count, alphaCount[start-'a']);
							count--;
							if (start == 'a')
								start = 'z';
							else
								start--;
						}
						count = 1;
						start = p[i];
					}
				}
			}
			while(count > 0){
				alphaCount[start-'a'] = max(count, alphaCount[start-'a']);
				count--;
				if (start == 'a')
					start = 'z';
				else
					start--;
			}

			for (int i = 0 ; i < 26 ; i++){
				//cout << i << ":" << alphaCount[i]<< endl;
				ret += alphaCount[i];
			}
			cout << endl;
			return ret;
		}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
//	string A("abaab");
//	string B("cac");
	string C("zab");
//	string D("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	Solution sol;
//	cout << sol.findSubstringInWraproundString(A) << endl;
//	cout << sol.findSubstringInWraproundString(B) << endl;
	//cout << sol.findSubstringInWraproundString("aabb") << endl;
	cout << sol.findSubstringInWraproundString("acd") << endl;
//	cout << sol.findSubstringInWraproundString("zab") << endl;
//	cout << sol.findSubstringInWraproundString(D) << endl;
	cout << "\n";

	return 0;
}
