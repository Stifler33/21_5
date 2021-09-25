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
    cout << "Number area\n";
    int numberArea;
    cin >> numberArea;
    vecArea.resize(numberArea);
    for (int a = 0 ; a < numberArea; a++){
        // added number builds
        cout << "how many buildings ?\n";
        int numb_home;
        cin >> numb_home;
        vecArea[a].v_Home.resize(numb_home);
        for (int h = 0; h < vecArea[a].v_Home.size(); h++) {
            // added name builds
            cout << "type building " << a + 1 << endl;
            cin >> vecArea[a].v_Home[h].type;
            // added square builds
            cout << "square " << vecArea[a].v_Home[h].type << endl;
            cin >> vecArea[a].v_Home[h].square;
            // if type home then enter pipe
            if (vecArea[a].v_Home[h].type == "home") {
                cout << "Oven pipe ?\n";
                string ansver;
                cin >> ansver;
                if (ansver == "yes") {
                    vecArea[a].v_Home[h].ovenPipe = true;
                }
            }
            // added floor
            cout << "number floor " << vecArea[a].v_Home[h].type << endl;
            int numberFloor;
            cin >> numberFloor;
            vecArea[a].v_Home[h].v_Floor.resize(numberFloor);
            // added ceiling floor
            for (int f = 0; f < numberFloor; f++){
                cout << "ceiling floor " << f + 1 << endl;
                cin >> vecArea[a].v_Home[h].v_Floor[f].h_ceiling;
                // added number room
                cout << "number of rooms per floor " << f + 1 << endl;
                int numbRoom;
                cin >> numbRoom;
                vecArea[a].v_Home[h].v_Floor[f].v_Room.resize(numberFloor);
                // added name room
                for (int r = 0; r < numbRoom; r++){
                    cout << "enter type room " << r+1 << endl;
                    cin >> vecArea[a].v_Home[h].v_Floor[f].v_Room[r].nameRoom;
                }
            }
        }
    }



}
int main(){
    area Area;
    home Home;
    floor Floor;
    room Room;
    vector<area> vecArea;
    addArea(vecArea, Area);
    for (int a = 0; a < vecArea.size(); a++){
        cout << "numbers area " << a+1 << endl;
        for (int h = 0; h < vecArea[a].v_Home.size(); h++) {
            cout << "  parameter home " << h+1 << endl;
            cout << "  " << "type " << vecArea[a].v_Home[h].type << endl;
            cout << "  " << "square " << vecArea[a].v_Home[h].square << endl;
            cout << "  " << "ovenPipe " << vecArea[a].v_Home[h].ovenPipe << endl;
            for (int f = 0; f < vecArea[a].v_Home[h].v_Floor.size(); f++){
                cout << "   " << "parameter floor " << f+1 << endl;
                cout << "   " << "ceiling " << vecArea[a].v_Home[h].v_Floor[f].h_ceiling << endl;
                for (int r = 0; r < vecArea[a].v_Home[h].v_Floor[f].v_Room.size(); r++){
                    cout << "   " << "room " << r+1 << " " << vecArea[a].v_Home[h].v_Floor[f].v_Room[r].nameRoom << endl;
                }
            }
        }
    }

    return 0;
}
