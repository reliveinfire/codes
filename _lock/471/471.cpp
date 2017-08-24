#include "../../helpers.cpp"
/*not sure if this is correct*/
class Solution {
        public:
        string encodeString(string s){
		unordered_map<string, string> dp;
		return helper(s, dp);
        }
	string helper(string s, unordered_map<string,string>& dp)
	{
		string tmp;
		if (s.size() <= 4)
			return s;
		if (dp.find(s)!= dp.end()){
			return dp[s];
		}
		for (int i = 1 ; i <= s.size()/2 ; i++){
			string cur;
			int cnt = 0;
			string head = s.substr(0, i);
			string next = s.substr(i, s.size() - i);
			while(true){
				string nh = next.substr(0,i);
				if (nh == head){
					cnt++;
					next= next.substr(i, next.size() - i);
				} else
					break;
			}
			string in = helper(head, dp);
			string ou = helper(next, dp);
			if (cnt==0){
				cur += in;
			} else {
				cur += to_string(cnt+1);
				cur += "[" + in + "]";
			}
			cur += ou;
			if (tmp.empty()){
				tmp = cur;
			} else {
				if (cur.size() < tmp.size())
					tmp = cur;
			}
		}
		dp[s] = tmp;
		return tmp;
	}
};
int main()
{
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	string ret;
	//ret = sol.encodeString("aaaaa");
	//ret = sol.encodeString("aabcaabcd");
	ret = sol.encodeString("abbbabbbcabbbabbbc");
	ret = sol.encodeString("abbbabbbcabbbabbbcdededededededededededededed");
	cout << ret << "\n";


	return 0;
}
