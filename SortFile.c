#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int dsc_sorter(const void *i1, const void *i2) {
    return *(int *)i2 - *(int *)i1; /* absteigend sortiert */
}

int main(int argc, const char * argv[]) {
    
    int sorting = 0; //0 = Aufsteigend, 1 = Absteigend
    
    for(int i=0; i < argc; i++) {
        
        //printf("%s\n",argv[i]); //Debugging
        
        if (strcmp(argv[i], "-a") == 0){
           // sorting = 0;
        }
        
        if (strcmp(argv[i], "-d") == 0){
            sorting = 1;
        }
        
        if (strcmp(argv[i], "-h") == 0){
            printf("Beschreibung der Funktionen. ");
        }
        
    }
    
    printf("Datei: %s\n",argv[argc-1]);
    
    if (sorting == 0){
        printf("Es wird aufsteigend sortiert!\n");
    }
    
    if (sorting == 1){
        printf("Es absteigend sortiert!\n");
    }
    
    FILE *fp;
    int temp,v,i=0,count=0;
    int values[200];
    fp = fopen("test.txt", "r");
    
    
    for (int n=0;n<200;n++){
        values[n]=11111;
    }
    
    
    if(fp == NULL) {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }else {
        
        while((temp = fgetc(fp))!=EOF) {
            fscanf(fp, "%i\n", &v);
            printf("Wert: %i\n", v);
            values[i]=v;
            i++;
            
        }
        
        
        for (int n=0;n<200;n++){
            if (values[n]!=11111){
                //printf("%i - ",values[n]); //Debugging
                count++;
            }
        }
        printf("%i Werte\n\n",count);
        fclose(fp);
    }

    //Sortierung aufsteigend
    if (sorting == 0){
        qsort(values, 5, sizeof(int), cmpfunc);
        printf("Aufsteigend sortiert:\n");
        //Ausgabe der Werte
        for (int n=0;n<count;n++){
            if (values[n]!=11111){
                printf("%i\n",values[n]);
            }
        }
    }
    
    //Sortierung absteigend
    if (sorting == 1){
        qsort(values, 5, sizeof(int), dsc_sorter);
        printf("Absteigend sortiert:\n");
        //Ausgabe der Werte
        for (int n=0;n<count;n++){
            if (values[n]!=11111){
                printf("%i\n",values[n]);
            }
        }
    }
    
    
    printf("\n");
    
    
    
    return 0;
}
