#include <iostream>
//#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <cstdlib>
#include <string.h>

void pegaGarfo(int filosofo, int* garfos){
    if(filosofo == 1){
        if(garfos[1] == 0 && garfos[2] == 0){
            printf("O filosofo %d começou a comer\n", filosofo);
            
            garfos[1] = 1;
            garfos[2] = 1;
        }
        else{
            if(garfos[1] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 1\n", filosofo);
            if(garfos[2] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 2\n", filosofo);
        }
    }
    
    else if(filosofo == 2){
        if(garfos[2] == 0 && garfos[3] == 0){
            printf("O filosofo %d começou a comer\n", filosofo);
            
            garfos[2] = 1;
            garfos[3] = 1;
        }
        else{
            if(garfos[2] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 2\n", filosofo);
            if(garfos[3] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 3\n", filosofo);
        }
    }

    else if(filosofo == 3){
        if(garfos[3] == 0 && garfos[4] == 0){
            printf("O filosofo %d começou a comer\n", filosofo);
            
            garfos[3] = 1;
            garfos[4] = 1;
        }
        else{
            if(garfos[3] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 3\n", filosofo);
            if(garfos[4] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 4\n", filosofo);
        }
    }

    else if(filosofo == 4){
        if(garfos[4] == 0 && garfos[5] == 0){
            printf("O filosofo %d começou a comer\n", filosofo);
            
            garfos[4] = 1;
            garfos[5] = 1;
        }
        else{
            if(garfos[4] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 4\n", filosofo);
            if(garfos[5] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 5\n", filosofo);
        }
    }

    else if(filosofo == 5){
        if(garfos[5] == 0 && garfos[1] == 0){
            printf("O filosofo %d começou a comer\n", filosofo);
            
            garfos[5] = 1;
            garfos[1] = 1;
        }
        else{
            if(garfos[5] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 5\n", filosofo);
            if(garfos[1] != 0)
                printf("O filosofo %d não conseguiu pegar o garfo 1\n", filosofo);
        }
    }
}

void comecaCiclo(int* filosofos, int* garfos, int* devolve){
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() != 10)){
        end = std::chrono::system_clock::now();

        int tempo = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        
        for(int j = 0; j < 6; j++){

            if(tempo == devolve[j]){
                //printf("O filosofo %d vai devolver os garfos\n", j + 1);
                if(j == 5){
                    garfos[j] = 0;
                    garfos[1] = 0;
                    //printf("Os garfos %d e 1 foram devolvidos\n", j + 1);
                }
                else{
                    garfos[j + 1] = 0;
                    garfos[j + 2] = 0;
                    //printf("Os garfos %d e %d foram devolvidos\n", j + 1, j + 2);
                }
            }

            if(tempo == filosofos[j]){
                printf("Achei o tempo em que o filosofo %d vai comer, tempo: %d\n", j + 1, tempo);
                filosofos[j] = 11;
                pegaGarfo(j + 1, garfos);
            }
        }

    }
}

int main(){
    srand (time(NULL));


    int filosofos[4], garfos[] = {0,0,0,0,0,0}, devolve[4],pos0;

    
    for(int o = 0; o < 5; o++){    
        filosofos[o] = rand() % 9; 
    }

    for(int j = 0; j < 5; j++)
        devolve[j] = filosofos[j] + 1;


    for(int k = 0; k < 5; k++)
        printf("O tempo do filosofo %d vai começar a comer: %d\n", k + 1, filosofos[k]);

    for(int l = 0; l < 5; l++)
        printf("O tempo do filosofo %d vai começar devolver o garfo: %d\n", l + 1, devolve[l]);

    for(int n = 1; n < 6; n++)
        printf("A disponibilidade do garfo %d: %d\n", n, garfos[n]);


    comecaCiclo(filosofos,garfos,devolve);

    return 0;
}