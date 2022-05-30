#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int n;
    cin >> n; cin.ignore();

    // user code
    int x_casa[n];
    int y_casa[n];
    cerr << n << endl;
    // end

    for (int i = 0; i < n; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();

        // user code
        x_casa[i] = x;
        y_casa[i] = y;
        // end
        cerr << i << ":" << x << "/" << y << endl;

    }

    int minX = x_casa[0], maxX = x_casa[0], minY = y_casa[0], maxY = y_casa[0];
    for(int i = 0; i < n; i++){
        if(x_casa[i] < minX) minX = x_casa[i];
        if(x_casa[i] > maxX) maxX = x_casa[i];
        if(y_casa[i] < minY) minY = y_casa[i];
        if(y_casa[i] > maxY) maxY = y_casa[i];
    }


    int minL = -1, L = -1;
    for(int i = minY; i <= maxY; i++){
        int tot = maxX - minX;

        for(int j = 0; j < n; j++){
            if(y_casa[j] > i) tot = tot + (y_casa[j] - i);
            if(y_casa[j] < i) tot = tot + (i - y_casa[j]);
        }

    if(minL == -1) minL = tot;
    if(tot < minL) minL = tot;
    }

    cout << minL << endl;
}
