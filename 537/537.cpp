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
class compNum{
	public:
	int rr;
	int ii;
	compNum(int r,int i){rr = r;ii = i;}
	compNum(){}
};
class Solution {
	public:
	string complexNumberMultiply(string a, string b){
		int ar, ai, br, bi, ansR, ansI;
		string result;
		stringstream ss;
		compNum cc;
		cc = parse(a);
		ar = cc.rr;ai = cc.ii;	
		cc = parse(b);
		br = cc.rr;bi = cc.ii;
		ansR = (ar * br) - (ai*bi);
		ansI = (ar * bi) + (ai * br);
		cout << ar <<":"<< ai<<endl;
		cout << br <<":"<< bi<<endl;
		ss << ansR;ss << "+";ss << ansI;ss << "i";
		result += ss.str();
		return result;
	}

	compNum parse(string s)
	{
		compNum cc;
		int negative = 0;
		string tmp;
		for (int i = 0 ; i < s.size() ; i++){
			if (s[i] == '-')
				negative = 1;
			else if (s[i] == '+'){
				cc.rr = atoi(tmp.c_str());
				if (negative)
					cc.rr = 0- cc.rr;
				negative = 0;
				tmp.clear();
			} else if(s[i] == 'i'){
				cc.ii = atoi(tmp.c_str());
				if (negative)
					cc.ii = 0- cc.ii;
			}else
				tmp += s.substr(i,1);
		}
		return cc;
	}
};

#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("78+-76i");
	string sb("-86+72i");
	genVector(da, A);
	genVector(db, B);
	Solution sol;
	string ret;
	ret = sol.complexNumberMultiply(sa,sb);
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
