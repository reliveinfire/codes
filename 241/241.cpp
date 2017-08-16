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
	vector<int> diffWaysToCompute(string input){
			return compute(input, 0, input.size() - 1);
	}

	vector<int> compute(string str, int ss, int ee){
		vector<int> ans;
		bool found = false;
		for (int i = ss ; i <= ee ; i++){
			if (str[i] == '+' || str[i]=='-' || str[i]=='*'){
				found = true;
				vector<int> left = compute(str, ss, i-1);
				vector<int> right = compute(str, i+1, ee);
				for (int l = 0 ; l < left.size() ; l++){
					for (int r = 0 ; r < right.size() ; r++){
						int tmp;
						if (str[i]=='+')
							tmp = left[l] + right[r];
						else if (str[i] == '-')
							tmp = left[l] - right[r];
						else if (str[i]=='*')
							tmp = left[l] * right[r];
						ans.push_back(tmp);
						cout << left[l] <<":" <<right[r] <<"="<< tmp << endl;
					}
				}
			}
		}
		if (!found){
			str = str.substr(ss, ee - ss + 1);
			return {stoi(str)};
		}
		return ans;
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
	ret_vec = sol.diffWaysToCompute("2*3-4*5");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
