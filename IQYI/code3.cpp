

int _max;


int dfs(vector<int> &v, string &f, map<string, int> &m, int n) {
	if (n == 0) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		if (f[i] == '0') {
			int x = i;
			while (x >= 0 && f[x] == '1') {
				x--;
			}
			int left = x >= 0 ? v[x] : 1;
			while (x <= (v.size() - 1) && f[x] == '1') {
				x++;
			}
			int right = x <= (v.size() - 1) ? v[x] : 1;
			int t = left * v[i] * right + dfs(v, f, m, --n);
			m[f] = t;
			if (_max < t) {
				_max = t;
			}
		}
	}
}