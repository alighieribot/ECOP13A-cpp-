// Lab 02
// Questão 1:

#include <iostream>

class CRetangulo {
private:
    double comprimento;
    double largura;
    char borda;
    char preenchimento;
    bool preencher;

public:
    CRetangulo(double comprimento = 1, double largura = 1, char borda = '*', char preenchimento = ' ', bool preencher = false) {
        set_comprimento(comprimento);
        set_largura(largura);
        this->borda = borda;
        this->preenchimento = preenchimento;
        this->preencher = preencher;
    }

    double get_comprimento() const {
        return comprimento;
    }

    void set_comprimento(double valor) {
        if (valor >= 1 && valor <= 20) {
            comprimento = valor;
        } else {
            comprimento = 1;
        }
    }

    double get_largura() const {
        return largura;
    }

    void set_largura(double valor) {
        if (valor >= 1 && valor <= 20) {
            largura = valor;
        } else {
            largura = 1;
        }
    }

    double calcular_area() const {
        return comprimento * largura;
    }

    double calcular_perimetro() const {
        return 2 * (comprimento + largura);
    }

    void imprimir_retangulo() const {
        for (int i = 0; i < largura; i++) {
            for (int j = 0; j < comprimento; j++) {
                if (i == 0 || i == largura - 1 || j == 0 || j == comprimento - 1) {
                    std::cout << borda;
                } else {
                    std::cout << (preencher ? preenchimento : ' ');
                }
            }
            std::cout << std::endl;
        }
    }

    bool eh_quadrado() const {
        return comprimento == largura;
    }
};

int main() {
    double largura, comprimento;
    char borda, preenchimento;
    bool preencher;

    std::cout << "Digite a largura do retângulo: ";
    std::cin >> largura;
    std::cout << "Digite o comprimento do retângulo: ";
    std::cin >> comprimento;

    std::cout << "Digite o caractere da borda: ";
    std::cin >> borda;
    std::cout << "Digite o caractere de preenchimento: ";
    std::cin >> preenchimento;

    std::cout << "Deseja preencher o retângulo? (1 para sim, 0 para não): ";
    std::cin >> preencher;

    CRetangulo retangulo(comprimento, largura, borda, preenchimento, preencher);
    retangulo.imprimir_retangulo();

    return 0;
}

//Questão 2:
          
#include <iostream>

class CRetangulo {
private:
    double comprimento;
    double largura;

public:
    CRetangulo(double comprimento = 1, double largura = 1) {
        set_comprimento(comprimento);
        set_largura(largura);
        std::cout << "Retângulo criado: (" << comprimento << ", " << largura << ")" << std::endl;
    }

    ~CRetangulo() {
        std::cout << "Retângulo destruído: (" << comprimento << ", " << largura << ")" << std::endl;
    }

    double get_comprimento() const {
        return comprimento;
    }

    void set_comprimento(double valor) {
        if (valor >= 1 && valor <= 20) {
            comprimento = valor;
        } else {
            comprimento = 1;
        }
    }

    double get_largura() const {
        return largura;
    }

    void set_largura(double valor) {
        if (valor >= 1 && valor <= 20) {
            largura = valor;
        } else {
            largura = 1;
        }
    }

    double calcular_area() const {
        return comprimento * largura;
    }

    double calcular_perimetro() const {
        return 2 * (comprimento + largura);
    }

    void imprimir_retangulo() const {
        for (int i = 0; i < largura; i++) {
            for (int j = 0; j < comprimento; j++) {
                if (i == 0 || i == largura - 1 || j == 0 || j == comprimento - 1) {
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    bool eh_quadrado() const {
        return comprimento == largura;
    }
};


//Questão 3:

// cretangulo.h

#ifndef CRETANGULO_H
#define CRETANGULO_H

class CRetangulo {
private:
    double comprimento;
    double largura;

public:
    CRetangulo(double comprimento = 1, double largura = 1);
    ~CRetangulo();

    double get_comprimento() const;
    void set_comprimento(double valor);

    double get_largura() const;
    void set_largura(double valor);

    double calcular_area() const;
    double calcular_perimetro() const;

    void imprimir_retangulo() const;
    bool eh_quadrado() const;
};

#endif // CRETANGULO_H

// cretangulo.cpp

#include <iostream>
#include "cretangulo.h"

CRetangulo::CRetangulo(double comprimento, double largura) {
    set_comprimento(comprimento);
    set_largura(largura);
}

CRetangulo::~CRetangulo() {
}

double CRetangulo::get_comprimento() const {
    return comprimento;
}

void CRetangulo::set_comprimento(double valor) {
    if (valor >= 1 && valor <= 20) {
        comprimento = valor;
    } else {
        comprimento = 1;
    }
}

double CRetangulo::get_largura() const {
    return largura;
}

void CRetangulo::set_largura(double valor) {
    if (valor >= 1 && valor <= 20) {
        largura = valor;
    } else {
        largura = 1;
    }
}

double CRetangulo::calcular_area() const {
    return comprimento * largura;
}

double CRetangulo::calcular_perimetro() const {
    return 2 * (comprimento + largura);
}

void CRetangulo::imprimir_retangulo() const {
    for (int i = 0; i < largura; i++) {
        for (int j = 0; j < comprimento; j++) {
            if (i == 0 || i == largura - 1 || j == 0 || j == comprimento - 1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool CRetangulo::eh_quadrado() const {
    return comprimento == largura;
}

// main.cpp

#include <iostream>
#include "cretangulo.h"

int main() {
    CRetangulo retangulo(4, 6);
    retangulo.imprimir_retangulo();

    return 0;
}

//Questão 4:
          
// cretangulo.h

#ifndef CRETANGULO_H
#define CRETANGULO_H

class CRetangulo {
private:
    double comprimento;
    double largura;

public:
    CRetangulo(double comprimento = 1, double largura = 1);
    ~CRetangulo();

    double get_comprimento() const;
    void set_comprimento(double valor);

    double get_largura() const;
    void set_largura(double valor);

    double calcular_area() const;
    double calcular_perimetro() const;

    void imprimir_retangulo() const;
    bool eh_quadrado() const;

    void leitura();
};

#endif // CRETANGULO_H

// cretangulo.cpp

#include <iostream>
#include "cretangulo.h"


void CRetangulo::leitura() {
    double novo_comprimento, nova_largura;

    std::cout << "Digite o comprimento do retângulo: ";
    std::cin >> novo_comprimento;

    std::cout << "Digite a largura do retângulo: ";
    std::cin >> nova_largura;

    set_comprimento(novo_comprimento);
    set_largura(nova_largura);
}
// main.cpp

#include <iostream>
#include "cretangulo.h"

int main() {
    CRetangulo retangulo;

    retangulo.leitura();
    retangulo.imprimir_retangulo();

    return 0;
}

//Questão 5:

// main.cpp

#include <iostream>
#include "cretangulo.h"

int main() {
    const int tamanho_vetor = 5;
    CRetangulo retangulos[tamanho_vetor];

    for (int i = 0; i < tamanho_vetor; i++) {
        std::cout << "Digite os atributos para o retângulo " << i + 1 << ":\n";
        retangulos[i].leitura();
        std::cout << "\n";
    }

    std::cout << "Retângulos criados:\n";

    for (int i = 0; i < tamanho_vetor; i++) {
        std::cout << "Retângulo " << i + 1 << ":\n";
        retangulos[i].imprimir_retangulo();
        std::cout << "\n";
    }

    return 0;
}

//Questão 6:
          
// main.cpp

#include <iostream>
#include "cretangulo.h"

int main() {
    CRetangulo* ptr_retangulo = new CRetangulo(4, 6);

    ptr_retangulo->leitura();

    std::cout << "Retângulo criado:\n";
    ptr_retangulo->imprimir_retangulo();
    std::cout << "\n";

    double area = ptr_retangulo->calcular_area();
    double perimetro = ptr_retangulo->calcular_perimetro();
    std::cout << "Área: " << area << "\n";
    std::cout << "Perímetro: " << perimetro << "\n";

    delete ptr_retangulo;

    return 0;
}

//Questão 7:
          
// poligono_regular.h

#ifndef POLIGONO_REGULAR_H
#define POLIGONO_REGULAR_H

#include <string>

class PoligonoRegular {
private:
    int num_lados;
    double comprimento_lado;

public:
    PoligonoRegular(int num_lados, double comprimento_lado);

    double area() const;
    double perimetro() const;
    std::string nome_poligono() const;
};

#endif // POLIGONO_REGULAR_H

// poligono_regular.cpp

#include <iostream>
#include <cmath>
#include "poligono_regular.h"

PoligonoRegular::PoligonoRegular(int num_lados, double comprimento_lado)
    : num_lados(num_lados), comprimento_lado(comprimento_lado) {}

double PoligonoRegular::area() const {
    double apotema = comprimento_lado / (2 * tan(M_PI / num_lados));
    return 0.5 * num_lados * comprimento_lado * apotema;
}

double PoligonoRegular::perimetro() const {
    return num_lados * comprimento_lado;
}

std::string PoligonoRegular::nome_poligono() const {
    switch (num_lados) {
    case 3:
        return "Triângulo";
    case 4:
        return "Quadrado";
    case 5:
        return "Pentágono";
    case 6:
        return "Hexágono";
    case 7:
        return "Heptágono";
    case 8:
        return "Octógono";
    case 9:
        return "Eneágono";
    case 10:
        return "Decágono";
    default:
        return "Polígono";
    }
}

// main.cpp

#include <iostream>
#include "poligono_regular.h"

int main() {
    PoligonoRegular poligono(6, 4);

    std::cout << "Nome do polígono: " << poligono.nome_poligono() << std::endl;
    std::cout << "Área: " << poligono.area() << std::endl;
    std::cout << "Perímetro: " << poligono.perimetro() << std::endl;

    return 0;
}
