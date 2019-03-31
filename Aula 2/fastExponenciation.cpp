#include <bits/stdc++.h>

using namespace std;

const int MODULO = 1e9 + 7; 
// Numero geralemnte utilizado como modulo
// porque é um primo bem grande que ao quadrado é menor que o valor maximo que cabe num long long (10¹⁸)
// e seu valor original cabe num inteiro (10⁹)

// Define ll como long long
// Um tipo de dado que guarda um inteiro de até 64-bits (2⁶⁴)
// O 'int' guarda inteiros de 32-bits (2³²)
using ll = long long;

// So fuciona pra inteiros
// Complexidade O(log(expoente)) porque divide
// o trabalho de elevar um numero a tal expoente em dois
ll exponenciacaoRapida(ll base, ll expoente, ll mod = MODULO){

	ll resposta = 1LL; // Esse LL no final é um sufixo para representar numero 64 bits (long long)
	
	base = base % mod;

	while(expoente > 0){

		if(expoente & 1){ // Se o valor atual é ímpar, mesmo significado de (expoente % 2 == 0)
			resposta = resposta * base % mod; // Você multiplica pela base
		}

		expoente >>= 1;
		// Isso pode ser interpretado como um divisão inteira de expoente por 2
		// ou como, por exemplo, o numero 0010110 virar 001011, moveu uma casa pra esqueda

		base = base * base % mod;

	}

	return resposta;

}

/*
	Eu sei que o codigo acima é confuso a primeira vista
	Pensa na representacao binaria do expoente
	exemplo: expoente2(0010110) = expoente10(22)
	
	Se eu quero elevar uma base a tal exponte
	Ao inves deu eu multiplicar a base por ela mesma expoente vezes
	Eu posso multiplicar a base pelo valor atual dela

	E se o valor na representação binaria do expoente for igual a um,
	eu multiplico o resultado por base ^ (2 ^ x), sendo x a posição
	da direta pra esquerda, no primeiro caso sendo 1
	
	Como eu multiplico a base por ela mesma, base * base = base²,
	depois base² * base² = base⁴, base⁴ * base⁴ = base⁸ e por ai vai
	Ao todo, a base, pra cada iteração do while (x) vira a base aterior ao quadrado
	portanto base ^ (2 ^ x)

	Pra você entender totalmente o motivo desse resultado
	em modulo dar certo, procura 'modulo properties' no google
	isso é muito util pra competições e te indroduz uma forma de pensar
	matematica nova.
*/

int main(){

	ll a,b;
	cin>>a>>b;
	cout<<a<<" elevado a "<<b<<" modulo "<<MODULO<<" = "<<exponenciacaoRapida(a,b)<<endl;

}
