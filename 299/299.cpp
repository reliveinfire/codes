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
	string getHint(string secret, string guess){
		unordered_map<char, int> sec;
		for (int i = 0 ; i < secret.size() ; i++)
			sec[secret[i]]++;
		int countA = 0, countB = 0;
		for (int i = 0 ; i < guess.size() ; i++){
			if (guess[i] == secret[i]){
				countA++;
				sec[guess[i]]--;
			} else if (secret[i]!=guess[i] && sec.count(guess[i])!= 0){
				countB++;
				sec[guess[i]]--;
			}
			if (sec[guess[i]]==0)
				sec.erase(guess[i]);
		}
		return to_string(countA) + string("A") + to_string(countB) + string("B");
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
	ret = sol.getHint("1123","0111");
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
