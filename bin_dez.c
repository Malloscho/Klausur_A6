#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
    //überprüfen der Länge
    int bin_to_dec(int binaryzahl[], int n)
    {
        if(n>=31)
        {
            return -2;
        }
    // Einsetzen eines Multiplikators um der Wert der entsprechenden Stelle der Binarzahl festzuhalten
    int multiplikator = 1;
    // Variable zum festhalten der Summe, wird am Ende zuruckgegeben (Wert der decimal Zahl)
    int summe = 0;
    
    // Durchgehen der Arrays
      for (int i = n-1; i >= 0; i--)
    {
        // Check ob der Wert 0 oder 1 ist, da der Vorgang auch mit anderen Zahlen laufen würde
        if (binaryzahl[i] == 0 || binaryzahl[i] == 1 )
        {
            int temp_wert;
            temp_wert = multiplikator * binaryzahl[i];
            summe = summe + temp_wert;
            //printf("%d ", binaryzahl[i]);
            multiplikator = multiplikator * 2;
        }
        else
        {
            return -1;
        }
        
    }
    
    return summe;

    //printf("Erste Zahl: %i, Length: %i", binaryzahl[0], n);
    
}
int rechner()
{
    int binarry[] = {1,0,1,0,1,1};          //evtl das Array mit scanf einlesen?
        // Ermitteln der Lenght des Arrays
        size_t n = sizeof(binarry)/sizeof(binarry[0]);
         //printf("Length des Arrays: %i \n", n);
         int result = bin_to_dec(binarry, n);
        if (result == -1)
         {
            printf("bitte nur 0 und 1 eingeben\n");
            }
        else if (result == -2)
         {
             printf("Array zu groß!\n");
             printf("max. 31 Zeichen!\n");
         }
        else
        {
            printf("Das Ergebnis als Dezimalzahl ist: %i\n",result);
        }
        
        return 0;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
       
        printf("No option recognized. Wrong Usage. Please try -h\n");
        return 0;
        
    }
    
    
    int c;
    while((c = getopt(argc, argv, "hvr?"))!=1)
    {
        switch(c)
        {
        case 'h':
            printf("Die Zahlen können nur über den Quellcode eingegeben werden, mit -r kann das Ergebnis ausgegeben werden\n");
            exit(0);

        case 'v':
            printf("Version 1.0\n");
            exit(0);
                
                
        case 'r':
            rechner();
            exit(0);
                
        

        case '?':
            fprintf(stderr, "Please try -h\n");
            exit(1);
        
            
            
       
        }
    }
    
    
}
