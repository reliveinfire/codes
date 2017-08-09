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
	int findLUSlength(vector<string>& strs){
		int tmax = 0;
		bool same = true;
		vector<int> allsize;
		vector<int> target;
		if (strs.size() == 1)
			return -1;
		int pre;
		int size;
		for (int i = 0 ; i < strs.size() ; i++){
			size = strs[i].size();
			allsize.push_back(size);
		}
		for (int i = 0 ; i < allsize.size() ; i++){
			size = allsize[i];
			tmax = max(tmax, size);
		}
		for (int i = 0 ; i < allsize.size() ; i++){
			size = allsize[i];
			if (size == tmax)
				target.push_back(i);
		}
		if (target.size()==1)
			return tmax;
		char compare;
		int count = 0;
		string tmp = strs[target[0]];
		for (int j = 0 ; j < tmp.size() ; j++){
			compare = tmp[j];
			for (int i = 0 ; i < target.size() ; i++){
				int index = target[i];
				if (compare != strs[index][j]){
					count++;
					break;
				}
			}
		}
		if (count == 0)
			return -1;
		return tmax;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("aaa");
	string sb("aa");
	string sc("aa");
	genVector(da, A);
	genVector(db, B);
	vector<string> strs;
	strs.push_back(sa);
	strs.push_back(sb);
	strs.push_back(sc);
	Solution sol;
	int ret = sol.findLUSlength(strs);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
