#include "../helpers.cpp"
#ifdef I2C
static void i2c_flush_rxfifo(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        while (readl(&i2c_base->ic_status) & IC_STATUS_RFNE) {
                readl(&i2c_base->ic_cmd_data);
                //debug("flush rxfifo: read data %02x\n", data);
        }
}
static int i2c_wait_for_bb(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;

        //debug("wait for BB: ic status %08x\n", readl(&i2c_base->ic_status));
        while ((readl(&i2c_base->ic_status) & IC_STATUS_MA) ||
               !(readl(&i2c_base->ic_status) & IC_STATUS_TFE)) {
                /* Evaluate timeout */
                udelay(1000);
                count++;
                if (count > TIMEOUT_LOOP)
                        return 3;
        }

        return 0;
}
static int i2c_xfer_init(struct i2c_adapter *adap, uchar chip, uint addr,
                         int alen)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int ret = i2c_wait_for_bb(adap);
        if (ret){
                return ret;
        }

        i2c_setaddress(adap, chip);
        while (alen) {
                alen--;
                /* high byte address going out first */
                writel((addr >> (alen * 8)) & 0xff,
                       &i2c_base->ic_cmd_data);
        }
static int i2c_xfer_finish(struct i2c_adapter *adap)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);

        int count = 0;
        while (1) {
                if ((readl(&i2c_base->ic_raw_intr_stat) & IC_STOP_DET)) {
                        readl(&i2c_base->ic_clr_stop_det);
                        break;
                } else if (count > TIMEOUT_LOOP){
                        break;
                } else {
                        udelay(1000);
                        count++;
                }
        }

        if (i2c_wait_for_bb(adap)) {
                return 5;
        }

        i2c_flush_rxfifo(adap);

        return 0;
}

static int dw_i2c_read(struct i2c_adapter *adap, u8 dev, uint addr,
                       int alen, u8 *buffer, int len)
{
        struct i2c_regs *i2c_base = i2c_get_base(adap);
        int count = 0;
        int ret = i2c_xfer_init(adap, dev, addr, alen);
        if (ret){
                return ret;
        }

        if (len == 1)
                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
        else if (len > 0)
                writel(IC_CMD, &i2c_base->ic_cmd_data);

        while (len) {
                if ((readl(&i2c_base->ic_status) & IC_STATUS_RFNE) != 0) {
                        *buffer++ = (uchar)readl(&i2c_base->ic_cmd_data);
                        len--;
                        if (len == 1)
                                writel(IC_CMD | IC_STOP, &i2c_base->ic_cmd_data);
                        else if (len > 0)
                                writel(IC_CMD, &i2c_base->ic_cmd_data);
                } else if (count > TIMEOUT_LOOP){
                        return 7;
                } else {
                        count++;
                        // 4bytes + address, start/stop bit, take it as 8 bytes
                        // 8 bytes = 256 bits
                        udelay(5000);
                }
        }

        return i2c_xfer_finish(adap);
}
int giu_i2c_read(unsigned int reg)
{
        unsigned int val;
        dw_i2c_read(NULL, GIU_SLAVE_ADDR, reg, 1, (u8*)&val, 4);
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        return val;
}

int giu_i2c_write(unsigned int reg, unsigned int val){
        int ret = 0;
        val = (val &0x00FFFF00) | (val &0xFF) << 24 | (val &0xFF000000) >> 24;
        val = (val &0xFF0000FF) | (val &0xFF00) << 8 | (val&0xFF0000) >> 8;
        ret = dw_i2c_write(NULL, GIU_SLAVE_ADDR, reg, 1, (uint8_t*)&val, 4);
        return ret;
}
int wl = L[0].size();
for (int i = 0; i < wl; ++i) {
	int left = i, count = 0;
	unordered_map<string, int> tdict;
	for (int j = i; j <= n - wl; j += wl) {
		string str = S.substr(j, wl);
		// a valid word, accumulate results
		if (dict.count(str)) {
			tdict[str]++;
			if (tdict[str] <= dict[str]) 
				count++;
			else {
				// a more word, advance the window left side possiablly
				while (tdict[str] > dict[str]) {
					string str1 = S.substr(left, wl);
					tdict[str1]--;
					if (tdict[str1] < dict[str1]) count--;
					left += wl;
				}
			}
			// come to a result
			if (count == cnt) {
				ans.push_back(left);
				// advance one word
				tdict[S.substr(left, wl)]--;
				count--;
				left += wl;
			}
		}
		// not a valid word, reset all vars
		else {
			tdict.clear();
			count = 0;
			left = j + wl;
		}
	}
}
#else

vector<int> preOrder = {100,50, 40, 80, 60, 200, 150, 180, 250};
class Solution {
        public:
        vector<int> findSubstring(string s, vector<string>& words){
		vector<int> res;
		unordered_map<string,int> ww;
		vector<int> visit(s.size(), 0);
		if (words.size() == 0)
			return res;
		int sz = words[0].size();
		for(string str:words)
			ww[str]++;
		for (int i = 0 ; i + sz * words.size() - 1 < s.size() ; i++ ){
			if (!visit[i]){
				visit[i] = 1;
				if (ok(s,i,ww)){
					res.push_back(i);
					printf("i:%d\n", i);
					int left = i;
					int right = i + sz*words.size();
					left += sz;
					right += sz;
					while(right < s.size()){
						visit[left] = 1;
						printf("left:%d right:%d\n",left, right);
						cout<<	s.substr(left-sz,sz) << " "<< s.substr(right-sz,sz);
						if (s.substr(left-sz,sz)==s.substr(right-sz,sz))
							res.push_back(left);
						else
							break;
						left += sz;
						right += sz;
					}
				}
			}
		}
		return res;
        }
	bool ok(string s, int i, unordered_map<string,int> wo){
		int sz = wo.begin()->first.size();
		while(!wo.empty()){
			string tmp = s.substr(i, sz);
			if (wo.count(tmp)==0)
				return false;
			else {
				i += sz;
				wo[tmp]--;
				if (wo[tmp]==0)
					wo.erase(tmp);
			}
		}
		return true;
	}
};
#endif
#define genVector(data, array) vector<int> data(array, array+sizeof(array)/sizeof(array[0]));
int main()
{
	vector<string> b = {"foo","bar","the"};
	Solution sol;
	auto ret_vec = sol.findSubstring("barfoofoobarthefoobarman" ,b);

	for (int i = 0 ; i < ret_vec.size() ; i++)
		cout << ret_vec[i] << " ";
	cout <<endl;

	return 0;
}
