#include<stdio.h>
#include<time.h>
#include<windows.h>

void devinfo()
{
    system("cls");
    printf("1.Jakaria Kollol\n Student of Daffodil International University\n Department of Software Engineering\n Student ID:222-35-1184\n");
    printf(" Email Address: jakaria.kollol@outlook.com");

}
struct patient{
    int id;
    char patientName[50];
    char patientAddress[50];
    char disease[50];
    char date[12];
}p;

struct doctor{
    int id;
    char name[50];
    char address[50];
    char specialize[50];
    char date[12];
}d;

FILE *fp;
char password[10]={"hospital"};
int main()

{
      Password();
      getch();
   return 0;

}
void returnfunc(void);
int checkid(int t);
void mainmenu(){

    int ch;

    while(1){
        system("cls");

        printf("\xB2\xB2\xB2\xB2 Hospital Management System \xB2\xB2\xB2\xB2\n");
        printf("\n\n");
        printf("\xB2\xB2\xB2\xB2\xB2 For Patient Record \xB2\xB2\xB2\xB2\xB2\n ");
        printf("\n\n\n");
        printf("1.Patient Registration\n");
        printf("2.Patient List\n");
        printf("3.Discharge Patient\n");
        printf("4.Edit Patients Data\n");
        printf("5.Add Doctor\n");
        printf("6.Doctors List\n");
        printf("7.Developer's Information\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            regPatient();
            break;

        case 2:
            patientList();
            break;

        case 3:
            dischargePatient();
            break;
        case 4:
            editpatient();
            break;

        case 5:
            addDoctor();
            break;

        case 6:
            doctorList();
            break;
        case 7:
            devinfo();
            break;


        default:
            printf("Invalid Choice...\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}

void regPatient(){
    system("cls");
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(p.date, myDate);

    fp = fopen("patient.txt", "ab");

    printf("Enter Patient id: ");
    scanf("%d", &p.id);

    printf("Enter Patient name: ");
    fflush(stdin);
    gets(p.patientName);

    printf("Enter Patient Address: ");
    fflush(stdin);
    gets(p.patientAddress);

    printf("Enter Patient Disease: ");
    fflush(stdin);
    gets(p.disease);

    printf("\nPatient Added Successfully");

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void patientList(){

    system("cls");
    printf("\xB2\xB2 Patient List \xB2\xB2\n\n");
    printf("%-10s %-30s %-30s %-20s %s\n", "Id", "Patient Name", "Address", "Disease", "Date");
    printf("----------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patient.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-20s %s\n", p.id, p.patientName, p.patientAddress, p.disease, p.date);
    }

    fclose(fp);
}
void editpatient()
{


    system("cls");
    int c=0;
    int d,e;

    printf("\xB2\xB2\xB2\xB2\xB2 EDITING PATIENT DATA \xB2\xB2\xB2\xB2\xB2\n ");
    char another='y';
    printf("\n\n");
    while(another =='y')
    {
        system("cls");
        printf("Enter Patient Id to be edited:");
        scanf("%d",&d);
        fp=fopen("patient.txt","rb+");
        while(fread(&p,sizeof(p),1,fp)==1)
        {
            if(checkid(d)==0)
            {

                printf("The Patient ID is availble\n");

                printf("The Patient ID:%d\n",p.id);

                printf("Enter new Name:");scanf("%s",p.patientName);
                printf("\n");
                printf("Enter new Address:");scanf("%s",p.patientAddress);
                printf("\n");
                printf("Enter new Disease:");scanf("%s",p.disease);
                printf("\n");
                printf("The Patient Data is modified");

                fseek(fp,ftell(fp)-sizeof(p),0);
                fwrite(&p,sizeof(p),1,fp);
                fclose(fp);

            }
            if(c==0)
            {

                printf("\nNo record found\n");
            }
        }

        printf("Modify another Record?(Y/N)\n");
        fflush(stdin);
        another=getch() ;
    }
        returnfunc();
}

int checkid(int t)
{
    rewind(fp);
    while(fread(&p,sizeof(p),1,fp)==1)
    if(p.id==t)
    return 0;
    return 1;
}
void returnfunc(void)
{
    {
    printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13)
    mainmenu();

    else
    goto a;
}

void dischargePatient(){
    int id, f=0;
    system("cls");
    printf("\xB2\xB2 Discharge Patient\xB2\xB2\n\n");
    printf("Enter Patient id to discharge: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPatient Discharged Successfully.");
    }else{
        printf("\n\nRecord Not Found !");

        fflush(stdin);

if(getch())
        mainmenu();

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

}
}

void addDoctor(){

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(d.date, myDate);

    //int f=0;

    system("cls");
    printf("\n");
    printf("\xB2\xB2 Add Doctor \xB2\xB2\n\n");

    fp = fopen("doctor.txt", "ab");

    printf("Enter Doctor id: ");
    scanf("%d", &d.id);

    printf("Enter Doctor Name: ");
    fflush(stdin);
    gets(d.name);

    printf("Enter Doctor Address: ");
    fflush(stdin);
    gets(d.address);

    printf("Doctor Specialize in: ");
    fflush(stdin);
    gets(d.specialize);

    printf("Doctor Added Successfully\n\n");

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);
}



void doctorList(){
    system("cls");
    printf("\xB2\xB2\xB2 Doctor List \xB2\xB2\xB2\n\n");

    printf("%-10s %-30s %-30s %-30s %s\n", "id", "Name", "Address", "Specialize","Date");
    printf("-------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("doctor.txt", "rb");
    while(fread(&d, sizeof(d), 1, fp) == 1){
        printf("%-10d %-30s %-30s %-30s %s\n", d.id, d.name, d.address, d.specialize, d.date);
    }

    fclose(fp);
}
void Password(void)
{

   system("cls");

   char ch,pass[10];
   int i=0,j;

printf("  \xB2\xB2\xB2\xB2 Hospital Management System \xB2\xB2\xB2\xB2\n\n");
  printf("    \xB2\xB2\xB2 PASSWORD PROTECTED \xB2\xB2\xB2\n");
   printf("\nEnter Password:\n");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {

	printf("\nPassword match!\n");
    printf("Press any key to countinue.....\n");
	getch();
	mainmenu();

   }
   else
   {

	 printf("\nWarning!! Incorrect Password. \n");
	 getch();
	 Password();
   }
}


