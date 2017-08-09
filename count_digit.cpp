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

int countdigit(void)
{
	int count = 0;
	for (int i = 100 ; i <= 199 ; i++){
		char a = i % 10;
		char b = (i /10) %10;
		char c = (i/100) %10;

		if (a==b || a==c || b == c){
			cout << i<< endl;
			count++;
		}
	}
	cout << count <<endl;
	return count;
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
	vector<int> ret_vec;
	int ret;
	countdigit();

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
