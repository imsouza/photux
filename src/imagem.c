#include <stdio.h>  
#include <stdlib.h> 
#include <math.h>   
#include <string.h>

#include "imagem.h"

struct imagem {
  int largura;   /* número de colunas (largura) da imagem em pixels */
  int altura;    /* número de linhas (altura) da imagem em pixels */
  Pixel **pixel; /* matriz altura x largura de pixels com os níveis RGB */
};

void * mallocSafe(size_t nbytes);

Imagem *alocaImagem (int largura, int altura) {  
  Imagem *I = mallocSafe (sizeof(Imagem));

  I->largura = largura;
  I->altura = altura;

  I->pixel = mallocSafe (altura * sizeof(int *));

  for (int i = 0; i < altura; i++) {
    I->pixel[i] = mallocSafe (largura * sizeof(int));
  }

  return I;
}


void liberaImagem (Imagem *img) {  
  if (img->pixel == NULL || img == NULL) {
    fprintf(stderr, "Dado não alocado!\n");
    exit(1);
  }

  for (int i = 0; i < img->altura; i++) {
    free(img->pixel[i]);
  }

  free(img->pixel);
  free(img);
  img = NULL;
}


int obtemLargura (Imagem *img) {
  return img->largura;
}


int obtemAltura (Imagem *img){
  return img->altura;
}


Pixel obtemPixel (Imagem *img, int l, int c) {
  return img->pixel[l][c];
}


Imagem* copiaImagem (Imagem *origem) {
  if (origem == NULL) {
    fprintf(stderr, "Erro na alocacao da memoria\n");
    return NULL;
  }

  Imagem *I = alocaImagem (origem->largura, origem->altura);

  for (int i = 0; i < I->altura; i++) {
    for (int j = 0; j < I->largura; j++) {
      I->pixel[i][j].cor[RED]   = origem->pixel[i][j].cor[RED];
      I->pixel[i][j].cor[GREEN] = origem->pixel[i][j].cor[GREEN];
      I->pixel[i][j].cor[BLUE]  = origem->pixel[i][j].cor[BLUE];
    }
  }

  return I;
}


void recolorePixel (Imagem *img, int l, int c, Pixel pixel) {
  img->pixel[l][c].cor[RED] = pixel.cor[RED];
  img->pixel[l][c].cor[GREEN] = pixel.cor[GREEN];
  img->pixel[l][c].cor[BLUE] = pixel.cor[BLUE];
}


Imagem *carregaImagem (const char *nomeArquivo) {
  char buff[16];
  Imagem *img;
  FILE *fp;
  int c;

  char dir[100] = "../imgs/";

  strcat((char*)dir, nomeArquivo);

  fp = fopen(dir, "r");

  if (fp == NULL) {
    fprintf(stderr, "Nao foi possivel abrir o arquivo %s\n", nomeArquivo);
    exit(1);
  }

  if (!fgets(buff, sizeof(buff), fp)) {
    perror("stdin");
    exit(1);
  }

  if (buff[0] != 'P' || buff[1] != '3') {
    fprintf(stderr, "Formato da imagem invalido (deve ser 'P3')\n");
    exit(1);
  }

  c = getc(fp);

  while (c == '#') {
    while (getc(fp) != '\n') ;
    c = getc(fp);
  }

  ungetc(c, fp); /* coloca ultimo caractere devolta no buffer */
  
  int largura, altura, threshold;

  if (fscanf(fp, "%d %d", &largura, &altura) != 2) {
    fprintf(stderr, "Tamanho da imagem invalido\n");
    exit(1);
  }

  if (fscanf(fp, "%d", &threshold) != 1) {
    fprintf(stderr, "Componente rgb invalido\n");
    exit(1);
  }

  while (fgetc(fp) != '\n');

  img = alocaImagem(largura, altura);

  if (!img) {
    fprintf(stderr, "Erro na alocacao da memoria\n");
    exit(1);
  }

  img->altura = altura;
  img->largura = largura;

  int r, g, b;

  for (int i = 0; i < img->altura; i++) {
    for (int j = 0; j < img->largura; j++) {
      c = fscanf(fp, "%d %d %d", &r, &g, &b);
      img->pixel[i][j].cor[RED]   = (Byte)r; /* intensidade vermelho */
      img->pixel[i][j].cor[GREEN] = (Byte)g; /* intensidade verde */
      img->pixel[i][j].cor[BLUE]  = (Byte)b; /* intensidade azul */
    }
  }

  fclose(fp);

  return img;
}


void salvaImagem (Imagem *img, const char *nomeArquivo) {
  FILE *arquivo;

  int c, rgb_comp_color;
 
  char dir[100] = "../results/";

  strcat((char*)dir, nomeArquivo);

  arquivo = fopen(dir, "w");

  if (arquivo == NULL) {
    fprintf(stderr, "salvaImagem: ERRO: arquivo '%s' nao pode ser criado\n", nomeArquivo);
    return;
  }

  fprintf(arquivo, "P3\n");
  fprintf(arquivo, "#EP1 - Estruturas de Dados - Mateus Almeida\n");
  fprintf(arquivo, "%d %d %d\n", img->largura, img->altura, 255);
 
  for (int i = 0; i < img->altura; i++) {
    for (int j = 0; j < img->largura; j++) {
      fprintf(arquivo, "%d\n",img->pixel[i][j].cor[RED]);
      fprintf(arquivo, "%d\n",img->pixel[i][j].cor[GREEN]);
      fprintf(arquivo, "%d\n",img->pixel[i][j].cor[BLUE]);
    }
  }

  fclose(arquivo);
  printf("salvaImagem: A imagem foi salva no arquivo: '%s'\n", nomeArquivo);
}


void *mallocSafe (size_t nbytes) {
  void *ptr = malloc(nbytes);

  if (ptr == NULL) {
    fprintf(stderr, "Sem memória!\n");
    exit(1);
  }

  return ptr;
}
