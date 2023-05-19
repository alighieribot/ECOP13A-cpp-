// Pedro Henrique Oliveira Francisco 2022003245
// ECOP13A LAB06

// 1
#include <iostream>
#include <cmath>
#include <vector>
#include "PhoneNumber.h"
using namespace std;

class Politico
{
public:
    Politico()
    {
        cout << "Construtor Politico" << endl;
    }

    void Imprime()
    {
        cout << "Sou um político" << endl;
    }
};

class Presidente : public Politico
{
public:
    Presidente()
    {
        cout << "Construtor Presidente" << endl;
    }

    void Imprime()
    {
        Politico::Imprime();
        cout << "Sou um presidente" << endl;
    }
};

class Governador : public Politico
{
public:
    Governador()
    {
        cout << "Construtor Governador" << endl;
    }

    void Imprime()
    {
        Politico::Imprime();
        cout << "Sou um governador" << endl;
    }
};

class Prefeito : public Politico
{
public:
    Prefeito()
    {
        cout << "Construtor Prefeito" << endl;
    }

    void Imprime()
    {
        Politico::Imprime();
        cout << "Sou um prefeito" << endl;
    }
};

int main()
{
    Politico politico;
    politico.Imprime();
    cout << endl;

    Presidente presidente;
    presidente.Imprime();
    cout << endl;

    Governador governador;
    governador.Imprime();
    cout << endl;

    Prefeito prefeito;
    prefeito.Imprime();
    cout << endl;

    return 0;
}

// 2
class Ponto
{
protected:
    double x;
    double y;

public:
    Ponto(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    friend istream &operator>>(istream &in, Ponto &ponto)
    {
        in >> ponto.x >> ponto.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Ponto &ponto)
    {
        out << "(" << ponto.x << ", " << ponto.y << ")";
        return out;
    }
};

class Circulo : public Ponto
{
protected:
    double raio;

public:
    Circulo(double _x = 0, double _y = 0, double _raio = 0) : Ponto(_x, _y), raio(_raio) {}

    double getRaio() const
    {
        return raio;
    }

    double area() const
    {
        return M_PI * raio * raio;
    }

    friend istream &operator>>(istream &in, Circulo &circulo)
    {
        in >> static_cast<Ponto &>(circulo);
        in >> circulo.raio;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Circulo &circulo)
    {
        out << "Centro: " << static_cast<const Ponto &>(circulo);
        out << ", Raio: " << circulo.raio;
        return out;
    }
};

class Cilindro : public Circulo
{
protected:
    double altura;

public:
    Cilindro(double _x = 0, double _y = 0, double _raio = 0, double _altura = 0)
        : Circulo(_x, _y, _raio), altura(_altura)
    {
        if (altura == 0)
            throw invalid_argument("A altura do cilindro deve ser diferente de zero.");
    }

    double getAltura() const
    {
        return altura;
    }

    double volume() const
    {
        return area() * altura;
    }

    friend istream &operator>>(istream &in, Cilindro &cilindro)
    {
        in >> static_cast<Circulo &>(cilindro);
        in >> cilindro.altura;
        if (cilindro.altura == 0)
            throw invalid_argument("A altura do cilindro deve ser diferente de zero.");
        return in;
    }

    friend ostream &operator<<(ostream &out, const Cilindro &cilindro)
    {
        out << "Base: " << static_cast<const Circulo &>(cilindro);
        out << ", Altura: " << cilindro.altura;
        return out;
    }
};

int main()
{
    Ponto ponto(1, 2);
    cout << "Ponto: " << ponto << endl;

    Circulo circulo(1, 2, 3);
    cout << "Círculo: " << circulo << endl;
    cout << "Área do Círculo: " << circulo.area() << endl;

    Cilindro cilindro(1, 2, 3, 4);
    cout << "Cilindro: " << cilindro << endl;
    cout << "Área da base do Cilindro: " << cilindro.area() << endl;
    cout << "Volume do Cilindro: " << cilindro.volume() << endl;

    // Leitura de um ponto do usuário
    cout << "Digite as coordenadas de um ponto (x y): ";
    cin >> ponto;
    cout << "Ponto lido: " << ponto << endl;

    // Leitura de um círculo do usuário
    cout << "Digite as coordenadas do centro do círculo (x y) e o raio: ";
    cin >> circulo;
    cout << "Círculo lido: " << circulo << endl;
    cout << "Área do círculo lido: " << circulo.area() << endl;

    // Leitura de um cilindro do usuário
    cout << "Digite as coordenadas da base do cilindro (x y), o raio e a altura: ";
    cin >> cilindro;
    cout << "Cilindro lido: " << cilindro << endl;
    cout << "Área da base do cilindro lido: " << cilindro.area() << endl;
    cout << "Volume do cilindro lido: " << cilindro.volume() << endl;

    return 0;
}

// 3
template <typename T>
class Polinomio
{
private:
    vector<T> coeficientes;

public:
    Polinomio(const vector<T> &_coeficientes) : coeficientes(_coeficientes) {}

    Polinomio<T> Derivada() const
    {
        vector<T> derivada;
        for (size_t i = 1; i < coeficientes.size(); i++)
        {
            derivada.push_back(coeficientes[i] * i);
        }
        return Polinomio<T>(derivada);
    }

    T ValorNoPonto(const T &x) const
    {
        T valor = 0;
        T x_i = 1;
        for (size_t i = 0; i < coeficientes.size(); i++)
        {
            valor += coeficientes[i] * x_i;
            x_i *= x;
        }
        return valor;
    }

    T MetodoNewton(const T &x0, const double epsilon, const int max_iteracoes) const
    {
        T xn = x0;
        for (int iteracao = 0; iteracao < max_iteracoes; iteracao++)
        {
            T fxn = ValorNoPonto(xn);
            T dfxn = Derivada().ValorNoPonto(xn);
            T xn1 = xn - (fxn / dfxn);
            if (abs(xn1 - xn) < epsilon)
                return xn1;
            xn = xn1;
        }
        throw runtime_error("Raiz não encontrada após o número máximo de iterações.");
    }
};

int main()
{
    vector<double> coeficientes = {1, -4, -10, 8}; // Coeficientes do polinômio: x^3 - 4x^2 - 10x + 8
    Polinomio<double> polinomio(coeficientes);

    Polinomio<double> derivada = polinomio.Derivada();
    cout << "Derivada do polinômio: ";
    for (size_t i = 0; i < derivada.coeficientes.size(); i++)
    {
        cout << derivada.coeficientes[i] << "x^" << i << " ";
    }
    cout << endl;

    double x = 2.0;
}

// 4
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

class PhoneNumber
{
    friend std::ostream &operator<<(std::ostream &, const PhoneNumber &);
    friend std::istream &operator>>(std::istream &, PhoneNumber &);

private:
    int areaCode; // Código de área (DDD) com três dígitos
    int exchange; // Código de troca com três dígitos
    int line;     // Número da linha com quatro dígitos
};

#endif

ostream &operator<<(ostream &output, const PhoneNumber &number)
{
    output << "(" << number.areaCode << ") " << number.exchange << "-" << number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number)
{
    char discard;
    input >> discard; // Ignora o (
    input >> number.areaCode;
    input >> discard; // Ignora o )
    input >> discard; // Ignora o espaço
    input >> number.exchange;
    input >> discard; // Ignora o -
    input >> number.line;
    return input;
}

int main()
{
    PhoneNumber phone;
    cout << "Digite o número de telefone no formato (DDD) XXXX-XXXX: ";
    cin >> phone;
    cout << "O número de telefone digitado foi: " << phone << endl;

    return 0;
}
