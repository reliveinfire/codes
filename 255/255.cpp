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
	bool verifyPreorder(vector<int>& preorder){
		for (int i = 0 ; i+1 < preorder.size() ; i++){
			int isIncrease = 0;
			for (int j = i+1 ; j < preorder.size() ; j++){
				cout << i <<":" << j <<  " isIncrease:" << isIncrease<<endl;
				if (j == i+1){
					if (preorder[j] > preorder[i])
						isIncrease = 1;
				}
				if (!isIncrease){
					if (preorder[j]> preorder[j])
						isIncrease = 1;
				} else {
					if (preorder[j] < preorder[i])
						return false;
				}
				
			}
			
		}
		return true;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//vector<int> A = {50,30,20,40,35,70,60,80};
	//vector<int> A = {50,30,20,80,35,70,60,40};
	vector<int> A = {2,5,1,3,6};
	Solution sol;
	vector<int> ret_vec;
	int ret;
	ret = sol.verifyPreorder(A);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
