
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Lab 04 - ECOP13A
// Pedro Henrique Oliveira Francisco 2022003245
// Q.01

class Polinomio
{
private:
    vector<double> coeficientes; // vetor com os coeficientes do polinômio
    int grau;                    // grau do polinômio

public:
    // Construtor que recebe o grau do polinômio e inicializa os coeficientes como 0
    Polinomio(int n)
    {
        grau = n;
        coeficientes.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            coeficientes[i] = 0;
        }
    }

    // Construtor que recebe os coeficientes do polinômio
    Polinomio(vector<double> c)
    {
        grau = c.size() - 1;
        coeficientes = c;
    }

    // Sobrecarga do operador de soma
    Polinomio operator+(Polinomio &p)
    {
        int maiorGrau = max(grau, p.grau);
        vector<double> soma(maiorGrau + 1);
        for (int i = 0; i <= maiorGrau; i++)
        {
            soma[i] = coeficientes[i] + p.coeficientes[i];
        }
        return Polinomio(soma);
    }

    // Sobrecarga do operador de subtração
    Polinomio operator-(Polinomio &p)
    {
        int maiorGrau = max(grau, p.grau);
        vector<double> subtracao(maiorGrau + 1);
        for (int i = 0; i <= maiorGrau; i++)
        {
            subtracao[i] = coeficientes[i] - p.coeficientes[i];
        }
        return Polinomio(subtracao);
    }

    // Sobrecarga do operador de leitura
    friend istream &operator>>(istream &is, Polinomio &p)
    {
        for (int i = 0; i <= p.grau; i++)
        {
            is >> p.coeficientes[i];
        }
        return is;
    }

    // Sobrecarga do operador de impressão
    friend ostream &operator<<(ostream &os, Polinomio &p)
    {
        for (int i = p.grau; i >= 0; i--)
        {
            if (p.coeficientes[i] != 0)
            {
                if (i != p.grau && p.coeficientes[i] > 0)
                {
                    os << "+";
                }
                if (p.coeficientes[i] != 1 || i == 0)
                {
                    os << p.coeficientes[i];
                }
                if (i > 1)
                {
                    os << "x^" << i;
                }
                else if (i == 1)
                {
                    os << "x";
                }
            }
        }
        return os;
    }
};

// Q.02

class Ponto
{
private:
    double x, y;

public:
    // Construtor que recebe as coordenadas do ponto
    Ponto(double x0, double y0)
    {
        x = x0;
        y = y0;
    }

    // Operador de pré-incremento
    Ponto &operator++()
    {
        x++;
        y++;
        return *this;
    }

    // Operador de pos-incremento
    Ponto operator++(int)
    {
        Ponto tmp = *this;
        x++;
        y++;
        return tmp;
    }

    // Método que imprime as coordenadas do ponto
    void imprimir()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    Ponto p(1, 2);
    cout << "Coordenadas do ponto inicial: ";
    p.imprimir();

    ++p;
    cout << "Coordenadas do ponto após o pré-incremento: ";
    p.imprimir();

    p++;
    cout << "Coordenadas do ponto após o pos-incremento: ";
    p.imprimir();

    return 0;
}

// Q.03

class Data
{
private:
    int dia, mes, ano;

public:
    // Construtor que recebe as informações da data
    Data(int d, int m, int a)
    {
        dia = d;
        mes = m;
        ano = a;
    }

    // Operador de pré-incremento
    Data &operator++()
    {
        dia++;
        if (dia > diasNoMes())
        {
            dia = 1;
            mes++;
            if (mes > 12)
            {
                mes = 1;
                ano++;
            }
        }
        return *this;
    }

    // Operador de pos-incremento
    Data operator++(int)
    {
        Data tmp = *this;
        ++(*this);
        return tmp;
    }

    // Sobrecarga do operador de leitura
    friend istream &operator>>(istream &is, Data &d)
    {
        char barra1, barra2;
        is >> d.dia >> barra1 >> d.mes >> barra2 >> d.ano;
        return is;
    }

    // Sobrecarga do operador de impressão
    friend ostream &operator<<(ostream &os, const Data &d)
    {
        os << setfill('0') << setw(2) << d.dia << " de ";
        switch (d.mes)
        {
        case 1:
            os << "janeiro";
            break;
        case 2:
            os << "fevereiro";
            break;
        case 3:
            os << "março";
            break;
        case 4:
            os << "abril";
            break;
        case 5:
            os << "maio";
            break;
        case 6:
            os << "junho";
            break;
        case 7:
            os << "julho";
            break;
        case 8:
            os << "agosto";
            break;
        case 9:
            os << "setembro";
            break;
        case 10:
            os << "outubro";
            break;
        case 11:
            os << "novembro";
            break;
        case 12:
            os << "dezembro";
            break;
        }
        os << " de " << d.ano;
        return os;
    }

    // Método auxiliar que retorna o número de dias no mês atual
    int diasNoMes()
    {
        if (mes == 2)
        {
            if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            return 30;
        }
        else
        {
            return 31;
        }
    }
};

// Q.04

// Classe Fracao

class Fracao
{
private:
    int numerador;
    int denominador;

public:
    Fracao(int numerador = 0, int denominador = 1);

    // Sobrecarga de operadores aritméticos
    Fracao operator+(const Fracao &outra) const;
    Fracao operator-(const Fracao &outra) const;
    Fracao operator*(const Fracao &outra) const;
    Fracao operator/(const Fracao &outra) const;

    // Funções auxiliares
    void simplificar();
    int mdc(int a, int b) const;
    void imprimir() const;

    // Operador de conversão para double
    operator double() const { return (double)numerador / denominador; }
};

// Classe Complexo

class Complexo
{
private:
    double real;
    double imaginario;

public:
    Complexo(double real = 0.0, double imaginario = 0.0);

    // Sobrecarga de operadores aritméticos
    Complexo operator+(const Complexo &outro) const;
    Complexo operator-(const Complexo &outro) const;
    Complexo operator*(const Complexo &outro) const;
    Complexo operator/(const Complexo &outro) const;

    // Sobrecarga de operadores de comparação
    bool operator<(const Complexo &outro) const;
    bool operator>(const Complexo &outro) const;
    bool operator<=(const Complexo &outro) const;
    bool operator>=(const Complexo &outro) const;
    bool operator==(const Complexo &outro) const;
    bool operator!=(const Complexo &outro) const;

    // Sobrecarga de operadores de entrada e saída
    friend ostream &operator<<(ostream &os, const Complexo &complexo);
    friend istream &operator>>(istream &is, Complexo &complexo);

    double modulo() const;

    // Operador de conversão para double
    operator double() const { return real; }
};

// Q0.5

class Livro
{
private:
    string titulo;
    string autor;
    string editora;
    string ISBN;
    int anoPublicacao;
    int numPaginas;
    int qtdDisponivel;
    int qtdTotal;

public:
    Livro(string titulo, string autor, string editora, string ISBN, int anoPublicacao, int numPaginas, int qtdTotal);

    // Métodos de acesso
    string getTitulo() const;
    string getAutor() const;
    string getEditora() const;
    string getISBN() const;
    int getAnoPublicacao() const;
    int getNumPaginas() const;
    int getQtdDisponivel() const;
    int getQtdTotal() const;

    // Métodos de modificação
    void setTitulo(string titulo);
    void setAutor(string autor);
    void setEditora(string editora);
    void setISBN(string ISBN);
    void setAnoPublicacao(int anoPublicacao);
    void setNumPaginas(int numPaginas);
    void setQtdTotal(int qtdTotal);
    void setQtdDisponivel(int qtdDisponivel);

    // Métodos de empréstimo e devolução
    void emprestarLivro();
    void devolverLivro();
};

// Construtor da classe Livro
Livro::Livro(string titulo, string autor, string editora, string ISBN, int anoPublicacao, int numPaginas, int qtdTotal) : titulo(titulo),
                                                                                                                          autor(autor),
                                                                                                                          editora(editora),
                                                                                                                          ISBN(ISBN),
                                                                                                                          anoPublicacao(anoPublicacao),
                                                                                                                          numPaginas(numPaginas),
                                                                                                                          qtdDisponivel(qtdTotal),
                                                                                                                          qtdTotal(qtdTotal)
{
}

// Métodos de acesso
string Livro::getTitulo() const
{
    return titulo;
}

string Livro::getAutor() const
{
    return autor;
}

string Livro::getEditora() const
{
    return editora;
}

string Livro::getISBN() const
{
    return ISBN;
}

int Livro::getAnoPublicacao() const
{
    return anoPublicacao;
}

int Livro::getNumPaginas() const
{
    return numPaginas;
}

int Livro::getQtdDisponivel() const
{
    return qtdDisponivel;
}

int Livro::getQtdTotal() const
{
    return qtdTotal;
}

// Métodos de modificação
void Livro::setTitulo(string titulo)
{
    this->titulo = titulo;
}

void Livro::setAutor(string autor)
{
    this->autor = autor;
}

void Livro::setEditora(string editora)
{
    this->editora = editora;
}

void Livro::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

void Livro::setAnoPublicacao(int anoPublicacao)
{
    this->anoPublicacao = anoPublicacao;
}

void Livro::setNumPaginas(int numPaginas)
{
    this->numPaginas = numPaginas;
}

void Livro::setQtdTotal(int qtdTotal)
{
    this->qtdTotal = qtdTotal;
    this->
}