#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int maxCrd = 6;
int getRandNumb(int min, int max){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * (max - min + 1) + min);
}
struct person{
    string name = "Enemy_#_";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
//init Enemy
void initEnemy(person &Person){
    // init HP
    Person.hp = getRandNumb(50,150);
    // init armor
    Person.armor = getRandNumb(0,50);
    // init damage
    Person.damage = getRandNumb(15,30);
    // init coordinates crd[x,y]
    Person.crd[0] = getRandNumb(0,maxCrd - 1);
    Person.crd[1] = getRandNumb(0,maxCrd - 1);
}
void movPers(person *Person){
    // init coordinates crd[x,y]
    for (int i = 0; i <= 4; i++){
        Person[i].crd[0] = getRandNumb(0,maxCrd);
        Person[i].crd[1] = getRandNumb(0,maxCrd);
    }
}
void showField(person *Person){
    for (int y = maxCrd; y >= 0; y--){
        for (int x = 0; x <= maxCrd; x++){
            bool print = false;
            for (int i = 0; i < 6; i++){
                if (Person[i].hp > 0 && i < 5 && Person[i].crd[0] == x && Person[i].crd[1] == y){
                    cout << "E";
                    print = true;
                }else if (i >=5 && Person[i].crd[0] == x && Person[i].crd[1] == y){
                    cout << "P";
                    print = true;
                }
            }
            if (!print) cout << ".";
        }
        cout << endl;
    }
}
void analysisCourse(person *Person , string flag){
    for (int i = 0; i <= 4; i++){
        if (Person[i].hp > 0 && Person[5].crd[0] == Person[i].crd[0] && Person[5].crd[1] == Person[i].crd[1]){
            if (flag == "user"){
                Person[i].armor -= Person[5].damage;
                if (Person[i].armor < 0) Person[i].hp += Person[i].armor;
                Person[i].armor = 0;
                cout << "hit the player\n";
            }else if (flag == "enemy"){
                Person[5].armor -= Person[i].damage;
                if (Person[5].armor < 0) Person[5].hp += Person[5].armor;
                Person[5].armor = 0;
                cout << "hit the enemy\n";
            }
        }
    }
}
int main(){
    srand(time(nullptr));
    getRandNumb(2,7);
    person Person[6];
    // init user
    bool autoInitUser = true;
    if (!autoInitUser){
        cout << "Enter name player\n";
        cin >> Person[5].name;
        cout << "How many HP ?(50-150)\n";
        cin >> Person[5].hp;
        if (Person[5].hp < 50 || Person[5].hp > 150){
            cout << "error hp\n";
            return -1;
        }
        cout << "How many damage?(15-30)\n";
        cin >> Person[5].damage;
        if (Person[5].damage < 15 || Person[5].damage > 30){
            cout << "error damage\n";
            return -1;
        }
        cout << "How many armor?(0-50)\n";
        cin >> Person[5].armor;
        if (Person[5].armor < 0 || Person[5].armor > 50){
            cout << "error damage\n";
            return -1;
        }
        Person[5].crd[0] = getRandNumb(0,maxCrd);
        Person[5].crd[1] = getRandNumb(0,maxCrd);
    }else if (autoInitUser){
        Person[5].name = "stif";
        Person[5].hp = 100;
        Person[5].damage = 20;
        Person[5].armor = 20;
        Person[5].crd[0] = getRandNumb(0,maxCrd - 1);
        Person[5].crd[1] = getRandNumb(0,maxCrd - 1);
    }

    // start game
    string option;
    while (option != "exit"){
        cout << "Enter option - game, save, load, exit\n";
        cin >> option;
        if (option == "game"){
            //init enemy
            for (int i = 0; i < 5; i++){
                Person[i].name += to_string(i + 1);
                initEnemy(Person[i]);
            }
            //showField(Person);
            cout << "Enter action - left, right, top, bottom\n" << "or exit, save\n";
            string action;
            while (action != "exit"){
                showField(Person);
                for (int i = 0; i < 6; i++){
                    cout << Person[i].name << " crd " <<Person[i].crd[0] << "," << Person[i].crd[1] <<
                    " " << "HP " << Person[i].hp << endl;
                }
                cout << "Enter action\n";
                cin >> action;
                if (action == "a"){
                    if (Person[5].crd[0] > 0) Person[5].crd[0]--;
                }else if (action == "d"){
                    if (Person[5].crd[0] < maxCrd) Person[5].crd[0]++;
                }else if (action == "w"){
                    if (Person[5].crd[1] < maxCrd) Person[5].crd[1]++;
                }else if (action == "s"){
                    if (Person[5].crd[1] > 0) Person[5].crd[1]--;
                }else if (action == "exit"){
                    cout << "Exit game\n";
                    break;
                }else {
                    cout << "no correct action\n";
                    continue;
                }
                analysisCourse(Person, "user");
                movPers(Person);
                analysisCourse(Person, "enemy");
            }
        }
    }

    return 0;
}
