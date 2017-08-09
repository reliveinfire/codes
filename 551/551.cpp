#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;
class Solution {
	public:
	bool checkRecord(string s){
		int ret;
		int A_count = 0;
		int L_count = 0;
		bool preL = false;

		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == 'P') {
				preL= false;
				L_count = 0;
				continue;
			} else if (s[i] == 'A') {
				A_count++;
				L_count = 0;
				if (A_count >= 2)
					return false;
				preL= false;
			} else {
				// == 'L'
				if (preL)
					L_count++;
				if (L_count >= 2)
					return false;
				preL = true;
			}
		}
		return true;
	}
};

int main()
{
	int ret;
	string A("PPALLP");
	string B("PPALLL");
	string C("LLPPPLL");
	Solution sol;
	cout << sol.checkRecord(A) << "\n";
	cout << sol.checkRecord(B) << "\n";
	cout << sol.checkRecord(C) << "\n";

	return 0;
}
