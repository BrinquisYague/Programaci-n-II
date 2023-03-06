#include "pilaEnt.hpp"

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p)
{
    p.top = 0;
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo)
{
    p.top++;
    p.stack[p.top-1] = nuevo;
    
    
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p)
{
    p.top--;
}

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
// Post: cima(p) = d_K
int cima(const PilaEnt &p)
{
    return p.stack[p.top-1];
}

// Pre: ---
// Post: estaVacia(p) = (p = [])
bool estaVacia(const PilaEnt &p)
{
    return p.top == 0;
}

// * Pre: p = [d_1, d_2, ..., d_K]
// * Post: estaLlena(p) = (K = DIM])
bool estaLlena(const PilaEnt &p)
{
    return p.top == DIM;
}