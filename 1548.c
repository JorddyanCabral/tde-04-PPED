#include <stdio.h>
// "Declarado os ponteiros e variáveis da func selection"
void selection(short *, unsigned short);
int changes;


// função principal 
void main ()
{
// declarando o tipo das variáveis cases,numstudents e i 
	unsigned short cases;
	unsigned short numStudents;
	int i;
// lendo a quantidade de casos de teste 
	scanf("%hu", &cases);

// estrutura de repetição que decrementa até do valor de casos até chegar em 0 

	while (cases--)
	{
// lendo a quantidade de estudantes que vão passar em cada caso de teste 
		scanf("%hu", &numStudents);

// declando os tipos de variáveis da fila qBefore e qAfter(queue before e queue after )
		short qBefore[numStudents];
		short qAfter[numStudents];


		for (i = 0; i < numStudents; i++)
		{
			// estrutura para ler e armazenar os valores das notas 
			scanf("%hd", &qBefore[i]); // o %hd serve para ler um numero inteiro unsigned
			qAfter[i] = qBefore[i];
		}

		changes = 0;

		selection(qAfter, numStudents);
	// verificando os se os valores são passiveis de mudança ou não 
		for (i = 0; i < numStudents; i++)
			if (qBefore[i] == qAfter[i])
				changes++;

		printf("%d\n", changes);

	}

}

/*func para verificar qual o maior dentro do vetor e armazenar ele de forma que verifique quantas vezes vai ser necessário a troca de 
alunos por tamanho da nota 
*/
void selection(short *vet, unsigned short len)
{

	unsigned short i, j;
	short larger, temp;

	for (i = 0; i < len - 1; i++)
	{

		larger = i;
		for (j = i + 1; j < len; j++)
			if (vet[j] > vet[larger])
				larger = j;

		if (i != larger)
		{

			temp = vet[i];
			vet[i] = vet[larger];
			vet[larger] = temp;

		}

	}

}