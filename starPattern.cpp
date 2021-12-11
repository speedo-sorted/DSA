#include <iostream>


using namespace std;


int main()
{
    int row, s, i, j;
    cin >> row;
    
    for (i = 0; i <= row; i++)
    {
        for (s = row; s > i; s--)
            cout << " ";

        for (j = 0; j < i; j++)
            cout << "* ";

        cout << "\n";
    }
    for (i = 1; i < row; i++)
    {
        for (s = 0; s < i; s++)
            cout << " ";

        for (j = row; j > i; j--)
            cout << "* ";

        cout << "\n";
    }
    return 0;
}