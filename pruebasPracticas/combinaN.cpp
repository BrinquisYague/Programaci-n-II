#include <iostream>

using namespace std;
const unsigned MAXN = 256;

void mostrar(int v[],const int n)
{
    if(n>0)
    {
        mostrar(v,n-1);
        cout <<v[n-1]<<" ";
        
    }
        
}
void combinaN(int v[MAXN], int a, int p, int sumap, int n)
{
    bool exito = false;
    if(p == n && sumap+p <n)
    {
        cout<<p<<endl;
        return;
    }
    while(p < n && !exito)
    {
        v[a] = p;
        if(p+sumap ==n)
        {
            exito = true;
        }
        else if(p+sumap <n)
        {
            combinaN(v,a+1,p,sumap+p,n);  
        }
        p++;
    }
    if(!exito)
    {
        v[a]=0;
        return;
    }
    else{
        mostrar(v,a+1);
        cout <<endl;
        return;
    }

}

int main()
{
    int vector[MAXN] = {0};
    combinaN(vector,0,4,0,50);
}