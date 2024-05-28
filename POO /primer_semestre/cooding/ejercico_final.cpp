# include <stdio.h>
# include <conio.h>
# include <String.h>
# include <fstream>
using namespace std;
class Archivo{
public:
char cve[6], nom[16];
int pre;
public :
Archivo(char p_cve[6], char p_nom[16], int p_pre){
strcpy(cve,p_cve);
strcpy(nom,p_nom);
pre=p_pre;
}
Archivo(){
// Vacío
}
void despliega(){
printf("Clave = %s\n",cve);
printf("Nombre = %s\n",nom);
printf("Precio = %d\n",pre);
getche();
}
void graba(){
ofstream arch;
arch.open("productos.csv",ios::app);
arch <<cve<<","<<nom<<","<<pre<<"\n";
arch.close();
}
void busca_rec(char *buf, char cve[6]){
bool existe;
ifstream arch;
arch.open("productos.csv",ios::in);
existe=false;
while (!arch.eof()){
arch >>buf;
if (strnicmp(buf,cve,5)==0){
existe=true;
break;
}
}
if (!existe) strcpy(buf,"XXX");
}
void listado(){
char cad[30], *token, cve[6], nom[16],pre[5];
for (int i=0;i<=40;i++) printf("\n");
printf("Clave Nombre Precio\n");
printf("------------------------------\n");
// 12345 123456789012345 1234
ifstream arch;
arch.open("productos.csv",ios::in);
while (!arch.eof()){
arch >>cad;
if (!arch.eof()){
token=strtok(cad,","); strcpy(cve,token);
token=strtok(NULL,","); strcpy(nom,token);
token=strtok(NULL,","); strcpy(pre,token);
printf("%s ",cve);
for (int i=0;i<strlen(nom);i++) if (nom[i]=='_') nom[i]='
';
printf("%s ",nom); for(int i=strlen(nom);i<=15;i++)
printf(" ");
printf("%s\n",pre);
}
}
arch.close();
getche();
}
};
void altas(){
char cve[6], nom[16];
int pre;
for (int i=0;i<=40;i++) printf("\n");
while (true){ // Pide y valida la matrícula
printf("Indica la clave del producto : "); gets(cve);
strupr(cve);
if ((strlen(cve)!=5) || (cve[0]!='P') || (cve[1]!='0')){
printf("Error, la clave debe estar en el formato \"P0999\"\n");
getche();
}
else break;
}
while (true){ // Pide y valida el nombre
printf("Indica el nombre del producto : "); gets(nom);
if ((strlen(nom)<1) || (strlen(nom)>15)){
printf("Error, el nombre debe tener entre 1 y 15 caracteres\n");
getche();
}
else break;
}
while (true){ // Pide y valida el precio
printf("Indica el precio del producto : "); scanf("%d",&pre);
if ((pre<1) || (pre>1000)){
printf("Error, el precio debe estar entre 1 y 1,000 pesos\n");
getche();
}
else break;
}
for (int i=0;i<strlen(nom);i++) if (nom[i]==' ') nom[i]='_';
Archivo obj(cve, nom, pre);
obj.graba();
}
void consultas(){
char cad[30], cve[6];
char *token, nom[16], pre[5];
printf("Indica la clave a consultar : "); gets(cve);
Archivo obj;
obj.busca_rec(cad,cve);
if (strcmp(cad,"XXX")==0){
printf("Error, clave de producto inexistene en archivo\n");
getche();
}
else{
token=strtok(cad,",");
token=strtok(NULL,","); strcpy(nom,token);
token=strtok(NULL,","); strcpy(pre,token);
printf("Clave : %s\n",cve);
printf("Nombre : %s\n",nom);
printf("Precio : %s\n",pre);
getche();
}
}
void menu(){
int op;
char falso[2];
while (op!=4){
for (int i=0;i<=40;i++) printf("\n");
printf("1) Alta de productos\n");
printf("2) Consulta de productos\n");
printf("3) Lista de productos\n");
printf("4) Terminar\n");
printf("Indica la opci%cn deseada : ",162);scanf("%d",&op);
gets(falso);
if (op==1) altas();
if (op==2) consultas();
if (op==3){
Archivo obj;
obj.listado();
}
}
}
main(){
menu();
}
