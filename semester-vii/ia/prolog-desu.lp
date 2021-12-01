gosta(jose, beatles).
gosta(jose, stones).
gosta(joão, pink).
gosta(joão, acdc).

toca(beatles, velho).
toca(stones, velho).
toca(pink, progressivo).
toca(acdc, metal).

gosta_estilo(X, Z):-gosta(X, Y), toca(Y, Z).
