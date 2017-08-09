#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;
#include "../helpers.cpp"
vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};


class Solution {
	public:
	bool isAdditiveNumber(string num){
		return helper(num);
	}

	bool helper(string cur){
		string pre, next;
		for (int i = 0 ; i < cur.size() ; i++){
			pre = cur.substr(0, i+1);
			if (pre.size() * 2 > cur.size())
				break;
			for (int j = i + 1  ; j < cur.size() ; j++){
				next = cur.substr(i+1, j - i);
				if (next[0] == '0')
					continue;
				if (next.size()*2 > cur.size())
					break;
				int ret = checker(pre, next, cur.substr(j+1, cur.size() - 1 -j));
					if (ret)
						return true;
			}
		}
		return false;
	}
	bool checker(string pre, string next, string curr){
		string sum = stradd(pre, next);
		cout << pre <<":" << next << "=" << sum << endl;
		if (sum.size() > curr.size())
			return false;
		else {
			for (int i = 0 ; i < sum.size() ; i++){
				if (sum[i]!=curr[i])
					return false;
			}
			if (sum.size() == curr.size())
				return true;
			else {
				string word = curr.substr(sum.size(), curr.size()-sum.size());
				return checker(next, sum, word);
			}
		}
	}
	string stradd(string a, string b){
		string ans;
		int carry = 0;
		int ai = a.size() -1;
		int bi = b.size() -1;
		while(ai >= 0 || bi >= 0){
			int tmp = 0;
			if (ai>=0)
				tmp += a[ai] - '0';
			if (bi>=0)
				tmp += b[bi] - '0';
			tmp += carry;
			carry = tmp / 10;
			tmp = tmp % 10;
			ans += to_string(tmp);
			ai--;
			bi--;
		}
		if (carry)
			ans += string("1");
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	Solution sol;
	vector<int> ret_vec;
	int ret;
//	ret = sol.isAdditiveNumber("112358");
	//ret = sol.isAdditiveNumber("199100199");
//	ret = sol.isAdditiveNumber("199001200");
	cout << A.begin() << endl;
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
