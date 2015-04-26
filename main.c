#include <stdio.h>
#include <stdlib.h>

// Definisci le costanti
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente  {
	char nome[MAX_STRLEN+1];
	char cognome[MAX_STRLEN+1];
	unsigned int eta;
	char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    char file[MAX_STRLEN+1];
    int i;
    FILE *puntafile;
    studente alunno;
    
    printf("Inserisci il nome del file: ");
    scanf("%s", file);
    puntafile=fopen(file, "rb");
    if (puntafile == NULL) {
        printf("Impossibile aprire il file.");
    }
    else {
        i=1;
        fread(&alunno,sizeof(alunno),1,puntafile);
        while (!feof(puntafile)) {
            printf("Studente %d:\n", i);
            printf("Nome: %s\n", alunno.nome);
            printf("Cognome: %s\n", alunno.cognome);
            printf("Eta': %d\n", alunno.eta);
            printf("Classe: %s\n", alunno.classe);
            fread(&alunno,sizeof(alunno),1,puntafile);
            i++; 
        }
        fclose(puntafile);
    }
    return (EXIT_SUCCESS);
}