#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	string removeKdigits(string num, int k){
		if (num.size() <= k)
			return string("0");
		while(k>0){
			if (num[0] - '0' > num[1] - '0'){
				num.erase(0,1);
				while(!num.empty() && num[0] == '0')
					num.erase(0,1);
				if (num.size() <= k - 1)
					return string("0");
			} else {
				int i = 1;
				int n = num.size();
				while(i < n){
					if (num[i] - '0' >= num[i-1] - '0')
						i++;
					else {
						num.erase(i-1,1);
						break;
					}
				}
				if (i==n)
					num.erase(i-1,1);
			}
			k--;
		}
		return num;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	vector<int> ret_vec;
	int ret;
	cout << sol.removeKdigits(string("1173"), 2);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
