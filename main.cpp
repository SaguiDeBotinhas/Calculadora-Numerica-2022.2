#include <iostream>
#include <math.h>

int F_Menu(int Size, std::string *OP_Implementadas);

void F_Raizes();

void F_Bissecao(int Erro, double x_menor, double x_maior);
void F_Secante(int Erro, double x_menor, double x_maior);
void F_PontoFixo(int Erro, double x_menor, double x_maior);
void F_Newton(int Erro, double x_menor, double x_maior);

int main() {

    int MConfig;
    std::string OP_Funcionalidades[] = {"Calculo de raizes", "Interpolação", "Derivada", "Integral", "MMQ", "Solução de PVI's Simples"};

    do {

        MConfig = F_Menu(sizeof(OP_Funcionalidades) / sizeof (OP_Funcionalidades[0]), OP_Funcionalidades);

        switch (MConfig) {

            case 0:

                std::cout << "Finalizando o programa... " << '\n';
                system("pause");
                system("cls");

                break;

            case 1:

                F_Raizes();
                system("pause");
                system("cls");

                break;

            case 2:

                
                break;

            case 3:

                

                break;

            case 4:

                

                break;

            default:

                std::cout << "Insira um numero valido! " << '\n';
                system("pause");
                system("cls");

                break;
        }
        
    } while (MConfig != 0);
    

    
    
        return 0;
}

int F_Menu(int Size, std::string *OP_Implementadas) {

    int F_MConfig;

    do {

        std::cout << "Funcionalidades implementadas: " << '\n';

        for (int cont0 = 0; cont0 < Size; cont0 += 1) {
            std::cout << cont0 + 1 << " - " << OP_Implementadas[cont0] << '\n';
        }
        std::cout << "0 - Sair" << '\n';

        std::cout << "Digite a opcao desejada: " << '\n';
        std::cin >> F_MConfig;

        if (F_MConfig <= 0 || F_MConfig >= Size)
            std::cout << "Digite uma opção valida... " << '\n';

    } while (!(F_MConfig >= 0 && F_MConfig <= Size));

    return F_MConfig;
}

double F_x(double x)
{
    return (1 + x + exp(x));
}

void F_Raizes() {
    
    int MConfig, erro;

    double x_menor, x_maior;
    std::string OP_Metodos[] = {"Bissecao", "Secante", "Ponto Fixo", "Newton"};

    MConfig = F_Menu(sizeof(OP_Metodos) / sizeof (OP_Metodos[0]), OP_Metodos);

    do {

        std::cout << "Digite o valor do extremo menor: " << '\n';
        std::cin >> x_menor;

        std::cout << "Digite o valor do extremo maior: " << '\n';
        std::cin >> x_maior;

        if (F_x(x_menor) * F_x(x_maior) >= 0 || x_menor > x_maior)
            std::cout << "A raiz nao pode ser encontrada no intervalo, tente novamente..." << '\n';            

    } while (F_x(x_menor) * F_x(x_maior) >= 0 || x_menor > x_maior);

    std::cout << "Digite um valor para o expoente do erro: " << '\n';
    std::cin >> erro;

    switch (MConfig) {

            case 0:

                std::cout << "Finalizando o programa... " << '\n';
                system("pause");
                system("cls");

                break;

            case 1:

                F_Bissecao(erro, x_menor, x_maior);
                system("pause");
                system("cls");

                break;

            case 2:

                F_Secante(erro, x_menor, x_maior);
                system("pause");
                system("cls");

                break;

            case 3:

                F_PontoFixo(erro, x_menor, x_maior);
                system("pause");
                system("cls");

                break;

            case 4:

                F_Newton(erro, x_menor, x_maior);
                system("pause");
                system("cls");

                break;

            default:

                std::cout << "Insira um numero valido! " << '\n';
                system("pause");
                system("cls");

                break;
        }
}

void F_Bissecao(int Erro, double x_menor, double x_maior) {
    
    double x;

    if (fabs(F_x(x_menor)) < 5 * pow(10, Erro) || fabs(F_x(x_maior)) < 5 * pow(10, Erro)) {
        std::cout << "Valor aproximado do intervalo: [" << x_menor << "][" << x_maior << "]" << '\n';
    }
    else {
        x = (x_menor + x_maior) / 2;

        std::cout << '|' << x_menor << '|' << x_maior << '|' << x << '|' << F_x(x) << '|' << '\n';

        if (F_x(x) * F_x(x_menor) < 0) {
            F_Bissecao(Erro, x_menor, x);
        }
        else if (F_x(x) * F_x(x_maior) < 0) {
            F_Bissecao(Erro, x, x_maior);
        }
    }

}

void F_Secante(int Erro, double x_menor, double x_maior) {
    
    double x;

    if (fabs(F_x(x_menor)) < 5 * pow(10, Erro) || fabs(F_x(x_maior)) < 5 * pow(10, Erro)) {

        std::cout << "Valor aproximado do intervalo: [" << x_menor << "][" << x_maior << "]" << '\n';
    }
    else {

        if (F_x(x_menor) * exp(x_menor) < 0) {

            x = x_menor - (F_x(x_menor) * (x_menor - x_maior)) / (F_x(x_menor) - F_x(x_maior));
            std::cout << '|' << x_menor << '|' << x << '|' << F_x(x) << '\n';
            F_Secante(Erro, x, x_maior);
        }
        else {

            x = x_maior - (F_x(x_maior) * (x_maior - x_menor)) / F_x(x_maior) - F_x(x_menor);
            std::cout << '|' << x_maior << '|' << x << '|' << F_x(x) << '\n';
            F_Secante(Erro, x_menor, x);
        }
    }

}

void F_PontoFixo(int Erro, double x_menor, double x_maior) {

    double x;

    if (fabs(F_x(x_menor)) < 5 * pow(10, Erro) || fabs(F_x(x_maior)) < 5 * pow(10, Erro)) {
        std::cout << "Valor aproximado do intervalo: [" << x_menor << "][" << x_maior << "]" << '\n';
    }
    else {

        x = (x_menor + x_maior) / 2;

        std::cout << '|' << x_menor << '|' << x_maior << '|' << x << '|' << F_x(x) << '|' << '\n';

        if (-exp(x_menor) < -exp(x_maior)) {

            x = (-1) + (-exp(x_menor));
            std::cout << '|' << x_menor << '|' << x << '|' << F_x(x) << '\n';
            F_PontoFixo(Erro, x, x_maior);

        }
        else {

            x = (-1) + (-exp(x_maior));
            std::cout << '|' << x_maior << '|' << x << '|' << F_x(x) << '\n';
            F_PontoFixo(Erro, x_menor, x);

        }
    }
}

void F_Newton(int Erro, double x_menor, double x_maior) {
    
    double x;

    if (fabs(F_x(x_menor)) < 5 * pow(10, Erro) || fabs(F_x(x_maior)) < 5 * pow(10, Erro)) {

        std::cout << "Valor aproximado do intervalo: [" << x_menor << "][" << x_maior << "]" << '\n';

    }
    else {

        x = x_menor - ((F_x(x_menor)) / (1 + exp(x_menor)));
        std::cout << '|' << x_menor << '|' << x << '|' << F_x(x) << '\n';
        F_Newton(Erro, x, x_maior);

        // x = x_maior - ((F_x(x_maior)) / (1 + exp(x_maior)));
        // std::cout << '|' << x_menor << '|' << x << '|' << F_x(x) << '\n';
        // F_Newton(Erro, x_maior, x);
    
    }
}