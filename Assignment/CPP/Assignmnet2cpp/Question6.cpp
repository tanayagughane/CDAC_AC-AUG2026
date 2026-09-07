//============================================================================
// Name        : Question6.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int R, C;

    cout << "Enter number of rows: ";
    cin >> R;

    cout << "Enter number of columns: ";
    cin >> C;

    // Dynamic 2D array
    int** gameMap = new int*[R];

    for (int i = 0; i < R; i++)
    {
        gameMap[i] = new int[C];
    }

    // Random tile values from 0 to 4
    srand(time(0));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            gameMap[i][j] = rand() % 5;
        }
    }

    // Display Game Map
    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====\n";

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << gameMap[i][j] << "  ";
        }
        cout << endl;
    }

    // Legend
    cout << "\nLegend: 0=Grass  1=Water  2=Mountain  "
         << "3=Forest  4=Dungeon\n";

    // Count each tile type
    int count[5] = {0};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            count[gameMap[i][j]]++;
        }
    }

    // Display count
    cout << "\nTile Count:\n";

    cout << "  Grass    : " << count[0] << endl;
    cout << "  Water    : " << count[1] << endl;
    cout << "  Mountain : " << count[2] << endl;
    cout << "  Forest   : " << count[3] << endl;
    cout << "  Dungeon  : " << count[4] << endl;

    // Deallocate memory
    for (int i = 0; i < R; i++)
    {
        delete[] gameMap[i];
    }

    delete[] gameMap;

    return 0;
}
