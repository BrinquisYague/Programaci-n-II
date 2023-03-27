#include "maxsolape.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double randDouble(double a,double b)
{
    return a + ((double) rand() / RAND_MAX) * (b - a);
}

int main()
{
    srand(time(NULL));
    int n = 90000;
    double inters[N][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            inters[i][j]=randDouble(double(i),100);
        }
    }
    /*inters[0][0] = 1.5;
    inters[0][1] = 8.5;
    inters[1][0] = 0.0;
    inters[1][1] = 4.5;
    inters[2][0] = 2.0;
    inters[2][1] = 4.0;
    inters[3][0] = 1.0;
    inters[3][1] = 6.0;
    inters[4][0] = 3.5;
    inters[4][1] = 7.0;*/
    tpInter indinters[N];
    crearvind(inters,indinters,n);
    clock_t t1 = clock();
    tpSolape max = maxSolFBruta(inters,n);
    clock_t t2 = clock();
    cout << "El solape máximo es entre el intervalo " << indinters[max.interA].ini<<" -> "<< indinters[max.interA].fin<<" y el intervalo "
         << indinters[max.interB].ini<<" -> "<< indinters[max.interB].fin<<" con un valor de : "<< max.solape << endl<<"Tiempo: "<<float(t2-t1)/CLOCKS_PER_SEC<<endl;
    mergesortIndInters(indinters,0,n-1);
    cout <<endl;
    t1 = clock();
    max = maxSolDyV(indinters,0,n-1);
    t2 = clock();
    /*for(int i = 0;i < n;i++)
    {
        cout<<"ind: "<<indinters[i].ind<<", ini: "<<indinters[i].ini <<", "<<indinters[i].fin<<endl;
    }*/
    cout <<endl;
    cout << "El solape máximo es entre el intervalo con indice "<<max.interA<<" y el intervalo con indice "
         << max.interB <<" con un valor de : "<< max.solape << endl<<"Tiempo: "<<float(t2-t1)/CLOCKS_PER_SEC<<endl;
}
