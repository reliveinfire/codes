#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>

using namespace std;
class Solution {
	public:
	enum {SEGMENT, EMPTY};
	int countSegments(string s){
		int ret = 0;
		int state = EMPTY;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] != ' ') {
				if (state == EMPTY) {
					ret++;
				}
				state = SEGMENT;
			} else {
				state = EMPTY;
			}
		}
		return ret;
	}
};

int main()
{
	int ret;
	int test[] = {1,2,3};
	string A("hello, my name is john");
	vector<int> data(test, test + sizeof(test)/sizeof(test[0]));
	Solution sol;
	cout << sol.countSegments(A) << "\n";

	return 0;
}
