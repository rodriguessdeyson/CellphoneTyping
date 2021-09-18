#include <corecrt_memcpy_s.h>
#include <vector>
#include <iostream>

using namespace std;

// Buffer máximo para alocação da árvore de links.
const int BufferMax = 1000000;

// Estrutura para tratar a árvore.
struct LinkTree
{
	int statesTree[BufferMax][27];
	int stateCount;
	
	// Adiciona cada caracter ao automato.
	void addWord(const char* s)
	{
		// Estado raiz da árvore.
		int state = 0;
		
		// Itera nos valores do caractere.
		for (; *s; s++)
		{
			// Obtém o índice (Unicode) para registrar a próxima letra da palavra.
			int next = (*s == '$') ? 26 : (*s - 'a');
			
			// Verifica se chegou no estado fictício (local onde não foi mapeado a letra da palavra)
			if (statesTree[state][next] == -1)
			{
				// Então adiciona um novo estado (mapeando que uma classe foi encontrada).
				statesTree[state][next] = stateCount;
				memset(statesTree[stateCount], -1, sizeof statesTree[stateCount]);
				stateCount++;
			}

			// Incrementa o estado (cur).
			state = statesTree[state][next];
		}
	}

	// Limpa a estrutura da árvore para um novo conjunto de entrada.
	void ClearTree()
	{
		memset(statesTree[0], -1, sizeof statesTree[0]);
		stateCount = 1;
	}

	// Realiza a contagem dos pressionamentos para cada caracter.
	int countUserPress(const char* s) 
	{
		// Estado inicial.
		int state = 0;

		// Variável com a quantidade de pressionamentos médios.
		int pressAvg = 0;
		for (; *s; ++s)
		{
			// Variável para armazenar quantas estruturas da árvore foram incrementadas
			// (de -1 estado desconhecido para 1 estado conhecido)
			int countingPress = 0;

			// Se ainda não é o fim da palavra (definido como $) 
			if (*(s + 1))
				for (int k = 0; k < 27; ++k)
					
					// Se a letra é conhecida, então incrementa a quantidade de pressionamentos.
					if (statesTree[state][k] != -1)
						countingPress++;

			// Verifica se é maior que 1 ao final da iteração, então sinaliza ao valor da média.
			if (countingPress > 1 or (countingPress == 1 and state == 0))
				pressAvg++;
			int next = (*s == '$') ? 26 : (*s - 'a');
			state = statesTree[state][next];
		}
		return pressAvg;
	}
};

LinkTree lt;
int main()
{
	// Número de entradas.
	int wordsNumber;
	while (cin >> wordsNumber)
	{
		// Vetor, ou lista, com as palavras que serão iteradas.
		vector<string> words(wordsNumber);
		
		// Limpa a estrutura da árvore a cada conjunto de palavras.
		lt.ClearTree();
		
		// Itera na quantidade de palavras a ser inserida
		for (int i = 0; i < wordsNumber; ++i)
		{
			// Obtém a palavra.
			cin >> words[i];

			// Sinaliza o fim dela.
			words[i] += "$";

			// Adiciona ao mapeamento de classes na árvore de links.
			lt.addWord(words[i].c_str());
		}

		// Variável que armazena a quantidade de pressionamentos.
		double pressAvg = 0;
		for (int i = 0; i < wordsNumber; ++i)
			pressAvg += lt.countUserPress(words[i].c_str());
		
		// Imprime o valor médio de pressionamentos.
		printf("%.2lf\n", (pressAvg / (double)wordsNumber));
	}
	return 0;
}