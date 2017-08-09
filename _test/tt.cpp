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
#include <set>
#include <map>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int add(int a, int b){
	int ans = 0;
	int carry = 0;
	for (int i = 0 ; i < 32 ; i++){
		int ta = (a >> i) & 1;
		int tb = (b >> i) & 1;
		int tc = carry ^ ta ^ tb;
		if (!carry){
			carry = ta % tb;
		} else {
			carry = ta | tb;
		}
		ans |= tc << i;
	}
	return ans;
}


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	cout << add (3,4);
	set<int> set;
	set.insert(11);
	set.insert(7);
	set.insert(9);
	set.insert(10);
	set.insert(3);
	set.insert(22);
	map<int, string> map = {{4,"D"},{1,"A"},{5,"E"},{3,"C"}};
	for (auto iter = set.begin() ; iter!=set.end() ; iter++)
		cout << *iter << endl;
	
	for (auto iter = map.begin() ; iter!=map.end() ; iter++)
		cout << iter->first <<"==" << iter->second << endl;

	vector<int> ret_vec;
	int ret = 0;

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
