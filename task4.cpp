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
};
struct two{
    string name = "Enemy_#2";
    int hp;
    int damage;
    int armor;
};
struct three{
    string name = "Enemy_#3";
    int hp;
    int damage;
    int armor;
};
struct four{
    string name = "Enemy_#4";
    int hp;
    int damage;
    int armor;
};
struct five{
    string name = "Enemy_#5";
    int hp;
    int damage;
    int armor;
};
struct user{
    string name = "User";
    int hp;
    int damage;
    int armor;
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

}
int main(){
    srand(time(nullptr));
    getRandNumb(2,7);
    person Person;
    initEnemy(Person);
    cout << 'q';
    return 0;
}
