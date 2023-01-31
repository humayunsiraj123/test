#include <iostream>
using namespace std;
/*inherticane aqxcuring attrribyute and methods of base class anfd using 
in your sub class along wiht the constructor building of child class 
also applied concept of protected constructor where we can assces atrribue of base class whihc aws private so to 
change private class to protected class we can access the property ffrom the base class of the
at child class like follows*/
class Askforpromotion{
    public :
        virtual void askforpromotion()=0;
};

class Employee :Askforpromotion{
private: 
    
    string Company;
    int Age;
protected:
string Name;
public:
    string getName(){
        return Name;
    }
    void setName(string name){
        Name=name;
    }
    string getCompany(){
        return Company;
    }
    void setcompany(string name){
        Company=name;
    }
    int getAge(){
        return Age;
    }
    void setName(int age){
        Age=age;
    }
    Employee(string name,string company,int age){
        Name=name;
        Company=company;
        Age=age;
    }
    void introduction(){
        cout<<"Hello Mr/Ms " <<getName()<<"\n";
        cout<<"From " <<getCompany()<<"\n";
        cout<<"Your are  " <<getAge()<<"\n";


 }
    void askforpromotion(){
        if(getAge()>18){
            cout<<"Hello Mr/Ms " <<getName()<< " Congration you are promoted "<<endl;

        }
        else
            cout<<"Hello Mr/Ms" <<getName()<< " soory your are not elagibale of rthe promotion "<<endl;

    }


};

class Developer: public Employee{//i have make class public so proppeorties like ask for pormotion make accesible to class developer
    public:
        string Planguage; 
        Developer(string name,string company,int age,string planguage):
            Employee(name,company,age)
            {
            Planguage=planguage;};
        void DevDet(){
            {//here NAme is accessbile directly because protection construtor has been used
             cout<<"MR "<<Name<<"From  "<<getCompany()<<" your are "<<getAge()<<"and you like programming "<<Planguage<<endl;

            } 
            

        }
        


};
class Teacher :public  Employee{
    public:
        string Subject;
        Teacher(string name,string company,int age,string sub):Employee(name,company,age){
            Subject=sub;
        };
        void Preparation(){
                cout<<Name<<" is going to teach "<<Subject<<endl;
            }
};


int main(){
Employee employee1=Employee("Ali","dell",19);
employee1.introduction();
employee1.askforpromotion();
Developer dev1=Developer("Abs","dell",19,"python");
dev1.askforpromotion();//to acces other properties we have public the base class in developer class while attr can be access using making protected attr of base class
Teacher teacher1=Teacher("AHEMD","aBC",27,"maths");
cout<<teacher1.Subject;
teacher1.Preparation();
teacher1.askforpromotion();

return 0;
}