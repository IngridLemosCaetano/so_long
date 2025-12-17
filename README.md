<h1 align="center"> 🎮✅ so_long ✅🕹️ </h1>


## 💻 Sobre o projeto

O <strong>so_long</strong> faz parte da grade da Escola 42. Ele é um projeto gráfico desenvolvido utilizando a biblioteca [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html/). 

Nesse projeto temos que desenvolver um jogo 2D na Linguagem C, utilizando a [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html/) (biblioteca disponibilizada pela escola). 

O objetivo é mover o jogador pelo mapa, coletar todos os itens e alcançar a saída. Sempre respeitando as regras definidas pelo mapa e movimentações.

## 🕹️ Objetivo do Jogo

- O jogador deve coletar todos os coletáveis (C) presentes no mapa.

- Após coletar tudo, deve ir até a saída (E) para vencer o jogo.

- O jogador não pode atravessar paredes (1).

- Cada movimento é contado e exibido no terminal. No caso do Bônus deve exibir na tela do jogo.

## 🧩 Regras do Mapa

O mapa é fornecido por um arquivo com extensão .ber e deve seguir as regras abaixo:

- O mapa deve ser retangular.

- O mapa deve ser totalmente cercado por paredes (1).

- Deve conter apenas um jogador (P).

- Deve conter apenas uma saída (E).

- Deve conter ao menos um coletável (C).

- Apenas os seguintes caracteres são permitidos:

  - 0 → Espaço vazio

  - 1 → Parede

  - P → Jogador

  - C → item coletável

  - E → Saída

Caso alguma dessas regras não seja respeitada, o programa encerra exibindo uma mensagem de erro.

## 🗺️ Exemplo de Mapa

    
    111111
    1P0C01
    100001
    1C0E01
    111111
    
    
## 🎮 Controles

| Tecla  | Ação                |
|:-------|:--------------------|
| W / ↑  | Mover para cima     |
| S / ↓  | Mover para baixo    |
| A / ←  | Mover para esquerda |
| D / →  | Mover para direita  |
| ESC	   | Fechar o jogo       |



## 🛠️ Tecnologias Utilizadas

- Linguagem C

- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html/) (X11) 

- Linux

- Makefile


## ⚙️ Compilação

 - Para compilar o projeto, execute:

       make

 - Para limpar os arquivos objeto:

       make clean

 - Para remover tudo (obj e executável):

       make fclean

## ▶️ Execução

Após compilar, execute o programa passando o mapa como argumento:

    ./so_long maps/mapa.ber

## 🎮 Jogo 🕹️

![Web1](https://github.com/IngridLemosCaetano/so_long/blob/main/so_long.png)

## 📁 Estrutura do Projeto

so_long/ <br>
├── inc/ # Headers <br>
├── lib/ # Bibliotecas <br>
├── maps/ # Mapas .ber <br>
├── src/ # Código fonte <br>
├── textures/ # Sprites e imagens (.xpm) <br>
├── Makefile <br>
└── README.md <br>

## 📌 Observações

- O jogo utiliza gráficos simples via [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html/).
- O projeto segue as normas da [Norminette](https://github.com/42school/norminette).
- É necessário ter o ambiente gráfico X11 para execução do programa.

  - Instalar dependências:
  
        sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev

## <img src="https://github.com/user-attachments/assets/c7002718-57e0-4c87-9a47-5c14e509d9ea" width="30px"/> Autora

Ingrid Lemos Caetano Silva

👩‍💻 [GitHub](https://github.com/IngridLemosCaetano) | 💼 [Linkedin](https://br.linkedin.com/in/ingrid-lemos-caetano)


![42](https://img.shields.io/badge/School-42-black?style=for-the-badge)
