#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
#if 0
class Solution {
	public:
		int findSubstringInWraproundString(string p){
			int count = 1;
			int ret = 0;
			int table[26] = {0};
			if (p.empty())
				return ret;
			table[p[0]-'a']++;
			for (int i = 1 ; i < p.size() ; i++)
			{
				if (table[p[i]-'a'] == 0){
					table[p[i]-'a']++;
				}

				if (p[i] - p[i-1] == 1 ||
						p[i] - p[i-1] == 'a' - 'z')
					count++;
				else {
					if (count > 1) {
						for (int j = 2 ; j <= count ; j++)
							ret+= (count - j + 1);
					}
					count = 1;
				}
			}
			if (count > 1) {
				for (int j = 2 ; j <= count ; j++)
					ret+= (count - j + 1);
			}
			for (int i = 0 ; i < 26 ; i++){
				if (table[i]){
					ret++;
				}
			}
			return ret;
		}
};
#else
class Solution {
	public:
		int findSubstringInWraproundString(string p){
			int size = p.size();
			int ret = 0;
			int alphaCount[26] = {0};
			string start;

			if (p.empty())
				return ret;
			if (p.size() == 1)
				return 1;

			int count = 1;
			int i = 0;
			while( i < size){
				if (count == 1)
					start = p[i];
				if (i+1 < size) {
					if (p[i+1] - p[i] == 1 ||
							p[i+1] - p[i] == 'a' - 'z')
						count++;
					else {
						if (count > alphaCount[start[0] - 'a'])
							alphaCount[start[0] - 'a'] = count;
						count = 1;
					}
				}
				i++;
			} 
			if (count > alphaCount[start[0] - 'a'])
				alphaCount[start[0] - 'a'] = count;

			
			for (int i = 0 ; i < 26 ; i++){
				if (alphaCount[i]!= 0){
					ret += calcu(alphaCount[i]);
				}
			}

			return ret;
		}
		int calcu(int x){
			int ret = 0;
			for (int i = 1 ; i <=x ; i++ )
				ret +=i;
			return ret;
		}
};
#endif

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	string A("abaab");
	string B("cac");
	string C("zaba");
	string D("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	Solution sol;
	cout << sol.findSubstringInWraproundString(A) << endl;
	cout << sol.findSubstringInWraproundString(B) << endl;
	cout << sol.findSubstringInWraproundString(C) << endl;
	cout << sol.findSubstringInWraproundString(D) << endl;
	cout << "\n";

	return 0;
}
