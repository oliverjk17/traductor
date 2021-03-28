#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstring>
#define s 150

using namespace std;

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void cambiarcolor(int X)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}
void fondo()
{
    system("COLOR f3");
}

void co(int, int);
const char *nombe_archivo = "traduc7.dat";
const char *nom_temporal = "tempo8.dat";

struct Traducir
{

    char palabra[s];
    char traduccion[s];
    char funcionalidad[s];
    int codigo;
};
void eliminar33();

void ingresar_palabra();
void mostrar_palabra();
void control();
void modificar_palabra();
void comparar();
void multilineas();

void marco(){	
int z=241;	
for(int i=0; i <= 29;  i++){	
gotoxy(117,i);co(1,z); //y
}
for(int i=1; i <= 29;  i++){
gotoxy(1,i);co(1,z);//-y
}
for(int i=1; i <= 115;  i++){
gotoxy(i,0);co(1,z);//x
}
for(int i=1; i <= 115;  i++){
gotoxy(i,29);co(1,z);//x
}
}

void multilineas(string& texto, string buscar,string restituir){
    int pos= texto.find(buscar);
	while (pos != -1){
		
		texto.replace(pos,buscar.size(),restituir);
		pos = texto.find((buscar),+(co(0,240),restituir.size()));
	}
}

int main()
{
    control();
}

void control()
{
    int a, b, c;
    do
    {
        fondo();
        system("cls");
        marco();
        co(0, 241);
        gotoxy(25, 3);
        cout << ("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같");
        gotoxy(25, 4);
        cout << ("같               M E N U       D  E      O P C I O N E S            같");
        gotoxy(25, 5);
        cout << ("같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같같");
        
        gotoxy(46, 11);
        cout << ("_____________________________");
        gotoxy(46, 12);
        cout <<"|  "<< (" 1. Insertar  Palabra    |");
        gotoxy(46, 13);
        cout <<"|  "<< (" 2. Ver Datos            |");
        gotoxy(46, 14);
        cout <<"|  "<< (" 3. Eliminar Palabra     |");
        gotoxy(46, 15);
        cout <<"|  "<< (" 4. Usar Diccionario     |");
        gotoxy(46, 16);
        cout <<"|  "<< (" 5. Multilineas          |");
        gotoxy(46, 17);
        cout <<"|  "<< (" 6. Modificar Palabra    |");
        gotoxy(46, 18);
        cout <<"|  "<< (" 7. Salir                |");
        gotoxy(46, 19);
        cout<<("|___________________________|");
       
	    gotoxy(45, 25);
       
	    cout << ("Ingrese opcion: ");
        cin >> a;
        switch (a)
        {
        case 1:
            system("cls");
            ingresar_palabra();
            break;
        case 2:
            system("cls");
            mostrar_palabra();
            break;
        case 3:
            system("cls");
            eliminar33();
            break;
        case 4:
            system("cls");
            comparar();
            break;

        case 5:
            system("cls");
            multilineas();
            break;
        
        
        case 6:
            system("cls");
            modificar_palabra();
            break;
		}
    } while (a!=7);
}

void ingresar_palabra()
{
    char continuar;
    FILE *archivo = fopen(nombe_archivo, "ab"); // ab
    Traducir traductor;
    string palabra, traduccion, funcionalidad;
    do
    {
     
        system("cls");
        gotoxy(20, 2);
        cout << ("__________________________________________________________________________________");
        gotoxy(20, 3);
        cout << ("|                    R E G I S T R A R          P A L A B R A                     |");
        gotoxy(20, 4);
        cout << ("|_________________________________________________________________________________|");

        fflush(stdin);
        traductor.codigo = 0;
        traductor.codigo = traductor.codigo + 1;
        gotoxy(20, 10);
        cout << "-------------------------------------------------------------------------------------";
        gotoxy(20, 11);
        cout << "Ingrese palabra: ";
        getline(cin, palabra);
        strcpy(traductor.palabra, palabra.c_str());
        gotoxy(20, 13);
        cout << "-------------------------------------------------------------------------------------";
        gotoxy(20, 14);
        cout << "Ingrese traduccion: ";
        getline(cin, traduccion);
        strcpy(traductor.traduccion, traduccion.c_str());
        gotoxy(20, 17);
        cout << "-------------------------------------------------------------------------------------";
        gotoxy(20, 18);
        cout << "Ingrese Funcionalidad: ";
        getline(cin, funcionalidad);
        strcpy(traductor.funcionalidad, funcionalidad.c_str());

        fwrite(&traductor, sizeof(Traducir), 1, archivo);

        gotoxy(20, 25);
        cout << "Desea Agregar otro Palabra s/n : ";
        cin >> continuar;
    } while ((continuar == 's') || (continuar == 'S'));
    fclose(archivo);
    system("cls");
}

void modificar_palabra()
{
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id;
    char respuesta[s],d;
    string palabras, traduccions, funcionalidads;
    Traducir traductor;
system("cls");
    gotoxy(20, 2);
        cout << ("__________________________________________________________________________________");
        gotoxy(20, 3);
        cout << ("|                   M O D I F I C A R           P A L A B R A                     |");
        gotoxy(20, 4);
        cout << ("|_________________________________________________________________________________|");
        gotoxy(20, 7);
        cout << "Ingrese el ID que desea Modificar: ";
    cin >> id;
    fseek(archivo, id * sizeof(Traducir), SEEK_SET); // esto es lo que permite modificar en la pocision
    fread(&traductor, sizeof(Traducir), 1, archivo);

    gotoxy(25, 10);
    cout << ("-----------------------   Datos Encontrados ------------------------");
    gotoxy(25, 11);
    cout << ("Palabra:  ") << traductor.palabra;
    gotoxy(25, 12);
    cout << ("Traduccion:  ") << traductor.traduccion;
    gotoxy(25, 13);
    cout << ("Funcionalidad:  ") << traductor.funcionalidad;
    gotoxy(25, 14);
    cout << ("--------------------------------------------------------------------");

    co(0,242); cout << "<\n\npalabra: " << traductor.palabra << endl;
    cout << ("Desea modificar la palabra [s/n]: ");
    cin >> respuesta, s;

    if (strcmp(respuesta, "s") == 0)
    {

        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();
        cout << ("Nueva palabra : ");
        getline(cin, palabras);
        strcpy(traductor.palabra, palabras.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }

    co(0,242);cout << "\n\nTraduccion: " << traductor.traduccion << endl;
    cout << ("Desea modificar la traduccion [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();
        cout << "Ingrese nueva traduccion: ";
        getline(cin, traduccions);
        strcpy(traductor.traduccion, traduccions.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }

    co(0,242);cout << "\n\nFuncionalidad: " << traductor.funcionalidad << endl;
    cout << ("Desea modificar la funcionalidad [s/n]: ");
    cin >> respuesta, s;
    if (strcmp(respuesta, "s") == 0)
    {
        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        cin.ignore();

        cout << "Ingrese nueva funcionalidad: ";
        getline(cin, funcionalidads);
        strcpy(traductor.funcionalidad, funcionalidads.c_str());
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
    }
    cout << ("\n\n\t\t\tDatos actualizados!!");
    fclose(archivo);
    getch();
mostrar_palabra();
 cout<<("Desea volver a repetirlo [s/n]:");
    cin>>d;
    if ((d=='s')||(d == 'S')){
modificar_palabra();
    }else{
       control(); 
    }
}


void mostrar_palabra()
{
    system("cls");
    FILE *archivo = fopen(nombe_archivo, "rb");
    if (!archivo)
    {
        archivo = fopen(nombe_archivo, "w+b");
    }

    Traducir traductor;
    int registro = 0;
    fread(&traductor, sizeof(Traducir), 1, archivo);
        gotoxy(20, 2);
        cout << ("__________________________________________________________________________________");
        gotoxy(20, 3);
        cout << ("|                    P A L A B R A S       G U A R D A D A S                      |");
        gotoxy(20, 4);
        cout << ("|_________________________________________________________________________________|");
       
    
    cout << "\n\n_______________________________________________________________________________________________________________________" << endl;
    cout << " id |"<< "  PALABRA\t|"<< "\tTRADUCCION\t |" << "\tFUNCIONALIDAD" << endl;

    do
    {
  cout << "_______________________________________________________________________________________________________________________" << endl;
        cout << registro << "   |"<< traductor.palabra << "\t|" << traductor.traduccion << " \t|" << traductor.funcionalidad << endl;

        fread(&traductor, sizeof(Traducir), 1, archivo);
        registro += 1;

    } while (feof(archivo) == 0);

    cout << endl;
getch();
    fclose(archivo);
    
}

void comparar(){
char continuar;
int comparacion,error = 0;
Traducir traductor;
    FILE *busqueda = fopen(nombe_archivo, "rb");
    char palabra[40]; //buscar dato

   	system("cls");
	gotoxy(20, 5);
    cout << "Buscar Palabra: ";
    cin >> palabra;

    while (!feof(busqueda))
    {
        fread(&traductor, sizeof(Traducir), 1, busqueda);

        comparacion = strcmp(palabra, traductor.palabra);

        if (comparacion == 0)
        {
            gotoxy(30, 8);
            cout << "Datos Encontrados";
            gotoxy(20, 12);
            cout << "palabra:  " << traductor.palabra;
            gotoxy(20, 13);
            cout << ("------------------------------------------------------------------------");
            gotoxy(20, 15);
            cout << "Traduccion:  " << traductor.traduccion;
            gotoxy(20, 16);
            cout << ("------------------------------------------------------------------------");
            gotoxy(20, 18);
            cout << "Funcionalidad:  " << traductor.funcionalidad;
            gotoxy(20, 19);
            cout << ("------------------------------------------------------------------------");
            error = 1;
            break;
        }
    } 
	
    if (error == 0)
    {
       gotoxy(25,22);cout<< "Error! Palabra no registrada en el archivo";
    }
gotoxy(22,23);cout<<("Desea Volver a intentarlo [s/n]: ");
cin>>continuar;
if((continuar=='s')||(continuar=='S')){
comparar();
}else{
control();	
}
fclose(busqueda);
}

void co(int x, int c)
{
    cambiarcolor(c);
    int i;
    for (i = 1; i <= x; i++)
    {
        cout << char(219) << char(219);
    }
}

void multilineas(){
	
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	string texto,x,y;
	char f;
	Traducir traductor;
	gotoxy(20,1);cout<<("******************************************************************");
	gotoxy(20,2);cout<<("**          T R A D U C C I O N       M U L T I L I N E A S    	**");
    gotoxy(20,3);cout<<("__________________________________________________________________");
    cout<<"\n\nIngrese codigo : \n";
    cout<<"(Al terminar precione tab y enter para la traduccion) \n";
	getline(cin,texto,'\t');
	fread(&traductor,sizeof(Traducir),1,archivo);	
	do{
	co(0,240);
	x=traductor.palabra;
	y=traductor.traduccion;
	multilineas(texto, x, y);
	fread ( &traductor, sizeof(Traducir), 1, archivo );
	} while (feof( archivo ) == 0);
	cout<<"\n\n-----------------           T  R A D U C C I O N               -----------------\n";
	co(0,242);cout<<texto<<endl;

	cout<<("Desea vover a traducir [s/n]: ");
	cin>>f;
	if((f=='s')||(f=='S')){
	multilineas();
	}else{
    cout<<("\n\t\t Adios Crack :)");	
	control();
	}
fclose(archivo);

}

void eliminar33()
{
     Traducir traductor;
    FILE *temporal = fopen(nom_temporal, "w+b");
    FILE *archivo = fopen(nombe_archivo, "r+b");
    int id = 0, r = 0,pe=0;
    char respuesta, p;
    gotoxy(20, 2);
    cout << ("__________________________________________________________________________________");
    gotoxy(20, 3);
    cout << ("|                      E L I M I N A R         P A L A B R A                      |");
    gotoxy(20, 4);
    cout << ("|_________________________________________________________________________________|");

    gotoxy(25,8);cout << "Ingrese el codigo del registro que desea eliminar: ";
    cin >> id;
    
    gotoxy(20, 11);
    cout << "--------------------------- [   " << id << "   ]-----------------------------";
    fseek(archivo, id * sizeof(Traducir), SEEK_SET);
    fread(&traductor, sizeof(Traducir), 1, archivo);
    gotoxy(45, 8);
    cout << "Datos Encontrados";
    gotoxy(20, 12);
    cout << "palabra:  " << traductor.palabra;
    gotoxy(20, 13);
    cout << ("-----------------------------------------------------------------");
    gotoxy(20, 15);
    cout << "Traduccion:  " << traductor.traduccion;
    gotoxy(20, 16);
    cout << ("-----------------------------------------------------------------");
    gotoxy(20, 18);
    cout << "Funcionalidad:  " << traductor.funcionalidad;
    gotoxy(20, 19);
    cout << ("-----------------------------------------------------------------");

    gotoxy(20, 24);
    cout << ("Desea eliminarlo [s/n]: ");
    cin >> respuesta;
    if ((respuesta=='s')||(respuesta=='S'))
    {
        fseek(archivo, id * sizeof(Traducir), SEEK_SET);
        traductor.codigo = -1;
        fwrite(&traductor, sizeof(Traducir), 1, archivo);
        fclose(archivo);

        archivo = fopen(nombe_archivo, "r+b");

        fread(&traductor, sizeof(Traducir), 1, archivo);
        temporal = fopen(nom_temporal, "a+b");
        do
        {
            if (traductor.codigo == -1){
                cout << ("\n\n\t\t\t\tRegistro eliminado");
                getch();
            }
            if (traductor.codigo >= 0)
            {
                fwrite(&traductor, sizeof(Traducir), 1, temporal);
            }
            fread(&traductor, sizeof(Traducir), 1, archivo);
        } while (feof(archivo) == 0);
        fclose(temporal);
        fclose(archivo);

        archivo = fopen(nombe_archivo, "w");
        fclose(archivo);

        temporal = fopen(nom_temporal, "r+b");

        fread(&traductor, sizeof(Traducir), 1, temporal);
        archivo = fopen(nombe_archivo, "a+b");
        do
        {
            fwrite(&traductor, sizeof(Traducir), 1, archivo);
            fread(&traductor, sizeof(Traducir), 1, temporal);
        } while (feof(temporal) == 0);
        fclose(archivo);
        fclose(temporal);
        mostrar_palabra();
    }
    else
    {
        cout << ("Adios crack!!!");
        getch();
        control();
    }

    cout << ("\n\n\t\t\tDesea volver a eliminar? [s/n]: ");
    cin >> p;
    if ((p == 's')||(p == 'S'))
    {
        eliminar33();
    }
    else
    {
        control();
    }
}

