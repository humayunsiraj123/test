//#include<iostream>
//#include <conio.h>
//#include <string.h>

#include<string>
class Stack{
    private:
        int top;
        int n;
        int arr[];
    public:
        Stack(){
        n=5;
        top=-1;
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        }

    bool isnull(){
        if(top==-1)
            {cout<<"yes its is NULL"<<endl;
            return true;}
        else{cout<<"No ITS filled"<<endl;
            return false;}    
    }

    bool isfull(){
        if(top==n-1)
            {cout<<"yes its is FULL"<<endl;
            return true;}
        else{cout<<"No its no filled"<<endl;
            return false;}        }

    void push(int value){
        if(!isfull()){
            top++;
            arr[top]=value;

        }
        else
            cout<<"the stack is full \n";
       
    }
    int pop(){int result;
        if(isnull()){
            cout<<"the stack is empyth\n";
        }
        else{            result=arr[top];
            top--;
    }
        return result
            
    }
    
    int count(){
        return(top+1);

    }

    int peek(int index){
        int result;
        if(isnull()){
            cout<<"the stack is empyth\n";
    }   
        else
        result=arr[index];
    return result;

}

 void change(int pos,int val){
    arr[pos]=value;
    cout<<"the value has been change\n";
 }

 void display(){
    
    for(int i=0;i<n;i++){
        cout<<"At position = "< i<" value ="<arr[i]<endl;
    }

 }

};
 int main(){
    Stack s1;
    int pos,option ,value;

    do{
        cout<<"what o[perationyou want to do :"<<endl;
        cout<<"1 for PuSh :"<<endl;
        cout<<"2 for pop :"<<endl;
        cout<<"3 for isnull() :"<<endl;
        cout<<"4 for isfull() :"<<endl;
        cout<<"5 for count() :"<<endl;
        cout<<"6 for change():"<<endl;
        cout<<"7 for dsiaply():"<<endl;
        cout<<"8 for peek():"<<endl;
        
        cout<<"q for quitt:"<<endl;

        cin>>option;
        switch (option){
            case 1:{int value;

            cout<<"enter the value to be push";
            cin>>value;
            s1.push(value);
            break;}
        case 2:{int value;

            cout<<"the pop value result is;\n";
            
            value=s1.pop();
            break;}
        
        }
        case 5:{
            cout<<"the no of count is ="<<s1.count();
        break;
        }
case 3:{s1.isnull();
            break;
        }
case 4:{s1.isfull();
            break;
        }

        case 6:{
            int pos,value;
            cout<<"enter the possition ";
            cin>>pos;

            cout<<"enter the value ";
            cin>>value;
            s1.change(pos,value);
            break;

        }

        case 7:{
            s1.display();
            break;

        }

        case 8:{
            int pos;
            cout<<"enter the positon to peek";
            cin>>pos;
            cout<< "the value at peek pos ="<<pos << " is  ="<<s1.peek(pos)<<endl;;
        }
    default:
    cout<<"invalid entery";

    }
    while(option=!q);

    return;

    
 }




    

