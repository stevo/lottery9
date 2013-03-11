#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

struct numbers
       {
        int drewn[6]; //wylosowana
        int choosed[6];  //wybrane
       };
numbers losowanie;

int tablica_czestotliwosci[49];
int numer;

FILE *plik1;
FILE *plik2; //Plik przechowywujacy czestotliwosc wystapien numerkow w czesie losowan

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Pokazczestotliwosci1Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Quit1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

bool istnieje(int numer) //Sprawdza czy liczba istnieje w tablicy
{
bool istnieje;
istnieje=False;  // Zakladamy ze nie istnieje
for (int i=0; i<6; i++)  //Dla kazdego elementu tej tablicy
   if (losowanie.drewn[i]==numer){     //Jesli liczba jest rowna temu elementowi
    istnieje=True;;     // To zwaracamy true;
    break;        //i przerywamy petle, bo po co ciagnac ja dalej
    }
return istnieje;  // w przeciwnym wypadku pozostanie false
}


void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender) //kontroluje zaby nie zaznaczyc wiecej niz 6 numerow
{
int idx = Form1->CheckListBox1->ItemIndex;
int CHECKED=0;
for (int i=0; i<Form1->CheckListBox1->Items->Count ; i++)
if (Form1->CheckListBox1->Checked[i]) CHECKED++;
if (CHECKED>=6) Losuj1->Enabled=True;
else Losuj1->Enabled=False;
if (CHECKED>6) Form1->CheckListBox1->Checked[idx]=False;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Losuj1Click(TObject *Sender)
{
randomize(); //Uruchamiamy generator liczb losowych
Losuj1->Enabled=False;
NoweLosowanie1->Enabled=True;

int idx=0;                                                        //Wypelnij tablice losowanie.choosed wybranymi numerami
for (int i=0; i<Form1->CheckListBox1->Items->Count-1 ; i++)
 if (Form1->CheckListBox1->Checked[i]) losowanie.choosed[idx++]=i+1;

for (int i=0; i<6; i++)  //Wypelnij tablice losowanie.liczby_wwylosowane wylosowanymi numerami
      {
      numer=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
       if (!istnieje(numer))
        losowanie.drewn[i]=numer; //Jesli jeszcze takiej nie wylosowano to wstawia ja do tablicy
        else i=i-1;  //W przeciwnym wypadku powtarza ten krok
      }
plik2=fopen("p1.fil","r+"); //Otwieramy plik statystyk
fread(&tablica_czestotliwosci,sizeof(tablica_czestotliwosci),1,plik2);  //Zczytujemy tablice z czestotliwosciami
   fclose(plik2);                                  //Zamykamy plik
for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
     tablica_czestotliwosci[losowanie.drewn[i]]++;

plik2=fopen("p1.fil","r+");                   //Ponownie otwieramy plik

  fwrite(tablica_czestotliwosci,sizeof(tablica_czestotliwosci),1,plik2); //i zapisujemy uaktualniona tablice w miejsce starej
   fclose(plik2);                          //zamykamy plik

for (int i=0; i<6; i++){    // wyswietl wszystie te liczby w StringGridzie
 Form1->StringGrid1->Cells[i][0]=losowanie.choosed[i];
 Form1->StringGrid1->Cells[i][1]=losowanie.drewn[i];
                        }
bool jest_trafienie=FALSE; // Zakladamy ze nie bylo trafienia

for (int i=0; i<6; i++) //sprawdzamy czy w wylosowanych sa takie liczby jakie wybralismy, jesli jest, to wpisujemy ja na kolejne
 if (istnieje(losowanie.choosed[i]))
  jest_trafienie=TRUE;   //Jesli trafilismy to zapisujemy to w zmiennej jest_trafienie

if (jest_trafienie)    //Jesli trafilismy, to zapisujemy liczby wylosowane i wytypowane w pliku
 {
 plik1=fopen("p2.fil","a+b");  //Odpalamy se plik w trybie binarnym i dopisywania na koniec
 fwrite(&losowanie,sizeof(losowanie),1,plik1);  //dodajemy do pliku wypelnion¹ strukture
 fclose(plik1);                //i zamykamy go
 }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::NoweLosowanie1Click(TObject *Sender)
{
for (int a=0; a<Form1->CheckListBox1->Items->Count;a++)    //Odznacz wszystkie CheckBox'y
if (Form1->CheckListBox1->Checked[a]==True)
Form1->CheckListBox1->Checked[a]=False;
Losuj1->Enabled=True;
NoweLosowanie1->Enabled=False;
for (int i=0; i<6; i++){   // wszystkie  liczby w StringGridzie zamien na NULL
        Form1->StringGrid1->Cells[i][0]="NULL";
        Form1->StringGrid1->Cells[i][1]="NULL";
        }


}
//---------------------------------------------------------------------------

