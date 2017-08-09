#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;
class Solution {
	public:
	string convertToBase7(int num){
		int mod;
		string tmp;
		string ret;
		stringstream ss;
		if (num == 0)
			return string("0");
		string flag("");
		if (num < 0){
			num = 0 - num;
			flag += string("-");
		}
		while(num!=0){
			mod = num % 7;
			ss << mod;
			tmp += ss.str();
			ss.str("");
			num = num/7;
		}
		reverse(tmp.begin(), tmp.end());
		ret = ret + flag + tmp;
		return ret;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	string ret = sol.convertToBase7(-99);
	cout << ret << "\n";
	
	ret = sol.convertToBase7(0);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
