//http://www.cranems.com/
//Estoque
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


class Estoque
{
    friend std::ostream& operator<<(std::ostream&, const Estoque&);

private:
    int Cod;
    int Quant;

public:
    Estoque( int c, int q );
    Estoque();
    void SetQtd( int c, int q );
    int getCod();
    int getQuant();
};


Estoque::Estoque( int c, int q )
{
    Cod = c;
    Quant = q;

}

Estoque::Estoque()
{
    Cod = 0;
    Quant = 0;
}

void Estoque::SetQtd( int c, int q )
{
    Cod = c;
    Quant = q;
}


int Estoque::getCod()
{
    return Cod;
}

int Estoque::getQuant()
{
    return Quant;
}

ostream& operator<<(ostream& s, const Estoque& Prod)
{
    s  << "Codigo: " << Prod.Cod  //<< endl;

       << "\t Quantidade: " << Prod.Quant << endl;

    return s;
}
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

int main()
{

    int co;
    float p;
    string m;


    ifstream myfile;
    myfile.open ("bd1.txt", ios::in);
    myfile >> co >> m >> p;

    while (co != -1){
    Produto Refri(co,m,p);
    myfile >> co >> m >> p;
    cout << Refri << endl;
    }
    myfile.close();

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Estoque Prod[7];

    int proc_operacao = 0;
    bool produto_encontrado = false;
    int prod_select;
    int i=0;
    int j=0;
    int k=0;
    int c;
    int q;

    cout << " >>>>> CONSULTANDO Estoque-cp.txt <<<<<<" << endl;
    cout << endl;
    cout << " >>> PRODUTOS DIPONIVEIS: <<<" << endl;
    cout << endl;

    ifstream consulta_estoque;
    consulta_estoque.open ("Estoque-cp.txt", ios::in);
    consulta_estoque >> c >> q;

    while (c != -1)
    {
        Prod[i].SetQtd(c,q);
        consulta_estoque >> c >> q;
        cout << Prod[i] << endl;
        i++;
    }

    cout << endl;
    cout << endl;
    consulta_estoque.close();

    cout << " >>> ESCOLHA SEU PRODUTO:" << endl;
    cout << "Codigo: ";
    cin >> prod_select;


    ifstream consulta_produto;
    consulta_produto.open ("Estoque-cp.txt", ios::in);
    consulta_produto >> c >> q;

    while (c != -1)
    {

        if (c == prod_select)
        {
            cout << endl;
            cout << " >>> PRODUTO ESCOLHIDO:" << endl;
            cout << Prod[k] << endl;
            produto_encontrado = true;
            break;
        }
        else
        {
            consulta_produto >> c >> q;
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


        else
        {
            //CONFIRMAR PEDIDO
            cout << " >>>>> CONFIRMAR PEDIDO, DIGITE:" << endl;
            cout << "(1)PARA CONFIRMAR PEDIDO;" << endl;
            cout << "(2)REFAZER PEDIDO;" << endl;
            cout << "(3)CANCELAR OPERACAO;" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << " !!!CODIGO DE PRODUTO INCORRETO!!! " << endl;
        cout << "DIGITE: " << endl;
        cout << "(2)REFAZER PEDIDO;" << endl;
        cout << "(3)CANCELAR OPERACAO;" << endl;
        cout << endl;

    }

    cout << endl;
    cout << endl;


    consulta_produto.close();


    if(proc_operacao==0)
    {


        cout << " >>>>> ALTERANDO Estoque-cp.txt <<<<<<" << endl;
        cout << endl;

        ofstream altera_estoque("Estoque-cp.txt", ios::out); //ios::out = cria novo arquivo ou deleta dados; ios::app = mantem dados arquivo; ios::ate = mantem e coloca na posicao final; ios::trunc = deleta dados arquivo;

        cout << "PRODUTO ALTERADO:" << endl;
        Prod[k].SetQtd(Prod[k].getCod(),Prod[k].getQuant()-1);
        cout << Prod[k] << endl;
        cout << endl;

        cout << "ATUALIZANDO ESTOQUE:" << endl;
        //altera_estoque << "\n";
        while (j != 7)
        {
            altera_estoque << Prod[j].getCod() << " " << Prod[j].getQuant() << "\n";
            cout << Prod[j] << endl;
            j++;
        }
        altera_estoque << "-1";

        altera_estoque.close();


        cout << endl;
        cout << "OPERACAO CONCLUIDA!" << endl;

    }

    else if(proc_operacao==1)
    {
        cout << endl;
        cout << "OPERACAO CANCELADA!" << endl;

    }

    else if(proc_operacao==2)
    {
        cout << endl;
        cout << "OPERACAO CANCELADA!" << endl;

    }




    return 0;


}
