#include <iostream>

#include "board.h"

using namespace std;

int main()
{
    cout << "Setup board:" << endl;
    Board b(true);
    cout << "Setup complete, trying to display: " << endl;
    b.display();
    return 0;
}
