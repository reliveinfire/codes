#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        string nextClosestTime(string time){
		unordered_set<int> digit;
		int hr = stoi(time.substr(0,2));
		int mi = stoi(time.substr(3));
		digit.insert(hr%10);
		digit.insert((hr/10)%10);
		digit.insert(mi%10);
		digit.insert((mi/10)%10);
		if (digit.size() == 1)
			return time;
		vector<int> hours;
		vector<int> mins;
		gen(digit, 0, 2, 0, hours);
		mins = hours;
		int lmin = INT_MAX;
		string res;
		for (int h : hours){
			for (int m : mins){
				if (0<=h && h <=23 && 0<=m && m <=59){
					int di = diff(hr,mi,h,m);
					if (di < lmin){
						lmin = di;
						string sh = to_string(h);
						string sm = to_string(m);
						if (sh.size()==1)
							sh = "0" + sh;
						if (sm.size()==1)
							sm = "0" + sm;
						res = sh + ":" + sm;
					}
				}
			}
		}
		return res;
        }
	int diff(int hr, int mi, int hh, int mm){
		int orig = 60*hr + mi;
		int comp = 60*hh + mm;
		if (orig > comp)
			return orig - comp;
		else
			return orig-comp + 1440;
	}

	void gen(unordered_set<int>& digit, int cur, int up, int num, vector<int>& val)
	{
		if (cur == up){
			val.push_back(num);
			return;
		}
		for (auto iter = digit.begin() ; iter != digit.end() ; iter++){
			gen(digit, cur+1, up, num*10 + *iter, val);
		}
		return;
	}
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<int> A = {1,2,3};
	vector<int> B = {1,2,3};
	string tre("1,#,3,2,#,#,4,#,5,#,#");
	Codec cc;
	//TreeNode* node = cc.deserialize(tre);
	//cout <<  cc.serialize(node) << endl;
	Solution sol;
	int ret;
	ret = sol.
	auto ret_vec = sol.
	cout << ret << "\n";

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
