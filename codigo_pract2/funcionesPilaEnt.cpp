#include "funcionesPilaEnt.hpp"

using namespace std;
// * Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// * Post: p = [d_1, d_2, ..., d_K] AND numDatos(p) = K
int numDatos(PilaEnt &p)
{
    if(estaVacia(p))
        return 0;
    else
    {
        int n = cima(p);
        desapilar(p);
        int n_datos = numDatos(p);
        apilar(p,n);
        return 1 + n_datos;
    }
}

// Pre:  p = [d_1, d_2, ..., d_K]  AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de
//       los datos apilados en la pila comenzando por la cima, d_K, y acabando
//       por el del fondo de la pila, d_1. Cada dato lo escribe en una línea,
//       empleando anchura caracteres y alineado a la derecha. Cada dato es
//       precedido por el carácter '|' y es seguido por los caracteres ' ' y
//       '|', tal como se  ilustra a continuación. Tras el último dato se
//       presenta una linea de la forma "+--...--+", seguida por una línea
//       en blanco:
//
//        |     d_K |
//        |     ... |
//        |     d_2 |
//        |     d_1 |
//        +---------+
void mostrar(PilaEnt &p, const int anchura)
{
    if(estaVacia(p))
        cout <<'+'<<setfill('-')<< setw(anchura+2)<<'+'<<setfill(' ')<<endl;
    else
    {
        int datoCima = cima(p);
        cout << '|'<<setw(anchura) <<datoCima <<" |"<<endl;
        desapilar(p);
        mostrar(p,anchura);
        apilar(p,datoCima);
    }


}


// Pre:  p = [d_1, d_2, ..., d_K]  AND 0<= n <=K
// Post: p = [d_N, d_N-1, ..., d_1] y presenta por pantalla un listado de los
//       datos apilados en la pila comenzando por el del fondo de la pila, d_1,
//       y acabando por el de la cima de la pila, d_K. Cada dato lo escribe
//       en una línea, empleando anchura caracteres y alineado a la derecha.
//       Cada dato es precedido por el carácter '|' y es seguido por los
//       caracteres ' ' y '|', tal como se  ilustra a continuación. Antes
//       del primer dato se presenta una linea de la forma "+--...--+":
//
//        +---------+
//        |     d_N |
//        |     d_N-1|
//        |     ... |
//        |     d_1 |
void mostrarInvertida(PilaEnt &p,const int n,const int anchura)
{
    if(n == 0)
        cout <<'+'<<setfill('-')<< setw(anchura+2)<<'+'<<setfill(' ')<<endl;
    else
    {
        mostrarInvertida(p,n-1,anchura);
        cout << '|'<<setw(anchura) <<p.stack[n-1] <<" |"<<endl;
    }

}
// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de los
//       datos apilados en la pila comenzando por el del fondo de la pila, d_1,
//       y acabando por el de la cima de la pila, d_K. Cada dato lo escribe
//       en una línea, empleando anchura caracteres y alineado a la derecha.
//       Cada dato es precedido por el carácter '|' y es seguido por los
//       caracteres ' ' y '|', tal como se  ilustra a continuación. Antes
//       del primer dato se presenta una linea de la forma "+--...--+":
//
//        +---------+
//        |     d_1 |
//        |     d_2 |
//        |     ... |
//        |     d_K |
void mostrarInvertida(PilaEnt &p, const int anchura)
{
    if(estaVacia(p))
        cout <<'+'<<setfill('-')<< setw(anchura+2)<<'+'<<setfill(' ')<<endl;
    else
    {
        int datoCima = cima(p);
        desapilar(p);
        mostrarInvertida(p,anchura);
        apilar(p,datoCima);
        cout << '|'<<setw(anchura) <<datoCima <<" |"<<endl;
    }

}


// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [d_2, ..., d_K]
void eliminarFondo(PilaEnt &p)
{
    if(!estaVacia(p))
    {
        int datoCima = cima(p);
        desapilar(p);
        if(!estaVacia(p))
        {
            eliminarFondo(p);
            apilar(p,datoCima);
        }
    }

}


// Pre:  p = [d_1, ..., d_{(K-i)}, d_{(K-i+1)}, d_{(K-i+2)}, ..., d_K] AND 0<= K AND 1<= i <= K
// Post: p = [d_1, ..., d_{(K-i)}, d_{(K-i+2)}, ..., d_K]
void eliminar(PilaEnt &p, const int i)
{
    if(i == 1)
        desapilar(p);
    else
    {
        int datoCima = cima(p);
        desapilar(p);
        eliminar(p,i-1);
        apilar(p,datoCima);
    }
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [nuevo, d_1, d_2, ..., d_K]
void insertarEnFondo(PilaEnt &pila, const int nuevo)
{
    
    if(estaVacia(pila))
        apilar(pila,nuevo);
    else
    {
        int datoCima = cima(pila);
        desapilar(pila);
        insertarEnFondo(pila,nuevo);
        apilar(pila,datoCima);
    }
    
}
