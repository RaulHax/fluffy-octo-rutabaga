//http://www.cranems.com/
//teste2
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class Produto{
private:
string Marca;
int Quantidade;
//float Preco;
//vector<MaquinaVenda> mv;

public:
Produto();
void Estoque(int v); //Verifica a quantidade de produtos na maquina

//void InformarPreço();
//float LerDinheiro(int  v);
//float DarTroco(int v);



};

Produto::Produto(){

}
//void Estoque(int v){

   // mv.push_back(v);
//}



int main()
{
    string m;
    float p;
    int q;
    int c;

    cout << "Maquina de vendas" << endl ;

    ifstream myfile;
    myfile.open ("test.txt", ios::in);
    myfile >> m >> p >> q >> c;
    cout << "Marca|Preco|Quantidade|Codigo" << endl;
    cout << m << "|" << p << "|" << q << "|" << c << "|";



   //vector <MaquinaVenda> maq;

    //maq.Estoque(5);
    //cout << maq;

}
