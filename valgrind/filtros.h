#ifndef FILTRO_H
#define FILTRO_H

#include "imagem.h"

void escurecerImagem(Imagem *img);

void clarearImagem(Imagem *img);

void escalaDeCinzaImagem(Imagem *img);

void filtroSobel(Imagem *img);

void deteccaoBordasLaplace(Imagem *img);

void grid(Imagem *img);

#endif /* FILTRO_H */