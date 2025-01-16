#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Employee{
    private:
    string database;
    public:
    Employee(string db):database(db){}

    void create(){
        ofstream file(database, ios::app);
        if(!file.is_open()){
            cout<<"Creating file Error!"<<endl;
            return;
        }
       
       int id;
       string name,department;
        cout<<"Enter the Empolyee Id:";
        cin>>id;
        cin.ignore();
        cout<<"Enter the Empolyee Name:";
        getline(cin,name);
        cout<<"Enter the Empolyee Department:";
        getline(cin,department);

        file<<id<<','<<name<<','<<department<<","<<endl;
        file.close();
        cout<<"Data add Successfully!"<<endl;

    }

    void read(){
        ifstream file(database);
        if(!file.is_open()){
            cout<<"Database Reading Error";
            return;
        }

        string line;
        cout<<"Empolyee  Details:"<<endl;
        while(getline(file,line)){
            stringstream ss(line);
            string id,name,department;
            getline(ss,id,',');
            getline(ss,name,',');
            getline(ss,department,',');
            cout<<"ID:"<<id<<" Name:"<<name<<" Department:"<<department<<endl;
           
        }
         file.close();
    }

    void search(){
        ifstream file(database);
        if(!file.is_open()){
            cout<<"Searching Reading File Error:";
            return;
        }   
        
        string strid;
        cout<<"Enter the Unique ID:";
        cin>>strid;
        
        bool found=false;
        string line;
        while(getline(file,line)){
            stringstream ss(line);
            string id,name,department;
            getline(ss,id,',');
            getline(ss,name,',');
            getline(ss,department,',');
            if(strid==id){
                cout<<"ID:"<<id<<" Name:"<<name<<" Department:"<<department<<endl;
                found=true;
            }
           
        }
        if(!found){
            cout<<"Tha Data is not Found"<<endl;
           }
           file.close();
        }
};

int main(){
    Employee em("database.csv");
    int choice;

    do
    {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            em.create();
            break; 
        case 2:
            em.read();
            break;
        case 3:
            em.search();
            break;
        case 4:
            cout << "Exiting...\n";
            break;   
        default:
            cout<<"Invaild input";
            break;
        }
    } while (choice != 4);

    return 0;
    
}