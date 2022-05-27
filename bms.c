//Simple Bank Management System in C
/* PICL : CSE B : 2021-25
Kailash Ashok Swaminathan : 21070122069 : CSE B1
Mohammad Omar Shaikh : 21070122095 : CSE B2
Narasimha Lokhesh Nidadavole : 21070122101 : CSE B2
Mudit Garg : 21070122098 : CSE B2 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void home(char username[]); // function prototype, function defined later
void delay(){ //function to give sense of actual data processing
    int i,j,k;
    for(i=0; i<3; i++){    
        for (j=0; j<5; j++){
            for(k=0; k<10000000; k++){
                k++;
                k--;
            }
        printf("* ");
        }
        printf("\n");
    }
}   

//structure to store user details
struct details{
    char username[20];
    char pass[20];
	int date, month, year;
	int phone;
	int aadhaar;
	char name[50];
	char address[50];
    int obal;
}; 
struct details u1; //global structure variable

//function for user to create account
void open_acc(){
    FILE *fu;
    char ch;
    printf("----OPEN YOUR SAVINGS ACCOUNT----");
    getchar();
    printf("\nNAME: ");
    gets(u1.name);
    printf("\nADDRESS: ");
    gets(u1.address);
    printf("\nDATE OF BIRTH:");
    printf("\nDATE(dd)-");
    scanf("%d", &u1.date);
    printf("\nMONTH(mm)-");
    scanf("%d", &u1.month);
    printf("\nYEAR(yy)-");
    scanf("%d", &u1.year);
    printf("\nAADHAAR NUMBER: ");
    scanf("%d", &u1.aadhaar);
    printf("\nPHONE NUMBER: ");
    scanf("%d", &u1.phone);
    printf("\nOPENING BALANCE: ");
    scanf("%d",&u1.obal);

    printf("\nUSERNAME: ");
    scanf("%s", &u1.username);
    printf("\nPASSWORD:");
    scanf("%s",&u1.pass);

    printf("\nProcessing your data, Please Wait!\n");
    delay();
    ch = getchar();
    printf("\nAccount Created Successfully !");

    fu = fopen("user-details.txt","ab");
    fwrite(&u1, sizeof(u1),1,fu);
}
//checking username and password
void authentication(char username[],char password[]){
    FILE *fu;
    char ch;
    fu = fopen("user-details.txt","rb");
    while (fread(&u1,sizeof(u1), 1, fu)){ 
        if ((strcmp(username,u1.username) == 0) && (strcmp(password,u1.pass) == 0)){
            printf("\nPlease Wait while we check your details!");
            printf("\n");
            delay();
            ch = getchar();
            printf("\nAuthentication Successful !");
            printf("\nPress any key to continue");
            ch = getchar();
            home(username);
        }
    }
}

//function to login
void login(){
    char username[20], password[20], ch;
    FILE *fu;
    fu = fopen("user-details.txt","rb");
    printf("\n------ ACCOUNT LOGIN PORTAL -------");
    printf("\nEnter your username: ");
    scanf("%s",&username);
    printf("\nEnter your password: ");
    scanf("%s",&password);
    //authentication
    while (fread(&u1,sizeof(u1), 1, fu)){
        if ((strcmp(username,u1.username) == 0) && (strcmp(password,u1.pass) == 0)){
            printf("\nPlease Wait while we check your details!");
            printf("\n");
            delay();
            ch = getchar();
            printf("\nAuthentication Successful !");
            printf("\nPress any key to continue");
            ch = getchar();
            home(username);
        }  
        else{
            printf("\nInvalid Credentials Entered !");  
            printf("\nRenter your username: ");
            scanf("%s",&username);
            printf("\nRenter your password: ");
            scanf("%s",&password);
            authentication(username,password);      
        }
    }
}

//main driver code
int main(){
    int i, choice;
    printf("\nWelcome to the KLM Banking Services !!\n\n");
    printf("**************************************\n\n");
    printf("[1] New User? Register Now !\n");
    printf("[2] Existing User? Login Here !\n");
    printf("[3] Done with Banking? Exit here!\n");
    printf("Enter integral choice: ");
    scanf("%d",&choice);

    switch (choice){
        case 1:
            system("cls"); //clear console display screen
            open_acc();
            break;
        case 2:
            system("cls");
            login();
            break;
        case 3:
            printf("Thank You for your Transaction!");
            exit(0);
            break;
    }
}

//function to facilitate withdraw
void withdraw(){
    system("cls");
    FILE *fu;
    int with;
    char ch;
    printf("\nEnter Withdrawl Amount: ");
    scanf("%d", &with);
    printf("\nPerforming Transaction, Please Wait!\n");
    delay();
    ch = getchar();
    if (u1.obal<with)
        printf("\nInsufficient Balance !");
    else{ 
        u1.obal = u1.obal-with;
        printf("\nBalance: %d",u1.obal);
    }      
    fu = fopen("user-details.txt","ab");
    fwrite(&u1, sizeof(u1),1,fu);
}

//function to facilitate deposit
void deposit(){
    system("cls");
    FILE *fu;
    int dep;
    char ch;
    printf("\nEnter Amount to Deposit: ");
    scanf("%d", &dep);
    u1.obal += dep;
    printf("\nPerforming Transaction, Please Wait!\n");
    delay();
    ch = getchar();
    printf("\nBalance: %d",u1.obal);
    fu = fopen("user-details.txt","ab");
    fwrite(&u1, sizeof(u1),1,fu);
}

//function to check balance
void balance(){
    char ch;
    system("cls");
    printf("\nPerforming Transaction, Please Wait!\n");
    delay();
    ch = getchar();
    printf("\nBalance: %d",u1.obal);
}

void menu_list(){ //menu driven program - display choices
    system("cls");
    printf("~~~ HOME ~~~\n");
    printf("[1] Display Account Details\n");
    printf("[2] Withdraw Money\n");
    printf("[3] Deposit Money\n");
    printf("[4] Check Balance\n");
    printf("[5] Logout and Exit\n");
}

//function to logout from the system
void logout(){
    int i, j;
    char ch;
	system("cls");
	printf("Terminating Session, Please Wait.\n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 1000000000; j++) {
			i++;
			i--;
		}
		printf(". ");
	}
    ch = getchar();
	printf("\nSign Out Successful\nThank You for your Transaction!");
	printf("\nPress any key to Exit ....");
	getchar();
}

//function to print the account details of the user
void details(char username[]){
    system("cls");
	FILE *fp;
	fp = fopen("user-details.txt", "rb");

    while (fread(&u1, sizeof(u1),1, fp)) {
		if (strcmp(username,u1.username) == 0) {
			printf("\nWELCOME, %s",u1.name);
			printf("\n.........................");
			printf("\n---- ACCOUNT DETAILS ----");
			printf("\n.........................");			
			printf("\nNAME: %s",u1.name);
            printf("\nADDRESS: %s", u1.address);
            printf("\nDATE OF BIRTH: %d/%d/%d",u1.date,u1.month,u1.year);
			printf("\nAADHAAR CARD NUMBER: %d",u1.aadhaar);			
			printf("\nREGISTERED CONTACT NUMBER: %d",u1.phone);
            printf("\nSAVINGS ACCOUNT BALANCE: %d", u1.obal);
            printf("\n\nPress any key to continue!");
		}
	}
	fclose(fp);
}

void home(char username[]){
    int choice;
    do {
        menu_list();
        printf("Enter Integral Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                details(username);
                getchar();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                deposit();
                break;
            case 4:
                balance();
                break;

            case 5:
                logout();
                exit(0);
                break;

            default:
                printf("Invalid Input, Retry!");
                getchar();
                break;
        }
    getchar();
    }
    while (choice != 5);
}