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
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	int longestStr(string s, int k){
		unordered_map<char,int> cnt;
		int i, j;
		int ans = INT_MIN;
		if (k<0)
			return 0;
		if (k>=s.size())
			return s.size();
		for (i=0, j=0 ; i < s.size() ; i++){
			if (cnt.size() <= k){
				cnt[s[i]]++;
				ans =  max(ans, i - j + 1);
			} else {
				while(cnt.size()>k){
					cnt[s[j]]--;
					if (cnt[si] == 0)
						cnt.erase(s[j]);
					j++;
				}
			}
		}
		return ans;	
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
