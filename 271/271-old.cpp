#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec{
	public:
	string encode(vector<string>& strs){
		string result;
		stringstream ss;
		for (int i = 0 ; i < strs.size() ; i++){
			string target = strs[i];
			for (int j = 0 ; j < target.size() ; j++){
				ss.str("");
				ss << (int)target[j];
				result+= ss.str();
				result += ",";
			}
			result += "#";
		}
		return result;
	}

	vector<string> decode(string s){
		vector<string> result;
		string words, ww;
		string tmp;
		int i = 0;
		while(i < s.size()){
			int pos = s.find("#", i);
			string word = s.substr(i, pos - i);
			int j = 0;
			tmp.clear();
			stringstream ss;
			while( j < word.size()){
				int pp = word.find(",", j);
				ss.str("");
				string ww = word.substr(j, pp - j);
				ss << ww;
				char tt = (char)atoi(ss.str().c_str());
				tmp+= tt;
				j = pp + 1;
			}
			result.push_back(tmp);
			i = pos+1;
		}
		return result;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> ret_vec;
	int A[] = {1,2,3};
	int B[] = {1,2,3};
	string sa("godding");
	string sb("gd");

	genVector(da, A);
	genVector(db, B);
	int ret;
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("ddd");
	strs.push_back("345//22");
	strs.push_back("@@33/##$$");
	strs.push_back("/**[][]");
	strs.push_back("_)(*&^%$#@!");
	Codec cc;
	string tmp = cc.encode(strs);
	cout << tmp << endl;
	ret_vec = cc.decode(tmp);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << "   ";
	cout <<endl;

	return 0;
}
