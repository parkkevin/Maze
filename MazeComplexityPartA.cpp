#include "MazeComplexityPartA.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

MazeComplexityPartA::MazeComplexityPartA()
{
    readInput(canvas);
}

void MazeComplexityPartA::fillBlack(int m, int n)
{
    fillBlack(canvas, m, n);
}

void MazeComplexityPartA::readInput(PixelValues canvas[][COLS])
{
    char ch;
    std::string fileName;
    cout << "File names are data1.txt, data2.txt, data3.txt,...,data10.txt \nPlease choose a file name: ";
    cin >> fileName;
    std::ifstream fin;
    fin.open(fileName.c_str());
    
    while (!fin)
    {
        fin.clear();
        cout << "could not open file \"" << fileName << "\" ...\nEnter a file name again:  ";
        cin >> fileName;
        fin.open(fileName.c_str());
    }
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fin >> ch;
            if (ch == 'B')
                canvas[i][j] = BLACK;
            else
                canvas[i][j] = WHITE;
        }
    }
    fin.close();
}

void MazeComplexityPartA::fillBlack(PixelValues canvas[][COLS], int i, int j)
{
    if (i < 0 || i >= ROWS || j < 0 || j >= COLS)
        return;
    
    if (canvas[i][j] == WHITE)
        canvas[i][j] = BLACK;
    else
        return;
    
    fillBlack(canvas, i + 1, j);
    fillBlack(canvas, i, j + 1);
    fillBlack(canvas, i - 1, j);
    fillBlack(canvas, i, j - 1);
}

void MazeComplexityPartA::print()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (canvas[i][j] == BLACK)
                cout << "B";
            else
                cout << " ";
        }
        cout << endl;
    }
}











