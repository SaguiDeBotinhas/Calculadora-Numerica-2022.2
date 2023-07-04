#include <iostream>

int F_Menu(int Size, std::string *OP_Implementadas);

void F_Raizes();

void F_Bisseccao();
void F_Secante();
void F_PontoFixo();
void F_Newton();

int main() {

    int MConfig;
    std::string OP_Funcionalidades[] = {"Calculo de raizes", "Interpolação", "Derivada", "Integral", "MMQ", "Solução de PVI's Simples"};

    do {

        MConfig = F_Menu(sizeof(OP_Funcionalidades) / sizeof (OP_Funcionalidades[0]), OP_Funcionalidades);

        switch (MConfig) {

            case 0:

                std::cout << "Finalizando o programa... " << '\n';
                system("pouse");
                system("cls");

                break;

            case 1:

                F_Raizes();
                system("pouse");
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
                system("pouse");
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

void F_Raizes() {
    
    int MConfig;
    std::string OP_Metodos[] = {"Bissecao", "Secante", "Ponto Fixo", "Newton"};

    MConfig = F_Menu(sizeof(OP_Metodos) / sizeof (OP_Metodos[0]), OP_Metodos);

    switch (MConfig) {

            case 0:

                std::cout << "Finalizando o programa... " << '\n';
                system("pouse");
                system("cls");

                break;

            case 1:

                F_Bisseccao();
                system("pouse");
                system("cls");

                break;

            case 2:

                F_Secante();
                system("pouse");
                system("cls");

                break;

            case 3:

                F_PontoFixo();
                system("pouse");
                system("cls");

                break;

            case 4:

                F_Newton();
                system("pouse");
                system("cls");

                break;

            default:

                std::cout << "Insira um numero valido! " << '\n';
                system("pouse");
                system("cls");

                break;
        }
}
void F_Bisseccao() {

}

void F_Secante() {

}

void F_PontoFixo() {

}

void F_Newton() {

}