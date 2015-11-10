//http://www.cranems.com/
//teste2
#include <iostream>
#include <string>

using namespace std;


class Produto
{
private:
    string Marca;
    float  Preco;
    int Quant;
    int Cod;
public:
    Produto(string m, float p,int q, int c);
    //void MarcaRefri(string a);
    //void PrecoRefri(float a);
    //void QuantRefri(int a);
    //void CodRefri(int a);

};
Produto::Produto( string m, float p,int q, int c)
{
Marca = m;
Preco = p;
Quant = q;
Cod = c;
}

/*void Produto::MarcaRefri(string a)
{
   a = Marca;

}

void Produto::PrecoRefri(float a)

{
    Preco = a;
}
void QuantRefri(float a)
{

}
*/
int main()
{

 Produto Coca("coca",5.5,5,32);

    cout << Coca << endl;











}
