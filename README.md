<h1 align="center"> 🎮✅ so_long ✅🕹️ </h1>


## 💻 Sobre o projeto

O projeto so_long faz parte da grade (common core) na Escola 42. Temos que desenvolver um jogo 2D em C, utilizando a MiniLibX (biblioteca disponibilizada pela escola). O objetivo é mover o jogador pelo mapa, coletar todos os itens e alcançar a saída respeitando as regras definidas pelo mapa e movimentações.

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

Tecla	Ação
W / ↑	Mover para cima
S / ↓	Mover para baixo
A / ←	Mover para esquerda
D / →	Mover para direita
ESC	Fechar o jogo


## 🛠️ Tecnologias Utilizadas

- Linguagem C

- MiniLibX (X11)

- Linux

- Makefile

## 🚀 Como executar o projeto

1 - Baixar o Projeto. <br>
2 - Compile utilizando o comando make. Isso vai gerar o programa so_long <br>
3 - Execute o programa com um mapa válido. Exemplo: ./so_long ./maps/map_42.ber

## 🎮 Jogo 🕹️

![Web1](https://github.com/IngridLemosCaetano/so_long/blob/main/so_long.png)

## 📁 Estrutura do Projeto

so_long/
├── inc/ # Headers
├── lib/ # Bibliotecas
├── maps/ # Mapas .ber
├── src/ # Código fonte
├── textures/ # Sprites e imagens (.xpm)
├── Makefile
└── README.md

## <img src="https://github.com/user-attachments/assets/c7002718-57e0-4c87-9a47-5c14e509d9ea" width="30px"/> Autora

Ingrid Lemos Caetano Silva

👩‍💻 [GitHub](https://github.com/IngridLemosCaetano) | 💼 [Linkedin](https://br.linkedin.com/in/ingrid-lemos-caetano)


![42](https://img.shields.io/badge/School-42-black?style=for-the-badge)
