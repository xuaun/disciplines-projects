/*
File *arq  //ponteiro do tipo "FILE"

fopen  -- A fun��o fopen() serve para especificarmos algumas caracter�sticas do arquivo.
Especificamente, como pode ser visto na declara��o desta fun��o, precisamos fornecer dois dados:
Endere�o do arquivo no seu computador (representado por uma string)
Modo de abertura do arquivo (outra string contendo o m�todo de abertura) --

fclose  -- Identificar o final de um arquivo --

fprintf  -- "Printar" alguma informa��o no arquivo --

fscanf  -- Ler alguma informa��o do arquivo --


"w" - Voc� ir� criar um arquivo (se existir, ir� apagar tudo nele para criar "do zero") e adicionar coisas nele
"w+" - Se o arquivo n�o existe, vc ira cria-lo, se existe, vc ir� adicion� coisas a ele
"a" - O arquivo j� existe e vc vai adicionar algo nele
"t" - Voc� ir� adicionar informa��es do tipo texto
"r" - O arquivo j� existe e voc� o abriu para leitura
"r+" - Se adicionarmos um sinal de "+" no "r", ser� poss�vel abrir o arquivo tanto para leitura como para escrita, e caso ele n�o exista, ser� automaticamente criado. E caso exista, o seu conte�do anterior ser� apagado e substitu�do pelo novo
"b" - Voc� ir� adicionar informa��es do tipo bin�rio

--  Erros em abertura de arquivos

Quando abrimos um arquivo, o ponteiro que criamos do tipo FILE armazenar� o endere�o de um arquivo.

Por�m, nem sempre esta tarefa � poss�vel, gerando um erro.
Quando este erro ocorre o ponteiro ir� apontar para NULL, sendo essa pr�tica (checagem se o ponteiro aponta para NULL) muito importante para o tratamento de erros na abertura de arquivos em C.

Este erro pode ocorrer por v�rios motivos. O mais �bvio � abrir um arquivo que n�o existe (geralmente ocorre quando escrevemos errado o endere�o do arquivo).

Em sistemas operacionais mais seguros, como os Linux, o acesso aos arquivos (seja para leitura, escrita ou anexa��o) � geralmente limitado, n�o sendo poss�vel acessar e alterar qualquer arquivo (como geralmente ocorre em sistemas mais vulner�veis, como o Windows).

Caso voc� tente alterar ou acessar um arquivo sem permiss�o, a fun��o fopen tamb�m ir� retornar NULL para o ponteiro.

if(arquivo == NULL)
   printf("Nao foi possivel abrir o arquivo!");  --

*/
