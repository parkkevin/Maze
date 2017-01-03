#include "MazeComplexityPartB.h"
#include <stack>
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::stack;

MazeComplexityPartB::MazeComplexityPartB()
{
    readInput(canvas);
}

void MazeComplexityPartB::readInput(PixelValues canvas[][COLS])
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

void MazeComplexityPartB::fillBlack(int m, int n)
{
    fillBlack(canvas, m, n);
}

void MazeComplexityPartB::fillBlack(PixelValues canvas[][COLS], int i, int j)
{
    stack<int> st;
    int temp;
    
    st.push(i * COLS + j);
    
    while (!st.empty())
    {
        temp = st.top();
        i = temp / COLS;
        j = temp % COLS;
        st.pop();
        
        if (canvas[i][j] == WHITE)
        {
            if (i >= 0 && i < ROWS && j >= 0 &&  j < COLS)
            {
                canvas[i][j] = BLACK;
                st.push(i * COLS + (j - 1));
                st.push(i * COLS + (j + 1));
                st.push((i - 1) * COLS + j);
                st.push((i + 1) * COLS + j);
            }
        }
    }
}

void MazeComplexityPartB::print()
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















