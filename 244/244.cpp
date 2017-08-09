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
	int shortestDistance(vector<string> words, string word1, string word2){
		int idx1 = -1, idx2 = -1;
		int ans = INT_MAX;
		for (int i = 0 ; i < words.size() ; i++){
			if (word1 == words[i])
				idx1 = i;
			else if (word2 == words[i])
				idx2 = i;
			if (idx1 >= 0 && idx2 >= 0){
				ans = min(ans, abs(idx1-idx2));
			}
		}
		return ans;	
	}
};

class shortDistance
{
	public:
		shortDistance(vector<string> w){
			words.assign(w.begin(), w.end());
		}
		int distance(string word1, string word2){
		
		}
	private:
		vector<string> words;
}

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
