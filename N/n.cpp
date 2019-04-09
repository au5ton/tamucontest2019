#include <iostream>
#include <string>

using namespace std;

int main() {
    int n = 0;
    int sum = 0;
    const int U = 19;
    const int Pu = 20;
    const int Th = 12;
    string line = "";

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> line;
        if(line.compare("uranium") == 0)
            sum += U;
        if(line.compare("plutonium") == 0)
            sum += Pu;
        if(line.compare("thorium") == 0)
            sum += Th;
    }
    cout <<  sum;
}
