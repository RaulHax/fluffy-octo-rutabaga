#include "MaquinaDeVendas.h"

MaquinaDeVendas::MaquinaDeVendas( int c, string m, int p, int q )
{
    Cod = c;
    Marca = m;
    Preco = p;
    Quant = q;


}

MaquinaDeVendas::MaquinaDeVendas()
{
    Cod = 0;
    Marca = "N";
    Preco = 0.0;
    Quant = 0;
}

void MaquinaDeVendas::SetQtd( int c, string m, int p, int q )
{
    Cod = c;
    Marca = m;
    Preco = p;
    Quant = q;
}


int MaquinaDeVendas::getCod()
{
    return Cod;
}

string MaquinaDeVendas::getMarca()
{
    return Marca;
}

int MaquinaDeVendas::getPreco()
{
    return Preco;
}

int MaquinaDeVendas::getQuant()
{
    return Quant;
}

ostream& operator<<(ostream& s, const MaquinaDeVendas& Prod)
{
    s   << "Codigo: " << Prod.Cod
    << "\tMarca:" << Prod.Marca << ""
    << "\tPreco:" << Prod.Preco << ""
    << "\tQuantidade: " << Prod.Quant << endl;

    return s;
}

