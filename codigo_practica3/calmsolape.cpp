#include "maxsolape.hpp"
#include <iostream>

using namespace std;

int main()
{

    double inters[N][2];
    inters[0][0] = 1.5;
    inters[0][1] = 8.5;
    inters[1][0] = 0.0;
    inters[1][1] = 4.5;
    inters[2][0] = 2.0;
    inters[2][1] = 4.0;
    inters[3][0] = 1.0;
    inters[3][1] = 6.0;
    inters[4][0] = 3.5;
    inters[4][1] = 7.0;
    tpInter indinters[N];
    crearvind(inters,indinters,5);
    tpSolape max = maxSolFBruta(inters,5);
    cout << "El solape máximo es entre el intervalo " << indinters[max.interA].ini<<" -> "<< indinters[max.interA].fin<<" y el intervalo "
         << indinters[max.interB].ini<<" -> "<< indinters[max.interB].fin<<" con un valor de : "<< max.solape << endl;
    mergesortIndInters(indinters,0,4);
    cout <<endl;
    max = maxSolDyV(indinters,0,4);
    for(int i = 0;i < 5;i++)
    {
        cout<<"ind: "<<indinters[i].ind<<", ini: "<<indinters[i].ini <<", "<<indinters[i].fin<<endl;
    }
    cout <<endl;
    cout << "El solape máximo es entre el intervalo con indice "<<max.interA<<" y el intervalo con indice "
         << max.interB <<" con un valor de : "<< max.solape << endl;
}
