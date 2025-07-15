#include <iostream>
#include "datetime.h"
using namespace std;

int main() {
    DateTime dt1(30, 59, 23, 31, 12, 2024);
    DateTime dt2(45, 0, 0, 1, 1, 2025);
    DateTime dt3;

    cout << "dt1: "; dt1.display(cout) << "\n";
    cout << "dt2: "; dt2.display(cout) << "\n";

    cout << "dt1 == dt2? " << (dt1 == dt2) << "\n";
    cout << "dt1 != dt2? " << (dt1 != dt2) << "\n";
    cout << "dt1 < dt2? " << (dt1 < dt2) << "\n";
    cout << "dt1 <= dt2? " << (dt1 <= dt2) << "\n";
    cout << "dt1 > dt2? " << (dt1 > dt2) << "\n";
    cout << "dt1 >= dt2? " << (dt1 >= dt2) << "\n";

    dt3 = dt1 + dt2;
    cout << "dt1 + dt2: "; dt3.display(cout) << "\n";

    dt3 = dt2 - dt1;
    cout << "dt2 - dt1: "; dt3.display(cout) << "\n";

    dt3 = dt1;
    dt3 += dt2;
    cout << "dt1 += dt2: "; dt3.display(cout) << "\n";

    dt3 = dt2;
    dt3 -= dt1;
    cout << "dt2 -= dt1: "; dt3.display(cout) << "\n";

    dt3 = dt1;
    ++dt3;
    cout << "++dt1: "; dt3.display(cout) << "\n";

    dt3 = dt2;
    --dt3;
    cout << "--dt2: "; dt3.display(cout) << "\n";

    dt3 = dt1;
    dt3 / dt2;
    cout << "Time until dt2 from dt1 (dt1 / dt2): "; dt3.display(cout) << "\n";

    cout << "Enter date and time (year month day hour minute second): ";
    DateTime inputDT;
    cin >> inputDT;
    cout << "You entered: ";
    inputDT.display(cout) << "\n";

    return 0;
}
