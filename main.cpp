#include <iostream>
using namespace std;

#include "demo.h"


int main() {
    if (!mclInitializeApplication(NULL,0)) {
        cerr << "Couldn't initialize the application!" << endl;
        return -1;
    } else {
        cout << "Initialized the application." << endl;
    }

    if (!demoInitialize()) {
        cerr << "Couldn't initialize the library!" << endl;
    } else {
        cout << "Initialized the library." << endl;
    }
    double vx[1] = {12};
    mwArray x(1, 1, mxDOUBLE_CLASS);
    x.SetData(vx, 1);
    mwArray y(1, 1, mxDOUBLE_CLASS);

    demo(1, y, x);
    double vy = y.Get(1,1);

    demo2(1, y, x);
    vy = y.Get(1,1);

    demoTerminate();
    mclTerminateApplication();
    return 0;
} 
