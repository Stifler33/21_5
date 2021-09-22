#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct bills{
    string first_name;
    string last_name;
    string date;
    int salary;
};
bills note;
bool add_in_data(fstream &data ,string flag, char sy = ' ',string textUser = ""){

    if (flag == "fullName"){
        cout << "First name\n";
        cin >> note.first_name;
        cout << "Last name\n";
        cin >> note.last_name;
        textUser = note.first_name + " " + note.last_name;
        for (int i = 0; i < textUser.size(); i++){
            if (textUser[i] >= '0' && textUser[i] <= '9'){
                std::cerr << "error format full name !\n";
                return false;
            }
        }
    }
    if (flag == "date"){
        cin >> textUser;
        if (textUser.size() != 10) {
            cerr << "error is long date\n";
            return false;
        }
        if (stoi(textUser.substr(0,2)) < 0 || stoi(textUser.substr(0,2)) > 31){
            cerr << "error format date - day\n";
            return false;
        }
        if (stoi(textUser.substr(3,2)) < 0 || stoi(textUser.substr(3,2)) > 12){
            cerr << "error format date - month\n";
            return false;
        }
        if (stoi(textUser.substr(6,4)) < 1999 || stoi(textUser.substr(6,4)) > 2024){
            cerr << "error format date - year\n";
            return false;
        }
    }
    if (flag == "salary"){
        cin >> textUser;
        for (char i : textUser){
            if (i < '0' || i > '9'){
                cerr << "error format salary\n";
                return false;
            }
        }
    }
    data << textUser << sy;
    return true;
}
int main() {
    fstream data("register.txt", ios::in | ios::out);
    if (!data.is_open()){
        fstream init("register.txt", ios::out | ios::trunc);
        init.close();
    }
    string stopWord;
    string option;
    cout << "enter option\n";
    cin >> option;
    if (option == "add") {
        while (stopWord != "n") {
            do {
                cout << "Enter full name :\n";
            } while (!add_in_data(data, "fullName"));
            do {
                cout << "Enter date :\n";
            } while (!add_in_data(data, "date"));
            do {
                cout << "Enter sum salary :\n";
            } while (!add_in_data(data, "salary", '\n'));
            cout << "proceed ?\n";
            cin >> stopWord;
        }
    }
    data.close();
    return 0;
}