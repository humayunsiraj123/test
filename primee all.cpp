


int main(){
    int n=2;
    int N=100;
    int div;
    while(n<N){
        div=2;
        while(div<n){
            if(n%div==0)
                {cout<< n<<" is  prime "<<endl;
                n=n+1;
            else 
                div=div+1;

        }
        
        cout<<"there are " <<n <<" no of prime no in ";
        n=n+1;


    }
    return 0;

}