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
	int findPairs(vector<int>& nums, int k){
		map<int,int> table;
		map<int,int> visit;
		int result = 0;
		if (nums.size()<=1)
			return 0;
		for (int i = 0 ; i < nums.size() ; i++){
			int tt = nums[i];
			if (table.find(tt)!= table.end())
				table[tt]++;
			else
				table[tt] = 1;
		}
		map<int,int>::iterator iter;
		if (k ){
			for (int i = 0 ; i < nums.size() ; i++){
				int tt = nums[i];
				if (visit.find(tt) != visit.end())
					continue;
				iter = table.find(tt+k);
				if (iter != table.end()){
					result++;
				}
				visit[tt] = 1;
			}
		} else {
			for (iter = table.begin() ; iter!=table.end() ; iter++){
				if (iter->second > 1)
					result++;
			}
		}
		return result;
		
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {3,1,4,1,5};
	int B[] = {1,3,1,5,4};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	int ret;
	ret = sol.findPairs(da,2);
	cout << ret << "\n";
	ret = sol.findPairs(db,0);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
