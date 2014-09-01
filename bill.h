
#ifndef _bill_h
#define _bill_h
#define NUMBER_OF_TENANTS 10
#define BILL_NAME_LEN 20
#define TENANT_NAME_LEN 20
#define INT_INPUT_LEN 2
#define DOUBLE_INPUT_LEN 6
#define EXTRA_SPACES 2

struct tenant {

	char tenant_name[TENANT_NAME_LEN];
	int num_of_days;
	double final_tenant_cost;
    int wholebill;

};

typedef struct tenant Tenant;


/*boolean type*/
typedef enum truefalse
{
    FALSE, TRUE
} BOOLEAN;



/*function prototypes*/
void initTenant(Tenant * peoplearray);
char * stringinput(char * prompt, char * storage, int size);
int intinput(char * prompt, char * storage, int size);
double doubleinput(char * prompt, char * storage, int size);
void read_rest_of_line(void);
#endif