#include <stdio.h>

long long fatorial(int n) {
    if (n == 0) return 1;
    long long fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

long long combinacao(int n, int r) {
    return fatorial(n) / (fatorial(r) * fatorial(n - r));
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int escolha;

    do {
        printf("\nEscolha uma das opcoes:\n");
        printf("1. Calcular apertos de mao.\n");
        printf("2. Determinar o minimo de cores para uma montadora.\n");
        printf("3. Numero de maneiras de formar um grupo de alunos.\n");
        printf("4. Permutacoes em um dodecaedro.\n");
        printf("0. Sair.\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        limparBuffer();

        switch(escolha) {
            case 1:
            {
                int pessoas;
                printf("Digite o numero de pessoas: ");
                scanf("%d", &pessoas);
                limparBuffer();
                if(pessoas < 2) {
                    printf("Numero de pessoas deve ser pelo menos 2.\n");
                    continue;
                }
                printf("Numero de apertos de mao: %lld\n", combinacao(pessoas, 2));
            }
                break;

            case 2:
            {
                int total_combinacoes, modelos, motores, opcionais;
                printf("Digite o numero total de combinacoes (ex: 1000): ");
                scanf("%d", &total_combinacoes);
                limparBuffer();
                printf("Digite o numero de modelos de carros: ");
                scanf("%d", &modelos);
                limparBuffer();
                printf("Digite o numero de tipos de motores: ");
                scanf("%d", &motores);
                limparBuffer();
                printf("Digite o total de combinacoes de opcionais: ");
                scanf("%d", &opcionais);
                limparBuffer();
                int cores = total_combinacoes / (modelos * motores * opcionais);
                if (modelos * motores * opcionais * cores < total_combinacoes) cores++;
                printf("Minimo de cores para atingir as combinacoes: %d\n", cores);
            }
                break;

            case 3:
            {
                int total_alunos, grupo, nao_participam;
                printf("Digite o numero total de alunos: ");
                scanf("%d", &total_alunos);
                limparBuffer();
                printf("Digite o tamanho do grupo a ser formado: ");
                scanf("%d", &grupo);
                limparBuffer();
                printf("Digite o numero de alunos que nao querem participar: ");
                scanf("%d", &nao_participam);
                limparBuffer();
                if(grupo > total_alunos - nao_participam) {
                    printf("Tamanho do grupo nao pode ser maior que o numero de alunos participantes.\n");
                    continue;
                }
                printf("Numero de maneiras de formar o grupo: %lld\n", combinacao(total_alunos - nao_participam, grupo));
            }
                break;

            case 4:
            {
                int faces;
                printf("Digite o numero de faces do poliedro (ex: 12 para dodecaedro): ");
                scanf("%d", &faces);
                limparBuffer();
                if(faces <= 0) {
                    printf("Numero de faces deve ser positivo.\n");
                    continue;
                }
                printf("Numero de permutacoes: %lld\n", fatorial(faces-1));
            }
                break;

            case 0:
                return 0;

            default:
                printf("Escolha invalida. Tente novamente.\n");
        }
    } while(1);

    return 0;
}