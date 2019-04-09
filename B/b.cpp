#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

// print 1d array
void pprint1(int ray[100], int size) {
    cout << "[";
    for(int i = 0; i < size; i++) {
        cout << ray[i] << " ";
    }
    cout << "]" << endl;
}

// print 2d array
void pprint2(int ray[100][3], int n, int m) {
    cout << "{";
    for(int i = 0; i < n; i++) {
        pprint1(ray[i], m);
    }
    cout << "}" << endl;
}

int main() {
    int n = 0;
    int t = 0;
    int p[100]; // planets with teleporters, flagged by index
    int inv[100][3]; // parts inventory of all planets
    int ships = 0;

    cin >> n;
    cin >> t;

    // flag planets
    for(int i = 0; i < 100; i++) {
        p[i] = 0;
    }
    for(int i = 0; i < t; i++) {
        int temp = -1;
        cin >> temp;
        if(temp < 1) {
            cout << "temp fucked up: "<< temp << endl;
            exit(1);
        }
        p[temp - 1] = 1;
    }

    // load inventory
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> inv[i][j];
        }
    }

    int shared[3] = {0, 0, 0}; // inv of planets with a teleporter, 
    // all planets with teleporters effectively have the same invetory
    

    // compute shared inventory
    for(int i = 0; i < n; i++) {
        if(p[i] == 1) {
            for(int j = 0; j < 3; j++) {
                shared[j] += inv[i][j];
            }
        }
    }

    //pprint1(shared, 3);

    // traverse inventory
    for(int i = 0; i < n; i++) {
        // check if index i is not flagged
        if(p[i] == 0) {
            int min = INT_MAX;
            // find smallest parts count => max number of space ships possible
            for(int j = 0; j < 3; j++) {
                min = fmin(min, inv[i][j]);
            }
            // sum total ships
            ships += min;
        }
    }

    // compute shared ships
    int shared_min = INT_MAX;
    for(int i = 0; i < 3; i++) {
        shared_min = fmin(shared_min, shared[i]);
    }

    // add shared ships to sum
    ships += shared_min;

    cout << ships;
}
