#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct list{
    string name = "";
    string date = "";
    int salary = 0;
};
void getList(fstream &file, vector<list> &vecList){
    file.open("register.bin", ios::binary | ios::in);
    int lenVec = vecList.size();
    file.read((char*) &lenVec, sizeof(lenVec));
    vecList.resize(lenVec);
    for (int i = 0; i < vecList.size(); i++) {
        int lenName;
        int lenDate;
        file.read((char *) &lenName, sizeof(lenName));
        vecList[i].name.resize(lenName);
        file.read((char*)vecList[i].name.c_str(), lenName);
        file.read((char *) &lenDate, sizeof(lenDate));
        vecList[i].date.resize(lenDate);
        file.read((char*) vecList[i].date.c_str(), lenDate);
        file.read((char *) &vecList[i].salary, sizeof(vecList[i].salary));
    }
    file.close();
    // chek
    cout << "size vec :" << vecList.size() << endl;
    for (int i = 0; i < vecList.size(); i++){
        cout << vecList[i].name << " " << vecList[i].salary << " " << vecList[i].date << endl;
    }
}
void addList(fstream &reg,vector<list> &vecList){
    getList(reg,vecList);
    reg.open("register.bin", ios::binary | ios::out | ios::trunc);
    reg.close();
    reg.open("register.bin", ios::binary | ios::out | ios::app);
    list to_list;
    int i_vec;
    string fullName;
    string date;
    string stop;
    int salary;
    while(stop != "q") {
        vecList.push_back(to_list);
        i_vec = vecList.size() - 1;
        //Full name
        string F_name;
        string L_name;
        cout << "Enter first name\n";
        cin >> F_name;
        cout << "Enter last name\n";
        cin >> L_name;
        fullName += F_name + " " + L_name;
        for (int i = 0; i < fullName.size(); i++){
            if (fullName[i] >= '0' && fullName[i] <= '9'){
                std::cerr << "error format full name !\n";
                return;
            }
        }
        //date
        cout << "Enter date\n";
        cin >> date;
        if (date.size() != 10) {
            std::cerr << "error is long date\n";
            return;
        }
        if (std::stoi(date.substr(0,2)) < 0 || std::stoi(date.substr(0,2)) > 31){
            std::cerr << "error format date - day\n";
            return ;
        }
        if (std::stoi(date.substr(3,2)) < 0 || std::stoi(date.substr(3,2)) > 12){
            std::cerr << "error format date - month\n";
            return ;
        }
        if (std::stoi(date.substr(6,4)) < 1999 || std::stoi(date.substr(6,4)) > 2024){
            std::cerr << "error format date - year\n";
            return ;
        }
        //salary
        cout << "Enter salary\n";
        cin >> salary;
        if (salary < 0 || salary > INT32_MAX) {
            cout << "Error format salary\n";
            return;
        }
        vecList[i_vec].name = fullName;
        vecList[i_vec].date = date;
        vecList[i_vec].salary = salary;
        cout << "add more ?";
        cin >> stop;
    }
    //chek
    cout << "size vec :" << vecList.size() << endl;
    for (int i = 0; i < vecList.size(); i++){
        cout << vecList[i].name << " " << vecList[i].salary << " " << vecList[i].date << endl;
    }
    // added struct to file
    int lenVec = vecList.size();
    reg.write((char*) &lenVec, sizeof(lenVec));
    for (int i = 0; i < vecList.size(); i++) {
        int lenName = vecList[i].name.length();
        int lenDate = vecList[i].date.length();
        reg.write((char *) &lenName, sizeof(lenName));
        reg.write(vecList[i].name.c_str(), lenName);
        reg.write((char *) &lenDate, sizeof(lenDate));
        reg.write(vecList[i].date.c_str(), lenDate);
        reg.write((char *) &vecList[i].salary, sizeof(vecList[i].salary));
    }
    reg.close();
}

int main() {
    list to_list;
    vector<list> vecList;
    fstream reg("register.bin", ios::binary |ios::in | ios::out);
    if (!reg.is_open()){
        fstream reg("register.bin", ios::out | ios::trunc);
        cout << "File created !\n";
        reg.close();
    }
    string ans;
    cout << "enter option\n";
    cin >> ans;
    if (ans == "add") {
        reg.close();
        addList(reg, vecList);
    }else if (ans == "list"){
        reg.close();
        getList(reg, vecList);
    }else if (ans == "init"){
        reg.close();
        reg.open("register.bin", ios::binary | ios::out | ios::trunc);
        reg.close();
    }
    return 0;
}
