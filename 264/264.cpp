#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	int nthUglyNumber(int n){
		priority_queue<long,vector<long>,greater<long>> pq;
		unordered_set<long> set;
		long ans;
		pq.push(1);
		set.insert(1);
		while(n>1){
			long tmp;
//			cout << pq.top() << endl;
			tmp = pq.top()*2;
			if (set.count(tmp)==0){
				set.insert(tmp);
				pq.push(tmp);
			}
			tmp = pq.top()*3;
			if (set.count(tmp)==0){
				set.insert(tmp);
				pq.push(tmp);
			}
			tmp = pq.top()*5;
			if (set.count(tmp)==0){
				set.insert(tmp);
				pq.push(tmp);
			}
			set.erase(pq.top());
			pq.pop();
			n--;
		}
		return pq.top();
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.nthUglyNumber(4);
	cout << ret << "\n";
	ret = sol.nthUglyNumber(10);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
