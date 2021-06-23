#include <utility>
#include <list>

using namespace std;

int main(){
    list<pair<int, int>> deltaCoords;
    deltaCoords.push_back(make_pair(-1, -2));
    deltaCoords.push_back(make_pair(-2, -1));
    deltaCoords.push_back(make_pair(1, -2));
    deltaCoords.push_back(make_pair(2, -1));
    deltaCoords.push_back(make_pair(-1, 2));
    deltaCoords.push_back(make_pair(-2, 1));
    deltaCoords.push_back(make_pair(1, 2));
    deltaCoords.push_back(make_pair(2, 1));
}
