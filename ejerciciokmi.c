#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//cambiar busnum
typedef struct{
	char name[50];
	int esp_num;
    char hora;
}pd;
void reservation(void);
void verespecialidades(void);
void printticket(char name[],int,float);
void specificbus(int);
float charge(int);
void login();
void horario1();
int main()
{
		system("cls");
		system("COLOR 0A");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|          FUNDACION SALUD PARA TODOS           |\n");
	printf("\t\t|               SISTEMA DE CITAS                |\n");
	printf("\t\t|       ---------------------------------       |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n=================================\n");
	printf("SISTEMA DE AGENDAMIENTO DE CITAS");
	printf("\n=================================");
	printf("\n1>> Reserve una cita");
	printf("\n------------------------");
	printf("\n2>> Ver la lista de especialidades");
	printf("\n------------------------");
	printf("\n3>> Salir");
	printf("\n-->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			verespecialidades();
			printf("\n\nPresione cualquier tecla para volver al menu...");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\n Opcion invalida");
	}
	goto start;
	return(0);
}


void verespecialidades(void)
{
	system("cls");
	printf("---------------------------------------------------------------------------------------");
	printf("\nNo.Esp\tEspecialidades\t\tDoctores\t\tCostos\t\tHorario de atencion\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n01.\tMedicina general   \tDr.Tobias Sosa       \t$15    \t\t9:00am-16pm");
	printf("\n02.\tObstetricia            \tDr.Koda Zuniga       \t$15  \t\t9:00am-16pm");
	printf("\n03.\tGinecologia         \tDra.Yeana Viral    \t$15   \t\t9:00am-16pm");
	printf("\n04.\tCardiologia        \tDr.Henry Guerra    \t$15   \t\t9:00am-16pm");
	printf("\n05.\tPediatria          \tDra.Abigail Casas \t$15  \t\t9:00am-16pm");
	printf("\n06.\tOdontologia     \tDr.Derek Shepard \t$15   \t\t9:00am-16pm");
    printf("\n07.\tOftalmologia        \tDra.Meredith Grey   \t$15   \t\t9:00am-16pm");
    printf("\n08.\tLaboratorio        \tDr.Juan P Isaza        \t$15   \t\t9:00am-16pm");
    printf("\n09.\tDermatologia    \tDr.Benito Martinez  \t$15  \t\t9:00am-16pm");
    printf("\n10.\tPsicologia       \tDr.Jh de la Cruz  \t$15  \t\t9:00am-16pm");
    
   
}
void horario1(){
    pd passdetails;
    printf("\nNo.Cita\t\tCostos\t\tHora de la cita\n");
	printf("---------------------------------------------------------------------------------------");
	printf("\n01\t\t$15    \t\t9:00 AM");
    printf("\n02.\t\t$15    \t\t10:00 AM");
    printf("\n03.\t\t$15    \t\t11:00 AM");
    printf("\n04.\t\t$15    \t\t12:00 PM");
    printf("\n05.\t\t$15    \t\t13:00 PM");
    printf("\n06.\t\t$15    \t\t15:00 PM");
    printf("\n05.\t\t$15    \t\t16:00 PM");
    printf("\nIngrese el numero de horario:");
    scanf("%s",&passdetails.hora);

    
}

void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("citasreservadas.txt","w");
	system("cls");
    fp=fopen("citasreservadas.txt","r+");
	printf("\nIngrese el nombre del paciente:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\n\n>>Presiona Enter para ver las especialidades disponibles<< ");
	getch();
	system("cls");
	verespecialidades();
	printf("\n\nIngresa el numero de la especialidad:");
	start1:
	scanf("%d",&passdetails.esp_num);
	if(passdetails.esp_num>=1 && passdetails.esp_num<=10)
	{
		charges=charge(passdetails.esp_num);
		printticket(passdetails.name,passdetails.esp_num,charges);
	}
	else
	{
		printf("\nNumero de especialidad incorrecto, intente de nuevo--> ");
		goto start1;
	}
     switch (passdetails.esp_num)
    {
    case 1:
        horario1();
        break;
    case 2:
        horario1();
        break;
         case 3:
        horario1();
        break;
         case 4:
        horario1();
        break;
         case 5:
        horario1();
        break;
         case 6:
        horario1();
        break;
         case 7:
        horario1();
        break;
         case 8:
        horario1();
        break;
         case 9:
        horario1();
        break;
         case 10:
        horario1();
        break;
    
    default:
     printf("Opcion invalida...");
        break;
    }
    
	printf("\n\nPara confirmar cita escriba 'y', caso contrario escriba 'n':--->");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.esp_num,charges);
		printf("==================");
		printf("\n CITA AGENDADA\n");
		printf("==================");
		printf("\nPresiona cualquier tecla para ir al menu...");
	}
	else
	{
		if(confirm=='n'){
			printf("\n CITA NO AGENDADA!\nPresiona cualquier tecla para ir al menu...");
		}
		else
		{
			printf("\nOpcion incorrecta intente de nuevo... ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int esp_num)
{

	if (esp_num==1)
	
	{
		return(15);
	}
	if (esp_num==2)
	{
		return(15);
	}
	if (esp_num==3)
	{
		return(15);
	}
	if (esp_num==4)
	{
		return(15);
	}
	if (esp_num==5)
	{
		return(15);
	}
	if (esp_num==6)
	{
		return(15);
	}
	if (esp_num==7)
	{
		return(15); 
	}
	if (esp_num==8)
	{
		return(15);
	}
	if (esp_num==9)
	{
		return(15);
	}
	if (esp_num==10)
	{
	    return(15);
	}
}

void printticket(char name[],int esp_num,float charges)
{
	system("cls");
	printf("-------------------\n");
	printf(" DATOS DE LA CITA\n");
	printf("-------------------\n\n");
	printf("Nombre:\t\t\t%s",name);
	printf("\nNro.Esp:\t\t%d",esp_num);
	specificbus(esp_num);
	printf("\nTotal:\t\t\t%.2f",charges);
}


void specificbus(int esp_num)
{

	if (esp_num==1)
	{
		printf("\nEspecialidad:\t\tMedicina general ");
		printf("\nMedico:\t\t\tDr.Tobias Sosa");
		printf("\nHora de la cita:\t9am ");
	}
	if (esp_num==2)
	{
		printf("\nEspecialidad:\t\tObstetricia ");
		printf("\nMedico:\t\t\tDr.Koda Zuniga");
		printf("\nHora de la cita:\t12pm ");
	}
	if (esp_num==3)
	{
		printf("\nEspecialidad:\t\tGinecologia ");
		printf("\nMedico:\t\t\tDra.Yeana Viral");
		printf("\nHora de la cita:\t1:50pm ");
	}
	if (esp_num==4)
	{
		printf("\nEspecialidad:\t\tCardiologia ");
		printf("\nMedico:\t\t\tDr.Henry Guerra");
		printf("\nHora de la cita:\t11am ");
	}
	if (esp_num==5)
	{
		printf("\nEspecialidad:\t\tPediatria ");
		printf("\nMedico:\t\t\tDr.Abigail Casas");
		printf("\nHora de la cita:\t7:05am ");
	}
	if (esp_num==6)
	{
		printf("\nEspecialidad:\t\t\tOdontologia");
		printf("\nMedico:\t\t\tDr.Derek Shepard");
		printf("\nHora de la cita:\t9:30am ");
	}
	if (esp_num==7)
	{
		printf("\nEspecialidad:\t\tOftalmologia ");
		printf("\nMedico:\t\t\tDra.Meredith Grey");
		printf("\nHora de la cita:\t1pm ");
	}
	if (esp_num==8)
	{
		printf("\nEspecialidad:\t\tLaboratorio ");
		printf("\nMedico:\t\t\tDr.Juan P Isaza");
		printf("\nHora de la cita:\t4pm ");
	}
	if (esp_num==9)
	{
		printf("\nEspecialidad:\t\tDermatologia ");
		printf("\nMedico:\t\t\tDr.Benito Martinez");
		printf("\nHora de la cita:\t5:35pm ");
	}
	if (esp_num==10)
	{
		printf("\nEspecialidad:\t\tPsicologia ");
		printf("\nMedico:\t\t\tDr.JH de la Cruz");
		printf("\nHora de la cita:\t4:15pm ");
	}
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
{

    printf("\n  =======================  INICIAR SESION  =======================\n  ");
    printf(" \n                       USUARIO:-");
	scanf("%s", &uname);
	printf(" \n                       CONTRASENA:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,"admin")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n       BIENVENIDO A LA RESERVACION DE CITAS DE LA FUNDACION SALUD PARA TODOS");
	printf("\n\n\n\t\t\t\tPresione cualquier tecla para continuar...");
	getch();
	break;
	}
	else
	{
		printf("\n        DATOS INCORRECTOS, INGRESE DE NUEVO");
		a++;

		getch();
		system("cls");
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nDemasiados intentos fallidos, no se pudo ingresar sesion...");

		getch();

		}
		system("cls");
}
