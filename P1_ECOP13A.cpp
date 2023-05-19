//P1 ECOP13A
//Pedro Henrique Oliveira Francisco [2022003245]

/*
Instruções:
• Compactar os arquivos de código fonte e enviar na tarefa aberta no SIGAA.

1ª Questão:
Com base na questão 9 do lab1 e a classe Inteiro Longo com operadores sobrecarregados da questão
3 do lab4:
a) Implemente uma função membro que verifique se o objeto da classe Inteiro Longo é um
palíndromo.
b) Utilizar a função membro criada em um programa que lê um vetor com 5 objetos Inteiro Longo, e
verifica se cada um dos elementos lidos pelo usuário são palíndromos.
c) Sobrecarregue os operadores += e -= para a classe Inteiro Longo.

2ª Questão:
Com base no exercício 3-4 do lab7, acrescentar na hierarquia Ponto/Círculo/Cilindro, as classes
Quadrado e Prisma, considerando que um Prisma é um Quadrado com altura diferente de zero, e um
Quadrado é um Ponto com lado diferente de zero. Implemente as funções virtuais área e volume para as
classes criadas. Altere a função main e o menu criado no exercício 3 do lab7 para permitir que o usuário
insira no vetor de pontos, objetos dos tipos Quadrado e Prisma.
*/

//Questão 1
//a) Implementação da função membro para verificar se o objeto InteiroLongo é um palíndromo:

bool InteiroLongo::ehPalindromo() const
{
    for (int i = 0; i < 15; i++)
    {
        if (digitos[i] != digitos[29 - i])
        {
            return false;
        }
    }
    return true;
}

//b) Implementação do programa que lê um vetor com 5 objetos InteiroLongo e verifica se são palíndromos:

#include <iostream>
#include "InteiroLongo.h"

using namespace std;

int main()
{
    InteiroLongo vetor[5];

    for (int i = 1; i <= 5; i++)
    {
        cout << "Digite o " << i << "o numero inteiro de 7 digitos: ";
        cin >> vetor[i - 1];
        if (cin.fail() || cin.peek() != '\n') // verifica se o input é válido (7 dígitos)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Digite um numero inteiro de 7 digitos." << endl;
            i--;
        }
        else if (vetor[i - 1].ehPalindromo())
        {
            cout << "O numero digitado e um palindromo!\n";
        }
        else
        {
            cout << "O numero digitado nao e um palindromo.\n";
        }
    }

    return 0;
}

//c) Sobrecarga dos operadores += e -=:

InteiroLongo& InteiroLongo::operator+=(const InteiroLongo &outro)
{
    int carry = 0;

    for (int i = 29; i >= 0; i--)
    {
        int soma = digitos[i] + outro.digitos[i] + carry;
        digitos[i] = soma % 10;
        carry = soma / 10;
    }

    return *this;
}

InteiroLongo& InteiroLongo::operator-=(const InteiroLongo &outro)
{
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
        digitos[i] = subtracao;
    }

    return *this;
}

//Questão 2
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

class Quadrado : public Ponto
{
protected:
    double lado;

public:
    Quadrado(double _x = 0, double _y = 0, double _lado = 0) : Ponto(_x, _y), lado(_lado)
    {
        if (lado == 0)
            throw invalid_argument("O lado do quadrado deve ser diferente de zero.");
    }

    double getLado() const
    {
        return lado;
    }

    double area() const override
    {
        return lado * lado;
    }

    friend istream &operator>>(istream &in, Quadrado &quadrado)
    {
        in >> static_cast<Ponto &>(quadrado);
        in >> quadrado.lado;
        if (quadrado.lado == 0)
            throw invalid_argument("O lado do quadrado deve ser diferente de zero.");
        return in;
    }

    friend ostream &operator<<(ostream &out, const Quadrado &quadrado)
    {
        out << "Vértice: " << static_cast<const Ponto &>(quadrado);
        out << ", Lado: " << quadrado.lado;
        return out;
    }
};

class Cilindro : public Ponto
{
protected:
    double raio;
    double altura;

public:
    Cilindro(double _x = 0, double _y = 0, double _raio = 0, double _altura = 0)
        : Ponto(_x, _y), raio(_raio), altura(_altura)
    {
        if (altura == 0)
            throw invalid_argument("A altura do cilindro deve ser diferente de zero.");
        if (raio == 0)
            throw invalid_argument("O raio do cilindro deve ser diferente de zero.");
    }

    double getRaio() const
    {
        return raio;
    }

    double getAltura() const
    {
        return altura;
    }

    double volume() const
    {
        return area() * altura;
    }

    double area() const override
    {
        return 2 * M_PI * raio * (raio + altura);
    }

    friend istream &operator>>(istream &in, Cilindro &cilindro)
    {
        in >> static_cast<Ponto &>(cilindro);
        in >> cilindro.raio;
        if (cilindro.raio == 0)
            throw invalid_argument("O raio do cilindro deve ser diferente de zero.");
        in >> cilindro.altura;
        if (cilindro.altura == 0)
            throw invalid_argument("A altura do cilindro deve ser diferente de zero.");
        return in;
    }

    friend ostream &operator<<(ostream &out, const Cilindro &cilindro)
    {
        out << "Base: " << static_cast<const Ponto &>(cilindro);
        out << ", Raio: " << cilindro.raio;
        out << ", Altura: " << cilindro.altura;
        return out;
    }
};

class Prisma : public Quadrado
{
protected:
    double altura;

public:
    Prisma(double _x = 0, double _y = 0, double _lado = 0, double _altura = 0)
        : Quadrado(_x, _y, _lado), altura(_altura)
    {
        if (altura == 0)
            throw invalid_argument("A altura do prisma deve ser diferente de zero.");
    }

    double getAltura() const
    {
        return altura;
    }

    double volume() const
    {
        return area() * altura;
    }

    double area() const override
    {
        return 2 * Quadrado::area() + 4 * getLado() * altura;
    }

    friend istream &operator>>(istream &in, Prisma &prisma)
    {
        in >> static_cast<Quadrado &>(prisma);
        in >> prisma.altura;
        if (prisma.altura == 0)
            throw invalid_argument("A altura do prisma deve ser diferente de zero.");
        return in;
    }

    friend ostream &operator<<(ostream &out, const Prisma &prisma)
    {
        out << "Vértice: " << static_cast<const Ponto &>(prisma);
        out << ", Lado: " << prisma.getLado();
        out << ", Altura: " << prisma.altura;
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
        cout << "2 - Círculo" << endl;
        cout << "3 - Cilindro" << endl;
        cout << "4 - Quadrado" << endl;
        cout << "5 - Prisma" << endl;
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
        case 4:
            elemento = new Quadrado();
            break;
        case 5:
            elemento = new Prisma();
            break;
        case 0:
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
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
        cout << "Área: " << elemento->area() << endl;

        const Circulo *circulo = dynamic_cast<const Circulo *>(elemento);
        if (circulo != nullptr)
        {
            cout << "Raio do Círculo: " << circulo->getRaio() << endl;
        }

        const Cilindro *cilindro = dynamic_cast<const Cilindro *>(elemento);
        if (cilindro != nullptr)
        {
            cout << "Altura do Cilindro: " << cilindro->getAltura() << endl;
            cout << "Volume do Cilindro: " << cilindro->volume() << endl;
        }

        const Quadrado *quadrado = dynamic_cast<const Quadrado *>(elemento);
        if (quadrado != nullptr)
        {
            cout << "Lado do Quadrado: " << quadrado->getLado() << endl;
        }

        const Prisma *prisma = dynamic_cast<const Prisma *>(elemento);
        if (prisma != nullptr)
        {
            cout << "Altura do Prisma: " << prisma->getAltura() << endl;
            cout << "Volume do Prisma: " << prisma->volume() << endl;
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