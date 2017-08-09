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
	vector<string> fizzBuzz(int n){
		vector<string> ans;
		
		for (int i = 1 ; i <=n ; i++){
			string tmp;
			if (n%3==0){
				cout << n%3 << endl;
				tmp+= string("Fizz");
			}
			if (n%5==0)
				tmp+= string("Buzz");
			if (tmp.empty())
				tmp+= to_string(n);
			
			ans.push_back(tmp);
		}
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
	vector<string> ret_vec;
	int ret;
	ret_vec = sol.fizzBuzz(3);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
