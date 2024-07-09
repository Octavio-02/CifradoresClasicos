#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int menu(HANDLE consola);
void obtenerMensaje(char *mensaje,HANDLE consola);
void toUpper(char *mensaje);
void cifrar(char *mensaje,char rotor_I[27],char rotor_II[27],char rotor_III[27],char reflector[27]);
void rotar(char rotor[27]);
int cargarRotor(char *rotor,char *ruta);
void menuEnigma(char *mensaje,HANDLE consola);
void obtenerRotor(int opcion, char *ruta);
void atbash(char *mensaje);
void cesar(char *mensaje,HANDLE consola);

#endif // ENIGMA_H_INCLUDED
