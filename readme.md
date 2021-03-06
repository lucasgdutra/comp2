# Trabalho de Comp

## Orientações gerais:
1. Modularize seu programa, isto é, divida seu programa em funções. Essas funções devem estar em arquivos diferentes do main.c. A não utilização de funções penalizará a pontuação. Obs: Toda leitura do teclado deve ser feita na main.

2.  Atenção quanto às validações e mensagens de erro quando do acesso às informações. Exemplos:

 	1. O usuário deve receber uma mensagem se houver erro ao abrir/criar um arquivo ou ao alocar memória.

	2. Mensagens quando a busca não retorna resultado: Em um arquivo com nomes de pessoas, por exemplo, o usuário solicita uma busca por um nome que não existe no arquivo. Neste caso, uma mensagem deve avisar o usuário que a busca não teve resultados.

3. Toda informação a ser gravada em um arquivo deve ser acrescentada ao fim do arquivo existente, quando for o caso. O contrário, ou seja, a substituição do arquivo com o conteúdo antigo pelo novo, só deve ser feita quando o exercício exigir isso explicitamente.

4. Para fazer remoção de dados em arquivos texto (nos exercícios onde isso for necessário), considere a seguinte sequência de passos:

	1. Crie um arquivo novo (por exemplo, copia.txt);

	2. Grave em copia.txt tudo que deve ser mantido;

	3. Delete o arquivo original (função remove);

	4. Renomeie copia.txt para o nome do arquivo original (função rename).

	5. Lembre-se de desalocar memória e fechar os arquivos abertos. Não fazer isso penalizará a pontuação da dupla

## Descrição do trabalho

### Considere um arquivo de dados do tipo texto com o seguinte conteúdo:

4  
GUSTAVO SILVA; 8.5; 9.5; 10.0;  
ANTONIO SANTOS; 7.5; 8.5; 8.0;  
SEBASTIAO OLIVEIRA; 5.0; 6.0; 4.0;  
MARIA CARLA PONTES; 7.5; 10.0; 9.0;  

O arquivo acima é um exemplo.  Trata-se de um arquivo de alunos onde a primeira linha contém a quantidade  de alunos no arquivo e as linhas seguintes contém, em cada linha, o nome de um aluno e  três  notas.  Observe-se  que  ao  fim  de  cada  dado  existe  um  ponto  e  vírgula.  Levando  isto  em consideração,  faça  um  programa  para  gerenciar  as  notas  dos  alunos cadastrados  com  um  menu contendo as seguintes opções:

1.  Inserir  nome  do  aluno  e  suas  notas  (três).  Neste  caso,  o  programa  deve  armazenar  as informações  do  aluno  no  arquivo  texto  existente  (Não  esqueça  de  alterar a  quantidade  de alunos).

2. Exibir o nome e a nota do aluno que possui a maior nota. 

3. Exibir  alunos  e médias.  Neste caso, o  programa  lê o arquivo  com  as  informações  e  exibe os nomes  e  médias  [(nota1  +  nota2  +  nota3)  /  3]  no  monitor.
Por exemplo:
MARIA  CARLA PONTES: 8.8.

4. Exibir e gravar em um arquivo texto os alunos aprovados juntamente com o valor da sua média (alunos com média >= 6).   
Por exemplo:  
MARIA CARLA PONTES: 8.8 – aprovado(a).  

5. Exibir e gravar em um arquivo texto os alunos reprovados (alunos com média < 6).  
Por exemplo:   
SEBASTIAO OLIVEIRA: 5.0 – aprovado(a)  
