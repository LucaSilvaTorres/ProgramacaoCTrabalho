#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICAMENTOS 10

// Variáveis globais
char medicamentos[MAX_MEDICAMENTOS][50];
char horarios[MAX_MEDICAMENTOS][20];
int totalMedicamentos = 0;

// Função para limpar tela
void limparTela() {

    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

// Pausa do sistema
void pausarSistema() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

// Função para cadastrar medicamentos
void cadastroMedicamentos() {

    limparTela();

    if (totalMedicamentos >= MAX_MEDICAMENTOS) {
        printf("\nLIMITE DE MEDICAMENTOS ATINGIDO!\n");
        pausarSistema();
        return;
    }

    printf("===== CADASTRO DE MEDICAMENTOS =====\n");

    printf("Digite o nome do medicamento: ");
    scanf(" %[^\n]", medicamentos[totalMedicamentos]);

    printf("Digite o horario do medicamento: ");
    scanf(" %[^\n]", horarios[totalMedicamentos]);

    printf("\nMEDICAMENTO CADASTRADO COM SUCESSO!\n");

    totalMedicamentos++;

    pausarSistema();
}

// Função para listar medicamentos
void listaMedicamentos() {

    limparTela();

    printf("===== LISTA DE MEDICAMENTOS =====\n");

    if (totalMedicamentos == 0) {
        printf("Nenhum medicamento cadastrado.\n");
    } else {

        for (int i = 0; i < totalMedicamentos; i++) {
            printf("%d - %s\n", i + 1, medicamentos[i]);
        }
    }

    pausarSistema();
}

// Função para listar horários
void listaHorarios() {

    limparTela();

    printf("===== LISTA DE HORARIOS =====\n");

    if (totalMedicamentos == 0) {
        printf("Nenhum horario cadastrado.\n");
    } else {

        for (int i = 0; i < totalMedicamentos; i++) {
            printf("%s -> %s\n", medicamentos[i], horarios[i]);
        }
    }

    pausarSistema();
}

int main() {

    int opcao;

    do {

        limparTela();

        printf("=================================\n");
        printf("      SISTEMA DE MEDICAMENTOS\n");
        printf("=================================\n");
        printf("1 - CADASTRAR MEDICAMENTO\n");
        printf("2 - LISTAR MEDICAMENTOS\n");
        printf("3 - LISTAR HORARIOS\n");
        printf("4 - SAIR\n");
        printf("=================================\n");

        printf("ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                cadastroMedicamentos();
                break;

            case 2:
                listaMedicamentos();
                break;

            case 3:
                listaHorarios();
                break;

            case 4:
                limparTela();
                printf("SAINDO DO SISTEMA...\n");
                break;

            default:
                printf("\nOPCAO INVALIDA!\n");
                pausarSistema();
        }

    } while(opcao != 4);

    return 0;
}