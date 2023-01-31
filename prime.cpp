 
#include<iostream>
using namespace std;

int main(){
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
    return 0;

}