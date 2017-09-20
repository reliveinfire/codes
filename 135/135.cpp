#include "../helpers.cpp"

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
	private:
		class Element{
			public:
			int rate;
			int pos;
			Element(int r, int p){
				rate = r;
				pos = p;
			}
			bool operator>(const Element& ele)const{
				return rate > ele.rate;
			}
		};
        public:
        int candy(vector<int>& ratings){
		int res = 0;
		vector<int> cands(ratings.size());
		priority_queue<Element, vector<Element>, greater<Element>> pq;
		for (int i = 0 ; i < ratings.size() ; i++){
			pq.push(Element(ratings[i],i));
		}
		while(!pq.empty()){
			Element top = pq.top();
			pq.pop();
			int ll = 0;
			int rr = 0;
			if (top.pos>0){
				if (ratings[top.pos] > ratings[top.pos-1] )
					ll = cands[top.pos-1]+1;
			}
			if (top.pos<ratings.size()-1){
				if (ratings[top.pos] > ratings[top.pos+1])
					rr = cands[top.pos+1]+1;
			}
			cands[top.pos] = max(ll,rr);
			res += cands[top.pos];
		}
		return res;
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
