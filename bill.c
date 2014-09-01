/*Water, Electricity, Gas Bill Calculator*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bill.h"



int main(){
    
    char *prompt1 = "Please enter a name for this bill: ";
    char *prompt2 = "Please enter total cost of bill (in $ and cents): $";
    char *prompt3 = "Please enter number of days the bill is for (whole numbers only): ";
    char *prompt4 = "Please enter number of tenants this bill is for (up to 10): ";
    char *prompt5 = "Please enter tenant name: ";
    char *prompt6 = "Please enter number of days (during the bill) tenant has been here for (whole numbers only): ";
    
    
    
    
    /*temp variables*/
    int i;
    int j;
    char bill_name[BILL_NAME_LEN];
    char temp_tenant_name[TENANT_NAME_LEN + EXTRA_SPACES];
    char temp_int_inputs[INT_INPUT_LEN + EXTRA_SPACES];
    char temp_double_inputs[DOUBLE_INPUT_LEN + EXTRA_SPACES];
    int num_of_tenants;
    int bill_num_of_days;
    int tenant_num_of_days;
    double total_cost_of_bill;
    double cost_of_bill_per_day;
    double cost_per_person;

    
    Tenant peoplearray[NUMBER_OF_TENANTS];
    
    /*initialise our memory*/
    initTenant(peoplearray);


    
    printf("\tShare House Bill Calculator\t\t\n");
    printf("\t\tBy James Snee\t\t\n");
    printf("-------------------------------------------------------\n\n");

    printf("INFORMATION: This program will work out the total cost of\n");
    printf("a bill, for each person living in the house, according to\n");
    printf("how many days they were living here at the time of the\n");
    printf("billing cycle. If at any time you would like to quit, simply\n");
    printf("press enter, although nothing will be saved.\n\n");

    
    if(stringinput(prompt1, bill_name, BILL_NAME_LEN) == FALSE){
        printf("Error: Nothing entered! Exiting....\n");
        return EXIT_FAILURE;
    }
    
    total_cost_of_bill = doubleinput(prompt2, temp_double_inputs, DOUBLE_INPUT_LEN + EXTRA_SPACES);
    
    if (total_cost_of_bill == 0){
        printf("Error: Nothing entered! Exiting....\n");
        return EXIT_FAILURE;
    }

    bill_num_of_days = intinput(prompt3, temp_int_inputs, INT_INPUT_LEN + EXTRA_SPACES);
    
    if (bill_num_of_days == 0){
        printf("Error: Nothing entered! Exiting....\n");
        return EXIT_FAILURE;
    }
    
    /*calculate cost of bill per day*/
    cost_of_bill_per_day = total_cost_of_bill / bill_num_of_days;
    printf("Cost of bill per day is $%g.\n", cost_of_bill_per_day);
    
    num_of_tenants = intinput(prompt4, temp_int_inputs, INT_INPUT_LEN + EXTRA_SPACES);
    
    if (num_of_tenants == 0){
        printf("Error: Nothing entered! Exiting....\n");
        return EXIT_FAILURE;
    }
    
    
    /*divide the cost of bill per day by how many people*/
    cost_per_person = cost_of_bill_per_day / num_of_tenants;
    printf("Cost of bill per person, per day is $%g.\n", cost_per_person);
    
    double total_calculated_cost;
    /*count of all tenants who have been at the place for the whole bill*/
    int divisor = 0;
    
    for (i = 1; i <= num_of_tenants; i++){
    
        if(stringinput(prompt5, temp_tenant_name, TENANT_NAME_LEN + EXTRA_SPACES) == FALSE){
            printf("Error: Nothing entered! Exiting....\n");
            return EXIT_FAILURE;
        }
        
        /*copy temp string to array*/
       	strcpy(peoplearray[i].tenant_name, temp_tenant_name);
       	 /*loop to print all names*/
       	printf("Tenant number %i is %s.\n", i, peoplearray[i].tenant_name);
        
        tenant_num_of_days = intinput(prompt6, temp_int_inputs, INT_INPUT_LEN + EXTRA_SPACES);
        
        if (tenant_num_of_days == 0){
            printf("Error: Nothing entered! Exiting....\n");
            return EXIT_FAILURE;
        }
        
        /*put number of days into array*/
        peoplearray[i].num_of_days = tenant_num_of_days;
        
        /*we need to multiply tenants number of days with cost pp per day*/
        peoplearray[i].final_tenant_cost = cost_per_person * peoplearray[i].num_of_days;
        /*if tenant has been here for whole bill, set boolean to true*/
        if (peoplearray[i].num_of_days == bill_num_of_days){
            peoplearray[i].wholebill = 1;
            printf("%s has been here for the whole bill.\n", peoplearray[i].tenant_name);
            divisor++;
        }else {
            peoplearray[i].wholebill = 0;
        }

        printf("%s's final cost is $%g.\n", peoplearray[i].tenant_name, peoplearray[i].final_tenant_cost);
        total_calculated_cost += peoplearray[i].final_tenant_cost;
        
        
    }
    
    /*if they have not been here for the whole bill, that means we need to*/
    /*make sure that, if there is a discrepancy at the end of the calculation*/
    /*we add the remainder to people who HAVE been there for the whole bill*/
    if (total_calculated_cost != total_cost_of_bill){
        
        double remainder = total_cost_of_bill - total_calculated_cost;
        
        for(int count = 1; count <= num_of_tenants; count++){
            
            if (peoplearray[count].wholebill == 1){
                peoplearray[count].final_tenant_cost += (remainder / divisor);
            }
        
        }
        
    }
    
    printf("\n\n\t\tFinal Bill Calculation:\t%s\n",bill_name);
    printf("--------------------------------------------------------\n");
    
    printf("\nTotal number of days for bill: %i\n", bill_num_of_days);
    printf("Cost per day for bill: $%g\n", cost_of_bill_per_day);
    printf("Cost per person, per day for bill: $%g\n", cost_per_person);
    printf("Number of Tenants: %i\n\n", num_of_tenants);
    
    
    printf("Tenant Name\t\tNumber of Days\t\tTotal Cost\t\t\n");
    
    double final_total_to_print = 0;

    for (j = 1; j <= num_of_tenants; j++){

    	/*Loop to print all information goes here*/
        printf("%s\t\t\t%i\t\t\t$%g\t\t\t\n", peoplearray[j].tenant_name,peoplearray[j].num_of_days, peoplearray[j].final_tenant_cost);
        final_total_to_print += peoplearray[j].final_tenant_cost;
        

    }
    printf("\nTotal Cost of Bill:\t\t\t\t$%g\n", final_total_to_print);
    

    return EXIT_SUCCESS;
}

/*Initialise tenant array*/
void initTenant(Tenant * peoplearray){

	int count;

	for (count = 0; count < NUMBER_OF_TENANTS; count++){
		strcpy(peoplearray[count].tenant_name, "NULL");
		peoplearray[count].num_of_days = 0;
		peoplearray[count].final_tenant_cost = 0.0;

	}

}

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

