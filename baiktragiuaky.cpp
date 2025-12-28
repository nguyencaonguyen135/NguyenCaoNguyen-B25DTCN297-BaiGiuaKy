#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee() {
        id = 0;
        salary = 0;
    }

    Employee(int id) {
        this->id = id;
        salary = 0;
    }

    void input() {
        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);
        cout << "Nhap luong: ";
        cin >> salary;
    }

    void printInfo() {
        cout << "ID: " << id << " - Ten: " << name << " - Luong: " << salary << endl;
    }

    int getId() {
        return id;
    }

    void setSalary(float newSalary) {
        salary = newSalary;
    }
};


class EmployeeManager {
private:
    vector<Employee> list;
    int nextId;

public:
    EmployeeManager() {
        nextId = 3001;
    }

    void addEmployee() {
        Employee e(nextId);
        cout << "Ma nhan vien: " << nextId << endl;
        e.input();
        list.push_back(e);
        nextId++;
        cout << "Da them nhan vien!\n";
    }

    void showAll() {
        if (list.size() == 0) {
            cout << "Danh sach rong!\n";
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            list[i].printInfo();
        }
    }

    void updateSalaryById() {
        int id;
        cout << "Nhap ma nhan vien can cap nhat: ";
        cin >> id;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                float newSalary;
                cout << "Nhap luong moi: ";
                cin >> newSalary;
                list[i].setSalary(newSalary);
                cout << "Cap nhat thanh cong!\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien!\n";
    }

    void deleteById() {
        int id;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> id;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].getId() == id) {
                list.erase(list.begin() + i);
                cout << "Da xoa nhan vien!\n";
                return;
            }
        }
        cout << "Khong tim thay nhan vien!\n";
    }

    void menu() {
        int choice;
        do {
            cout << "\n--------- MENU ---------\n";
            cout << "1. Them nhan vien\n";
            cout << "2. Hien thi danh sach\n";
            cout << "3. Cap nhat luong\n";
            cout << "4. Xoa nhan vien\n";
            cout << "5. Thoat\n";
            cout << "------------------------\n";
            cout << "Chon: ";
            cin >> choice;

            switch (choice) {
                case 1: 
				addEmployee(); 
					break;
                case 2: 
				showAll(); 
					break;
                case 3: 
				updateSalaryById(); 
					break;
                case 4: 
				deleteById(); 
					break;
                case 5: 
				cout << "Tam biet!\n"; 
					break;
                default: 
				cout << "Lua chon sai!\n";
            }
        } while (choice != 5);
    }
};

int main() {
    EmployeeManager manager;
    manager.menu();
    return 0;
}

