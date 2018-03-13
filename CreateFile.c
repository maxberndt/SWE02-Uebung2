#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, const char * argv[]) {
    
    int number = 100;
    int range = 100;
    time_t t;
    
    
    for(int i=0; i < argc; i++) {
        
        //printf("%s\n",argv[i]); //Zum Testen
        
        if (strcmp(argv[i], "-n") == 0){
            number = atoi(argv[i+1]);
        }
        
        if (strcmp(argv[i], "-r") == 0){
            range = atoi(argv[i+1]);
        }
        
        if (strcmp(argv[i], "-h") == 0){
            printf("Kurze Beschreibung");
        }
        
    }
    
    printf("%i Zahlen, 0 - %i Zahlenbereich, Datei: %s\n",number,range,argv[argc-1]);

    FILE *fp;
    int random[number];
    
    srand((unsigned) time(&t));
    
    //Zufallszahlen erzeugen
    for (int i=0;i<number;i++){
        random[i] = rand() % (range+1);
    }
    
    char* randomchar[number];

    for (int i=0; i < number; i++)
    {
        char c[sizeof(int)];
        snprintf(c, sizeof(int), "%d", random[i]);
        randomchar[i] = malloc(sizeof(c));
        strcpy(randomchar[i], c);
        printf("c[%d] = %s\n", i, randomchar[i]);
    }
    
    fp = fopen(argv[argc-1], "w");
    
    if(fp == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }else {
        for(int i=0; i<number; i++) {
            
            int len = strlen(randomchar[i]);
            //printf("%i\n",len);
            for (int n=0;n<len;n++){
                fputc(randomchar[i][n],fp);
            }
            fputc(10, fp);
        }
        fclose(fp);
    }
    
    return 0;
    
    
    
    
    
    
        
        
    
    
    
    
    
    
}
