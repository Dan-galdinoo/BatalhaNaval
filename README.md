Projeto Batalha Naval em C com Habilidades Especiais
Descrição
Este projeto implementa um jogo simplificado de Batalha Naval em linguagem C, focado no aprendizado e prática de manipulação de vetores e matrizes. Ele representa um tabuleiro 10x10 com posicionamento de navios, incluindo navios colocados nas direções horizontal, vertical e diagonal.

Além disso, o projeto apresenta uma camada estratégica extra com habilidades especiais, que criam áreas de efeito com formatos geométricos diferentes (cone, cruz e octaedro), sobrepostas ao tabuleiro.

Funcionalidades
Tabuleiro 10x10 representado por uma matriz bidimensional, com posições iniciais preenchidas com água.

Quatro navios posicionados no tabuleiro:

Dois posicionados horizontal ou verticalmente.

Dois posicionados na diagonal (crescente e decrescente).

Habilidades especiais representadas por matrizes 5x5 que indicam as áreas de efeito:

Cone: Área triangular expandindo para baixo.

Cruz: Área em formato de cruz com origem no centro.

Octaedro: Área losangular simulando vista frontal do octaedro.

Sobreposição das áreas de efeito no tabuleiro, marcando as posições afetadas.

Exibição visual clara do tabuleiro no console, com:

~ para água,

N para navios,

* para áreas afetadas pelas habilidades.

Validações básicas para evitar sobreposição de navios.

Estrutura do Código
inicializarTabuleiro: Preenche o tabuleiro com água.

posicionarNavio: Coloca navios no tabuleiro nas direções horizontal, vertical e diagonal, validando limites e sobreposições.

criarHabilidadeCone, criarHabilidadeCruz, criarHabilidadeOctaedro: Criam as matrizes que definem as áreas de efeito de cada habilidade.

sobreporHabilidade: Aplica as áreas de efeito sobre o tabuleiro, respeitando limites.

imprimirTabuleiro: Mostra o tabuleiro no console com símbolos visuais e legenda.

Como Executar
Requisitos:

Um compilador C, como gcc.

Terminal ou console para rodar o programa.

Compilar:

bash
Copiar
Editar
gcc batalha_naval.c -o batalha_naval
Executar:

bash
Copiar
Editar
./batalha_naval
O programa exibirá o tabuleiro com os navios posicionados e as áreas das habilidades sobrepostas.

Exemplo de Saída

=== TABULEIRO BATALHA NAVAL ===

    A  B  C  D  E  F  G  H  I  J
 0  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~
 1  ~  N  N  N  ~  ~  ~  ~  ~  ~
 2  ~  ~  *  *  *  *  *  ~  ~  ~
 3  ~  ~  ~  ~  *  N  ~  ~  ~  ~
 4  ~  ~  ~  ~  *  N  ~  ~  ~  ~
 5  ~  N  N  N  ~  *  ~  ~  ~  ~
 6  ~  ~  ~  ~  ~  *  N  ~  ~  ~
 7  ~  ~  ~  ~  ~  ~  N  N  N  ~
 8  *  *  *  ~  ~  ~  ~  ~  ~  ~
 9  ~  ~  *  ~  ~  ~  ~  ~  ~  ~

** ~ Água | N Navio | * Área de habilidade

Considerações Finais:
O projeto é focado em aprendizado de estruturas de dados e manipulação de matrizes.

A interação com o usuário para posicionamento e uso de habilidades pode ser implementada em futuras versões.

O código é extensível para adicionar mais funcionalidades, como ataques, pontuação e jogabilidade completa.
