#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main (int argc,char **argv){
    FILE* fl1,*fl2;
    int key;
    char ch,crypt;
    // проверка то что мы передали 3 аргумента командной строке т.е ./a.out plaintext cryptedtext
    if(argc!=3){
        fprintf(stderr,"can't open the %s %s\n",argv[1],argv[2]);
        exit(EXIT_FAILURE);
    }
    fl1=fopen(argv[1],"r");
    fl2=fopen(argv[2],"w");
    if(fl1 && fl2){ // проверка то что файлы открылись успешно
    puts("enter key (1 to 25): ");
    scanf(" %d",&key);
    key%=26;
    while ((ch= getc(fl1))!=EOF){
        if(ch == ' ' || ch == '\n')
            continue;
        ch=1+(int)ch%97;
        crypt=((int)ch+key)%26+96;   
        putc(crypt,fl2);
    }
    } else { 
        fprintf(stderr,"open error files %s and %s",argv[1],argv[2]);
        exit(EXIT_FAILURE);
    }
    fclose(fl1);
    fclose(fl2);
    puts("Programm finished");
    exit(EXIT_SUCCESS);
}


