#include <iostream>
#include <math.h>
using namespace std;

long long  modular(unsigned long long  base, unsigned long long  exp, unsigned long long  mod){
    long long  x = 1;
    int i;
    long long  power = base % mod;
    for (i = 0; i < sizeof(int) * 64; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }
    return x;
} 

bool WITNESS(long long a,long long  n){// n es impar, u es impar, a[1-n-1] , 
    long long int  t=1,u=1,aux = 2;;
    while(n-1>aux){  // hallamos t y u , n-1 = 2^t *u
        while(n-1>aux){
            u=u+2;
            aux = pow(2,t)*u;
        }
        if((n-1)== pow(2,t)*u)break;
        u=1;
        t=t+1;
        aux = pow(2,t)*u;
    }
    long long x0 = modular(a,u,n); //caso base x0 = a^u mod n
    if(x0 == 1 || x0+1 == n)return  false; // si es igual a 1 o -1 es un posible primo
    for(long i = 1;i<t;i++){
        x0 = modular(x0,2,n);
        if(x0 == (n-1))return false;// posible primo
    }
    return true;// compuesto
}

bool MILLER_RABIN(long long n,long long  s){// n
    for(long j = 1;j<s;j++){
        long long a = 2 + rand()% (n-1);
        if(WITNESS(a,n))return true;// compuesto 
    }
    return false;// posible primo
}

int main(){
    long long s = 10,n = 101;
    for(int i = 0;n<1000;n=n+2){
        if(!MILLER_RABIN(n,s)){
            cout<<"primo: "<<n<<"\t";i++;
            if(i==10){i=0;cout<<endl;}
        }
    }
    return 0;
}