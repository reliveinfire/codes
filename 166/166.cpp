#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	string fractionToDecimal(int onum, int oden){
		string ans;
		long mod, div;
		long num = onum;
		long den = oden;
		unordered_map<int,int> oldmod;
		int numN = 1, denN = 1;
		if (num == 0)
			return string("0");
		if (num < 0){
			num = -num;
			numN = -1;
		}
		if (den < 0 ){
			den = -den;
			denN = -1;
		}
		if (numN * denN < 0)
			ans += string("-");
		bool lowerZero = false;
		while(true){
			if (num < den){
				if (ans.empty() || (ans[0] == '-' && ans.size() == 1))
					ans += string("0");
				if (!lowerZero){
					ans += string(".");
					lowerZero = true;
				} 
				if (lowerZero){
					oldmod[num]++;
					if (oldmod[num] == 3)
						break;
				}
				num *= 10;
			}
			div = num / den;
			mod = num % den;
			ans += to_string(div);
			if (mod == 0){
				return ans;
			} else {
				num = mod;
			}
		}
		int pos = 0;
		for (unordered_map<int,int>::iterator iter = oldmod.begin() ; iter != oldmod.end() ; iter++){
			if (iter->second > 1)
				pos++;
		}
		ans.erase(ans.size()-pos, pos);
		ans.insert(ans.size()-pos, string("("));
		ans+= string(")");
		return ans;
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
	string ret;
	ret = sol.fractionToDecimal(-2147483648,1);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
