#include <iostream>
#include <initializer_list>
#include <cmath>
#include <vector>
using namespace std;

struct P{
	double x;
	double y;
	double z;
	bool operator==(const P &o) {
		return x == o.x && y == o.y && z == o.z;
	}
};

double dist(P p1, P p2) {
	double dx = (p2.x - p1.x) * (p2.x - p1.x);
	double dy = (p2.y - p1.y) * (p2.y - p1.y);
	double dz = (p2.z - p1.z) * (p2.z - p1.z);
	return sqrt(dx + dy + dz);
}

int main(){ 
	int n, k;
	cin >> n >> k;
	vector<P> planets;
	for (int i = 0; i < n; ++i) {
		double x, y, z;
		cin >> x >> y >> z;
		planets.push_back({x, y, z});
	}
	vector<P> reached {{0, 0, 0}};
	int n_ = 0;
	while (true){ 
		n_  = 0;
		for (P &p : planets) {
			for (P &r : reached) {
				if (p.x == r.x && p.y == r.y && p.z == r.z) {
					break;
				}
				if (dist(p, r) <= k) {
					reached.push_back(p);
					++n_;
					break;
				}
			}
		}
		if (n_ == 0) {
			break;
		}
	}
	cout << reached.size() - 1 << endl;
}
