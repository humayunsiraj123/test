#include <iostream>
using namespace std;
//with get  set fucntion
//Encapsulation si basically enclosing some of your class data and make it private so no can directly access it or through consctructor
//so it need to access th private data through getter and setter sfucntions 
class Employee 
{private:
    string name; 
    int age;
    string  type; 
public:
    string getname(){
        return name;
    }
    void setname(string Name){
    name=Name;}


    int getAge(){
        return age;
    }
    void setAge(int Age){
    if(Age>=18)
        age=Age;
    }


    void introduction(){
        cout<<"Hi i am "<<name<<" with age  "<<age<< " and i am "<<type<<endl;

    }
    
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
    //cout<<employee1.name; NOT WORKING BCZ PRIVATE VAR
    employee1.setname("KHAN");

    cout<<"updated name is "<<employee1.getname()<<endl;
    //check age limitation;
    employee2.setAge(17);
    employee1.setAge(100);
//as age is below the limt so all the values is same above the range
    cout<<"Employee 1 updates AGe is "<<employee1.getAge() <<endl; 
    cout<<"Employee 2 updates AGe is "<<employee1.getAge() <<endl;

    int n=2;
  int N=50;
  int div;
  while(n<N){
    div=2;
    while(div<n){
        if(n%div==0){
                n+=1;
                cout<<n<<" is prime "<<endl;
        }
        else 
            div=div+1;
           cout<<n<<" is ------------------ "<<endl;
         
    }
  }
        
        
        //n=n+1;
    
    cout<<"there are " <<n <<" no of prime no in ";
    

return 0;}