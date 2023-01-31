#include <iostream>
using namespace std;

class Employee
{
private: 
    string pName;
    int pAge;
    string ppost;
public :
    string Name;
    int Age;
    string post;
    void getNAME(){
        return pName ;
    } 
    void setName(string name){
        pName=name;
        
    }
     void getpost(){
        return ppost ;
    } 
    void setpost(string POST){
        ppost=POST;
        
    }

    void getAge(){
        return pAge; 
    } 
    void setAge(int age){
        pAge=age
        
    }
    void intro_private(){

        cout<<"Helll0 it is "<<getNAME()<< "i am "<< getAge()<< "my work is " <<getpost() <<endl; 
    }
    void intro(){
           cout<<"Helll0 it is "<<Name<< " i am "<< Age<< "my work is " <<post  <<endl; 
    
    }
    Employee(string name,int age,string postt){
        Name=name;
        Age=age;
        post=postt;
    };

};

int main(){
    Employee Employee1("HUMAYUN",22,"CEO");
    Employee1.intro();
    Employee1.intro_private();
    cout<<Employee1.getNAME()<<endl;
    Employee1.setName="ALI";
    cout<<Employee1.getNAME()<<endl;


}