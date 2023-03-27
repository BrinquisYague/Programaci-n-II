#include "maxsolape.hpp"

// Cada fila de inters representa un intervalo. La primera columna
// es el inicio del intervalo, y la segunda el final. Por ejemplo:
//    double inters[N][2] = {
//        {1.5, 8.0},
//        {0.0, 4.5},
//        {2.0, 4.0},
//        {1.0, 6.0},
//        {3.5, 7.0}
//    };
// tiene cinco intervalos, el primero empieza en 1.5 y termina en 8.0.

double distIntervalos(tpInter a, tpInter b)
{
    if(a.ini <= b.ini && b.ini <= a.fin)
    {
        if(b.fin > a.fin)
            return a.fin - b.ini;
        else
            return b.fin - b.ini;
    }
    else if(b.ini <= a.ini && a.ini <= b.fin)
    {
        if(a.fin > b.fin)
            return b.fin - a.ini;
        else
            return a.fin - a.ini;
    }
    else
    {
        return 0.0;
    }
}
// maxSolFBruta devuelve un registro tpSolape en el que el campo solape
// es el maximo solape entre parejas de los n primeros intervalos de inters,
// y los campos interA e interB son los indices de dichos intervalos.
// Para la matriz inters de ejemplo, el resultado es solape=4.5, interA=0,
// interB=3
// (los valores de interA e interB pueden estar intercambiados, es decir,
// el resultado para el ejemplo anterior tambi�n puede ser solape=4.5,
// interA=3, interB=0).
tpSolape maxSolFBruta(double inters[N][2], int n)
{
    tpSolape max = {0,0,0};
    for(unsigned i = 0; i < n; i++)
    {
        for(unsigned j = i+1; j < n; j++)
        {
           
            tpInter a = {int(i),inters[i][0],inters[i][1]};
            tpInter b = {int(j),inters[j][0],inters[j][1]};
            
            double dist = distIntervalos(a,b);
            if(dist > max.solape)
            {
                max.interA = a.ind;
                max.interB = b.ind;
                max.solape = dist;
            }
            
        }
    }

    return max;
}

// Crea un vector de tpInter con los n primeros intervalos de inters.
// Por ejemplo para la matrix inters de la funcion anterior y n=5, los
// valores de indinters seran:
// [{ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void crearvind(double inters[N][2], tpInter indinters[N], int n)
{
    if(n > 0)
    {
        indinters[n-1].ini = inters[n-1][0];
        indinters[n-1].fin = inters[n-1][1];
        indinters[n-1].ind = n-1;
        crearvind(inters,indinters,n-1);
    }
}
void merge(tpInter indinters[N], int p, int m,int f)
{
    tpInter aux[N];
    int h = p, i=p , j =m+1;

    while(h <=m && j <= f)
    {
        if(indinters[h].ini < indinters[j].ini)
        {
            aux[i]=indinters[h];
            h++;
        }
        else if(indinters[h].ini == indinters[j].ini)
        {
            if(indinters[h].fin <= indinters[j].fin)
            {
                aux[i]=indinters[h];
                h++;
            }
            else{
                aux[i]=indinters[j];
                j++;
            }
        }
        else
        {
            aux[i]=indinters[j];
            j++;
        }
        i++;
    }
    if(h >m)
    {
        for(int k = j;k <=f; k++)
        {
            aux[i]= indinters[k];
            i++;
        }
    }
    else{
        for(int k = h; k <=m; k++)
        {
            aux[i]= indinters[k];
            i++;
        }
    }
    for(int k=p;k<=f;k++)
    {
        indinters[k]=aux[k];
    }
}
// Ordena con el algoritmo mergesort los intervalos de indinters
// comprendidos entre las componentes indexadas por p y f, ambas incluidas,
// de acuerdo al valor de inicio de los intervalos (orden creciente).
// Por ejemplo, para el vector de la funcion anterior, p=0 y f=4, el vector
// ordenado sera:
// [{ind: 1, ini: 0.0, fin: 4.5},
//  {ind: 3, ini: 1.0, fin: 6.0},
//  {ind: 0, ini: 1.5, fin: 8.0},
//  {ind: 2, ini: 2.0, fin: 4.0},
//  {ind: 4, ini: 3.5, fin: 7.0}]
void mergesortIndInters(tpInter indinters[N], int p, int f)
{
    if(p < f)
    {
        int medio = (f+p)/2;
        mergesortIndInters(indinters,p,medio);
        mergesortIndInters(indinters,medio+1,f);
        merge(indinters,p,medio,f);

    }
}


tpSolape comb(tpInter indinters[N],int p,int m,int f)
{
    if(p > m || m+1 > f)
    {
        tpSolape sol;
        sol.interA = -1;
        sol.interB = -1;
        sol.solape= 0;
        return sol;
    }
    else{
        tpInter izq2de;
        izq2de.ind=-1; izq2de.ini=0; izq2de.fin=0;
        for(int i=p;i<=m;i++)
        {
            if(indinters[i].fin > izq2de.fin)
            {
                izq2de  = indinters[i]; 
            }
        }
        tpSolape sol;
        sol.interA=-1;sol.interB=-1;sol.solape = 0;
        for(int i = m+1; i<=f; i++)
        {
           double dist = distIntervalos(izq2de,indinters[i]);
           if(dist > sol.solape)
           {
                sol.interA=izq2de.ind;
                sol.interB=indinters[i].ind;
                sol.solape=dist;
           }
        }
        return sol;
    }
}

// Dado un vector indinters, utiliza la tecnica de Divide y Venceras para
// devolver el maximo solape entre parejas de intervalos comprendidos
// entre las componentes indexadas por p y f, ambas incluidas.
// Por ejemplo, para el vector del procedimiento anterior,
// el resultado es solape=4.5, interA=0, interB=3
tpSolape maxSolDyV(tpInter indinters[N], int p, int f)
{
    
}