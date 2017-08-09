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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int longestConsecutive(vector<int>& nums){
		map<int,int> table;
		if (nums.empty())
			return 0;
		int ret = 0;
		for (int i = 0 ; i < nums.size() ; i++){
			table[nums[i]] = 1;
		}
		for (map<int,int>::iterator iter = table.begin() ; iter != table.end() ; iter++){
			
		}
		while (!table.empty()){
			map<int,int>::iterator iter = table.begin();
			int up = 0, down = 0;
			int tmp;
			tmp = iter->first + 1;
			while(true){
				map<int,int>::iterator tt = table.find(tmp);
				if (tt!= table.end()){
					up++;
					tmp = tt->first + 1;
					table.erase(tt);
				} else {
					break;	
				}
			}
			tmp = iter->first - 1;
			while(true){
				map<int,int>::iterator tt = table.find(tmp);
				if (tt!= table.end()){
					down++;
					tmp = tt->first - 1;
					table.erase(tt);
				} else {
					break;	
				}
			}
			table.erase(iter);
			ret = max(ret, up + down + 1);
		}
		return ret;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {100,4,200,1,5,2};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.longestConsecutive(da);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
