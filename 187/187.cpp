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
	vector<string> findRepeatedDnaSequences(string s) {
		map<string, int> table;
		vector<string> result;
		map<string,int>::iterator iter;
		map<string,int> insert;
		if (s.empty())
			return result;
		if (s.size() < 10)
			return result;
			

		for(int i = 0 ; i <= s.size()-10 ; i++){
			string tmp = s.substr(i,10);
			iter = table.find(tmp);
			if (iter==table.end()){
				table[tmp] = 1;
			} else {
				if (insert.find(tmp) == insert.end()){
					result.push_back(tmp);
					insert[tmp] = 1;
				}
			}
		}
		return result;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int ret;
	vector<string> ret_vec;
	string aa("AAAAAAAAAAAA");
	Solution sol;
	ret_vec = sol.findRepeatedDnaSequences(aa);
	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << endl;

	return 0;
}
