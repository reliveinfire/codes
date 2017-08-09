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
	bool checkInclusion(string s1, string s2){
		int dic[26] = {0};
		if (s1.empty() || s2.empty())
			return false;
		for (int i = 0 ; i < s1.size() ; i++)
			dic[s1[i] - 'a']++;
		int j = 0;
		for (int i = 0 ; i < s2.size() ; i++){
			dic[s2[i] - 'a']--;
			if (i-j+1 > s1.size()){
				dic[s2[j] - 'a']++;
				j++;	
			}
			if (allZero(dic))
				return true;
		}
		return false;
		
	}
	bool allZero(int dic[]){
		for (int i = 0 ; i < 26 ; i++){
			if (dic[i]!= 0)
				return false;
		}
		return true;
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
	ret = sol.
	ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
