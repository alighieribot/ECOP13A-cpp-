#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Questão 1
int calcularFatorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * calcularFatorial(n - 1);
}

// Questão 2
bool verificarPrimo(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void imprimirPrimos(int n)
{
    int count = 0;
    int num = 2;

    while (count < n)
    {
        if (verificarPrimo(num))
        {
            cout << num << " ";
            count++;
        }
        num++;
    }

    cout << endl;
}

// Questão 3
void menu()
{
    int opcao;

    do
    {
        cout << "Selecione uma opção:" << endl;
        cout << "1 - Calcular fatorial" << endl;
        cout << "2 - Imprimir os 20 primeiros números primos" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int num;
            cout << "Digite um número: ";
            cin >> num;
            cout << "Fatorial de " << num << ": " << calcularFatorial(num) << endl;
            break;
        }
        case 2:
            cout << "Os 20 primeiros números primos são: ";
            imprimirPrimos(20);
            break;
        case 0:
            cout << "Encerrando o programa." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }

        cout << endl;

    } while (opcao != 0);
}

// Questão 4
int calcularResultado(int n, int base)
{
    if (n == 0)
        return 0;
    else
        return (n % base + 10 * calcularResultado(n / base, base));
}

// Questão 6
int calcularSomaRecursiva(int n)
{
    if (n == 1)
        return 1;
    else
        return n + calcularSomaRecursiva(n - 1);
}

// Questão 7
int calcularMDC(int x, int y)
{
    if (y == 0)
        return x;
    else
        return calcularMDC(y, x % y);
}

// Questão 8
int binarioParaDecimal(int binario)
{
    int decimal = 0;
    int posicao = 0;

    while (binario > 0)
    {
        decimal += (binario % 10) * pow(2, posicao);
        binario /= 10;
        posicao++;
    }

    return decimal;
}

// Questão 9
bool verificarPalindromo(int numero)
{
    string str = to_string(numero);

    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
            return false;
    }

    return true;
}

// Questão extra
class Retangulo
{
private:
    double comprimento;
    double largura;

public:
    Retangulo(double _comprimento = 1, double _largura = 1)
    {
        setComprimento(_comprimento);
        setLargura(_largura);
    }

    void setComprimento(double _comprimento)
    {
        if (_comprimento >= 0 && _comprimento <= 20)
            comprimento = _comprimento;
        else
            comprimento = 1;
    }

    void setLargura(double _largura)
    {
        if (_largura >= 0 && _largura <= 20)
            largura = _largura;
        else
            largura = 1;
    }

    double getComprimento() const
    {
        return comprimento;
    }

    double getLargura() const
    {
        return largura;
    }

    double calcularArea() const
    {
        return comprimento * largura;
    }

    double calcularPerimetro() const
    {
        return 2 * (comprimento + largura);
    }

    void desenharRetangulo(char borda, char preenchimento, bool preenchido) const
    {
        for (int i = 0; i < largura; i++)
        {
            for (int j = 0; j < comprimento; j++)
            {
                if (i == 0 || i == largura - 1 || j == 0 || j == comprimento - 1)
                {
                    cout << borda;
                }
                else if (preenchido)
                {
                    cout << preenchimento;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    bool verificarQuadrado() const
    {
        return comprimento == largura;
    }
};

int main()
{
    int opcao;

    do
    {
        cout << "Selecione uma opção:" << endl;
        cout << "1 - Calcular fatorial" << endl;
        cout << "2 - Imprimir os 20 primeiros números primos" << endl;
        cout << "3 - Menu de opções" << endl;
        cout << "4 - Calcular resultado" << endl;
        cout << "5 - Desenhar retângulo" << endl;
        cout << "6 - Calcular soma dos n primeiros números inteiros" << endl;
        cout << "7 - Calcular MDC" << endl;
        cout << "8 - Converter binário para decimal" << endl;
        cout << "9 - Verificar palíndromo" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
        {
            int num;
            cout << "Digite um número: ";
            cin >> num;
            cout << "Fatorial de " << num << ": " << calcularFatorial(num) << endl;
            break;
        }
        case 2:
            cout << "Os 20 primeiros números primos são: ";
            imprimirPrimos(20);
            break;
        case 3:
            menu();
            break;
        case 4:
            cout << "Resultado: " << calcularResultado(100, 16) << endl;
            break;
        case 5:
        {
            int largura, altura;
            char borda, preenchimento;
            bool preenchido;

            cout << "Digite a largura do retângulo: ";
            cin >> largura;
            cout << "Digite a altura do retângulo: ";
            cin >> altura;
            cout << "Digite o caractere da borda: ";
            cin >> borda;
            cout << "Digite o caractere de preenchimento: ";
            cin >> preenchimento;
            cout << "Deseja preencher o retângulo? (1 - Sim, 0 - Não): ";
            cin >> preenchido;

            for (int i = 0; i < altura; i++)
            {
                for (int j = 0; j < largura; j++)
                {
                    if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1)
                    {
                        cout << borda;
                    }
                    else if (preenchido)
                    {
                        cout << preenchimento;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }

            break;
        }
        case 6:
        {
            int num;
            cout << "Digite um número inteiro: ";
            cin >> num;
            cout << "Soma dos n primeiros números inteiros: " << calcularSomaRecursiva(num) << endl;
            break;
        }
        case 7:
        {
            int x, y;
            cout << "Digite dois números inteiros: ";
            cin >> x >> y;
            cout << "MDC(" << x << ", " << y << "): " << calcularMDC(x, y) << endl;
            break;
        }
        case 8:
        {
            int binario;
            cout << "Digite um número binário: ";
            cin >> binario;
            cout << "Equivalente decimal: " << binarioParaDecimal(binario) << endl;
            break;
        }
        case 9:
        {
            int numero;
            cout << "Digite um número de sete dígitos: ";
            cin >> numero;

            if (numero >= 1000000 && numero <= 9999999)
            {
                if (verificarPalindromo(numero))
                    cout << "É um palíndromo." << endl;
                else
                    cout << "Não é um palíndromo." << endl;
            }
            else
            {
                cout << "Número inválido. Digite um número de sete dígitos." << endl;
            }

            break;
        }
        case 10:
        {
            double comprimento, largura;
            char borda, preenchimento;
            bool preenchido;

            cout << "Digite o comprimento do retângulo: ";
            cin >> comprimento;
            cout << "Digite a largura do retângulo: ";
            cin >> largura;
            cout << "Digite o caractere da borda: ";
            cin >> borda;
            cout << "Digite o caractere de preenchimento: ";
            cin >> preenchimento;
            cout << "Deseja preencher o retângulo? (1 - Sim, 0 - Não): ";
            cin >> preenchido;

            Retangulo retangulo(comprimento, largura);

            cout << "Área do retângulo: " << retangulo.calcularArea() << endl;
            cout << "Perímetro do retângulo: " << retangulo.calcularPerimetro() << endl;

            cout << "Desenho do retângulo:" << endl;
            retangulo.desenharRetangulo(borda, preenchimento, preenchido);

            if (retangulo.verificarQuadrado())
                cout << "O retângulo é um quadrado." << endl;
            else
                cout << "O retângulo não é um quadrado." << endl;

            break;
        }
        case 0:
            cout << "Encerrando o programa." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }

        cout << endl;

    } while (opcao != 0);

    return 0;
}
