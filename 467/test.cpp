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
	int ret;
	map<string, int> test;
	test["111"] = 111;
	test["222"] = 222;
	for (map<string,int>::iterator iter = test.begin();
	iter!= test.end() ; iter++){
		cout << iter->first <<":" << iter->second << endl;
	}
	test["111"] = 333;
	cout << test["111"] << endl;

	for (map<string,int>::iterator iter = test.begin();
	iter!= test.end() ; iter++){
		cout << iter->first <<":" << iter->second << endl;
	}


	return 0;
}

