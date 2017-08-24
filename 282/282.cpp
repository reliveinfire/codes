#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<string> addOperators(string num, int target){
		vector<string> ans;
		helper(num, "", 0, 0, 0, target, ans);
		return ans;
        }
	void helper(string& num, string str, int cur, long now, long last, int target, vector<string>& ans){
		if (cur == num.size() && now == target){
			ans.push_back(str);
			return;
		}
		for (int sz = 1 ; sz <= num.size() - cur ; sz++){
			string tmp = num.substr(cur, sz);
			if (tmp.size()>1 && tmp[0]=='0')
				continue;
			long ts = stol(tmp);
			if (str.empty()){
				helper(num, tmp, cur+sz, ts, ts, target, ans);
			} else {
				helper(num, str+"+"+tmp, cur+sz, now+ts, ts, target, ans);
				helper(num, str+"-"+tmp, cur+sz, now-ts, -ts, target, ans);
				helper(num, str+"*"+tmp, cur+sz, (now-last)+ts*last, ts*last, target, ans);
			}
		}
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	auto ret_vec = sol.addOperators("3456237490",9191);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
#if 0	
	ret_vec = sol.addOperators("105",5);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	
	ret_vec = sol.addOperators("00",0);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
#endif

	return 0;
}
