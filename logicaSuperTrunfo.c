#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dados da primeira carta
    char estado1[100];
    char codigo1[100];
    char nomeCidade1[100];
    long long populacao1;
    double pib1;
    double area1;
    int pontosTuristicos1;
    double densidadePopulacional1;
    double pibPerCapita1;

    // Dados da segunda carta
    char estado2[100];
    char codigo2[100];
    char nomeCidade2[100];
    long long populacao2;
    double pib2;
    double area2;
    int pontosTuristicos2;
    double densidadePopulacional2;
    double pibPerCapita2;

    printf("Cadastro da primeira carta:\n");
    printf("Informe o estado: ");
    scanf("%99s", estado1);
    printf("Informe o código da carta: ");
    scanf("%99s", codigo1);
    printf("Informe o nome da cidade: ");
    scanf("%99s", nomeCidade1);
    printf("Informe a população: ");
    scanf("%lld", &populacao1);
    printf("Informe o PIB (em bilhões): ");
    scanf("%lf", &pib1);
    printf("Informe a área (em km²): ");
    scanf("%lf", &area1);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo da densidade populacional e PIB per capita para a primeira carta
    densidadePopulacional1 = (double)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1; // Convertendo PIB para a mesma unidade da população

    printf("\nCadastro da segunda carta:\n");
    printf("Informe o estado: ");
    scanf("%99s", estado2);
    printf("Informe o código da carta: ");
    scanf("%99s", codigo2);
    printf("Informe o nome da cidade: ");
    scanf("%99s", nomeCidade2);
    printf("Informe a população: ");
    scanf("%lld", &populacao2);
    printf("Informe o PIB (em bilhões): ");
    scanf("%lf", &pib2);
    printf("Informe a área (em km²): ");
    scanf("%lf", &area2);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional e PIB per capita para a segunda carta
    densidadePopulacional2 = (double)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2; // Convertendo PIB para a mesma unidade da população

    printf("\nInformações das cartas cadastradas:\n");
    printf("-------------------------\n");
    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", nomeCidade1);
    printf("População: %lld\n", populacao1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Área: %.2f km²\n", area1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB Per Capita: %.2f\n", pibPerCapita1);
    printf("-------------------------\n");

    printf("-------------------------\n");
    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", nomeCidade2);
    printf("População: %lld\n", populacao2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Área: %.2f km²\n", area2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB Per Capita: %.2f\n", pibPerCapita2);
    printf("-------------------------\n");

    printf("\nComparação de Cartas:\n");

    // Escolha do atributo para comparação (Altere para o atributo desejado)
    int atributoEscolhido = 1; // 1: População, 2: Área, 3: PIB, 4: Pontos Turísticos, 5: Densidade Populacional, 6: PIB Per Capita
    const char *nomeAtributo; // Alterado para ponteiro constante

    // Determina o vencedor com base no atributo escolhido
    int resultado = 0; // 0 para empate, 1 para Carta 1, 2 para Carta 2
    long long valorCarta1_int = 0, valorCarta2_int = 0;
    double valorCarta1_double = 0.0, valorCarta2_double = 0.0;
    switch (atributoEscolhido) {
        case 1:
            if (populacao1 > populacao2) resultado = 1;
            else if (populacao2 > populacao1) resultado = 2;
            nomeAtributo = "População";
            valorCarta1_int = populacao1;
            valorCarta2_int = populacao2;
            break;
        case 2:
            if (area1 > area2) resultado = 1;
            else if (area2 > area1) resultado = 2;
            nomeAtributo = "Área";
            valorCarta1_double = area1;
            valorCarta2_double = area2;
            break;
        case 3:
            if (pib1 > pib2) resultado = 1;
            else if (pib2 > pib1) resultado = 2;
            nomeAtributo = "PIB";
            valorCarta1_double = pib1;
            valorCarta2_double = pib2;
            break;
        case 4:
            if (pontosTuristicos1 > pontosTuristicos2) resultado = 1;
            else if (pontosTuristicos2 > pontosTuristicos1) resultado = 2;
            nomeAtributo = "Pontos Turísticos";
            valorCarta1_int = pontosTuristicos1;
            valorCarta2_int = pontosTuristicos2;
            break;
        case 5:
            if (densidadePopulacional1 < densidadePopulacional2) resultado = 1;
            else if (densidadePopulacional2 < densidadePopulacional1) resultado = 2;
            nomeAtributo = "Densidade Populacional";
            valorCarta1_double = densidadePopulacional1;
            valorCarta2_double = densidadePopulacional2;
            break;
        case 6:
            if (pibPerCapita1 > pibPerCapita2) resultado = 1;
            else if (pibPerCapita2 > pibPerCapita1) resultado = 2;
            nomeAtributo = "PIB Per Capita";
            valorCarta1_double = pibPerCapita1;
            valorCarta2_double = pibPerCapita2;
            break;
        default:
            printf("Atributo inválido!\n");
            exit(1); // Encerra o programa em caso de erro
    }

    if (resultado == 0) {
        printf("Empate em %s!\n", nomeAtributo);
    } else {
        printf("Comparação de cartas (Atributo: %s):\n", nomeAtributo);
        printf("Carta 1 - %s (%s): ", nomeCidade1, estado1);
        if (atributoEscolhido == 1 || atributoEscolhido == 4)
             printf("%lld\n", valorCarta1_int);
        else
            printf("%.2f\n", valorCarta1_double);
        printf("Carta 2 - %s (%s): ", nomeCidade2, estado2);
        if (atributoEscolhido == 1 || atributoEscolhido == 4)
             printf("%lld\n", valorCarta2_int);
        else
            printf("%.2f\n", valorCarta2_double);
        printf("Resultado: Carta %d venceu!\n", resultado);
    }

    return 0;
}
