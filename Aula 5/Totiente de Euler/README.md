Essa função calcula o número de coprimos à um dado número (natural) n.

Um número ser coprimo à outro significa que seu gcd (greatest common divisor ou máximo divisor comum, MDC) é 1. Por exemplo, 3 e 7 são coprimos porque seu máximo divisor comum é 1, 7 e 8, 12 e 13, 33 e 10 também são pares de números coprimos. 6 e 3, por exemplo, não são coprimos porque MMC(6 ,3) = GCD(6,3) = 3, 12 e 4 também não são, assim como 24 e 15, 69 e 420 ou 22 e 11. 

A função totiente de euler (que normalmente o pessoal da maratona chama de phi()) calcula p    ara um dado n inteiro e poistivo o número de coprimos. Veja o código.

Sua complexidade é O(sqrt(n)) ou O(raiz_quadrada(n)). Ela funciona da seguinte forma: ela itera por todos os valores até i ser menor ou igual à raíz quadrada de n. A cada passo de iteração, ela checa se o n é divisível por i, se esse for o caso, subtrai de n todos os múltiplos de i, isso é feito com uma divisão inteira de n / i, por exemplo, todos os múltiplos de dois até 11 seria a divisão inteira de 11 por 2, no caso, 11 / 2 = 5. Conte o número de mútiplos de 2 até 11 e veja se está certo. Troque o 11 por 10 e 12 e veja se ainda está certo. Ao encontrar o número de múltiplos até n, basta subtrair isso do retorno da função. Inicialmente a função supõe que todos os números de [1 - n] são coprimos e elimina os que que dividem n.
 
Note que seu n for divisível por 2 e 4, por exemplo, quando o algoritmo estiver no dois, o     quatro será eliminado. Fica claro que o algoritmo sempre elimina os números pelos primos qu    e dividem ele.

Ao final dessas operações, existem uma checagem importante a se fazer que é a de se n não for igual a 1. Se esse for o caso, n é um expoente de algum primo e, portanto, basta dividir subtrair da resposta todos os multiplos de n. Imagina que n seja 7. N não será dividido com nenhum outro número durante a execução, e no final vai ficar 7 lá. Dai fazendo retorno := retorno / n, subtrairíamos 1 de 7, que é o valor atual de retorno e teríamos 6, que é a resposta
