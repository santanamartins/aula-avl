# Aula: AVL

No momento, o repositório contém um protótipo usado para experimentar rotações em árvores antes de integrá-las a um TAD AVL completo.

## Estrutura do Repositório

```text
.
├── README.md
└── src/
    ├── avl-tad/
    │   └── README.md
    └── prototype/
        ├── Makefile
        ├── element.c
        ├── element.h
        ├── node.c
        ├── node.h
        ├── rotations.c
        ├── rotations.h
        ├── test_ll.c
        ├── test_lr.c
        ├── test_rl.c
        ├── test_rr.c
        └── build/
```

## Conteúdo Atual

### `src/prototype/`

Protótipo usado para montar árvores de exemplo e testar rotações AVL de forma isolada.

- `element.*`: define o tipo de elemento armazenado.
- `node.*`: define a estrutura `Node` e rotinas auxiliares da árvore.
- `rotations.*`: reservado para as funções de rotação AVL.
- `test_ll.c`: árvore de exemplo para rotação à direita (caso `LL`).
- `test_rr.c`: árvore de exemplo para rotação à esquerda (caso `RR`).
- `test_lr.c`: árvore de exemplo para rotação dupla esquerda-direita (caso `LR`).
- `test_rl.c`: árvore de exemplo para rotação dupla direita-esquerda (caso `RL`).
- `build/`: diretório de saída usado pelo Makefile.

### `src/avl-tad/`

Diretório reservado para a próxima etapa do material da aula: integrar as ideias do protótipo a um TAD AVL.

## Fluxo de Compilação

O diretório do protótipo inclui um `Makefile` com alvos que compilam os módulos comuns e cada programa de teste separadamente.

A partir de `src/prototype/`:

```bash
make test_ll
make test_rr
make test_lr
make test_rl
```

Os executáveis gerados são colocados em `src/prototype/build/`.

Comandos típicos de execução após a compilação:

```bash
./build/test_ll
./build/test_rr
./build/test_lr
./build/test_rl
```

Para remover os arquivos gerados:

```bash
make clean
```

## Estado Atual

Este repositório ainda está em construção.

- A estrutura geral do protótipo já está montada.
- Os arquivos de teste já modelam árvores para os quatro casos de rotação AVL.
- Partes da API ainda estão marcadas como `TODO`.
- No estado atual, o protótipo não compila com sucesso usando o Makefile fornecido porque ainda faltam funções auxiliares referenciadas por `node.c` e a implementação das rotações.

Em outras palavras, este repositório serve atualmente como material didático e código-base, não como uma implementação AVL finalizada.

## Uso Sugerido em Aula

1. Inspecionar as árvores de exemplo em `src/prototype/test_*.c`.
2. Implementar as utilidades de nó e as funções de rotação que faltam.
3. Compilar cada caso separadamente com o Makefile.
4. Comparar a árvore antes e depois de cada rotação.
5. Levar a lógica validada para o futuro TAD AVL em `src/avl-tad/`.
