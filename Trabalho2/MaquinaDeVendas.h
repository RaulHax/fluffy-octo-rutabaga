#ifndef MAQUINADEVENDAS_H_INCLUDED
#define MAQUINADEVENDAS_H_INCLUDED
#include <iostream>

using namespace std;

class MaquinaDeVendas
{
    friend std::ostream& operator<<(std::ostream&, const MaquinaDeVendas&);

private:
    int Cod;
    string Marca;
    float Preco;
    int Quant;


public:
    MaquinaDeVendas(int c, string m, int p, int q);
    MaquinaDeVendas();
    void SetQtd( int c, string m, int p, int q );
    int getCod();
    int getPreco();
    string getMarca();
    int getQuant();
};





#endif // MAQUINADEVENDAS_H_INCLUDED
