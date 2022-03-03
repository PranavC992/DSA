#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for Details
typedef struct Node {
	char name[20];
	char AN[20];
	char vT[20];
    char MN[20];
}Node;

// Structure to maintain Records
typedef struct record {
	Node data;
	struct record*next;
}record;

// Get Records
record*GreatLink() {
	record*h, *tail, *p;
	h=tail=(record*)malloc(sizeof(record));
	h->next = NULL;
	
    int n = 0;
	printf("\n  Enter the Number of Records to be Entered: ");
	scanf("%d", &n);
	
    for (int i = 0; i < n; i++) {
		p = (record*)malloc(sizeof(record));
		
        printf("\n  Name: ");
		scanf("%s", &p->data.name);
		
        printf("\n  Aaadhar No: ");
		scanf("%s", &p->data.AN);
		
        printf("\n  Vaccination Type: ");
		scanf("%s", &p->data.vT);
        
        printf("\n  Mobile Number: ");
		scanf("%s", &p->data.MN);
		
        p->next = NULL;
		tail->next = p; 
		tail = p;
	}
	return h;
}

// insert (head insertion method)
void Insert(record*h) {
	record*p;
	p = (record*)malloc(sizeof(record));
	
    printf("\n  Name: ");
	scanf("%s", &p->data.name);
	
    printf("\n  Aaadhar No: ");
	scanf("%s", &p->data.AN);
	
    printf("\n  Vaccination Type: ");
	scanf("%s", &p->data.vT);
    
    printf("\n  Mobile Number: ");
	scanf("%s", &p->data.MN);
	
    p->next = h->next;
	h->next = p;
}

//  search By Name
void Name(record*h) {
	char name[20];
	record*p = h->next;
	
    printf("\n  Enter the Name you want to find: ");
	scanf("%s", &name);
	
    while (p != NULL) {
	
    	if (strcmp(p->data.name, name) != 0) {
			p = p->next;
		} else {
	    	printf("\n\n  Name = %s", p->data.name);
			printf("\n\n  Aaadhar No = %s", p->data.AN);
			printf("\n\n  Vaccination Type = %s", p->data.vT);
            printf("\n\n  Mobile Number = %s", p->data.MN);
			return;
		}
	}
}


// search by adhar number
void AN(record*h) {
	char AN[20];
	record*p = h->next;
	
    printf("\n  Enter the Aaadhar Number to find: ");
	scanf("%s", &AN);
	
    while (p != NULL) {
	
    	if (strcmp(p->data.AN, AN) != 0) {
			p = p->next;
		} else {
			printf("\n\n  Name = %s", p->data.name);
			printf("\n\n  Aaadhar No = %s", p->data.AN);
			printf("\n\n  Vaccination Type = %s", p->data.vT);
            printf("\n\n  Mobile Number = %s", p->data.MN);
			return;
		}
	}
	
    if (p == NULL) {
		printf("\n  Not found! \n");
	}
}

// search by Mobile Number
void MN(record*h) {
	char MN[20];
	record*p = h->next;
	
    printf("\n  Enter the Mobile Number to find: ");
	scanf("%s", &MN);
	
    while (p != NULL) {
	
    	if (strcmp(p->data.MN, MN) != 0) {
			p = p->next;
		} else {
			printf("\n\n  Name = %s", p->data.name);
			printf("\n\n  Aaadhar No = %s", p->data.AN);
			printf("\n\n  Vaccination Type = %s", p->data.vT);
            printf("\n\n  Mobile Number = %s", p->data.MN);
			return;
		}
	}
	
    if (p == NULL) {
		printf("\n  Not found! \n");
	}
}

// Display Records
void PrintLink(record*h) {
	record*p;
    printf("********RECORDS***********");
	printf("\n Name \t\tAaadhar Number \t\tVaccination Type \t\t Mobile Number \n");
	
    for (p = h->next; p != NULL; p = p->next) {
		printf("\n%s",p->data.name);
		printf("\t\t%s", p->data.AN);
		printf("\t\t%s", p->data.vT);
        printf("\t\t\t%s", p->data.MN);
		printf("\n");
	}
    printf("***********************");
}

// Delete by  Aaadhar No
void delAN(record*h) {
	char AN[20];
	record*p = h->next;
	record*tail = h;
	
    printf("\n  Enter the  Aaadhar Number of the record to be deleted: ");
	scanf("%s", &AN);
	
    while (p != NULL) {
	
    	if (strcmp(p->data.AN, AN) != 0) {
			p = p->next;
			tail = tail->next;
		} else {
			tail->next = p->next;
			free(p);
			return;
		}
	}
}

// Delete by  Mobile No
void delMN(record*h) {
	char MN[20]; 
	record*p = h->next;
	record*tail = h;
	
    printf("\n  Enter the  Mobile Number of the record to be deleted: ");
	scanf("%s", &MN);
	
    while (p != NULL) {
		if (strcmp(p->data.MN, MN) != 0) {
			p = p->next;
			tail = tail->next;
		} else {
			tail->next = p->next;
			free(p);
			return;
		}
	}
}

void menu() {
	printf("\n\n\n--------* Vaccination Management System *-------- \n");
	printf("\n    1. Enter Records  \n");
	printf("    2. Insert a Record  \n");
	printf("    3. Search Records \n");
	printf("    4. Delete Records  \n");
	printf("    5. Display Records  \n");
	printf("\n-------------------- ** --------------------");
	printf("\n\n  Note: Only enter once, otherwise it will overwrite \n");
}

void choose(record*h) {
	int i;
	int a = 1;

	while (a > 0) {
		menu();
		printf("\n  Please Choose: ");
		scanf("%d", &i);
	
    	switch (i) {
		    case 1:
			    h = GreatLink();
			    break;
		
            case 2:
			    Insert(h);
			    break;
            case 3:
                printf("\n\n\n--------* Vaccination Management System *-------- \n");
                printf("\n    1. Search by Name \n");
                printf("    2. Search by Adhar Number \n");
              
                printf("    3. Search by Mobile Number \n");
                printf("\n-------------------- ** --------------------");
        	    printf("\n\n  Note: Only enter once, otherwise it will overwrite \n");
                printf("\n Please Choose: ");
    
                int j, b = 1;
                scanf("%d", &j);
    
                switch(j) {
                    case 1:
                        Name(h);
                        break;
                    case 2:
                        AN(h);
                        break;
                    
                    case 3:
                        MN(h);
                        break;
                    default:
                        printf("\n  Invalid command! \n");
				        b = -1;// jump out of the loop condition 
				        break;
                }
			    break;
            case 4:
                printf("\n\n\n--------* Vaccination Management System *-------- \n");
                printf("\n 1. Delete by Adhar Number \n");
                printf("\n 2. Delete by Mobile No \n");
                printf("\n-------------------- ** --------------------");
        	    printf("\n\n  Note: Only enter once, otherwise it will overwrite \n");
                printf("\n Please Choose: ");
    
                int k, c = 1;
                scanf("%d", &k);
    
                switch(k) {
                    case 1:
                        delAN(h);
                        break;
                    case 2:
                        delMN(h);
                        break;
                    default:
                        printf("\n  Invalid command! \n");
				        c = -1;// jump out of the loop condition 
				        break;
                }
				break;
            case 5:
				PrintLink(h);
				break;
            default:
			    printf("\n  Invalid command! \n");
				a = -1;// jump out of the loop condition 
				break;
		}
	}
}
int main() {
	record*head = NULL;
	choose(head);
	return 0;
}
