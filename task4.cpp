#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;
int getRandNumb(int min, int max){
    double x = 1.0 / RAND_MAX;
    return int(rand() * x * (max - min + 1) + min);
}
struct one{
    string name = "Enemy_#1";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
struct two{
    string name = "Enemy_#2";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
struct three{
    string name = "Enemy_#3";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
struct four{
    string name = "Enemy_#4";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
struct five{
    string name = "Enemy_#5";
    int hp;
    int damage;
    int armor;
    int crd[2];
};
struct user{
    string name = "User";
    int hp;
    int damage;
    int armor;
    //coordinates crd[x,y]
    int crd[2];
};
struct person{
    one One;
    two Two;
    four Four;
    three Three;
    five Five;
    user User;
};
//init Enemy
void initEnemy(person &Person){
    // init HP
    Person.One.hp = getRandNumb(50,150);
    Person.Two.hp = getRandNumb(50,150);
    Person.Three.hp = getRandNumb(50,150);
    Person.Four.hp = getRandNumb(50,150);
    Person.Five.hp = getRandNumb(50,150);
    // init armor
    Person.One.armor = getRandNumb(0,50);
    Person.Two.armor = getRandNumb(0,50);
    Person.Three.armor = getRandNumb(0,50);
    Person.Four.armor = getRandNumb(0,50);
    Person.Five.armor = getRandNumb(0,50);
    // init damage
    Person.One.damage = getRandNumb(15,30);
    Person.Two.damage = getRandNumb(15,30);
    Person.Three.damage = getRandNumb(15,30);
    Person.Four.damage = getRandNumb(15,30);
    Person.Five.damage = getRandNumb(15,30);
    // init coordinates crd[x,y]
    Person.One.crd[0] = getRandNumb(0,40);
    Person.One.crd[1] = getRandNumb(0,40);
    Person.Two.crd[0] = getRandNumb(0,40);
    Person.Two.crd[1] = getRandNumb(0,40);
    Person.Three.crd[0] = getRandNumb(0,40);
    Person.Three.crd[1] = getRandNumb(0,40);
    Person.Four.crd[0] = getRandNumb(0,40);
    Person.Four.crd[1] = getRandNumb(0,40);
    Person.Five.crd[0] = getRandNumb(0,40);
    Person.Five.crd[1] = getRandNumb(0,40);
    Person.User.crd[0] = getRandNumb(0,40);
    Person.User.crd[1] = getRandNumb(0,40);
}
void movPers(person &Person){
    // init coordinates crd[x,y]
    Person.One.crd[0] = getRandNumb(0,40);
    Person.One.crd[1] = getRandNumb(0,40);
    Person.Two.crd[0] = getRandNumb(0,40);
    Person.Two.crd[1] = getRandNumb(0,40);
    Person.Three.crd[0] = getRandNumb(0,40);
    Person.Three.crd[1] = getRandNumb(0,40);
    Person.Four.crd[0] = getRandNumb(0,40);
    Person.Four.crd[1] = getRandNumb(0,40);
    Person.Five.crd[0] = getRandNumb(0,40);
    Person.Five.crd[1] = getRandNumb(0,40);
}
void showField(person &Person){
    for (int y = 40; y >= 0; y--){
        for (int x = 0; x < 40; x++){
            if (Person.One.crd[0] == x && Person.One.crd[1] == y){
                cout << "E";
            }else if (Person.Two.crd[0] == x && Person.Two.crd[1] == y){
                cout << "E";
            }else if (Person.Three.crd[0] == x && Person.Three.crd[1] == y){
                cout << "E";
            }else if (Person.Four.crd[0] == x && Person.Four.crd[1] == y){
                cout << "E";
            }else if (Person.Five.crd[0] == x && Person.Five.crd[1] == y){
                cout << "E";
            }else if (Person.User.crd[0] == x && Person.User.crd[1] == y){
                cout << "P";
            }else cout << ".";
        }
        cout << endl;
    }
}
void analysisCourse(person &Person){
    if (Person.User.crd[0] == Person.One.crd[0] && Person.One.crd[1] == Person.User.crd[1]){

    }
}
int main(){
    srand(time(nullptr));
    getRandNumb(2,7);
    person Person;

    cout << "Enter name player\n";
    cin >> Person.User.name;
    cout << "How many HP ?(50-150)\n";
    cin >> Person.User.hp;
    if (Person.User.hp < 50 || Person.User.hp > 150){
        cout << "error hp\n";
        return -1;
    }
    cout << "How many damage?(15-30)\n";
    cin >> Person.User.damage;
    if (Person.User.damage < 15 || Person.User.damage > 30){
        cout << "error damage\n";
        return -1;
    }
    cout << "How many armor?(0-50)\n";
    cin >> Person.User.armor;
    if (Person.User.armor < 0 || Person.User.armor > 50){
        cout << "error damage\n";
        return -1;
    }
    string option;
    while (option != "exit"){
        cout << "Enter option - game, save, load, exit\n";
        cin >> option;
        if (option == "game"){
            initEnemy(Person);
            showField(Person);
            cout << "Enter action - left, right, top, bottom\n" << "or exit, save\n";
            string action;
            while (action != "exit"){
                cout << "Enter action\n";
                cin >> action;
                if (action == "left"){
                    Person.User.crd[0]--;
                }else if (action == "right"){
                    Person.User.crd[0]++;
                }else if (action == "top"){
                    Person.User.crd[1]++;
                }else if (action == "bottom"){
                    Person.User.crd[1]--;
                }else if (action == "exit"){
                    cout << "Exit game\n";
                    break;
                }else {
                    cout << "no correct action\n";
                    continue;
                }
                movPers(Person);
                showField(Person);
            }
        }
    }

    return 0;
}
