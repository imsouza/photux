# Photux 🖼️🐧

Uma aplicação que realiza o processamento de imagem em C usando o OpenGL + GLUT para a disciplina de Estruturas de Dados da UFES

## Filtros/Algoritmos

- [x] Clareamento
- [x] Escurecimento
- [x] Escala de cinza
- [x] Negativo
- [x] Filtro de Sobel
- [x] Detecção de bordas de Laplace
- [x] Grid

## Arquivo de entrada

> Adicione novas imagens para teste na pasta [/imgs]

<img>.ppm P3

## Resultados

##### Imagem original:

![Imagem original](https://imgur.com/Wt5IYOw.png)

##### Clareamento fator 100:
![Clareamento fator 100](https://imgur.com/uKHZz5T.png)

##### Escurecimento fator 100:
![Escurecimento fator 100](https://imgur.com/zeyVfag.png)

##### Escala de cinza:
![Escala de cinza](https://imgur.com/mDzxAdl.png)

##### Filtro de Sobel:
![Filtro de Sobel](https://imgur.com/zJEpvVW.png)

##### Detecção de bordas de Laplace:
![Detecção de bordas de Laplace](https://imgur.com/2TMpP5B.png)

##### Grid:
![Grid](https://imgur.com/ZiNx200.png)

##### Negativo:
![Negativo](https://imgur.com/b1cGrXU.png)


## Dependências

 - OpenGL
 - GLUT

## Execução

#### Instalação do freeglut3-dev

```$ sudo apt-get install freeglut3-dev```

#### Run

```$ make && make run```

#### Limpar arquivos .o
 
```$ make clean```

## OS Suporte

Linux

## Autor

Mateus Almeida

## Licença

This project is licensed under the [MIT](https://github.com/imsouza/photux/blob/main/LICENSE) License.