# Photux 🖼️🐧

Uma aplicação que realiza o processamento de imagem em C usando o OpenGL + GLUT para a disciplina de Estruturas de Dados da UFES

## Filtros/Algoritmos

- [x] Clareamento
- [x] Escurecimento
- [x] Escala de cinza
- [x] Filtro de Sobel
- [x] Detecção de bordas de Laplace
- [x] Grid

## Arquivo de entrada

<img>.ppm P3

## Resultados

##### Imagem original:

![Imagem original](https://imgur.com/2ICEHXO.png)

##### Clareamento fator 100:
![Clareamento fator 100](https://imgur.com/GLsIc6O.png)

##### Escurecimento fator 100:
![Escurecimento fator 100](https://imgur.com/5ov17Dn.png)

##### Escala de cinza:
![Escala de cinza](https://imgur.com/gHTm6JZ.png)

##### Filtro de Sobel:
![Filtro de Sobel](https://imgur.com/APjZ1RA.png)

##### Detecção de bordas de Laplace:
![Detecção de bordas de Laplace](https://imgur.com/n41trOr.png)

##### Grid:
![Grid](https://imgur.com/vfE3p0B.png)

## Dependências

 - OpenGL
 - GLUT

## Execução

#### Instalação do freeglut3-dev

```$ sudo apt-get install freeglut3-dev```

#### Run [src/]

```$ make && make run```

#### Checar memory leaks [valgrind/]

```$ make && make memcheck```

#### Limpar arquivos .o [src/] [valgrind/]
 
```$ make clean```

## OS Suporte

Linux

## Autor

Mateus Almeida

## Licença

This project is licensed under the [MIT](https://github.com/imsouza/photux/blob/main/LICENSE) License.