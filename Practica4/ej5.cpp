#include <iostream> 
using namespace std; 
 
void espacios(int n){ 
    for(int i=n; i>0; i--){ 
        cout<<" "; 
    } 
} 
 
void numCrec(int fila){ 
    for(int i=fila; i<=(fila*2-1); i++){ 
        cout<<i%10; 
    } 
} 
 
void numDec(int fila){ 
    for(int i=fila*2-2; i>=fila; i--){ 
        cout<<i%10; 
    } 
}

int main(){ 
    int n; 
    cout<<"Introduce un numero: "; 
    cin>>n; 
    for(int i=1; i<n; i++){ 
        espacios(n-i); 
        numCrec(i); 
        numDec(i); 
        cout<<endl; 
    } 
    return 0; 
} 
 
