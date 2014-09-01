//
//  util.c
//  Bill Calculator
//
//  Created by James Snee on 1/09/2014.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bill.h"

/*Function to take in a string of specific length*/
char * stringinput(char * prompt, char * storage, int size){
    
    BOOLEAN finished = FALSE;
    
    do{
        printf("%s", prompt);
        
        /*Handling CTRL-D Input*/
        if(fgets(storage, size, stdin) == NULL){
            return FALSE;
        }
        /*Handling input length*/
        if(storage[strlen(storage) -1] !='\n'){
            printf("Error: Input was too long! Try again.\n");
            read_rest_of_line();
            
        }
        
        /*Handling newline input*/
        else if (strcmp(storage, "\n") == 0){
            return FALSE;
        }
        
        else{
            storage[strlen(storage) -1] = '\0';
            finished = TRUE;
        }
        
    }while(!finished);
    
    return storage;
}

/*Function to take in an input of size 2 and convert to int*/
int intinput(char * prompt, char * storage, int size){
    
    int result;
    BOOLEAN finished = FALSE;
    
    do{
        printf("%s", prompt);
        
        /*Handling CTRL-D Input*/
        if(fgets(storage, size, stdin) == NULL){
            return FALSE;
        }
        /*Handling input length*/
        if(storage[strlen(storage) -1] !='\n'){
            printf("Error: Input was too long! Try again.\n");
            read_rest_of_line();
            
        }
        
        /*Handling newline input*/
        else if (strcmp(storage, "\n") == 0){
            return FALSE;
        }
        
        else{
            storage[strlen(storage) -1] = '\0';
            /*convert to int*/
            result = atoi(storage);
            
            
            finished = TRUE;
        }
        
    }while(!finished);
    
    return result;
    
    
}


/*Function to take in an input of size 2 and convert to double*/
double doubleinput(char * prompt, char * storage, int size){
    
    double result;
    BOOLEAN finished = FALSE;
    
    do{
        printf("%s", prompt);
        
        /*Handling CTRL-D Input*/
        if(fgets(storage, size, stdin) == NULL){
            return FALSE;
        }
        /*Handling input length*/
        if(storage[strlen(storage) -1] !='\n'){
            printf("Error: Input was too long! Try again.\n");
            read_rest_of_line();
            
        }
        
        /*Handling newline input*/
        else if (strcmp(storage, "\n") == 0){
            return FALSE;
        }
        
        else{
            storage[strlen(storage) -1] = '\0';
            /*convert to double*/
            result = atof(storage);
            
            
            finished = TRUE;
        }
        
    }while(!finished);
    
    return result;
    
    
}




void read_rest_of_line(void) {
    int ch;
    while(ch=getc(stdin), ch!=EOF && ch!='\n')
        ;
    clearerr(stdin);
}
