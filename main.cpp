#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>

int main(){
    int random, filosofos[4], garfos[4], i = 0;

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        random = rand() % 10;
        filosofos[i] = random;

        garfos[i] = 0;
    }

    random = rand() % 10;
    filosofos[0] = random;

    for(int i = 0; i < 5; i++)
        printf("O tempo que o filósofo %d deve começar a comer: %d\n", i + 1, filosofos[i]);
    
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    while((std::chrono::duration_cast<std::chrono::seconds>(end - start).count() != 10)){
        end = std::chrono::system_clock::now();

        for(int j = 0; j < 5; j++){        
            if(std::chrono::duration_cast<std::chrono::seconds>(end - start).count() == filosofos[j]){
                printf("\nO tempo: %d segundos", std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
                if(j == 0){
                    if(garfos[0] == 0 && garfos[1] == 0){
                        printf("\nO filosofo %d pegou o garfo 1", j + 1);
                        printf("\nO filosofo %d pegou o garfo 2", j + 1);
                    }
                }
                printf("\nO filosofo %d começou a comer\n", j + 1);
                filosofos[j] = 11;
            }
        }
        
        //printf("O tempo: %d segundos\n", std::chrono::duration_cast<std::chrono::seconds>(end - start).count());
    }

    return 0;
}