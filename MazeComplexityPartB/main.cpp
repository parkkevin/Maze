#include "MazeComplexityPartB.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    MazeComplexityPartB mc;
    int row, col;
    
    mc.print();
    cout << endl;
    
    cout << "Enter a row number of a starting point in range from 0 to 9: ";
    cin >> row;
    cout << endl;
    cout << "Enter a column number of a starting point in range from 0 to 9: ";
    cin >> col;
    cout << endl;
    
    mc.fillBlack(row, col);
    mc.print();
    cout << endl;
    
    return 0;
}







