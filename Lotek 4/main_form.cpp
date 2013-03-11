//---------------------------------------------------------------------------
/*                            !!!!UWAGA!!!!

Podczas czyczczenia przyciskiem "C" nie udalo sie zrealizowac zamieniania
Font->Color we wszystkich BitBtn'ach na czarny w petli, tylko poprzez zmiane
we wszystkich po koleji co dosyc brzydko wyglda w kodzie. Najprawdopodobniej
nalezy sie do tych buttonow odwolywac poprzez ich uchwyt HWND ale niestety po
2h prob nie udalo mi sie tego zrealizowac (nie probowalem przez HWND ale przez
kontrolki - moze dlatego) :-( Mozna byloby sie jakiego guru zappytac jak to
zrobic ;-P...
Podobnie jest z obsluga przyciskow z numerkami - dla kazdego osobna instrukcja...
No ale klawiaturka z numerami jest, a obsluga tych instrukcji jest b. szybka...
*/


//------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "main_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool klawiatura[50];
int ilosc=0;

struct liczby
 {
  int l[6]; //losowane
  int w[6]; //wytypowane

 } losowanie;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
for (int i=0; i<50; i++)
 klawiatura[i]=False;

for (int i=0; i<6; i++)
 {
  losowanie.l[i]=0;
  losowanie.w[i]=0;
 }

}
FILE *winner;
FILE *stats; //Plik przechowywujacy czestotliwosc wystapien numerkow w czesie losowan

TColor Add (char nr[2])   // Ta funkcja jest wywolywana jak klikniemy na jakis przycisk
{


TColor temp=clBlack;      //robimy sobie zmienna przechowujaca kolor (czcionki na przycisku)
int pozycja=atoi(nr);    //pozycja to mumerek ktory wzielismy z tekst opisujacego przycisk

  klawiatura[pozycja]=!klawiatura[pozycja]; //w tablicy klawiatura[pozycja] zmieniamy zmienna boolowska na przeciwna
                                            // czyli jesli byla false (pierwotnie) to na true, a jesli odwrotnie to odwrotnie :)
                                            //Jesli jest true to oznacza ze chcemy by [pozycja] oznaczala nasz wybrany numerek
   if (klawiatura[pozycja]) // jesli jest true
   {
    ilosc++; // zwiekszamy zmienna opisujaca ilosc wybranych aktualnie numerkow
    temp=clRed; // i zmieniamy kolor na czzerwony
   }

   if (!klawiatura[pozycja]) //jak jest na false
   {
    ilosc--;     //to zmniejszamy wspomniana zmienna
    temp=clWindowText; //i dajemy czarny kolor
   }
return temp; //zwaracamy kolor
}










//---------------------------------------------------------------------------

void __fastcall TForm1::Zakonczpraceprogramu1Click(TObject *Sender)
{
Application->Terminate();
}

void CZYSC()
{

for (int i=1; i<=Form1->StringGrid1->RowCount; i++)
 {
  Form1->StringGrid1->Cells[0][i]="";
  Form1->StringGrid1->Cells[1][i]="";
 }

 ilosc=0;

for (int i=0; i<6; i++)
 {
  losowanie.l[i]=0;
  losowanie.w[i]=0;
 }

for (int i=0; i<50; i++)
 klawiatura[i]=false;

Form1->BitBtn1->Font->Color=clBlack;
Form1->BitBtn2->Font->Color=clBlack;
Form1->BitBtn3->Font->Color=clBlack;
Form1->BitBtn4->Font->Color=clBlack;
Form1->BitBtn5->Font->Color=clBlack;
Form1->BitBtn6->Font->Color=clBlack;
Form1->BitBtn7->Font->Color=clBlack;
Form1->BitBtn8->Font->Color=clBlack;
Form1->BitBtn9->Font->Color=clBlack;
Form1->BitBtn10->Font->Color=clBlack;

Form1->BitBtn11->Font->Color=clBlack;
Form1->BitBtn12->Font->Color=clBlack;
Form1->BitBtn13->Font->Color=clBlack;
Form1->BitBtn14->Font->Color=clBlack;
Form1->BitBtn15->Font->Color=clBlack;
Form1->BitBtn16->Font->Color=clBlack;
Form1->BitBtn17->Font->Color=clBlack;
Form1->BitBtn18->Font->Color=clBlack;
Form1->BitBtn19->Font->Color=clBlack;
Form1->BitBtn20->Font->Color=clBlack;

Form1->BitBtn21->Font->Color=clBlack;
Form1->BitBtn22->Font->Color=clBlack;
Form1->BitBtn23->Font->Color=clBlack;
Form1->BitBtn24->Font->Color=clBlack;
Form1->BitBtn25->Font->Color=clBlack;
Form1->BitBtn26->Font->Color=clBlack;
Form1->BitBtn27->Font->Color=clBlack;
Form1->BitBtn28->Font->Color=clBlack;
Form1->BitBtn29->Font->Color=clBlack;
Form1->BitBtn30->Font->Color=clBlack;

Form1->BitBtn31->Font->Color=clBlack;
Form1->BitBtn32->Font->Color=clBlack;
Form1->BitBtn33->Font->Color=clBlack;
Form1->BitBtn34->Font->Color=clBlack;
Form1->BitBtn35->Font->Color=clBlack;
Form1->BitBtn36->Font->Color=clBlack;
Form1->BitBtn37->Font->Color=clBlack;
Form1->BitBtn38->Font->Color=clBlack;
Form1->BitBtn39->Font->Color=clBlack;
Form1->BitBtn40->Font->Color=clBlack;

Form1->BitBtn41->Font->Color=clBlack;
Form1->BitBtn42->Font->Color=clBlack;
Form1->BitBtn43->Font->Color=clBlack;
Form1->BitBtn44->Font->Color=clBlack;
Form1->BitBtn45->Font->Color=clBlack;
Form1->BitBtn46->Font->Color=clBlack;
Form1->BitBtn47->Font->Color=clBlack;
Form1->BitBtn48->Font->Color=clBlack;
Form1->BitBtn49->Font->Color=clBlack;
}



//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn50Click(TObject *Sender)
{
CZYSC();
}




//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
BitBtn2->Font->Color=Add(BitBtn2->Caption.c_str());        
/* Jesli nacisnelismy przycisk to wykonywana jest wczesniej opisana funkcja add i
kolor czcionki danego przycisku jest zmieniony na taki jaki zwrocila wpsomniana f-cja*/
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
BitBtn3->Font->Color=Add(BitBtn3->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
BitBtn4->Font->Color=Add(BitBtn4->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
BitBtn5->Font->Color=Add(BitBtn5->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
BitBtn6->Font->Color=Add(BitBtn6->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
BitBtn7->Font->Color=Add(BitBtn7->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
BitBtn8->Font->Color=Add(BitBtn8->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
BitBtn9->Font->Color=Add(BitBtn9->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
BitBtn10->Font->Color=Add(BitBtn10->Caption.c_str());        
}
void __fastcall TForm1::BitBtn11Click(TObject *Sender)
//---------------------------------------------------------------------------
{
BitBtn11->Font->Color=Add(BitBtn11->Caption.c_str());




}

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn12Click(TObject *Sender)
{
BitBtn12->Font->Color=Add(BitBtn12->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn13Click(TObject *Sender)
{
BitBtn13->Font->Color=Add(BitBtn13->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn14Click(TObject *Sender)
{
BitBtn14->Font->Color=Add(BitBtn14->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn15Click(TObject *Sender)
{
BitBtn15->Font->Color=Add(BitBtn15->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn16Click(TObject *Sender)
{
BitBtn16->Font->Color=Add(BitBtn16->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn17Click(TObject *Sender)
{
BitBtn17->Font->Color=Add(BitBtn17->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn18Click(TObject *Sender)
{
BitBtn18->Font->Color=Add(BitBtn18->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn19Click(TObject *Sender)
{
BitBtn19->Font->Color=Add(BitBtn19->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn20Click(TObject *Sender)
{
BitBtn20->Font->Color=Add(BitBtn20->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn22Click(TObject *Sender)
{
BitBtn22->Font->Color=Add(BitBtn22->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn23Click(TObject *Sender)
{
BitBtn23->Font->Color=Add(BitBtn23->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn24Click(TObject *Sender)
{
BitBtn24->Font->Color=Add(BitBtn24->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn25Click(TObject *Sender)
{
BitBtn25->Font->Color=Add(BitBtn25->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn26Click(TObject *Sender)
{
BitBtn26->Font->Color=Add(BitBtn26->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn27Click(TObject *Sender)
{
BitBtn27->Font->Color=Add(BitBtn27->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn28Click(TObject *Sender)
{
BitBtn28->Font->Color=Add(BitBtn28->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn29Click(TObject *Sender)
{
BitBtn29->Font->Color=Add(BitBtn29->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn30Click(TObject *Sender)
{
BitBtn30->Font->Color=Add(BitBtn30->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn32Click(TObject *Sender)
{
BitBtn32->Font->Color=Add(BitBtn32->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn33Click(TObject *Sender)
{
BitBtn33->Font->Color=Add(BitBtn33->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn34Click(TObject *Sender)
{
BitBtn34->Font->Color=Add(BitBtn34->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn35Click(TObject *Sender)
{
BitBtn35->Font->Color=Add(BitBtn35->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn36Click(TObject *Sender)
{
BitBtn36->Font->Color=Add(BitBtn36->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn37Click(TObject *Sender)
{
BitBtn37->Font->Color=Add(BitBtn37->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn38Click(TObject *Sender)
{
BitBtn38->Font->Color=Add(BitBtn38->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn39Click(TObject *Sender)
{
BitBtn39->Font->Color=Add(BitBtn39->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn40Click(TObject *Sender)
{
BitBtn40->Font->Color=Add(BitBtn40->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn42Click(TObject *Sender)
{
BitBtn42->Font->Color=Add(BitBtn42->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn43Click(TObject *Sender)
{
BitBtn43->Font->Color=Add(BitBtn43->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn44Click(TObject *Sender)
{
BitBtn44->Font->Color=Add(BitBtn44->Caption.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn45Click(TObject *Sender)
{
BitBtn45->Font->Color=Add(BitBtn45->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn46Click(TObject *Sender)
{
BitBtn46->Font->Color=Add(BitBtn46->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn47Click(TObject *Sender)
{
BitBtn47->Font->Color=Add(BitBtn47->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn48Click(TObject *Sender)
{
BitBtn48->Font->Color=Add(BitBtn48->Caption.c_str());        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn49Click(TObject *Sender)
{
BitBtn49->Font->Color=Add(BitBtn49->Caption.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
BitBtn1->Font->Color=Add(BitBtn1->Caption.c_str());
}

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn31Click(TObject *Sender)

{
BitBtn31->Font->Color=Add(BitBtn31->Caption.c_str());
}        

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn41Click(TObject *Sender)
{
BitBtn41->Font->Color=Add(BitBtn41->Caption.c_str());
}

void __fastcall TForm1::BitBtn21Click(TObject *Sender)
{
BitBtn21->Font->Color=Add(BitBtn21->Caption.c_str());
}
//---------------------------------------------------------------------------

void losuj()
{

int temp;
bool duplikat;

randomize(); //generator liczb losowych
for (int i=0; i<6; i++)
        {
         temp=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
          duplikat=False;  // Zakladamy ze nie istnieje

           for (int j=0; j<6; j++)  //Dla kazdego elementu tej tablicy
           if (losowanie.l[j]==temp) duplikat=true;    //Jesli liczba jest rowna temu elementowi to znaczy ze mamy duplikat

             if (duplikat) i--; else  //Jesli mamy duplikat to jeszcze raz losujemy
              losowanie.l[i]=temp; //A jesli nie to mozemy do tablicy z wylosowanymi liczbami dopisac temp'a (czyli wylosowana obecnie liczbe)
         }



}




void __fastcall TForm1::Losuj1Click(TObject *Sender)
{
if (ilosc==6){

StringGrid1->RowCount=7;
StringGrid1->Cells[0][0]="[Obstawione]";
StringGrid1->Cells[1][0]="[Wylosowane]";

int counter = 0;
losuj();


// poczatek sortowania
int x[6];
for (int i=0; i<6; i++)
x[i] = losowanie.l[i];
int pom;
for (int i=0; i<6; i++)
{
        int j=i;
        while(j>0 && x[j-1] > x[j])
        {
                pom=x[j];
                x[j]=x[j-1];
                x[j-1]=pom;
                j--;
        }
}
for (int i=0; i<6; i++)
losowanie.l[i]=x[i] ;
// koniec sortowania

for (int i=1; i<50; i++)
if (klawiatura[i])
 {
 losowanie.w[counter]=i;

 StringGrid1->Cells[0][++counter]=i;
 StringGrid1->Cells[1][counter]=losowanie.l[counter];
 }


int statystyki[50];



stats=fopen("stats.txt","r+"); //Otwieramy plik statystyk
fread(&statystyki,sizeof(statystyki),1,stats);  //Zczytujemy tablice z czestotliwosciami
   fclose(stats);                                  //Zamykamy plik

   for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
     statystyki[losowanie.l[i]]=statystyki[losowanie.l[i]]+1;

stats=fopen("stats.txt","r+");                   //Ponownie otwieramy plik

  fwrite(statystyki,sizeof(statystyki),1,stats); //i zapisujemy uaktualniona tablice w miejsce starej
   fclose(stats);                          //zamykamy plik



 bool wygrana=False;  // Zakladamy ze nie istnieje trafienie

           for (int i=0; i<6; i++)  //Dla kazdego elementu tablicy z wygranymi
            for (int j=0; j<6; j++) //Sprawdzamy czy wystapil w tablicy z wytypowanymi liczbamie
             if (losowanie.w[i]==losowanie.l[j])
              {
               wygrana=True;    // jesli tak - oznacza to wygrana
               break;
              }


 if (wygrana)     //Jesli trafilismy, to zapisujemy liczby wylosowane i wytypowane w pliku
 {


  winner=fopen("winners.txt","a+b");  //Odpalamy se plik w trybie binarnym i dopisywania na koniec
   fwrite(&losowanie,sizeof(losowanie),1,winner);  //dodajemy do pliku wypelnioną strukture
     fclose(winner);                //i zamykamy go

 ShowMessage(AnsiString("Gratulacje - WYGRALES!!!"));
 }






 } else ShowMessage("Nalezy wybrac dokladnie 6 numerow");


 }
//---------------------------------------------------------------------------
void __fastcall TForm1::NoweLosowanie1Click(TObject *Sender)
{
CZYSC();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pokaznumerywylosowoaneiwybranezprzynajmniejjednymtrafieniem1Click(
      TObject *Sender)
{
 StringGrid1->RowCount=2;


  StringGrid1->Cells[1][0]="Typy";
  StringGrid1->Cells[0][0]="Wylosowane";




winner=fopen("winners.txt","r+b");  //Odpalamy  plik w trybie binarnym i odczytu

while (fread(&losowanie,sizeof(liczby),1,winner)) //dopoki udaje sie zczytac cala strukture to robimy to
        {
char bufor1[2]={'\0','\0'}; //bufory do przchowywania stringow
 char bufor3[2]={'\0','\0'};

char bufor2[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
 char bufor4[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};


for(int i=0; i<6;i++)
 {
 itoa(losowanie.w[i],bufor1,10);  //w buforach tworzymy zapisy w postaci numer1 numer2 numer3. (np 1 42 14 21 53 12 )
  strcat(bufor2,bufor1);
   strcat(bufor2,"-");
 itoa(losowanie.l[i],bufor3,10);
  strcat(bufor4,bufor3);
   strcat(bufor4,"-");
 }



 StringGrid1->Cells[0][StringGrid1->RowCount-1]=bufor2; //wyswietlamy to w StringGridzie
  StringGrid1->Cells[1][StringGrid1->RowCount-1]=bufor4;

         StringGrid1->RowCount+=1;  //i zwiekszamy ilosc wierszy o 1

        }

fclose(winner);


  StringGrid1->RowCount-=1; //Obcinamy ostatni wiersz, bo jest pusty
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Pokazczestoscwylosowanychnumerow1Click(
      TObject *Sender)
{
int statystyki[50];
  StringGrid1->RowCount=50;
   StringGrid1->Cells[0][0]="___Nr___";
    StringGrid1->Cells[1][0]="___Count___";

stats=fopen("stats.txt","r+"); //Otwieramy plik z czestotliwosciami
  fread(&statystyki,sizeof(statystyki),1,stats);  //Zczytujemy tablice z czestotliwosciami
    fclose(stats);


for (int i=1; i<50; i++)
 {
  StringGrid1->Cells[0][i]=i;
   StringGrid1->Cells[1][i]=statystyki[i];
 }


}
//---------------------------------------------------------------------------

