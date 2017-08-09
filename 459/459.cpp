#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
	public:
		bool repeatedSubstringPattern(string s){
			bool result = false;
			for (int size = 1 ; size <= s.size() / 2 ; size++) {
				if (s.size() % size != 0)
					continue;
				int i = 0;
				int j;
				for (j = size ; j < s.size() ; j++) {
					if (s[i] == s[j]) {
						i = (i + 1) % size;
					} else {
						break;
					}
				}
				if (j == s.size())
					return true;
					
			}
			return result;
		}
};

int main()
{
	string A("bb");
	Solution sol;
	bool ret = sol.repeatedSubstringPattern(A);
	if (ret)
		cout << "true\n";
	else
		cout << "false\n";

	return 0;
}
