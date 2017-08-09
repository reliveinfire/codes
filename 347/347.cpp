#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;
bool mycompare(const pair<int,int>& a, const pair<int,int>& b)
{
	if (a.second > b.second)
		return true;
	else
		return false;
}
class Solution {
	public:
	vector<int> topKFrequent(vector<int>& nums, int k){
		int size = nums.size();
		vector<int> result;
		if (size == 0)
			return result;
		map<int, int> hash;
		map<int, int>::iterator iter;
		for (int i = 0 ; i < size ; i++){
			int target = nums[i];
			iter = hash.find(target);
			if (iter == hash.end()){
				hash[target] = 1;
			} else {
				int tmp = iter->second;
				tmp++;
				hash.erase(iter);
				hash[target] = tmp;
			}
		}
		vector< pair<int,int> > table;
		for (iter = hash.begin() ; iter!= hash.end() ; iter++){
			pair<int,int> pa(iter->first, iter->second);
			table.push_back(pa);
		}
 		sort(table.begin(), table.end(), mycompare);

		for (int i = 0 ; i < k ; i++){
			result.push_back(table[i].first);
		}
		return result;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,1,1,2,2,3};
	genVector(da, A);
	Solution sol;
	vector<int> ret =  sol.topKFrequent(da,2);
	
	for (int i = 0 ; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;

	return 0;
}
