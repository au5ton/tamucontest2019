#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

struct range {
    int a;
    int b;
    // for pretty printing
    friend std::ostream& operator <<(std::ostream& os, const range& ab)
    {
        return os << "<" <<ab.a << " " << ab.b << ">";
    }
};

// for debugging
void pprint(range* ab, int size){
    cout << "{";
    for(int i = 0; i < size; i++) {
        cout << ab[i] << " ";
    }
    cout << "}" << endl;
}

int main() {
    int n = 0;
    int l = 0;
    int r = 0;

    cin >> n;
    cin >> l;
    cin >> r;

    //cout << "l: " << l << ", r: " << r << endl;

    // on the heap
    range* ab = new range[n];

    // load ab
    for(int i = 0; i < n; i++) {
        cin >> ab[i].a;
        cin >> ab[i].b;
    }

    int ptmin = INT_MAX;

    // traverse l to r
    for(int i = l; i <= r; i){
        //cout << "[@" << i << "]";
        int pt = 0;
        int delta = INT_MAX;
        bool on_bound = false;

        // for every asteroid
        for(int j = 0; j < n; j++) {
            // check for passthru
            if(i >= ab[j].a && i <= ab[j].b) {
                pt++;
            }
            // if on boundary of any asteroid
            if(i == ab[j].a || i == ab[j].b) {
                on_bound = true;
            }

            // compute next target
            for(int k = 0; k < 2; k++) {
                // if candidate target actually moves forward, not back or still
                if(k == 0) {
                    int dd = ab[j].a - i;
                    if((dd > 0) && (i + dd) <= r) {
                        delta = fmin(delta, dd);
                    }
                }
                if(k == 1) {
                    int dd = ab[j].b - i;
                    if((dd > 0) && (i + dd) <= r) {
                        delta = fmin(delta, dd);
                    }
                }
            }
        }
        if(delta > 1 && on_bound == true && i < (r-1)) {
            delta = 1;
        }
        //cout << " delta:" << delta;
        //cout << " pt:" << pt;

        // if we're at the end
        if(i == r) {
            //cout << "end";
            ptmin = fmin(ptmin, pt);
            break;
        }
        // if delta unchanged (no more asteroids to jump to)
        if(delta == INT_MAX) {
            delta = 0;
            i = r;
        }

        // jump to closest asteroid boundary
        i += delta;
        // record lowest passthru
        ptmin = fmin(ptmin, pt);
        //cout << endl;
    }
    //cout << "\n\n" << ptmin << endl;
    cout << ptmin;
}
