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
#if 1
class Solution {
	public:
	int findStrobogrammatic(string low, string high){
		int ans = 0;
		for (int i = low.size() ; i <= high.size() ; i++){
			helper(low, high, string(""), i, ans);
			helper(low, high, string("0"), i, ans);
			helper(low, high, string("1"), i, ans);
			helper(low, high, string("8"), i, ans);
		}
		return ans;
	} 
	void helper(string low, string high, string now, int size, int& ans){
		if (now.size() > size)
			return;
		if (now.size() == size){
			if ((now.size() == low.size() && now[0] != '0') || (low==string("0") && now==string("0"))){
				if (now >= low && now <=high){
					cout << "sz low:" << now << endl;
					ans++;
				}
			} else if (now.size() == high.size() && now[0]!= '0'){
				if (now >= low && now <= high){
					cout << "sz high:" << now << endl;
					ans++;
				}
			} else if (now.size()>low.size() && now[0]!='0'){
				cout << "sz lohi:" << now << endl;
				ans++;
			}
		} else {
			helper(low, high, string("0") + now + string("0"), size, ans);
			helper(low, high, string("1") + now + string("1"), size, ans);
			helper(low, high, string("6") + now + string("9"), size, ans);
			helper(low, high, string("8") + now + string("8"), size, ans);
			helper(low, high, string("9") + now + string("6"), size, ans);
		}
		return;
	}
};
#endif
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	vector<string> ret_vec;
	cout << sol.findStrobogrammatic("50","8000") << endl;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	string na("234");
	string nb("222");

	if (na > nb){
		cout << "na geater\n";
	} else {
		cout << "nb greater\n";
	}
	unordered_map<string,string> mm = {{"AAA","As"},{"BBB","Bs"}};
	cout << mm["BBB"] << endl;
	return 0;
}
