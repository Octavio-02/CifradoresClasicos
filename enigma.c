#include "enigma.h"

int menu(HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO info;
    int opcion;
    char ingreso[3];

    GetConsoleScreenBufferInfo(consola,&info);

    do{
        system("cls");
        coords.X = info.dwSize.X / 2 - 14;
        coords.Y = 2;
        SetConsoleCursorPosition(consola,coords);
        puts("Sistemas de Cifrado Clasicos");
        coords.X = info.dwSize.X / 2 - 7;
        coords.Y+=3;
        SetConsoleCursorPosition(consola,coords);
        puts("1.Enigma");
        coords.X = info.dwSize.X / 2 - 7;
        coords.Y++;
        SetConsoleCursorPosition(consola,coords);
        puts("2.Atbash");
        coords.X = info.dwSize.X / 2 - 7;
        coords.Y++;
        SetConsoleCursorPosition(consola,coords);
        puts("3.Cifrado Cesar");
        coords.X = info.dwSize.X / 2 - 7;
        coords.Y++;
        SetConsoleCursorPosition(consola,coords);
        puts("4.Salir");
        coords.Y+=2;
        coords.X = info.dwSize.X / 2 - 7;
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        fgets(ingreso,3,stdin);
        opcion = atoi(ingreso);
    }while(opcion<1||opcion>4);

    return opcion;
}

void obtenerMensaje(char *mensaje,HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(consola,&info);

    do{
        system("cls");
        coords.X = info.dwSize.X / 2 - 26;
        coords.Y = 2;
        SetConsoleCursorPosition(consola,coords);
        printf("Ingrese el mensaje a cifrar (100 caracteres maximo):");
        coords.Y+=2;
        coords.X = 5;
        SetConsoleCursorPosition(consola,coords);
        fflush(stdin);
        fgets(mensaje,100,stdin);
    }while(strlen(mensaje)<1 || strlen(mensaje)>98);
}

void toUpper(char *mensaje){
    if(*mensaje >= 97 && *mensaje <= 122){
        *mensaje = *mensaje - 32;
    }
}

void obtenerRotor(int opcion, char *ruta){
    switch(opcion){
        case 1:
            strcpy(ruta,"rotores/Rotor1.txt");
            break;
        case 2:
            strcpy(ruta,"rotores/Rotor2.txt");
            break;
        case 3:
            strcpy(ruta,"rotores/Rotor3.txt");
            break;
        case 4:
            strcpy(ruta,"rotores/Rotor4.txt");
            break;
        case 5:
            strcpy(ruta,"rotores/Rotor5.txt");
            break;
        case 6:
            strcpy(ruta,"rotores/Rotor6.txt");
            break;
        case 7:
            strcpy(ruta,"rotores/Rotor7.txt");
            break;
        case 8:
            strcpy(ruta,"rotores/Rotor8.txt");
            break;
        case 9:
            strcpy(ruta,"rotores/GammaRotor.txt");
            break;
        case 10:
            strcpy(ruta,"rotores/BetaRotor.txt");
            break;
    }
}

void menuEnigma(char *mensaje,HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO info;
    char rotor_I  [27]={0};
    char rotor_II [27]={0};
    char rotor_III [27]={0};
    char reflector [27]={0};
    char ruta[20];
    char ingreso[5];
    int opcion;
    int uno;
    int dos;
    int i;
    char rotores[10][14] = {
        {"1.Rotor I"},
        {"2.Rotor II"},
        {"3.Rotor III"},
        {"4.Rotor IV"},
        {"5.Rotor V"},
        {"6.Rotor VI"},
        {"7.Rotor VII"},
        {"8.Rotor VIII"},
        {"9.Rotor Gamma"},
        {"10.Rotor Beta"},
    };

    GetConsoleScreenBufferInfo(consola,&info);

    do{
        system("cls");
        coords.Y = 2;
        coords.X = info.dwSize.X / 2 - 31;
        SetConsoleCursorPosition(consola,coords);
        puts("Ingrese que rotor desea en la primera posicion de la maquina:");
        coords.Y+=2;
        coords.X += 10;
        for(i=0;i<10;i++){
            coords.Y ++;
            SetConsoleCursorPosition(consola,coords);
            printf("%s\n",rotores[i]);
        }
        coords.Y = 9;
        coords.X = 60;
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        fgets(ingreso,5,stdin);
        opcion = atoi(ingreso);
    }while(opcion<1 || opcion>10);

    obtenerRotor(opcion,ruta);
    cargarRotor(rotor_I,ruta);
    uno = opcion;

    do{
        system("cls");
        coords.Y = 2;
        coords.X = info.dwSize.X / 2 - 31;
        SetConsoleCursorPosition(consola,coords);
        puts("Ingrese que rotor desea en la segunda posicion de la maquina:");
        coords.Y+=2;
        coords.X += 10;
        for(i=0;i<10;i++){
            if(i+1 != uno){
                coords.Y ++;
                SetConsoleCursorPosition(consola,coords);
                printf("%s\n",rotores[i]);
            }
        }
        coords.Y = 9;
        coords.X = 60;
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        fgets(ingreso,5,stdin);
        opcion = atoi(ingreso);
    }while( (opcion<1 || opcion>10) || opcion == uno);

    obtenerRotor(opcion,ruta);
    cargarRotor(rotor_II,ruta);
    dos = opcion;

    do{
        system("cls");
        coords.Y = 2;
        coords.X = info.dwSize.X / 2 - 31;
        SetConsoleCursorPosition(consola,coords);
        puts("Ingrese que rotor desea en la tercera posicion de la maquina:");
        coords.Y+=2;
        coords.X += 10;
        for(i=0;i<10;i++){
            if(i+1 != uno && i+1 != dos){
                coords.Y ++;
                SetConsoleCursorPosition(consola,coords);
                printf("%s\n",rotores[i]);
            }
        }
        coords.Y = 9;
        coords.X = 60;
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        fgets(ingreso,5,stdin);
        opcion = atoi(ingreso);
    }while( (opcion<1 || opcion>10) || opcion == uno || opcion == dos);

    obtenerRotor(opcion,ruta);
    cargarRotor(rotor_III,ruta);

    do{
        system("cls");
        coords.Y = 2;
        coords.X = info.dwSize.X / 2 - 21;
        SetConsoleCursorPosition(consola,coords);
        puts("Ingrese que reflector desea en la maquina:");
        coords.Y+=2;
        coords.X += 7;
        SetConsoleCursorPosition(consola,coords);
        puts("1.Reflector B");
        coords.Y++;
        SetConsoleCursorPosition(consola,coords);
        puts("2.Reflector C");
        coords.Y = 4;
        coords.X = 65;
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        fgets(ingreso,5,stdin);
        opcion = atoi(ingreso);
    }while(opcion<1 || opcion>2);

    if(opcion==1){
        cargarRotor(reflector,"rotores/ReflectorB.txt");
    }else{
        cargarRotor(reflector,"rotores/ReflectorC.txt");
    }

    cifrar(mensaje,rotor_I,rotor_II,rotor_III,reflector);
}

int cargarRotor(char *rotor,char *ruta){
    FILE *df;
    char linea[28];
    int i;
    df = fopen(ruta,"rt");
    if(!df){
        return 0;
    }
    fgets(linea,28,df);

    for(i=0;i<26;i++){
        *rotor = linea[i];
        rotor++;
    }

    fclose(df);

    return 0;
}

void cifrar(char *mensaje,char rotor_I[27],char rotor_II[27],char rotor_III[27],char reflector[27]){
    int pos;
    int movRotorUno=0;
    int movRotorDos=0;

    while(*mensaje){
        toUpper(mensaje);
        if(*mensaje >= 65 && *mensaje <= 90){

            //Proceso de Cifrado
            pos = *mensaje - 65;            //Posición de la letra ingresada en el alfabeto
            *mensaje = rotor_I[pos];        //Reemplazo la letra ingresada por su equivalente en el rotor I

            pos = *mensaje - 65;            //Posición de la letra del rotor I en el alfabeto
            *mensaje=rotor_II[pos];         //Reemplazo la letra del rotor I por su equivalente en el rotor II

            pos = *mensaje - 65;            //Posición de la letra del rotor II en el alfabeto
            *mensaje = rotor_III[pos];      //Reemplazo la letra del rotor II por su equivalente en el rotor III

            pos = *mensaje - 65;            //Posición de la letra del rotor III en el alfabeto
            *mensaje = reflector[pos];      //Reemplazo la letra del rotor III por su equivalente en el reflector

            pos = *mensaje - 65;            //Posición de la letra del reflector en el alfabeto
            *mensaje = rotor_III[pos];      //Reemplazo la letra del reflector por su equivalente en el rotor III

            pos = *mensaje - 65;            //Posición de la letra del rotor III en el alfabeto
            *mensaje = rotor_II[pos];       //Reemplazo la letra del rotor III por su equivalente en el rotor II

            pos = *mensaje - 65;            //Posición de la letra del rotor II en el alfabeto
            *mensaje = rotor_I[pos];        //Reemplazo la letra del rotor II por su equivalente en el rotor I

            movRotorUno++;
            rotar(rotor_I);

            if(movRotorUno == 26){
                movRotorUno = 0;
                movRotorDos++;
                rotar(rotor_II);
            }
            if(movRotorDos == 26){
                movRotorDos = 0;
                rotar(rotor_III);
            }
        }
        mensaje++;
    }
}

void rotar(char rotor[27]){
    char aux;
    int i;

    aux=rotor[25];

    for(i=25;i>=0;i--){
        rotor[i] = rotor[i-1];
    }
    rotor[0] = aux;
}

void espejar(char *mensaje,char *alfabeto){
    char *fin = alfabeto;

    while(*fin){
        fin++;
    }
    fin--;

    while(*alfabeto && *alfabeto != *mensaje){
        alfabeto++;
        fin--;
    }

    if(*alfabeto == *mensaje){
        *mensaje = *fin;
    }
}

void atbash(char *mensaje){
    char alfabeto[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    while(*mensaje){
        espejar(mensaje,alfabeto);
        mensaje++;
    }
}

int esLetra(char c){
    if((c >= 65 && c <=90) || (c >= 97 && c <= 122)){
        return 1;
    }
    return 0;
}

void cesar(char *mensaje,HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO info;
    int desplazamiento;
    char ingreso[5];

    GetConsoleScreenBufferInfo(consola,&info);

    do{
        system("cls");
        coords.X = info.dwSize.X / 2 - 21;
        coords.Y = 2;
        SetConsoleCursorPosition(consola,coords);
        printf("Ingrese el desplazamiento que desea: ");
        fgets(ingreso,5,stdin);
        desplazamiento = atoi(ingreso);
    }while(desplazamiento == 0);

    while(*mensaje){
        if(esLetra(*mensaje)){
            toUpper(mensaje);
            *mensaje = ((*mensaje-65) + desplazamiento) % 26;
            *mensaje = *mensaje + 65;
        }
        mensaje++;
    }
}
