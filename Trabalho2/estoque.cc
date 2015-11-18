//http://www.cranems.com/
//Estoque
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;


class Estoque
{
    friend std::ostream& operator<<(std::ostream&, const Estoque&);

private:
    int Cod;
    string Marca;
    float Preco;
    int Quant;


public:
    Estoque(int c, string m, int p, int q);
    Estoque();
    void SetQtd( int c, string m, int p, int q );
    int getCod();
    int getPreco();
    string getMarca();
    int getQuant();
};


Estoque::Estoque( int c, string m, int p, int q )
{
    Cod = c;
    Marca = m;
    Preco = p;
    Quant = q;


}

Estoque::Estoque()
{
    Cod = 0;
    Marca = "N";
    Preco = 0.0;
    Quant = 0;
}

void Estoque::SetQtd( int c, string m, int p, int q )
{
    Cod = c;
    Marca = m;
    Preco = p;
    Quant = q;
}


int Estoque::getCod()
{
    return Cod;
}

string Estoque::getMarca()
{
    return Marca;
}

int Estoque::getPreco()
{
    return Preco;
}

int Estoque::getQuant()
{
    return Quant;
}

ostream& operator<<(ostream& s, const Estoque& Prod)
{
    s   << "Codigo: " << Prod.Cod
        << "\tMarca:" << Prod.Marca << ""
        << "\tPreco:" << Prod.Preco << ""
        << "\tQuantidade: " << Prod.Quant << endl;

    return s;
}


int main()
{

    Estoque Prod[7];
    int a;

    cout << "-----------------DIGITE 1 PARA COMPRAR OU 0 PARA SAIR-----------------" << endl;
    cin >>  a ;

    system("cls");

    while (a!=0)
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

        //cout << " >>>>> CONSULTANDO Estoque-cp.txt <<<<<<" << endl;
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
        cin >> ficha;

        cout << endl;
        cout << endl;
        consulta_estoque.close();

        cout << " >>> ESCOLHA SEU PRODUTO:" << endl;
        cout << "Codigo: ";
        cin >> prod_select;



        ifstream consulta_produto;
        consulta_produto.open ("Estoque-cp.txt", ios::in);
        consulta_produto >> c >> m >> p >> q;

        //system("cls");

        while (c != -1)
        {

            if (c == prod_select)
            {

                cout << endl;
                cout << " >>> PRODUTO ESCOLHIDO:" << endl;
                cout << Prod[k] << endl;

                produto_encontrado = true;

             if(ficha >=p)
                {

                    resul = ficha - p;
                }
                else if(ficha < p )
                {

                    cout << "   !!!FICHAS INSUFICIENTES!!!   " << endl;
                    cout << endl;
                    cout << "Retire seu total te fichas: " << ficha << endl;

                    break;

                }
                 system("cls");
                cout << "Troco:" << resul;

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
            }

            /*       else{
                    //CONFIRMAR PEDIDO
                    cout << " >>>>> CONFIRMAR PEDIDO, DIGITE:" << endl;
                    cout << "(1)PARA CONFIRMAR PEDIDO;" << endl;
                    cout << "(2)REFAZER PEDIDO;" << endl;
                    cout << "(3)CANCELAR OPERACAO;" << endl;
                    cout << endl;
                }*/
        }
        else
        {
            cout << " !!!CODIGO DE PRODUTO INCORRETO!!! " << endl;
            /* cout << "DIGITE: " << endl;
             cout << "(2)REFAZER PEDIDO;" << endl;
             cout << "(3)CANCELAR OPERACAO;" << endl;
             cout << endl;*/

        }

        cout << endl;
        cout << endl;


        consulta_produto.close();

        if(proc_operacao==0 && ficha >=p)
        {


            // cout << " >>>>> ALTERANDO Estoque-cp.txt <<<<<<" << endl;
            //cout << endl;

            ofstream altera_estoque("Estoque-cp.txt", ios::out); //ios::out = cria novo arquivo ou deleta dados; ios::app = mantem dados arquivo; ios::ate = mantem e coloca na posicao final; ios::trunc = deleta dados arquivo;

            //cout << "PRODUTO ALTERADO:" << endl;
            Prod[k].SetQtd(Prod[k].getCod(),Prod[k].getMarca(),Prod[k].getPreco(),Prod[k].getQuant()-1);
            //  cout << Prod[k] << endl;
            //cout << endl;

            //cout << "ATUALIZANDO ESTOQUE:" << endl;
            //altera_estoque << "\n";
            while (j != 7)
            {
                altera_estoque << Prod[j].getCod() << " " << Prod[j].getMarca() << " " << Prod[j].getPreco() << " " << Prod[j].getQuant() << "\n";
                //cout << Prod[j] << endl;
                j++;
            }
            altera_estoque << "-1";

            altera_estoque.close();


            cout << endl;
            cout << "OPERACAO CONCLUIDA!" << endl;
            cout << endl;
        }

        }

        /*     else if(proc_operacao==1)
             {
                 cout << endl;
                 cout << "OPERACAO CANCELADA!" << endl;

             }

             else if(proc_operacao==2)
             {
                 cout << endl;
                 cout << "OPERACAO CANCELADA!" << endl;

             }
        */
        cout << "-----------------DIGITE 1 PARA COMPRAR OU 0 PARA SAIR-----------------" << endl;
        cin >>  a ;

    }




