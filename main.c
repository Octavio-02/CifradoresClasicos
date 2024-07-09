#include "enigma.h"

int main()
{
    int opcion;
    char mensaje[100];
    HANDLE consola;
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO info;

    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(consola,&info);

    do{
        opcion = menu(consola);
        if(opcion != 4){
            obtenerMensaje(mensaje,consola);
            switch(opcion){
                case 1:
                    menuEnigma(mensaje,consola);
                    break;
                case 2:
                    atbash(mensaje);
                    break;
                case 3:
                    cesar(mensaje,consola);
                    break;
            }

            system("cls");
            coords.X = 5;
            coords.Y = 2;
            SetConsoleCursorPosition(consola,coords);
            printf("Mensaje Cifrado: %s",mensaje);
            getchar();
        }
    }while(opcion!=4);

    return 0;
}
