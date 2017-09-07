#include "../../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	private:
		struct element{
			int count;
			char cc;
			element(int icount, char icc){count=icount;cc=icc;}
			bool operator<(const element& ele)const{
				if (count==ele.count)
					return cc > ele.cc;
				else
					return count < ele.count;
			}
		};
        public:
        string arrangek(string str, int k){
		priority_queue<element, vector<element>> pq;
		unordered_map<char,int> cnts;
		string ans;
		for (int i = 0 ; i < str.size() ; i++)
			cnts[str[i]]++;
		for (auto iter = cnts.begin() ; iter!=cnts.end() ; iter++){
			element top(iter->second, iter->first);
			pq.push(top);
		}
		int tk = k;
		vector<element> tmp;
		for (int i = 0 ; i < str.size() ; i++){
			if (tk==0){
				tk = k;
				for (int i = 0 ; i < tmp.size() ; i++)
					pq.push(tmp[i]);
				tmp.clear();
			}
			if (pq.empty())
				return "";
			element top = pq.top();
			pq.pop();
			ans += top.cc;
			top.count--;
			if (top.count)
				tmp.push_back(top);
			tk--;
		}
		return ans;
        }
};
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	Solution sol;
	string ret;
	//ret = sol.arrangek("aaadbbcc",2);
	ret = sol.arrangek("aaaabbcc",2);
	cout << ret << "\n";

	return 0;
}
