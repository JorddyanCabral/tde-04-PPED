#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

// Definindo o tipo (Tipagem) do dado no Array Fruit 
    char name[100];
    float price;

} fruit;


// Definindo as cariaveis de ponteiro 
bool findFruits(fruit *, char *, unsigned short);

// Caractere sem sinal podendo ir de 0 a 65.535 quando do tipo int 
unsigned short position;

// Chamando da função principal da estrutura 
void main ()
{

    unsigned short amounOfTrips, amountOfProducts;
    unsigned short i, amountWishFruits;
    unsigned short amountFruits;
    char fruitStr[100];
    float sumPrice;
//lendo os dados da quantidade de idas ao mercado 
    scanf("%hu", &amounOfTrips);

    while (amounOfTrips--)
    {
// lendo a quantidade de produtos que vão ser cadastrados 
        scanf("%hu", &amountOfProducts);

        fruit market[amountOfProducts];
        for (i = 0; i < amountOfProducts; i++)
        {
// lendo os valores e nomes do produto
            scanf(" %s", market[i].name);
            scanf("%f", &market[i].price);

        }
// lendo a quantidade de produtos que vão ser comprados (tipo Lista de desejo)
        scanf("%hu", &amountWishFruits); // o %hu serve para ler um numero inteiro unsigned

        sumPrice  = 0;
        for (i = 0; i < amountWishFruits; i++)
        {

            // lendo quais são os produtos que vçao ser comprados no mercado 
            scanf(" %s %hu", fruitStr, &amountFruits);
            //verificando se aquela fruta está no mercado e fazendo a soma dos valores (sum)
                if (findFruits(market, fruitStr, amountOfProducts))
                    sumPrice += market[position].price * amountFruits;

        }

        printf("R$ %.2f\n", sumPrice);

    }

}

bool findFruits(fruit *market, char *fruit, unsigned short tam)
{

    unsigned short i;

    for (i = 0; i < tam; i++)
    // comparando as strings da frutra que foi pedida e a que está no mercado 
        if (strcmp(market[i].name, fruit) == 0)
        {
            position = i;
            return true;
        }

    return false;

}