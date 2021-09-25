#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct room{
    string nameRoom;
};
struct floor{
    int h_ceiling;
    room Room;
    vector<room> v_Room;
};
struct home{
    int square;
    bool ovenPipe = false;
    string type;
    floor Floor;
    vector<floor> v_Floor;
};
struct area{
    int numbArea;
    home Home;
    vector<home> v_Home;
};
void addArea(vector<area> &vecArea, struct area){
    area Area;
    room Room;
    floor Floor;
    home Home;
    //added area
    vecArea.push_back(Area);
    cout << "Numb area\n";
    cin >> vecArea[0].numbArea;
    // added number builds
    cout << "how many buildings ?\n";
    int numb_home;
    cin >> numb_home;
    Area.v_Home.resize(numb_home);
    for (int i = 0; i < Area.v_Home.size(); i++) {
        // added name builds
        cout << "type building " << i + 1 << endl;
        cin >> Area.v_Home[i].type;
        // added square builds
        cout << "square " << Area.v_Home[i].type << endl;
        cin >> Area.v_Home[i].square;
        // if type home then enter pipe
        if (Area.v_Home[i].type == "home") {
            cout << "Oven pipe ?\n";
            string ansver;
            cin >> ansver;
            if (ansver == "yes") {
                vecArea[i].v_Home[i].ovenPipe = true;
            }
        }
        // added floor
        cout << "number floor " << Area.v_Home[i].type << endl;
        int numberFloor;
        cin >> numberFloor;
        Area.v_Home[i].v_Floor.resize(numberFloor);
        // added ceiling floor
        for (int i = 0; i < numberFloor - 1; i++){
            cout << "ceiling floor " << i + 1 << endl;
            cin >> Area.v_Home[i].v_Floor[i].h_ceiling;
            // added number room
            cout << "number of rooms per floor " << i + 1 << endl;
            int numbRoom;
            cin >> numbRoom;
            Area.v_Home[i].v_Floor[i].v_Room.resize(numberFloor);
        }
        // added name room
        for (int i = 0; i < Area.v_Home[i].v_Floor[i].v_Room.size(); i++){
            cout << "enter type room " << i+1 << endl;
            cin >> Area.v_Home[i].v_Floor[i].v_Room[i].nameRoom;
        }
    }

}
int main(){
    area Area;
    vector<area> vecArea;
    addArea(vecArea, Area);
    cout << "Added string\n";
    addArea(vecArea, Area);
    cout << Area.numbArea;
    return 0;
}
