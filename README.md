# Aula: AVL

* Protótipo para experimentar rotações AVL 
* Implementação completa do TAD AVL.

## Estrutura do Repositório

```text
.
├── README.md
└── src/
    ├── avl-tad/
    │   ├── Makefile
    │   ├── avl.c
    │   ├── avl.h
    │   ├── element.c
    │   ├── element.h
    │   ├── main.c
    │   ├── node.c
    │   ├── node.h
    │   ├── rotations.c
    │   ├── rotations.h
    │   ├── README.md
    │   └── build/
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

Implementação do TAD AVL, organizada em módulos similares ao protótipo.

- `element.*`: tipo de dado armazenado na árvore.
- `node.*`: estrutura de nó e funções auxiliares.
- `rotations.*`: funções de rotação usadas no balanceamento.
- `avl.*`: API principal da árvore AVL.
- `main.c`: programa de teste/execução do TAD.
- `build/`: saída de compilação do diretório.

## Fluxo de Compilação

O diretório do protótipo inclui um `Makefile` com alvos que compilam os módulos comuns e cada programa de teste separadamente.

A partir de `src/prototype/`:

```bash
make all
make test_ll
make test_rr
make test_lr
make test_rl
```

O alvo `all` compila os quatro programas de teste (`test_ll`, `test_rr`, `test_lr`, `test_rl`) de uma vez.

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


