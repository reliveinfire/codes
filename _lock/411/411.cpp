#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
int abblen(const string& str){
	int len = 1;
	enum State{NUM, STR};
	enum State st;
	if (str[0]>= '0' && str[0]<='9')
		st = NUM;
	else
		st = STR;
	for (int i = 1 ; i < str.size() ; i++){
		if (str[i]>='0' && str[i]<='9'){
			if (st != NUM)
				len++;
			st = NUM;
		} else {
			st = STR;
			len++;
		}
	}
	return len;
}
bool comp(const string& a, const string& b){
	return abblen(a) < abblen(b);
}
class Solution {
        public:
        string minAbber(string str, vector<string>& dict){
		vector<string> res;
		helper(str, 0, 0, res, "");
		sort(res.begin(), res.end(), comp);
		string ans;
		for (string ss : res)
			cout << ss << endl;
		for (int i = 0 ; i < res.size() ; i++){
			int j;
			ans = res[i];
			for (j = 0 ; j < dict.size() ; j++){
				int ret = check(dict[j], ans);
				if (ret)
					break;
			}
			if (j==dict.size())
				break;
		}
		return ans;
        }
	bool check(string& dic, string& str){
		int m = dic.size();
		int n = str.size();
		int i = 0, j = 0;
		while (i < m && j < n){
			if (str[j] >= '0' && str[j] <= '9'){
				int size = 0;
				while(j<n && str[j]>='0' && str[j]<='9'){
					size = size * 10;
					size += str[j]-'0';
					j++;
				}
				i += size;	
			} else {
				if (dic[i]!=str[j])
					return false;
				i++;j++;
			}
		} 
		return i==m && j==n;
	}
private:
	void helper(string str, int pos, int count, vector<string>& res, string ss){
		if (pos == str.size()){
			if (count > 0)
				ss = ss + to_string(count);
			res.push_back(ss);
			return;
		}
		helper(str, pos+1, count+1, res, ss);
		if (count>0)
			helper(str, pos+1, 0, res, ss + to_string(count) + str[pos]);
		else
			helper(str, pos + 1, count, res, ss+str[pos]);
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Codec cc;
	vector<string> dict = {"plain","amber","blade"};
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	string ret;
	ret = sol.minAbber("apple", dict);
	cout << ret << "\n";

	return 0;
}
