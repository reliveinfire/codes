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
//			carry = (ta % tb)%1;
			carry = ta & tb;
		} else {
			carry = ta | tb;
		}
//		cout << i <<":" << ta <<":"<<tb<<":"<<tc;
//		cout <<":"<<carry << endl;
		ans = ans | (tc << i);
	}
	return ans;
}


int helper(int a, int b, int carry, int i)
{
	int ans = 0;
	int ta = (a >> i) & 1;
	int tb = (b >> i) & 1;
	int tc = carry ^ ta ^ tb;
	if (!carry){
		carry = ta & tb;
	} else {
		carry = ta | tb;
	}
	ans = (tc << i);
	if (i == 31)
		return ans;
	else
		return ans | helper(a,b,carry, i+1);
}
int add2(int a, int b){
	return helper(a,b,0,0);
}


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	cout << add2 (3,4)  <<endl;
	cout << add2 (9,10) << endl;
	cout << add2 (-100,-300) << endl;

	return 0;
}
