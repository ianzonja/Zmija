#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

void ispis(char polje[][10]){
	cout<<" ============================"<<endl;
	for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(j == 0) cout<<"| "<<polje[i][j]<<" "<" ";
				if(j == 9) cout<<polje[i][j]<<" |"<<endl;
				if(j != 0 && j != 9) cout<<polje[i][j]<<" "<<" ";
			}
		}
	cout<<" ============================="<<endl;
}
int main(){
	int pozicijaX;
    int pozicijaY;
    int starapozX;
    int starapozY;
	int zmija[50];
    int zmijaI = 1;
    int pamtiX[50];
    int pamtiY[50];
     char polje[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            polje[i][j] = ' ';
            }
        }
              
    int X=3;
    int Y=3;
    int zivot=1;
    srand(time(NULL));
    int hrX;
    int hrY;
    hrX=rand()%5+1;
    hrY=rand()%5+1;
    char hrana='x';
    polje[hrX][hrY] = hrana;
              
    
	while(zivot==1){
              
        pamtiX[0] = X; //pozicija glave
        pamtiY[0] = Y;
              
        char ch; //character koji je unesen
        if(kbhit()!=0){
            ch=getch();
        }
              
        
              
        if(ch=='a'){
            Y--;
            polje[X][Y+1]=' ';
            starapozX = X;
            starapozY = Y+1;	
        }
        else if(ch=='d'){
            Y++;
            polje[X][Y-1]=' ';
            starapozX = X;
            starapozY = Y-1;
        }
        else if(ch=='w'){
            X--;
            polje[X+1][Y]=' ';
            starapozX = X+1;
            starapozY = Y;
        }
		else if(ch=='s'){
            X++;
            polje[X-1][Y]=' ';
            starapozX = X-1;
            starapozY = Y;
        }
		if(polje[X][Y] == 'o' || X > 9 || X < 0 || Y > 9 || Y <0){
            cout<<"KRAJ IGRE!"<<endl;
            system("pause");
        }
                   
        zmija[0] = 'O'; 
        polje[X][Y]=zmija[0];
              
              
        //mehanika elemenata
        for(int i=1; i<zmijaI; i++){
            polje[starapozX][starapozY] = zmija[i]; //element prelazi na praznu poziciju koju je napustio prijasnji element
            pozicijaX = pamtiX[i]; //zapamti staru poziciju tog elementa
            pozicijaY = pamtiY[i];
            polje[pozicijaX][pozicijaY] = ' '; //izbrisi staru poziciju iduceg elementa
            pamtiX[i] = starapozX; //pamti novu poziciju tog elementa
            pamtiY[i] = starapozY;
            starapozX = pozicijaX; //pamti staru poziciju elementa kako bi na nju dosao iduci element
            starapozY = pozicijaY;
        }
              
        //stvaranje novog elementa ako je pojedeno
        if(polje[X][Y] == polje[hrX][hrY]){
            do{
                hrX = rand()%9+1;
                hrY = rand()%9+1;
                }while(polje[hrX][hrY] != ' ');
            polje[hrX][hrY] = hrana;
            zmija[zmijaI] = 'o';
            polje[starapozX][starapozY] = zmija[zmijaI]; //postavi novi element na praznu poziciju ispred glave
            pamtiX[zmijaI] = starapozX; //zapamti koordinate novom elementu
            pamtiY[zmijaI] = starapozY;
            zmijaI++;
            }
        ispis(polje);                
        Sleep(0);
        system("cls");
    }
}

