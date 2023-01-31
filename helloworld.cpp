#include <iostream>
using namespace std;

class Employee 
{public:
    string name; 
    int age;
    string  type; 

    void introduction(){
        cout<<"Hi i am "<<name<<" with age  "<<age<< " and i am "<<type<<endl;

    }
    //construtor
        Employee(string Name,string Type,int Age){
        name=Name;
        type=Type;
        age=Age;
    }

};


int main(){
    Employee employee1=Employee("ALI","INTERN",20);
    Employee employee2=Employee("AHmed","pre",22);

    /*employee1.name="ALi";
    employee1.age=20;
    employee1.type="contract";
    //cout<<"Hi i am"<<employee1.name<<" with age  "<<employee1.age<< "and i am "<<employee1.type<<endl;
    */
    employee1.introduction();
    employee2.introduction();

    // 
return 0;}