#include <stdio.h>
#define DIM_NOME 100

struct insegnamento
{
    char nome_corso[DIM_NOME];
    int anno;
    int cfu;
    int voto;
};

void ins_corso(struct insegnamento *);
void scrivi_corso(struct insegnamento);
void vis_corsi();
int somma_crediti();
float media_pesata();

FILE *f_pointer;

int main() {
    int opzione=-1;
    char invio;
    struct insegnamento corso;
    struct insegnamento *ptr_corso;

    ptr_corso=&corso;

    while(opzione!=0)
    {
        printf("\n\nBENVENUTO NEL PROGRAMMA DI GESTIONE DEI TUOI ESAMI\n");
        printf("----------------------------------------------------");
        printf("\n\n");
        printf("\n\t1. Inserisci esame");
        printf("\n\t2. Visualizza esami");
        printf("\n\t3. Visualizza crediti totali");
        printf("\n\t4. Media pesata esami");
        printf("\n\t0. Esci");
        printf("\n\n\nScegli una delle possibili opzioni: \n");
        scanf("%d",&opzione);
        scanf("%c",&invio);
        switch(opzione)
        {
            case 1:
                printf("\nOpzione inserisci esame\n");
                ins_corso(ptr_corso);
                scrivi_corso(corso);
                break;
            case 2:
                printf("\nOpzione visualizza esami\n");
                vis_corsi();
                break;
                 case 3:
                     printf("\nOpzione visualizza crediti totali\n");
                     printf("\n\t\t>>>Il numero toale dei CFU conseguiti e' pari a: %d\n",somma_crediti());
                     break;
                 case 4:
                     printf("\nOpzione media pesata esami\n");
                     printf("\n\t\t>>>La media pesata al momento e' pari a: %.2f\n",media_pesata());
                     break;
            case 0:
                printf("\nSei uscito dal programma\n");
                printf("\nA PRESTO!\n");
                break;
            default:
                printf("\nScelta non valida!\n");
                break;
        }
    }

    return 0;
}

void ins_corso(struct insegnamento *ptr_corso) {
    printf("\nStai inserendo un nuovo corso\n");
    printf("Inserisci nome corso: \n");
    fgets(ptr_corso->nome_corso,DIM_NOME,stdin);
    printf("Inserisci anno del corso: \n");
    scanf("%d",&ptr_corso->anno);
    printf("Inserisci numero CFU: \n");
    scanf("%d",&ptr_corso->cfu);
    printf("Inserisci voto in trentesimi: \n");
    scanf("%d",&ptr_corso->voto);
}

void scrivi_corso(struct insegnamento corso) {
  f_pointer=fopen("/Users/matteo/Downloads/db_corsi.dat","a+");
  fwrite(&corso, sizeof(struct insegnamento), 1, f_pointer);
  fclose(f_pointer);
}

void vis_corsi() {
    struct insegnamento corso;
    int n;
    f_pointer=fopen("/Users/matteo/Downloads/db_corsi.dat","r");

    if(f_pointer==NULL)
        printf("ATTENZIONE: nessun esame inserito!\n\n");
    else
    {
        do{
            n = fread(&corso, sizeof(struct insegnamento), 1, f_pointer);
            if(n==0) fclose(f_pointer);
            else {
                printf("\n\nNOME ESAME: %s",corso.nome_corso);
                printf("ANNO ESAME: %d\n",corso.anno);
                printf("VOTO: %d\n",corso.voto);
                printf("CFU: %d\n",corso.cfu);
            }
        }
        while(n!=0);
    }
}
//
 int somma_crediti() {
     struct insegnamento corso;
     int somma=0;
     int n;
     f_pointer=fopen("/Users/matteo/Downloads/db_corsi.dat","r");

     if(f_pointer==NULL)
         printf("ATTENZIONE: nessun esame inserito!\n\n");
     else
     {
         do{
             n = fread(&corso, sizeof(struct insegnamento), 1, f_pointer);
             if(n==0) fclose(f_pointer);
             else {
                 somma+=corso.cfu;
             }
         }
         while(n!=0);
     }
     return somma;
 }
//
 float media_pesata() {
     struct insegnamento corso;
     int somma_cfu=0;
     float media=0;
     int n;
     f_pointer=fopen("/Users/matteo/Downloads/db_corsi.dat","r");

     if(f_pointer==NULL) {
       printf("ATTENZIONE: nessun esame inserito!\n\n");
       return 0;
     }

     else
     {
         do{
             n = fread(&corso, sizeof(struct insegnamento), 1, f_pointer);
             if(n==0) fclose(f_pointer);
             else {
                 somma_cfu+=corso.cfu;
                 media+=corso.cfu*corso.voto;
             }
         }
         while(n!=0);
     }
     return media/somma_cfu;
 }
