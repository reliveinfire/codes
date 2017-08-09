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


bool checkX(int X, map<int,int>& tb){
	if (tb.size() < X)
		return false;
	int pre;
	auto iter = tb.begin();
	for (int i = 0; i < X ; i++, iter++){
		if (i == 0){
			pre = iter->first;
		} else {
			if (pre != iter->first - 1)
				return false;
			else
				pre = iter->first;
		}
	}
	iter = tb.begin();
	for (int i = 0 ; i < X ; i++){
		iter->second--;
		auto pre = iter;
		iter++;
		if (iter->second == 0){
			tb.erase(pre);
		}
	}
	return true;
}

bool helper(map<int,int> tb)
{
	if (tb.size() == 0){
		return true;
	}
	for (int i = 3 ; i <= tb.size() ; i++){
		map<int,int> tmp = tb;
	//	cout << tmp.size()<<":" << i  << endl;
		if (checkX(i, tmp)){
	//		cout << "true\n";
			int ret = helper(tmp);
			if (ret)
				return true;
		}
	}
	return false;
}
bool detX(vector<int>& nums){
	map<int,int> tb;
	for (int item : nums)
		tb[item]++;
	return helper(tb);
}


#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	//vector<int> A = {1,2,3,4,4,5,6};
	vector<int> A = {1,2,3,2,4,5,6};
	cout << detX(A);

	return 0;
}
