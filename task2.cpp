#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct room{
    string nameRoom;
};
struct floor{
    int h_ceiling;
    vector<room> Room;
};
struct home{
    int square;
    bool ovenPipe;
    vector<floor> Floor;
};
struct area{
    int numbArea;
    vector<home> Home;
};
void addArea(vector<area> &vecArea, struct area){
    area Area;
    home lome;
    vecArea.push_back(Area);
    vecArea[vecArea.size() - 1].Home.push_back(lome);
    vecArea[vecArea.size() - 1].;
}
int main(){
    area Area;
    home Home;
    floor Floor;
    room Room;
    vector<area> vecArea;
    vecArea.push_back(Area);
    vecArea[0].Home.push_back(Home);
    cout << vecArea.size();
    return 0;
}
