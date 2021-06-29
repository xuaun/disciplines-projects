/*
File *arq  //ponteiro do tipo "FILE"

fopen  -- A função fopen() serve para especificarmos algumas características do arquivo.
Especificamente, como pode ser visto na declaração desta função, precisamos fornecer dois dados:
Endereço do arquivo no seu computador (representado por uma string)
Modo de abertura do arquivo (outra string contendo o método de abertura) --

fclose  -- Identificar o final de um arquivo --

fprintf  -- "Printar" alguma informação no arquivo --

fscanf  -- Ler alguma informação do arquivo --


"w" - Você irá criar um arquivo (se existir, irá apagar tudo nele para criar "do zero") e adicionar coisas nele
"w+" - Se o arquivo não existe, vc ira cria-lo, se existe, vc irá adicioná coisas a ele
"a" - O arquivo já existe e vc vai adicionar algo nele
"t" - Você irá adicionar informações do tipo texto
"r" - O arquivo já existe e você o abriu para leitura
"r+" - Se adicionarmos um sinal de "+" no "r", será possível abrir o arquivo tanto para leitura como para escrita, e caso ele não exista, será automaticamente criado. E caso exista, o seu conteúdo anterior será apagado e substituído pelo novo
"b" - Você irá adicionar informações do tipo binário

--  Erros em abertura de arquivos

Quando abrimos um arquivo, o ponteiro que criamos do tipo FILE armazenará o endereço de um arquivo.

Porém, nem sempre esta tarefa é possível, gerando um erro.
Quando este erro ocorre o ponteiro irá apontar para NULL, sendo essa prática (checagem se o ponteiro aponta para NULL) muito importante para o tratamento de erros na abertura de arquivos em C.

Este erro pode ocorrer por vários motivos. O mais óbvio é abrir um arquivo que não existe (geralmente ocorre quando escrevemos errado o endereço do arquivo).

Em sistemas operacionais mais seguros, como os Linux, o acesso aos arquivos (seja para leitura, escrita ou anexação) é geralmente limitado, não sendo possível acessar e alterar qualquer arquivo (como geralmente ocorre em sistemas mais vulneráveis, como o Windows).

Caso você tente alterar ou acessar um arquivo sem permissão, a função fopen também irá retornar NULL para o ponteiro.

if(arquivo == NULL)
   printf("Nao foi possivel abrir o arquivo!");  --

*/
