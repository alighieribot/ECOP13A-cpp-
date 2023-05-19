//    Lab04
//    Pedro Henrique Oliveira Francisco
//    2022003245

// Questão 1

#include "CFracao.h"
#include <iostream>
using namespace std;

class CFracao
{
    // ... outras declarações e métodos já existentes ...

    // Sobrecarga de operadores aritméticos
    CFracao operator+(const CFracao &rhs);
    CFracao operator-(const CFracao &rhs);
    CFracao operator*(const CFracao &rhs);
    CFracao operator/(const CFracao &rhs);

    // Sobrecarga de operadores de comparação
    bool operator<(const CFracao &rhs);
    bool operator>(const CFracao &rhs);
    bool operator<=(const CFracao &rhs);
    bool operator>=(const CFracao &rhs);
    bool operator==(const CFracao &rhs);
    bool operator!=(const CFracao &rhs);

    // Sobrecarga de operadores de entrada e saída
    friend ostream &operator<<(ostream &os, const CFracao &fracao);
    friend istream &operator>>(istream &is, CFracao &fracao);
};

// Sobrecarga do operador <<
ostream &operator<<(ostream &os, const CFracao &fracao)
{
    os << fracao.m_numerador << "/" << fracao.m_denominador;
    return os;
}

// Sobrecarga do operador >>
istream &operator>>(istream &is, CFracao &fracao)
{
    char separador;
    is >> fracao.m_numerador >> separador >> fracao.m_denominador;
    return is;
}

int main()
{
    CFracao fracao1, fracao2;

    cout << "Digite a primeira fracao (a/b): ";
    cin >> fracao1;
    cout << "Digite a segunda fracao (a/b): ";
    cin >> fracao2;

    cout << "Soma: " << fracao1 + fracao2 << endl;
    cout << "Subtracao: " << fracao1 - fracao2 << endl;
    cout << "Multiplicacao: " << fracao1 * fracao2 << endl;
    cout << "Divisao: " << fracao1 / fracao2 << endl;

    cout << "fracao1 < fracao2: " << (fracao1 < fracao2 ? "true" : "false") << endl;
    cout << "fracao1 > fracao2: " << (fracao1 > fracao2 ? "true" : "false") << endl;
    cout << "fracao1 <= fracao2: " << (fracao1 <= fracao2 ? "true" : "false") << endl;
    cout << "fracao1 >= fracao2: " << (fracao1 >= fracao2 ? "true" : "false") << endl;

    // Questão 2

#include <iostream>
#include <cmath>

    using namespace std;

    class Complexo
    {
    private:
        double real;
        double imaginario;
        static int contador;

    public:
        Complexo() : real(0.0), imaginario(0.0)
        {
            contador++;
        }

        Complexo(double real, double imaginario) : real(real), imaginario(imaginario)
        {
            contador++;
        }

        ~Complexo()
        {
            contador--;
        }

        // Sobrecarga de aritméticos
        Complexo operator+(const Complexo &outro) const;
        Complexo operator-(const Complexo &outro) const;
        Complexo operator*(const Complexo &outro) const;
        Complexo operator/(const Complexo &outro) const;

        // Sobrecarga comparação
        bool operator<(const Complexo &outro) const;
        bool operator>(const Complexo &outro) const;
        bool operator<=(const Complexo &outro) const;
        bool operator>=(const Complexo &outro) const;
        bool operator==(const Complexo &outro) const;
        bool operator!=(const Complexo &outro) const;

        // Sobrecarga entrada e saída
        friend ostream &operator<<(ostream &os, const Complexo &complexo);
        friend istream &operator>>(istream &is, Complexo &complexo);

        double modulo() const;

        static int getContador();
    };

    // Sobrecarga comparação
    bool Complexo::operator<(const Complexo &outro) const
    {
        return this->modulo() < outro.modulo();
    }

    bool Complexo::operator>(const Complexo &outro) const
    {
        return this->modulo() > outro.modulo();
    }

    bool Complexo::operator<=(const Complexo &outro) const
    {
        return this->modulo() <= outro.modulo();
    }

    bool Complexo::operator>=(const Complexo &outro) const
    {
        return this->modulo() >= outro.modulo();
    }

    bool Complexo::operator==(const Complexo &outro) const
    {
        return this->real == outro.real && this->imaginario == outro.imaginario;
    }

    bool Complexo::operator!=(const Complexo &outro) const
    {
        return !(*this == outro);
    }

    // Sobrecarga <<
    ostream &operator<<(ostream &os, const Complexo &complexo)
    {
        os << complexo.real << " + " << complexo.imaginario << "i";
        return os;
    }

    // Sobrecarga >>
    istream &operator>>(istream &is, Complexo &complexo)
    {
        is >> complexo.real >> complexo.imaginario;
        return is;
    }

#include "Complexo.h"

    int main()
    {
        Complexo complexo1(3, 2), complexo2(1, 7);

        cout << "Complexo 1: " << complexo1 << endl;
        cout << "Complexo 2: " << complexo2 << endl;
        cout << "Soma: " << complexo1 + complexo2 << endl;
        cout << "Subtracao: " << complexo1 - complexo2 << endl;
        cout << "Multiplicacao: " << complexo1 * complexo2 << endl;
        cout << "Divisao: " << complexo1 / complexo2 << endl;

        cout << "Complexo 1 < Complexo 2: " << (complexo1 < complexo2 ? "true" : "false") << endl;
        cout << "Complexo 1 > Complexo 2: " << (complexo1 > complexo2 ? "true" : "false") << endl;
        cout << "Complexo 1 <= Complexo 2: " << (complexo1 <= complexo2 ? "true" : "false") << endl;
        cout << "Complexo 1 >= Complexo 2: " << (complexo1 >= complexo2 ? "true" : "false") << endl;
        cout << "Complexo 1 == Complexo 2: " << (complexo1 == complexo2 ? "true" : "false") << endl;
        cout << "Complexo 1 != Complexo 2: " << (complexo1 != complexo2 ? "true" : "false") << endl;

        // Testar a entrada e saída de um novo Complexo
        Complexo complexo3;
        cout << "Digite um novo numero complexo (formato a b): ";
        cin >> complexo3;
        cout << "Novo Complexo: " << complexo3 << endl;

        return 0;
    }

    // Questão 3

#ifndef INTEIRO_LONGO_H
#define INTEIRO_LONGO_H

#include <iostream>
#include <vector>

    using namespace std;

    class InteiroLongo
    {
    private:
        vector<int> digitos;

    public:
        InteiroLongo();
        ~InteiroLongo();

        friend istream &operator>>(istream &in, InteiroLongo &inteiro);
        friend ostream &operator<<(ostream &out, const InteiroLongo &inteiro);
        InteiroLongo operator+(const InteiroLongo &outro) const;
        InteiroLongo operator-(const InteiroLongo &outro) const;
        bool operator<(const InteiroLongo &outro) const;
        bool operator>(const InteiroLongo &outro) const;
        bool operator<=(const InteiroLongo &outro) const;
        bool operator>=(const InteiroLongo &outro) const;
        bool operator==(const InteiroLongo &outro) const;
        bool operator!=(const InteiroLongo &outro) const;
    };

#endif // INTEIRO_LONGO_H

#include "InteiroLongo.h"

    InteiroLongo::InteiroLongo() : digitos(30, 0)
    {
    }

    InteiroLongo::~InteiroLongo()
    {
    }

    istream &operator>>(istream &in, InteiroLongo &inteiro)
    {
        string entrada;
        in >> entrada;

        for (int i = 0; i < 30; i++)
        {
            inteiro.digitos[i] = entrada[i] - '0';
        }

        return in;
    }

    ostream &operator<<(ostream &out, const InteiroLongo &inteiro)
    {
        for (const int &digito : inteiro.digitos)
        {
            out << digito;
        }

        return out;
    }

    InteiroLongo InteiroLongo::operator+(const InteiroLongo &outro) const
    {
        InteiroLongo resultado;
        int carry = 0;

        for (int i = 29; i >= 0; i--)
        {
            int soma = digitos[i] + outro.digitos[i] + carry;
            resultado.digitos[i] = soma % 10;
            carry = soma / 10;
        }

        return resultado;
    }

    InteiroLongo InteiroLongo::operator-(const InteiroLongo &outro) const
    {
        InteiroLongo resultado;
        int carry = 0;

        for (int i = 29; i >= 0; i--)
        {
            int subtracao = digitos[i] - outro.digitos[i] - carry;
            if (subtracao < 0)
            {
                subtracao += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            resultado.digitos[i] = subtracao;
        }

        return resultado;
    }

#include "InteiroLongo.h"

    int main()
    {
        InteiroLongo num1, num2;

        cout << "Digite o primeiro numero inteiro longo: ";
        cin >> num1;

        cout << "Digite o segundo numero inteiro longo: ";
        cin >> num2;

        InteiroLongo soma = num1 + num2;
        cout << "Soma: " << soma << endl;

        InteiroLongo diferenca = num1 - num2;
        cout << "Diferença: " << diferenca << endl;

        cout << "Comparacoes:" << endl;
        cout << "num1 < num2: " << (num1 < num2 ? "verdadeiro" : "falso") << endl;
        cout << "num1 > num2: " << (num1 > num2 ? "verdadeiro" : "falso") << endl;
        cout << "num1 <= num2: " << (num1 <= num2 ? "verdadeiro" : "falso") << endl;
        cout << "num1 >= num2: " << (num1 >= num2 ? "verdadeiro" : "falso") << endl;
        cout << "num1 == num2: " << (num1 == num2 ? "verdadeiro" : "falso") << endl;
        cout << "num1 != num2: " << (num1 != num2 ? "verdadeiro" : "falso") << endl;

        return 0;
    }
