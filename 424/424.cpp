#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
	int table[26];
	public:
		int characterReplacement(string s, int k) {

			int r =0, l = 0;
			int ret = 0;
			int maxChar;

			for (int i = 0 ; i < 26 ; i++)
				table[i] = 0;

			if (s.size() < k)
				return s.size();

			for (int i = 0 ; i < s.size() ; i++){
				//cout << i << "=================\n";
				table[s[i]-'A']++;
				maxChar = findMaxChar();
				if ( i - l + 1 <= k + maxChar){
					ret = max(i - l + 1, ret);
				} else {
					while( i - l + 1 > k + maxChar ){
						//cout << "remove\n";
						table[s[l]-'A']--;
						l++;
						maxChar = findMaxChar();
						//cout << l << " " << i << " " << k << " " << maxChar << "\n";
					}
				}
				//cout << l << ":" << i <<"\n";
			}
			return ret;
		}
		int findMaxChar(){
			int ret = 0;
			for (int i = 0 ; i < 26 ; i++){
				ret = max(ret, table[i]);
			}
			return ret;
		}
};

int main()
{
	int ret;
	string A("ABAB");
	string B("AABABBA");
	Solution sol;
	cout << sol.characterReplacement(A,2) << "\n";
	cout << sol.characterReplacement(B,1) << "\n";

	return 0;
}
