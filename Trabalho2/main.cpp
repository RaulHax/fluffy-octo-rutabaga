//http://www.cranems.com/
//teste2
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string m;
    float p;
    int q;
    int c;

    cout << "Maquina de vendas" << endl ;

    cout << "Marca|Preco|Quantidade|Codigo" << endl;
    ifstream myfile;
    myfile.open ("test.txt", ios::in);
    myfile >> c >> m >> p >> q;
    cout << c << "|" << m << "|" << p << "|" << q << "|" << endl;
}
