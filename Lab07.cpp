// Pedro Henrique Oliveira Francisco [2022003245]
// LAB07 - ECOP13A

// Quest�o 1:
#include <iostream>
#include <vector>

using namespace std;

class Politico
{
public:
    virtual void imprimir()
    {
        cout << "Sou um pol�tico." << endl;
    }
};

class Presidente : public Politico
{
public:
    void imprimir() override
    {
        cout << "Sou um presidente." << endl;
    }
};

class Governador : public Politico
{
public:
    void imprimir() override
    {
        cout << "Sou um governador." << endl;
    }
};

class Prefeito : public Politico
{
public:
    void imprimir() override
    {
        cout << "Sou um prefeito." << endl;
    }
};

int main()
{
    vector<Politico *> politicos;

    int opcao;
    do
    {
        cout << "Escolha o tipo de objeto a ser criado:" << endl;
        cout << "1 - Presidente" << endl;
        cout << "2 - Governador" << endl;
        cout << "3 - Prefeito" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        Politico *politico;

        switch (opcao)
        {
        case 1:
            politico = new Presidente();
            politicos.push_back(politico);
            break;
        case 2:
            politico = new Governador();
            politicos.push_back(politico);
            break;
        case 3:
            politico = new Prefeito();
            politicos.push_back(politico);
            break;
        case 0:
            break;
        default:
            cout << "Op��o inv�lida. Tente novamente." << endl;
            break;
        }

    } while (opcao != 0);

    for (Politico *politico : politicos)
    {
        politico->imprimir();
    }

    for (Politico *politico : politicos)
    {
        delete politico;
    }
    politicos.clear();

    return 0;
}

// Quest�o 2
#ifndef POLITICO_H
#define POLITICO_H

#include <string>
#include <iostream>

using namespace std;

namespace Politicos
{

    class Politico
    {
    protected:
        int numero;
        string nome;
        string partido;

    public:
        Politico(int numero, const string &nome, const string &partido);
        virtual void imprimir();

        friend ostream &operator<<(ostream &os, const Politico &politico);
    };

    class Presidente : public Politico
    {
    public:
        Presidente(int numero, const string &nome, const string &partido);
        void imprimir() override;
    };

    class Governador : public Politico
    {
    private:
        string estado;

    public:
        Governador(int numero, const string &nome, const string &partido, const string &estado);
        void imprimir() override;

        friend ostream &operator<<(ostream &os, const Governador &governador);
    };

    class Prefeito : public Politico
    {
    private:
        string municipio;

    public:
        Prefeito(int numero, const string &nome, const string &partido, const string &municipio);
        void imprimir() override;
    };

} // namespace Politicos

#endif

// Quest�o 3
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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
    vector<Ponto *> elementos;

    int opcao;
    do
    {
        cout << "Escolha o tipo de objeto a ser criado:" << endl;
        cout << "1 - Ponto" << endl;
        cout << "2 - C�rculo" << endl;
        cout << "3 - Cilindro" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        Ponto *elemento;

        switch (opcao)
        {
        case 1:
            elemento = new Ponto();
            cin >> *elemento;
            elementos.push_back(elemento);
            break;
        case 2:
            elemento = new Circulo();
            cin >> *dynamic_cast<Circulo *>(elemento);
            elementos.push_back(elemento);
            break;
        case 3:
            elemento = new Cilindro();
            cin >> *dynamic_cast<Cilindro *>(elemento);
            elementos.push_back(elemento);
            break;
        case 0:
            break;
        default:
            cout << "Op��o inv�lida. Tente novamente." << endl;
            break;
        }

    } while (opcao != 0);

    for (const Ponto *elemento : elementos)
    {
        cout << *elemento << endl;
    }

    for (Ponto *elemento : elementos)
    {
        delete elemento;
    }
    elementos.clear();

    return 0;
}

// Quest�o 4
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

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

    virtual double area() const
    {
        return 0;
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

    double area() const override
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

    double area() const override
    {
        double baseArea = Circulo::area();
        double lateralArea = 2 * M_PI * getRaio() * altura;
        return 2 * baseArea + lateralArea;
    }
};

int main()
{
    vector<Ponto *> elementos;

    int opcao;
    do
    {
        cout << "Escolha o tipo de objeto a ser criado:" << endl;
        cout << "1 - Ponto" << endl;
        cout << "2 - C�rculo" << endl;
        cout << "3 - Cilindro" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        Ponto *elemento = nullptr;

        switch (opcao)
        {
        case 1:
            elemento = new Ponto();
            break;
        case 2:
            elemento = new Circulo();
            break;
        case 3:
            elemento = new Cilindro();
            break;
        case 0:
            break;
        default:
            cout << "Op��o inv�lida. Tente novamente." << endl;
            continue;
        }

        if (elemento != nullptr)
        {
            cin >> *elemento;
            elementos.push_back(elemento);
        }

    } while (opcao != 0);

    for (const Ponto *elemento : elementos)
    {
        cout << *elemento << endl;
        cout << "�rea: " << elemento->area() << endl;

        const Circulo *circulo = dynamic_cast<const Circulo *>(elemento);
        if (circulo != nullptr)
        {
            cout << "Raio do C�rculo: " << circulo->getRaio() << endl;
        }

        const Cilindro *cilindro = dynamic_cast<const Cilindro *>(elemento);
        if (cilindro != nullptr)
        {
            cout << "Altura do Cilindro: " << cilindro->getAltura() << endl;
            cout << "Volume do Cilindro: " << cilindro->volume() << endl;
        }

        cout << "------------------------" << endl;
    }

    for (Ponto *elemento : elementos)
    {
        delete elemento;
    }
    elementos.clear();

    return 0;
}
