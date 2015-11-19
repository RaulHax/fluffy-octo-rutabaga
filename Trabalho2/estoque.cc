#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "MaquinaDeVendas.h"

using namespace std;

int main()
{

    MaquinaDeVendas Prod[7];

    int x,y,z;

    ifstream leitura;
    leitura.open ("Entrada.txt", ios::in);
    leitura >> x >> y >> z;



    system("cls");

    while (x!=0)
    {

        int proc_operacao = 0;
        bool produto_encontrado = false;
        int prod_select;
        int i=0;
        int j=0;
        int k=0;
        int c;
        string m;
        float p;
        int q;
        int ficha=0;
        int resul=0;

        cout << endl;
        cout << " >>> PRODUTOS DIPONIVEIS: <<<" << endl;
        cout << endl;

        ifstream consulta_estoque;
        consulta_estoque.open ("Estoque-cp.txt", ios::in);
        consulta_estoque >> c >> m >> p >> q;

        while (c != -1)
        {

            Prod[i].SetQtd(c,m,p,q);
            consulta_estoque >> c >> m >> p >> q;
            cout << Prod[i] << endl;
            i++;
        }

        cout << endl;

        cout << " >>> DEPOSITE SUAS FICHAS:";
        ficha = y;
        cout << y;
        cout << endl;

        consulta_estoque.close();
    cout << endl;


       cout << " >>> DIGITE O CODIGO DO PRODUTO    :" << z << endl;
    //cout << "Codigo: " << z;
        cout << endl;
        prod_select = z;


        ifstream consulta_produto;
        consulta_produto.open ("Estoque-cp.txt", ios::in);
        consulta_produto >> c >> m >> p >> q;



        while (c != -1)
        {

            if (c == prod_select)
            {

                cout << endl;
                cout << " >>> PRODUTO ESCOLHIDO:" << endl;
                cout << Prod[k] << endl;

                produto_encontrado = true;

                if (ficha >=p)
                {

                    resul = ficha - p;
                    break;

                }
                else if (ficha < p )
                {

                    cout << "   !!!FICHAS INSUFICIENTES!!!   " << endl;
                    cout << endl;
                    cout << "Troco:" << ficha << endl;
                    cout << endl;
                    break;

                }
                system("cls");


            }
            else
            {
                consulta_produto >> c >> m >> p >> q;
                k++;
            }
        }

//PROCESSAMENTO OPERACAO

        if (produto_encontrado == true)
        {

            if (Prod[k].getQuant()<=0)
            {
                proc_operacao = 1;
                cout << "!!!! PRODUTO ESCOLHIDO INDISPONIVEL !!!!" << endl;
                cout << endl;
                cout << "Troco:" << ficha << endl;
            }
        }
        else
        {
            cout << " !!!CODIGO DE PRODUTO INCORRETO!!! " << endl;

        }

        cout << endl;
        cout << endl;


        consulta_produto.close();

        if (proc_operacao==0 && ficha >=p)
        {


            ofstream altera_estoque("Estoque-cp.txt", ios::out);

            cout << "PRODUTO ALTERADO:" << endl;
            Prod[k].SetQtd(Prod[k].getCod(),Prod[k].getMarca(),Prod[k].getPreco(),Prod[k].getQuant()-1);
            cout << Prod[k] << endl;
            cout << endl;

            cout << "ATUALIZANDO ESTOQUE:" << endl;


            while (j != 7)
            {
                altera_estoque << Prod[j].getCod() << " " << Prod[j].getMarca() << " " << Prod[j].getPreco() << " " << Prod[j].getQuant() << "\n";
                 cout << Prod[j] << endl;
                j++;
            }
            altera_estoque << "-1";

            altera_estoque.close();


            cout << endl;
            cout << "!!!OPERACAO CONCLUIDA!!!" << endl;
            cout << endl;
            cout << "Troco:" << resul;
            cout << endl;

        }
        break;
    }





}




