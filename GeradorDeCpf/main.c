#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void imprimirCpf( int cpfAux[]);
int main(){
    int cpf[11];
    int decimoNumero;
    int decimoPrimeiroNumero;
    int contRepetido;
    printf("       GERADOR DE CPF\n");
    do{
        contRepetido = 0;
        int dezPrimeiros = 10;
        int soma9Primeiros = 0;
        int soma10Primeiros = 0;
        srand(time(NULL));
        // Pegando 9 números aleatórios e fazendo a soma9Primeiros e soma10Primeiros
        for(int i = 0; i < 9; i++){
            cpf[i] = rand() % 10;

            if( i < 9 ){
                soma9Primeiros += dezPrimeiros * cpf[i];
                soma10Primeiros += ( dezPrimeiros + 1 ) * cpf[i]; // dezPrimeiros + 1 Pois para encontrar o último número começa a multiplicar por 11
                dezPrimeiros--;
            }
        }
        // Cálculo matemático para encontrar o 10ª número
        decimoNumero = soma9Primeiros % 11;
        decimoNumero = 11 - decimoNumero;
        // Verificando qual será o 10ª número
        if(decimoNumero > 9){
            cpf[9] = 0;
        }else{
            cpf[9] = decimoNumero;
        }
        // Acrescentando a soma do 10ª  numero * 2
        soma10Primeiros += cpf[9] * 2;
        // Cálculo matemático para encontrar o 11ª número
        decimoPrimeiroNumero = soma10Primeiros % 11;
        decimoPrimeiroNumero = 11 - decimoPrimeiroNumero;
        // Verificando qual será o 11ª número
        if( decimoPrimeiroNumero > 9 ){
            cpf[10]= 0;
        } else{
            cpf[10] = decimoPrimeiroNumero;
        }
        // Verificando se os 11 números são iguais, pois não pode
        for( int i = 0; i < 11; i++ ){
            if( cpf[i] == cpf[i + 1] ){
                contRepetido++;
            }
        }

    } while( contRepetido == 10 );
    // Imprimindo o CPF
    imprimirCpf( cpf);
    printf("\n");
    return 0;
}
void imprimirCpf( int cpfAux[]){
    printf("\n CPF GERADO: ");
    for( int i = 0; i < 11; i++ ){
        if( i == 9){
            printf("-");
        }
        printf("%d", cpfAux[i]);
    }
}