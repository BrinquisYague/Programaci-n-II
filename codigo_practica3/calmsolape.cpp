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
    tpSolape max = maxSolFBruta(inters,5);
    cout << "El solape máximo es entre el intervalo " << max.interA<<" y el intervalo "
         << max.interB <<" con un valor de : "<< max.solape << endl;

}
