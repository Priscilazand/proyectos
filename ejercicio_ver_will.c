#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>


int fecha_duplicada();
void ingresar_paciente();
void lista_pacientes();
void eliminar_cita();
void verespecialidades();
void login();



struct patient{
    int cedula;
    char nombre_paciente[50];
    char especialidad[50];
    char fecha_ingreso[12];
    char fecha_cita[13];
    char hora_cita[13];
    int esp_num;
}p;


FILE *fp;

int main(){

    int ch;

    while(1){
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
	printf(" \n Presione cualquier tecla para continuar:");
	getch();
	system("cls");
	login();
    system("cls");
	printf("\n=================================\n");
	printf("SISTEMA DE AGENDAMIENTO DE CITAS");
	printf("\n=================================");
	printf("\n1>> Reserve una cita");
	printf("\n------------------------");
	printf("\n2>> Ver la lista de citas");
	printf("\n------------------------");
    printf("\n3>> Ver la lista de especialidades");
    printf("\n------------------------");
    printf("\n4>> Eliminar citas");
	printf("\n------------------------");
	printf("\n5>> Salir");
	printf("\n-->");

        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            ingresar_paciente();
            break;

        case 2:
            lista_pacientes();
            break;

        case 3:
            verespecialidades();
            break;
        
        case 4:
        	eliminar_cita();

        default:
            printf("Opcion invalida...\n\n");

        }
        printf("\n\nPresiona una tecla para continuar.");
        getch();
    }

    return 0;
}

void ingresar_paciente(){
	char confirm;
	int i=0, flag1=0;
	float charges;
	
	system("cls");
    char mi_Fecha[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(mi_Fecha, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(p.fecha_ingreso, mi_Fecha);

    fp = fopen("patient.txt", "ab");
	printf("\t\t=================================================\n\n\n");
    printf("Ingrese la cedula del paciente:  ");
    scanf("%d", &p.cedula);

    printf("Ingrese Nombre del paciente: ");
    fflush(stdin);
    gets(p.nombre_paciente);
    printf("\n>>Presiona Enter para ver las especialidades disponibles<< ");
	getch();
	system("cls");
	verespecialidades();
	printf("\n-----------------------------------------------------\n");
	
	printf("Ingrese la especialidad: ");
    fflush(stdin);
    gets(p.especialidad);
	
    printf("\n-----------------------------------------------------\n");

    printf("\nIngrese la fecha para la cita: ");
    fflush(stdin);
    gets(p.fecha_cita);
    printf("\n-----------------------------------------------------\n");
    printf("Ingrese la hora para la cita: ");
    fflush(stdin);
    gets(p.hora_cita);
    printf("\nCita Agendada");
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    while(flag1==0){ 
    printf("\nIngrese la fecha para la cita: ");
    fflush(stdin);
    gets(p.fecha_cita);

    
    if(fecha_duplicada("patient.txt") == 0){
    	printf("\nFecha no disponible");
    	
	}else{	
	  printf("Ingrese la hora para la cita: ");
    	fflush(stdin);
    	gets(p.hora_cita);
		printf("\nCita Agendada");
    	fwrite(&p, sizeof(p), 1, fp);
    	fclose(fp);
    	fwrite(&p, sizeof(p), 1, fp);
    	fclose(fp);
        flag1=0;
	}   
   }
    
    
}

void lista_pacientes(){
	system("cls");

    printf("<== Lista de Citas ==>\n\n");
    printf("%-10s %-30s %-20s %-20s %-20s %s\n", "Cedula", "Nombre Paciente", "Especialidad", "Fecha Ingreso", "Fecha cita", "Hora cita");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    fp = fopen("patient.txt", "rb");
    while(fread(&p, sizeof(p), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-20s %-20s %s\n", p.cedula, p.nombre_paciente, p.especialidad, p.fecha_ingreso, p.fecha_cita, p.hora_cita);
    }

    fclose(fp);
}


void eliminar_cita(){
	system("cls");
    int id, f=0;
    system("cls");
    printf("<== Eliminar Citas ==>\n\n");
    printf("Ingrese la cedula del paciente: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("patient.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.cedula){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        } 
    }

    if(f==1){
        printf("\n\nCITA ELIMINADA");
    }else{
        printf("\n\nCita no existe el registro !");
    }

    fclose(fp);
    fclose(ft);

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

}



int fecha_duplicada(const char* file_name ) {
	
    struct patient buffer[100];
    int count = 0;
    FILE* file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: no se pudo abrir el archivo %s\n", file_name);
        return -1;
    }
    while (fread(&buffer[count], sizeof(struct patient), 1, file)) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(buffer[i].fecha_cita, buffer[j].fecha_cita) == 0) {
                
                return 1;
            }
            else{
            	return 0;
			}
        }
    }

}
void verespecialidades(void)
{
	system("cls");
	printf("------------------------------------------------------------------------------------------------");
	printf("\nNo.Esp\tEspecialidades\t\t\tDoctores\t\tCostos\t\tHora de la cita\n");
	printf("------------------------------------------------------------------------------------------------");
	printf("\n01.\tMedicina general   \t\tDr.Tobias Sosa       \t$15    \t\t9:00  AM ");
	printf("\n02.\tObstetricia            \t\tDr.Koda Zuniga       \t$15  \t\t12:00 PM ");
	printf("\n03.\tGinecologia         \t\tDra.Yeana Viral    \t$15   \t\t1:50  PM ");
	printf("\n04.\tCardiologia        \t\tDr.Henry Guerra    \t$15   \t\t11:00 AM ");
	printf("\n05.\tPediatria          \t\tDra.Abigail Casas \t$15  \t\t7:05  AM ");
	printf("\n06.\tOdontologia     \t\tDr.Derek Shepard \t$15   \t\t9:30  AM ");
    printf("\n07.\tOftalmologia        \t\tDra.Meredith Grey   \t$15   \t\t1:00  PM");
    printf("\n08.\tLaboratorio        \t\tDr.Juan P Isaza        \t$15   \t\t4:00  PM");
    printf("\n09.\tDermatologia    \t\tDr.Benito Martinez  \t$15  \t\t5:35  PM");
    printf("\n10.\tPsicologia       \t\tDr.Jh de la Cruz  \t$15  \t\t4:15  PM");

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
	    
 