#include <iostream>
#include <cmath>
// сложение
using namespace std;
struct Vector{
    float y;
    float x;
};
void add(Vector &vec){
    cout << "enter vector x\n";
    cin >> vec.x;
    cout << "enter vector y\n";
    cin >> vec.y;
    cout << "summary vector\n";
    cout << vec.x + vec.y;
}
void subtract(Vector &vec){
    cout << "enter vector x\n";
    cin >> vec.x;
    cout << "enter vector y\n";
    cin >> vec.y;
    cout << "subtract vector\n";
    cout << vec.x - vec.y;
}
void scale(Vector &vec){
    cout << "scale\n";
    float s;
    cin >> s;
    cout << "which vector ?\n";
    char sy;
    cin >> sy;
    if (sy == 'x'){
        cout << "enter vector x\n";
        cin >> vec.x;
        cout << "result " << s * vec.x;
    }else if (sy == 'y'){
        cout << "enter vector y\n";
        cin >> vec.y;
        cout << "result " << s * vec.y;
    }
}
void length(Vector &vec){
    cout << "enter vector x\n";
    cin >> vec.x;
    cout << "enter vector y\n";
    cin >> vec.y;
    cout << "result " << sqrt(pow(vec.x,2) + pow(vec.y,2));
}
void normalize(Vector &vec){
    cout << "enter vector x\n";
    cin >> vec.x;
    cout << "enter vector y\n";
    cin >> vec.y;
    float len = sqrt(pow(vec.x,2) + pow(vec.y,2));
    float invLen = 1 / len;
    cout << "result " << "x " << vec.x * invLen << " y " << vec.y * invLen;
}
int main(){
    Vector vec;
    cout << "enter action\n";
    string action;
    cin >> action;
    if (action == "normalize"){
        normalize(vec);
    }
    if (action == "length"){
        length(vec);
    }
    if (action == "scale"){
        scale(vec);
    }
    if (action == "subtract"){
        subtract(vec);
    }
    if (action == "add"){
        add(vec);
    }
    return 0;
}
