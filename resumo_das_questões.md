

## QUESTÃO 1: Método Guloso (Alocação de Salas)

### Lógica do Método Guloso
O método guloso seleciona atividades com base em um critério local que leva a uma solução ótima global. Para este problema, o critério é ordenar as atividades por seus horários de término e escolher atividades que não conflitam (isto é, cujo horário de início seja após ou igual ao horário de término da atividade anterior escolhida). Esse critério garante a maximização do número de atividades porque atividades com menor tempo de término deixam mais espaço disponível para outras atividades.

### Complexidade do Algoritmo
- **Ordenação**: Ordenar as atividades pelos horários de término requer \(O(n \log n)\), onde \(n\) é o número de atividades.
- **Seleção das atividades**: Iterar pelas atividades para verificar conflitos leva \(O(n)\).
- **Complexidade Total**: \(O(n \log n)\).

---

## QUESTÃO 2: Problema da Mochila Fracionária

### Lógica do Método Guloso
O método guloso resolve o problema da mochila fracionária calculando o valor por unidade de peso (\(v/p\)) de cada item. Os itens são ordenados de forma decrescente por essa razão, e a mochila é preenchida com os itens mais valiosos primeiro. Quando a mochila atinge sua capacidade, a fração restante do próximo item é adicionada.

### Complexidade do Algoritmo
- **Ordenação**: Ordenar os itens pelo valor por peso exige \(O(n \log n)\).
- **Preenchimento da mochila**: Percorrer os itens para adicionar valores leva \(O(n)\).
- **Complexidade Total**: \(O(n \log n)\).

---

## QUESTÃO 3: Problema da Mochila 0/1

### Lógica do Algoritmo
O problema é resolvido usando programação dinâmica. A abordagem consiste em criar uma tabela onde o elemento \(dp[i][w]\) representa o valor máximo que pode ser obtido com os primeiros \(i\) itens e capacidade \(w\) da mochila. O algoritmo considera duas possibilidades para cada item:
1. **Não incluir o item**: o valor permanece \(dp[i-1][w]\).
2. **Incluir o item**: o valor é \(valor[i] + dp[i-1][w-peso[i]]\), se \(peso[i] \leq w\).

### Complexidade do Algoritmo
- **Preenchimento da tabela**: Requer \(O(n \cdot W)\), onde \(n\) é o número de itens e \(W\) é a capacidade da mochila.
- **Complexidade Total**: \(O(n \cdot W)\).

---

## QUESTÃO 4: Subsequência Comum Mais Longa (LCS)

### Lógica do Algoritmo
A solução utiliza programação dinâmica. A matriz \(dp[i][j]\) armazena o comprimento da LCS para os primeiros \(i\) caracteres de uma sequência e os primeiros \(j\) caracteres da outra. Se os caracteres forem iguais, \(dp[i][j] = 1 + dp[i-1][j-1]\). Caso contrário, \(dp[i][j] = \max(dp[i-1][j], dp[i][j-1])\).

### Complexidade do Algoritmo
- **Preenchimento da matriz**: Requer \(O(m \cdot n)\), onde \(m\) e \(n\) são os tamanhos das sequências.
- **Complexidade Total**: \(O(m \cdot n)\).

---

## QUESTÃO 5: Problema do Caixeiro Viajante (Força Bruta)

### Lógica do Algoritmo
O algoritmo tenta todas as permutações possíveis de cidades para calcular o custo total de cada rota e retorna a rota com menor custo. O método utiliza força bruta, explorando todas as combinações.

### Complexidade do Algoritmo
- **Número de Permutações**: Para \(n\) cidades, há \(n!\) permutações.
- **Cálculo do custo para cada permutação**: Requer \(O(n)\).
- **Complexidade Total**: \(O(n \cdot n!)\).

---

## QUESTÃO 6: Verificação de Sudoku (Força Bruta)

### Lógica do Algoritmo
O algoritmo verifica se:
1. Cada linha contém números de 1 a 9 sem repetições.
2. Cada coluna contém números de 1 a 9 sem repetições.
3. Cada subgrade 3x3 contém números de 1 a 9 sem repetições.

Para cada linha, coluna e subgrade, um conjunto ou array é utilizado para verificar duplicatas.

### Complexidade do Algoritmo
- **Verificação de linhas, colunas e subgrades**: Cada uma requer \(O(9)\), totalizando \(O(9^2)\).
- **Complexidade Total**: \(O(81) = O(1)\).

---

## QUESTÃO 7: Problema das N Rainhas (Backtracking)

### Lógica do Algoritmo
O algoritmo tenta posicionar as rainhas uma a uma em diferentes colunas, verificando se a posição é segura (isto é, sem ataques entre rainhas). Caso encontre uma posição válida, move para a próxima linha. Caso contrário, retrocede e tenta outra posição.

### Complexidade do Algoritmo
- **Número de Possibilidades**: Para um tabuleiro \(N 	imes N\), há \(N^N\) possibilidades.
- **Complexidade Total**: Aproximadamente \(O(N!)\) devido à poda do backtracking.

---

## QUESTÃO 8: Labirinto (Backtracking)

### Lógica do Algoritmo
O algoritmo tenta mover para todas as direções válidas (cima, baixo, esquerda, direita) a partir de uma célula, marcando-a como visitada. Se alcançar o destino, retorna o caminho; caso contrário, retrocede e tenta outra rota.

### Complexidade do Algoritmo
- **Número de Células**: Para um labirinto \(n 	imes m\), há \(O(n \cdot m)\) células.
- **Complexidade Total**: No pior caso, \(O(4^{n \cdot m})\) devido às tentativas em 4 direções.
