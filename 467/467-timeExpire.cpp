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
		int count = 1;
		int ret = 0;
		map<string,int> table;
		if (p.empty())
			return 0;
		string tmp;
		tmp.clear();

		int i = 0, j;
		while ( i < p.size() ){
			tmp += p[i];
			for (j = i+1 ; j < p.size() ; j++){
				if (p[j] - p[j-1] == 1 ||
				    p[j] - p[j-1] == 'a'-'z'){
					tmp += p[j];
					table[tmp] = 1;
				} else
					break;
			}
			if (tmp.size()!=1) {
				for (int l = 0 ; l < tmp.size() ; l++){
					for(int r = l; r < tmp.size() ; r++){
						string tt = tmp.substr(l,r-l+1);
						//cout << "we insert:" << tt << endl;
						table[tt] = 1;
					}
				}
			} else {
				//cout << "single insert:" << tmp << endl;
				table[tmp] = 1;
			}
			tmp.clear();
			i = j;
		}
		return table.size();
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	string A("abaab");
	string B("cac");
	string C("zab");
	string D("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	Solution sol;
	cout << sol.findSubstringInWraproundString(A) << endl;
	cout << sol.findSubstringInWraproundString(B) << endl;
	cout << sol.findSubstringInWraproundString(C) << endl;
	cout << sol.findSubstringInWraproundString(D) << endl;
	cout << "\n";

	return 0;
}
