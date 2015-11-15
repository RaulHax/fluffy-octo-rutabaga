//http://www.cranems.com/
//teste2
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Produto
{
    friend ostream& operator<<(ostream&, const Produto&);

private:
    string Marca;
    float  Preco;
    int Cod;
public:
    Produto(int c, string m, float p);
};

Produto::Produto( int c ,string m, float p)
{
    Marca = m;
    Preco = p;
    Cod = c;
}
ostream& operator<<(ostream& s, const Produto& Refri)
{
    s  << "Codigo do produto: " << Refri.Cod  << endl
       << "Marca: " << Refri.Marca << endl
       << "Preco: R$" << Refri.Preco << endl;


    return s;


}
class Estoque{
private:

public:



};
int main()
{

    int c;
    float p;
    string m;


    ifstream myfile;
    myfile.open ("bd1.txt", ios::in);
    myfile >> c >> m >> p;

    while (c != -1){
    Produto Refri(c,m,p); //, Refri1(c,m,p), Refri2(c,m,p);
    myfile >> c >> m >> p;
    cout << Refri << endl;

    //cout << Refri1 << endl;
   // cout << Refri2 << endl;
    }
    myfile.close();





}
