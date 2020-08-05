#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu(){
        printf("\n1. Zobrazenie kalendara pre zadany mesiac vo zvolenom roku\n");
        printf("2. Zobrazenie kalendara pre zadany rok\n");
        printf("3. Zistenie poctu dni medzi 2 zvolenymi datumami\n");
        printf("4. Ukoncenie programu\n");
}

int pocetDniMesiaca(int M){
    int p_D_M;

    p_D_M = 28 + (M + (M/8)) % 2 + 2 % M + 2 * (1/M);

    return p_D_M;
}

int priestupny_rok(int r){
    if (r % 4 != 0) return 0;
    else
        if (r % 100 == 0 && r % 400 != 0) return 0;
        else return 1;

}

int prvyDen(int M, int Y){
    int a, y, m, d;
    a = (14-M)/12;
    y = Y-a;
    m = M+12*a-2;

    d = (1+y+(y/4)-(y/100)+(y/400)+((31*m)/12))%7;

    return d;
}

int vypis_kalendara(int p_D_M, int p_D){
    int c, i, j, counter = 1;
    char *dni[] = {"Po", "Ut", "Sr", "St", "Pi", "So", "Ne"};

    int sum = p_D_M+p_D;
    int numb[sum];

    for(i = 0; i < p_D; i++){
        numb[i] = 0;
    }
    for(i = p_D; i < sum; i++){
        numb[i] = counter;
        counter++;
    }

    for(c=0; c < 7; c++){
        printf("%*s ", 1, dni[c]);
    }
    printf("\n");

    for(j = 0; j < sum; j++){
        if(numb[j] == 0){
            printf("   ");
        }else printf("%*d ", 2, numb[j]);
        if(j == 6 || j == 13 || j == 20 || j == 27 || j == 34){
            printf("\n");
        }
    }
    printf("\n");
}

int pocetDniMedzi(int d1, int m1, int y1, int d2, int m2, int y2){
    int counter = 0, y, m, d, i;
    //dni1 = pocetDniMesiaca(m1);
    if(y1 > y2){
        y = y1-y2;
    }
    if(m1 >= m2){
        m = m1 - m2;
    } else if (m1 < m2){
        y -= 1;
        m1+=12;
        m = m1-m2;
    }
    if(d1 >= d2){
        d = d1-d2;
    }
    for(i = 0; i <= y; i++){
        m+=12;
    }
    m=m*30,5;
    d += m;
    printf("Medzi datami je %d - dni\n", d);
}

int main(){
    int cyklus = 1, cislo, m, r, mesiac;
    int p_D_M, p_D;
    //char cisla1[2];
    int d1, m1, y1, d2, m2, y2;
    //int den[] = {0, 1, 2, 3, 4, 5, 6, 7};
    char *Mesiaca[] = {"Januar", "Februar", "Marec", "April", "Maj", "Jun", "Jul", "August", "September", "Oktober", "November", "December"};

    do {
        menu();

        printf("\nZadaj cislo, podla poziadavok: ");
        cislo = getch(); //scanf("%d", &cislo);
        printf("\n");

        switch(cislo){
        case '1':
            while(1==1){
                printf("Zadaj cislo mesiaca a rok: ");
                scanf("%d %d", &m, &r);
                if(m>=1 && m<=12) break;
            }
            p_D_M = pocetDniMesiaca(m);
            if (m == 2){
                if (priestupny_rok(r) == 1){
                    p_D_M ++;
                }
            }
            printf("\nV mesiace, %d dni.\n", p_D_M);
            p_D = prvyDen(m,r);
            //printf("%d\n", p_D);

            if(p_D >= 1 && p_D <= 6){
                p_D -= 1;
            } else if(p_D == 0){
                p_D += 6;
            }
            printf("%*s\n", 15, Mesiaca[m-1]);
            vypis_kalendara(p_D_M, p_D);

            continue;
        case '2':
            printf("Zadaj rok: ");
            scanf("%d", &r);
            printf("\n");

            for(mesiac = 1; mesiac <= 12; mesiac++){
            /////
                p_D_M = pocetDniMesiaca(mesiac);
                if (mesiac == 2){
                    if (priestupny_rok(r) == 1){
                        p_D_M ++;
                    }
                }
                printf("%*s\n", 15, Mesiaca[mesiac-1]);
                printf("V mesiace, %d dni.\n\n", p_D_M);
                p_D = prvyDen(mesiac,r);
                //printf("%d\n", p_D);

                if(p_D >= 1 && p_D <= 6){
                    p_D -= 1;
                } else if(p_D == 0){
                    p_D += 6;
                }
                //printf("%d\n", p_D);

                vypis_kalendara(p_D_M, p_D);
                printf("\n");
            /////
            }
             break;

        case '3':
            printf("Zadaj dva datumi, aby si mohol/-la pokracovat.\n");
            printf("Prvy datum: ");
            scanf("%d %d %d", &d1, &m1, &y1);
            printf("\nDruhy datum: ");
            scanf("%d %d %d", &d2, &m2, &y2);
            printf("\n");
            pocetDniMedzi(d1, m1, y1, d2, m2, y2);
            //printf("Pocet dni medzi je: %d", pocetDniMedzi(d1, m1, y1, d2, m2, y2));
            break;
        case '4':

            printf("\nPekny den prajem Vam!\n");
            cyklus++;
            break;
        }
    } while(cyklus == 1);
    return 0;
}
