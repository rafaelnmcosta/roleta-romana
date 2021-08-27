# RESOLUÇÃO DO PROBLEMA DA ROLETA ROMANA

## Descrição do problema
Um grupo de S soldados é circundado por uma força inimiga esmagadora. Não há esperança de vitória e só existe um cavalo disponível para escapar! Os soldados entram num acordo para determinar qual deles deverá escapar para trazer ajuda. Para tanto eles irão utilizar o método da roleta romana para selecionar o soldado sortudo. O procedimento funciona da seguinte forma:

1. Os soldados se dispõem em círculo formando uma certa sequência fixa.

2. Um número n> 0 é sorteado. Um dos nomes dos soldados é sorteado. O sentido da escolha também é definido.

3. Começando-se pelo soldado cujo nome foi sorteado, eles iniciam uma contagem sequencial ao longo do círculo em sentido horário ou anti-horário conforme a definição. Quando a contagem alcança o n-ésimo soldado, ele é retirado do círculo (e portanto eliminado da escolha) e a contagem reinicia com o soldado seguinte.

4. O processo continua de maneira que, toda vez que n é alcançado, outro soldado é eliminado do círculo (lembre-se, todo soldado retirado do círculo não entra mais na contagem).

5. O último soldado que restar deverá montar o cavalo e escapar.

Considerando como entrada um número n>0, a ordem dos soldados no círculo e o soldado a partir do qual a contagem se inicia, o objetivo é determinar a sequência na qual os soldados são eliminados do circulo e o soldado que escapará.

A entrada para o programa é uma sequência de nomes dos soldados até que o nome FIM seja fomecido. A ordem de entrada dos nomes corresponde a ordem da lista, ou seja, o primeiro nome fornecido é o primeiro da lista, o segundo nome informado será o segundo da lista e assim por diante. O programa deve imprimir os nomes na sequência em que os mesmos são eliminados e o nome do
soldado que escapará.

Por exemplo, suponha que n = 3, o sentido seja horário e que existam 5 soldados romanos chamados A, B, C, D e E. Digamos que A tenha sido o nome sorteado para iniciar o procedimento de eliminação. Então contamos três soldados a partir de A de forma que C é o soldado eliminado. Em seguida, começamos em De contamos D, E e novamente A, para que A seja eliminado a seguir. Depois B, D e E é o eliminado da vez; e finalmente, B, D e B, de modo que D seja o soldado a escapar.

## Informações

O problema foi resolvido utilizando linguagem C e listas duplamente encadeadas