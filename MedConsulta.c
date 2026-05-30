#include <stdio.h>
#include <string.h>

int main() {
    char medicamento[21][44];
    char dia[21][9];
    char hora[21][7];
    int quantidade[21];

    int z = 0;
    int acao;
    
    printf("\n1 - Cadastrar\n2 - Consultar medicamento ou dia\n3 - Medicamentos cadastrados\n4 - Sair\n");
    scanf("%d", &acao);

    while (acao != 4 && z < 21) {
        if (acao == 1) {
            printf("\nInforme o medicamento: ");
            scanf(" %[^\n]", medicamento[z]);
            printf("Informe o dia: ");
            scanf(" %s", dia[z]);
            printf("Informe a hora: ");
            scanf(" %s", hora[z]);
            printf("Informe a quantidade de comprimidos: ");
            scanf("%d", &quantidade[z]);
            printf("\n%s: %s às %s - %d comprimidos - CADASTRADO!\n", medicamento[z], dia[z], hora[z],quantidade[z]);
            z++;
            
        }else if (acao == 2) {

            int acao2;

            printf("\n1 - Consultar por medicamento\n");
            printf("2 - Consultar por dia\n");
            scanf("%d", &acao2);

            if (acao2 == 1) {

                char medicamento2[44];
                int medicamentos = 0;

                printf("\nMedicamentos disponiveis para consulta:\n");

                for (int i = 0; i < z; i++) {

                    int yy = 0;

                    for (int x = 0; x < i; x++) {

                        if (strcmp(medicamento[i], medicamento[x]) == 0) {
                            yy = 1;
                        }
                    }if (yy == 0) {
                        printf("- %s\n", medicamento[i]);
                    }
                }

                printf("\nInforme o medicamento para consultar: ");
                scanf(" %[^\n]", medicamento2);

                for (int i = 0; i < z; i++) {
                    if (strcmp(medicamento2, medicamento[i]) == 0) {
                        if (medicamentos == 0) {
                            printf("\n%s:\n", medicamento2);
                        }
                        printf("\t%s às %s - %d comprimidos\n", dia[i], hora[i], quantidade[i]);
                        medicamentos = 1;
                    }

                }if (medicamentos == 0) {
                    printf("\n%s - Esse medicamento não está cadastrado.\n", medicamento2);
                }

            }else if (acao2 == 2) {

                char dia2[9];
                int medicamentos = 0;

                printf("\nDias disponíveis para consulta:\n");

                for (int i = 0; i < z; i++) {
                    
                    int xx = 0;

                    for (int y = 0; y < i; y++) {
                        if (strcmp(dia[i], dia[y]) == 0) {
                            xx = 1;
                        }
                    }if (xx == 0) {
                        printf("- %s\n", dia[i]);
                    }
                }

                printf("\nInforme o dia para consultar: ");
                scanf(" %s", dia2);

                for (int i = 0; i < z; i++) {
                    if (strcmp(dia2, dia[i]) == 0) {
                        if (medicamentos == 0) {
                            printf("\n%s:\n", dia2);
                        }
                        printf("\t%s às %s - %d comprimidos\n", medicamento[i], hora[i], quantidade[i]);
                        medicamentos = 1;
                    }

                }if (medicamentos == 0) {
                    printf("\n%s - Nesse dia não tem medicamento cadastrado\n", dia2);
                }

            }else {
                printf("\nOpções disponíveis são: 1, 2 3, e 4\n");
            }

        }else if (acao == 3) {
            printf("\nMedicamentos cadastrados:\n");
            for (int i = 0; i < z; i++) {
                printf("\t%s: %s às %s - %d comprimidos\n", medicamento[i], dia[i], hora[i], quantidade[i]);
            }

        }else {
            printf("\n%d - Opção inválida\n", acao);
        }

        printf("\n1 - Cadastrar\n2 - Consultar medicamento ou dia\n3 - Medicamentos cadastrados\n4 - Sair\n");
        scanf("%d", &acao);
    }return 0;
}