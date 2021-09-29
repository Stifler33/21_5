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
struct gamePerson{
    string name = "";
    int hp = 0;
    int damage = 0;
    int armor = 0;
    int crd[2] = {0,0};
};
//init Enemy
void initEnemy(gamePerson &person){
    for (int i = 0; i < 4; i++) getRandNumb(i*3, 150);
    // init HP
    person.hp = getRandNumb(50,150);
    // init armor
    person.armor = getRandNumb(0,50);
    // init damage
    person.damage = getRandNumb(15,30);
    // init coordinates crd[x,y]
    person.crd[0] = getRandNumb(0,maxCrd - 1);
    for (int i = 0; i < 4; i++) getRandNumb(i*3, 150);
    person.crd[1] = getRandNumb(0,maxCrd - 1);
}
void movPers(gamePerson *person){
    // init coordinates crd[x,y]
    for (int i = 0; i <= 4; i++){
        person[i].crd[0] = getRandNumb(0,maxCrd);
        for (int j = 0; j < 5; j++){
            getRandNumb(j*13, 254);
        }

        person[i].crd[1] = getRandNumb(0,maxCrd);
    }
}
void showField(gamePerson *person){
    for (int y = maxCrd; y >= 0; y--){
        for (int x = 0; x <= maxCrd;){
            bool print = false;
            for (int i = 0; i < 6; i++){
                if (person[i].hp > 0 && i < 5 && person[i].crd[0] == x && person[i].crd[1] == y){
                    cout << "E";
                    print = true;
                    x++;
                }else if (i >=5 && person[i].crd[0] == x && person[i].crd[1] == y){
                    cout << "P";
                    print = true;
                    x++;
                }
            }
            if (!print) {
                cout << ".";
                x++;
            }
        }
        cout << endl;
    }
}
void analysisCourse(gamePerson *person , string flag){
    for (int i = 0; i <= 4; i++){
        if (person[i].hp > 0 && (person[5].crd[0] == person[i].crd[0]) && (person[5].crd[1] == person[i].crd[1])){
            if (flag == "user"){
                person[i].armor -= person[5].damage;
                if (person[i].armor < 0) {
                    person[i].hp += person[i].armor;
                    if (person[i].hp < 0) person[i].hp = 0;
                }
                person[i].armor = 0;
                cout << "hit the player\n";
            }else if (flag == "enemy"){
                person[5].armor -= person[i].damage;
                if (person[5].armor < 0) {
                    person[5].hp += person[5].armor;
                    if (person[5].hp < 0) person[5].hp = 0;
                }
                person[5].armor = 0;
                cout << "hit the enemy\n";
            }
        }
    }
}
void saveGame(gamePerson *person){
    fstream save("save.bin", ios::binary | ios::out | ios::trunc);
    for (int i = 0; i < 6; i++){
        int lenName = person[i].name.length();
        save.write((char*) &lenName, sizeof(lenName));
        save.write((char*) person[i].name.c_str(), lenName);
        save.write((char*) &person[i].hp, sizeof(person[i].hp));
        save.write((char*) &person[i].armor, sizeof(person[i].armor));
        save.write((char*) &person[i].damage, sizeof(person[i].damage));
        save.write((char*) &person[i].crd, sizeof(person[i].crd));
    }
    save.close();
    cout << "save game\n";
}
void loadGame(gamePerson *person){
    fstream load("save.bin", ios::binary | ios::in);
    for (int i = 0; i < 6; i++){
        int lenName;
        load.read((char*) &lenName, sizeof(lenName));
        person[i].name.resize(lenName);
        load.read((char*) person[i].name.c_str(), lenName);
        load.read((char*) &person[i].hp, sizeof(person[i].hp));
        load.read((char*) &person[i].armor, sizeof(person[i].armor));
        load.read((char*) &person[i].damage, sizeof(person[i].damage));
        load.read((char*) &person[i].crd, sizeof(person[i].crd));
    }
    load.close();
    cout << "game load\n";
}
int main(){
    srand(time(nullptr));
    getRandNumb(2,7);
    gamePerson person[6];
    // init user
    bool autoInitUser = false;

    // start game
    string option;
    while (option != "exit"){
        cout << "Enter option - newGame, load, exit\n";
        cin >> option;
        if (option == "newGame" || option == "load"){
            //load
            if (option == "load") {
                loadGame(person);
            }else {
                //init enemy
                for (int i = 0; i < 5; i++){
                    person[i].name = "Enemy_#_" + to_string(i + 1);
                    initEnemy(person[i]);
                }
                //init player
                if (!autoInitUser){
                    cout << "Enter name player\n";
                    cin >> person[5].name;
                    cout << "How many HP ?(50-150)\n";
                    cin >> person[5].hp;
                    if (person[5].hp < 50 || person[5].hp > 150){
                        cout << "error hp\n";
                        return -1;
                    }
                    cout << "How many damage?(15-30)\n";
                    cin >> person[5].damage;
                    if (person[5].damage < 15 || person[5].damage > 30){
                        cout << "error damage\n";
                        return -1;
                    }
                    cout << "How many armor?(0-50)\n";
                    cin >> person[5].armor;
                    if (person[5].armor < 0 || person[5].armor > 50){
                        cout << "error damage\n";
                        return -1;
                    }
                    person[5].crd[0] = getRandNumb(0,maxCrd);
                    person[5].crd[1] = getRandNumb(0,maxCrd);
                }else if (autoInitUser){
                    person[5].name = "stif";
                    person[5].hp = 100;
                    person[5].damage = 20;
                    person[5].armor = 20;
                    person[5].crd[0] = getRandNumb(0,maxCrd - 1);
                    person[5].crd[1] = getRandNumb(0,maxCrd - 1);
                }

            }
            //showField(person);
            cout << "Enter action - left - a, right - d, top - w, bottom - s\n" << "or exit, save\n";
            string action;
            bool enemyAlive = false;
            bool userAlive = false;
            while (action != "exit" || enemyAlive || userAlive){
                enemyAlive = person[0].hp > 0 || person[1].hp > 0 || person[2].hp > 0 || person[3].hp > 0 || person[4].hp > 0;
                userAlive = person[5].hp > 0;
                if (!enemyAlive){
                    cout << "User win !\n";
                    return 0;
                }else if (!userAlive){
                    cout << "enemy win !\n";
                    return 0;
                }
                showField(person);
                for (int i = 0; i < 6; i++){
                    cout << person[i].name << " crd " <<person[i].crd[0] << "," << person[i].crd[1] <<
                    " " << "HP " << person[i].hp << endl;
                }
                cout << "Enter action\n";
                cin >> action;
                //save
                if (action == "save") {
                    saveGame(person);
                    return 0;
                }
                // game option
                if (action == "a"){
                    if (person[5].crd[0] > 0) person[5].crd[0]--;
                }else if (action == "d"){
                    if (person[5].crd[0] < maxCrd) person[5].crd[0]++;
                }else if (action == "w"){
                    if (person[5].crd[1] < maxCrd) person[5].crd[1]++;
                }else if (action == "s"){
                    if (person[5].crd[1] > 0) person[5].crd[1]--;
                }else if (action == "exit"){
                    cout << "Exit game\n";
                    break;
                }else {
                    cout << "no correct action\n";
                    continue;
                }
                analysisCourse(person, "user");
                movPers(person);
                analysisCourse(person, "enemy");
            }
        }
    }

    return 0;
}
