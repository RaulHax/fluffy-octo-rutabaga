//http://www.cranems.com/
//teste2
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Produto
{
    friend std::ostream& operator<<(std::ostream&, const Produto&);

private:
    string Marca;
    float  Preco;
    int Quant;
    int Cod;
public:
    Produto(string m, float p,int q, int c);
};

Produto::Produto( string m, float p,int q, int c)
{
    Marca = m;
    Preco = p;
    Quant = q;
    Cod = c;
}
ostream& operator<<(ostream& s, const Produto& Refri)
{
    s  << "Codigo do produto: " << Refri.Cod  << endl
       << "Marca: " << Refri.Marca << endl
       << "Preco: " << Refri.Preco << endl
       << "Quantidade de itens: " << Refri.Quant << endl;

    return s;


}

int main()
{

    Produto Refri("Coca-Cola",2.50,5,1), Refri1("Kaut",2,5,2), Refri2("Fanta",3,5,3);
    cout << Refri << endl;
    cout << Refri1 << endl;
    cout << Refri2 << endl;

    int c, q;
    float p;
    string m;

    cout << "Marca|Preco|Quantidade|Codigo" << endl;
    ifstream myfile;
    myfile.open ("test.txt", ios::in);
    myfile >> c >> m >> p >> q;
    cout << c << "|" << m << "|" << p << "|" << q << "|" << endl;

}
