#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> exclusiveTime(int n, vector<string>& logs){
		vector<int> res(n, 0);
		int pre_time=-1;
		string pre_type;
		stack<int> st; // func
		for (string str : logs){
			int pos1 = str.find(":", 0);
			int pos2 = str.find(":", pos1+1);
			string func = str.substr(0, pos1);
			string type = str.substr(pos1+1, pos2-pos1-1);
			string time = str.substr(pos2+1, str.size()-pos2);
			int f = stoi(func);
			int t = stoi(time);
			cout << str << " f:" << f <<" t:"<<t << endl;
			cout << type << endl;
			if (st.empty()){
				st.push(f);
			} else {
				int tmp = st.top();
				cout << tmp <<endl;
				if (type=="start"){
					res[tmp] += t - pre_time;
					st.push(f);
				} else {
					res[tmp] += t - pre_time + 1;
					st.pop();
				}
				if (pre_type=="end")
					res[tmp]--;
			}
			pre_time = t;
			pre_type = type;
		}
		return res;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> log = {
		"0:start:0",
		"0:end:5",
		"1:start:6",
		"1:end:6"
	};
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	auto ret = sol.exclusiveTime(2, log);
	for (int it : ret)
		cout << it  << " ";
	cout << endl;
	return 0;
}
