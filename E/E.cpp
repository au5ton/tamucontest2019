#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	int n, k;
	cin >> n>> k;
	vector<string> msg;
	map<string, set<string>> p;
	string word, trans;
	for (int i = 0; i < n; ++i) {
		cin >> word;
		msg.push_back(word);
	}
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j < x; ++j) {
			cin >> word >> trans;
			if (p.find(word) == p.end()) {
				p[word] = set<string>();
			}
			p[word].insert(trans);
		}
	}
	long long m = 1;
	for (string w : msg) {
		if (p.find(w) == p.end()) {
			cout << 0 << endl;
			return 0;
		}
		m *= p[w].size();
		m %= 1000000007;
	}
	cout << m << endl;
}
