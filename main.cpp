#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct strBill{
    string name = "";
    int salary = 0;
    string date = "";
};
void addNote(fstream& file, strBill& note){
    int length_name = note.name.length();
    file.write(note.name.c_str(), length_name);
    int length_date = note.date.length();
    file.write(note.date.c_str(), length_date);
    file.write((char*) &note.salary, sizeof(note.salary));
}
void addVecBill(vector<strBill> &vecBill){
    strBill noteBill;
    vecBill.push_back(noteBill);
    int indexVec = vecBill.size() - 1;
    cout << "Enter name :\n";
    getline(cin,vecBill[indexVec].name, '\n');
    cout << "Enter salary :\n";
    cin >> vecBill[indexVec].salary;
    cout << "Enter date :\n";
    cin >> vecBill[indexVec].date;
}
int main() {
    //strBill to_strBill;
    fstream f_bills("bills.bin", ios::binary | ios::in | ios::out);
    if (!f_bills.is_open()){
       ofstream out("bills.bin", ios::binary);
       cout << "File added !\n";
   }
    vector<strBill> vecBill;
    string option;
    while (option != "q"){
        cout << "Enter option\n";
        getline(cin , option);
        if (option == "add"){
            addVecBill(vecBill);
        }
        for (int i = 0; i < vecBill.size(); i++){
            cout << vecBill[i].name << " " << vecBill[i].salary << " " << vecBill[i].date << endl;
            cout << "**************************\n";
        }
    }
    return 0;
}
