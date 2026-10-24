#include <stdio.h>

int main(){
    int sim2 = 1;
    while (sim2 == 1){
        int num, sig = 0, base = 2, bit, vet = 31, cont = 2, sim, soma=0, mult = 1;
        int vet2 = 31, n1, con, code, vet3 = 0, bit2 = 0, fim = 0;
        char byte[32], byte2[32];
        printf("\ndeseja converter de:\ndecimal para binario[1]  binario para  decimal[0]\n");
        scanf ("%d", &code);
        while(code != 1 && code != 0){
            printf("decimal para binario[1]  binario para  decimal[0]\n");
            scanf ("%d", &code);
        }
        if (code == 1){
            printf("insira um numero inteiro: ");
            scanf ("%d", &num);
            n1 = num;
            if (num < 0){
                num = num * (-1);
                sig = 1;
            }
            printf("deseja definir o limite de bits?\nsim[1]  nao[0]\n");
            scanf ("%d", &sim);
            while(sim != 1 && sim != 0){
                printf("sim[1]  nao[0]\n");
                scanf ("%d", &sim);
            }
            if (sim == 1){
                printf("insira o limite: ");
                scanf ("%d", &cont);
                for (con = 0; con <= cont; con++){
                    base = base * 2;
                }
            }else{
                if(sim == 0){
                    while (base <= num){
                        base = base * 2;
                        cont = cont + 1;
                    } 
                base = base * 2;
                }
            }
            for (vet; vet >= (32 - cont); vet--){
                byte[vet] = 0;
            }
            num = num * (1 - ( 2 * sig));
            num = num + base * sig;
            vet = vet + 1;
            while (num > 0){
                bit = num%2;
                num = num/2;
                byte[vet2] = bit;
                vet2 = vet2 - 1;
            }
            printf ("este e o numero em binario com %d bits: ", cont);
            for (vet; vet <= 31; vet++){
                printf ("%d", byte[vet]);
            }
            vet = vet - 1;
            for (vet; vet >= (32 - cont); vet--){
                if (vet <= (32 - cont)){
                    soma = soma + mult * byte[vet] * (-1);
                }else{
                    soma = soma + mult * byte[vet];
                    mult = mult * 2;
                    }
            }
            printf ("\no numero armazenado foi: %d", soma);
            if (soma != n1){
                printf ("\nOverflow Error");
            }
        }
        if (code == 0){
            printf("insira valor em binario: ");
            scanf ("%s", &byte2);
            printf("o codigo possui indicador negativo?\nsim[1]  nao[0]\n");
            scanf ("%d", &code);
            while(code != 1 && code != 0){
                printf("sim[1]  nao[0]\n");
                scanf ("%d", &code);
            }
            while(fim == 0){
                if(bit2 == 1 || bit2 == 0){
                    bit2 = byte2[vet3] - 48;
                    vet3 = vet3 + 1;
                }else{
                    fim = 1;
                }
            }
            vet3 = vet3 - 2;
            for (vet3; vet3 >= 0; vet3--){
                if (vet3 <= 0 && code == 1){
                    bit2 = byte2[vet3] - 48;
                    soma = soma + mult * bit2 * (-1);
                }else{
                    bit2 = byte2[vet3] - 48;
                    soma = soma + mult * bit2;
                    mult = mult * 2;
                }
            }
            printf("o valor em decimal e: %d", soma);
        }
        printf("\ndeseja refazer?\nsim[1]  nao[0]\n");
        scanf ("%d", &sim2);
        while(sim2 != 1 && sim2 != 0){
            printf("sim[1]  nao[0]\n");
            scanf ("%d", &sim2);
        }
    }
    return 0;
}
