#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "imagem.h"
#include "filtros.h"

void escurecerImagem (Imagem *img) {
  int v;
  printf("Digite o fator de escurecimento: ");
  scanf("%d", &v);

  for (int h = 0; h < obtemAltura(img); h++) {
    for (int w = 0; w < obtemLargura(img); w++) {
      Pixel pixel = obtemPixel(img, h, w);
      pixel.cor[RED]   = (((int)pixel.cor[RED]   - v) >= 0 ? (pixel.cor[RED]   - v) : 0);
      pixel.cor[GREEN] = (((int)pixel.cor[GREEN] - v) >= 0 ? (pixel.cor[GREEN] - v) : 0);
      pixel.cor[BLUE]  = (((int)pixel.cor[BLUE]  - v) >= 0 ? (pixel.cor[BLUE]  - v) : 0);
      recolorePixel(img, h, w, pixel);
    }
  }
}


void clarearImagem (Imagem *img) {
  int v;
  printf("Digite o fator de clareamento: ");
  scanf("%d", &v);

  for (int h = 0; h < obtemAltura(img); h++) {
    for (int w = 0; w < obtemLargura(img); w++) {
      Pixel pixel = obtemPixel(img, h, w);
      pixel.cor[RED]   = (((int)pixel.cor[RED]   + v) >= 255 ? 255 : pixel.cor[RED] + v);
      pixel.cor[GREEN] = (((int)pixel.cor[GREEN] + v) >= 255 ? 255 : pixel.cor[GREEN] + v);
      pixel.cor[BLUE]  = (((int)pixel.cor[BLUE]  + v) >= 255 ? 255 : pixel.cor[BLUE] + v);
      recolorePixel(img, h, w, pixel);
    }
  }
}


void escalaDeCinzaImagem (Imagem *img) {
  for (int h = 0; h < obtemAltura(img); h++) {
    for (int w = 0; w < obtemLargura(img); w++) {
      Pixel pixel = obtemPixel(img, h, w);
      double media = ((int)pixel.cor[RED] + (int)pixel.cor[GREEN] + (int)pixel.cor[BLUE]) / 3;
      pixel.cor[RED]   = media;
      pixel.cor[GREEN] = media;
      pixel.cor[BLUE]  = media;
      recolorePixel(img, h, w, pixel);
    }
  }
}


void filtroSobel (Imagem *img) {  
  int gx[3][3] = {{-1, 0, 1}, 
                  {-2, 0, 2}, 
                  {-1, 0, 1}};

  int gy[3][3] = {{-1, -2, -1}, 
                  {0, 0, 0}, 
                  {1, 2, 1}};

  Imagem *imgC = NULL;
  imgC = copiaImagem(img);

  Pixel pixel;

  for (int h = 1; h < obtemAltura(img) - 1; h++) {
    for (int w = 1; w < obtemLargura(img) - 1; w++) {
      int sumX = 0;
      int sumY = 0;
      for (int l = h; l < h + 3; l++) {
        if (l == obtemAltura(img)) { 
          break; 
        } 
        for (int c = w; c < w + 3; c++) {
          if (c == obtemLargura(img)) { 
            break; 
          } 
          pixel = obtemPixel(imgC, l, c);

          sumX += (((int)pixel.cor[RED] * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[GREEN] * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[BLUE] * gx[l % 3][c % 3])) / 3;

          sumY += (((int)pixel.cor[RED] * gy[l % 3][c % 3]) + \
                  ((int)pixel.cor[GREEN] * gy[l % 3][c % 3]) + \
                  ((int)pixel.cor[BLUE] * gy[l % 3][c % 3])) / 3;
        }
      }

      int sum = sqrt(pow(sumX, 2) + pow(sumY, 2));

      if (sum > 255) {
        sum = 255;
      } else if (sum < 0) {
        sum = 0;
      }

      pixel.cor[RED] = sum;
      pixel.cor[GREEN] = sum;
      pixel.cor[BLUE] = sum;

      recolorePixel(img, h, w, pixel);
    }
  }

  liberaImagem(imgC);
}


void deteccaoBordasLaplace (Imagem *img) {
  int gx[3][3] = {{0, -1, 0}, 
                  {-1, 4, -1}, 
                  {0, -1, 0}};

  Imagem *imgC = NULL;
  imgC = copiaImagem(img);

  Pixel pixel;

  for (int h = 1; h < obtemAltura(img) - 1; h++) {
    for (int w = 1; w < obtemLargura(img) - 1; w++) {
      int sum = 0;

      for (int l = h - 1; l < h + 2; l++) {
        if (l == obtemAltura(img)) { break; } 

        for (int c = w - 1; c < w + 2; c++) {
          pixel = obtemPixel(imgC, l, c);

          sum += (((int)pixel.cor[RED] * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[GREEN] * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[BLUE] * gx[l % 3][c % 3]));
        }
      }

      sum = sqrt(pow(sum, 2));

      sum = sum / 9;

      if (sum > 255) {
        sum = 255;
      } else if (sum < 0) {
        sum = 0;
      }

      pixel.cor[RED] = sum;
      pixel.cor[GREEN] = sum;
      pixel.cor[BLUE] = sum;

      recolorePixel(img, h, w, pixel);
    }
  }

  liberaImagem(imgC);
}


void negativo (Imagem *img) {
  for (int h = 0; h < obtemAltura(img); h++) {
    for (int w = 0; w < obtemLargura(img); w++) { 
      Pixel pixel = obtemPixel(img, h, w);                  
      pixel.cor[RED]   = 255 - pixel.cor[RED];
      pixel.cor[GREEN] = 255 - pixel.cor[GREEN];
      pixel.cor[BLUE]  = 255 - pixel.cor[BLUE];
      recolorePixel(img, h, w, pixel);
    }   
  }
}


void grid (Imagem *img) {
  int gx[3][3] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};

  Imagem *imgC = NULL;
  imgC = copiaImagem(img);

  Pixel pixel;

  for (int h = 0; h < obtemAltura(img); h++) {
    for (int w = 0; w < obtemLargura(img) ; w++) {
      int sum = 0;

      for (int l = h + 1; l < h + 2; l++) {
        if (l == obtemAltura(img)) { break; } 

        for (int c = w + 1; c < w + 2; c++) {
          if (c == obtemLargura(img)) { break; } 
          pixel = obtemPixel(imgC, l, c);

          sum += (((int)pixel.cor[RED]   * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[GREEN] * gx[l % 3][c % 3]) + \
                  ((int)pixel.cor[BLUE]  * gx[l % 3][c % 3]));
        }
      }

      sum = sqrt(pow(sum, 2));

      sum = sum / 9;

      if (sum > 255) {
        sum = 255;
      } else if (sum < 0) {
        sum = 0;
      }

      pixel.cor[RED] = sum;
      pixel.cor[GREEN] = sum;
      pixel.cor[BLUE] = sum;

      recolorePixel(img, h, w, pixel);
    }
  }

  liberaImagem(imgC);
}