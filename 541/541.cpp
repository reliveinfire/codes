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
	string reverseStr(string s, int k){
		stack<string> sk;
		string result;
		int local_k = k;
		for (int i = 0 ; i < s.size() ; i++){
			if (i% (2*k) == 0)
				local_k = k;

			if (local_k > 0 ){
				sk.push(s.substr(i,1));
				local_k--;
			} else if (local_k == 0){
				while(!sk.empty()){
					result += string(sk.top());
					sk.pop();
				}
				local_k = -1;
			}
			if (local_k < 0)
				result += s.substr(i,1);
		}

		while(!sk.empty()){
			result += string(sk.top());
			sk.pop();
		}
		return result;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("abcdefg");
	string sb("gd123445");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	string ret;
	ret = sol.reverseStr(sa,2);
	cout << ret << "\n";
	ret = sol.reverseStr(sb,3);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
