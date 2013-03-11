//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct losowanie
       {
        unsigned int liczby_wybrane[6];
        unsigned int liczby_wylosowane[6];
       };
losowanie los;

bool losowanie_odbyte=False;

unsigned int Freq[49];



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


bool check_if_exist(unsigned int numer) //Sprawdza czy liczba istnieje w tablicy
{
bool exist;
exist=False;  // Zakladamy ze nie istnieje

 for (int i=0; i<6; i++)  //Dla kazdego elementu tej tablicy
   if (los.liczby_wylosowane[i]==numer)     //Jesli liczba jest rowna temu elementowi
    {
    exist=!exist;     // To zwaracamy true;
    break;        //i przerywamy petle, bo po co ciagnac ja dalej
    }
return exist;  // w przeciwnym wypadku pozostanie false
}






void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
int index = Form1->CheckListBox1->ItemIndex;
int count=0;
for (int i=0; i<Form1->CheckListBox1->Items->Count-1 ; i++)
 {
  if (Form1->CheckListBox1->Checked[i]) count++;
 }

if (count>=6) Form1->BitBtn1->Enabled=True; else Form1->BitBtn1->Enabled=False;

if (count>6) {
                  Form1->CheckListBox1->Checked[index]=False;
                  ShowMessage(AnsiString("Mozna wybrac tylko szesc numerow"));
             }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)   // !!!!! TUTAJ WLASCIWIE JEST 60% PROGRAMU !!!!!!
{
if (!losowanie_odbyte) {  //Jesli loswanie jeszcze nie zostalo odbyte

Form1->BitBtn1->Caption=">>WYCZYSC TABLICE<<"; //Zmien nazwe przycisku
losowanie_odbyte=!losowanie_odbyte;  //Ustaw ze losowanie zostalo odbyte



int ind=0;                                                        //Wypelnij tablice los.liczby_wybrane wybranymi numerami
for (int i=0; i<Form1->CheckListBox1->Items->Count-1 ; i++)
 if (Form1->CheckListBox1->Checked[i]) los.liczby_wybrane[ind++]=i+1;



int numer;
randomize(); //Uruchamiamy generator liczb losowych


  for (int i=0; i<6; i++)  //Wypelnij tablice los.liczby_wwylosowane wylosowanymi numerami
        {
          numer=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
         if (!check_if_exist(numer)) los.liczby_wylosowane[i]=numer; //Jesli jeszcze takiej nie wylosowano to wstawia ja do tablicy
          else i--;  //W przeciwnym wypadku powtarza ten krok

        }



FILE *Frequency; //Plik przechowywujacy czestotliwosc wystapien numerkow w czesie losowan

Frequency=fopen("freq.txt","r+"); //Otwieramy plik statystyk

  fread(&Freq,sizeof(Freq),1,Frequency);  //Zczytujemy tablice z czestotliwosciami
   fclose(Frequency);                                  //Zamykamy plik

   for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
     Freq[los.liczby_wylosowane[i]]++;

Frequency=fopen("freq.txt","r+");                   //Ponownie otwieramy plik

  fwrite(Freq,sizeof(Freq),1,Frequency); //i zapisujemy uaktualniona tablice w miejsce starej
   fclose(Frequency);                          //zamykamy plik












  for (int i=0; i<6; i++){    // wyswietl wszystie te liczby w StringGridzie
     Form1->StringGrid1->Cells[i][0]=los.liczby_wybrane[i];
     Form1->StringGrid1->Cells[i][1]=los.liczby_wylosowane[i];
                         }

    int trafione[6]={0,0,0,0,0,0}; //Tablica do przechowywania info, które liczby zosta³y trafione
    int counter=0;

       bool jest_trafienie=FALSE; // Zakladamy ze nie bylo trafienia

    for (int i=0; i<6; i++)
//sprawdzamy czy w wylosowanych sa takie liczby jakie wybralismy, jesli jest, to wpisujemy ja na kolejne
        if (check_if_exist(los.liczby_wybrane[i])) {
                trafione[counter++]=los.liczby_wybrane[i];//miejsce tablicy "trafione"
                jest_trafienie=TRUE;   //Jesli trafilismy to zapisujemy to w zmiennej jest_trafienie
                                           }


    for (int i=0; i<6; i++)     //...i wyswietlamy zawartosc tej tablicy
      Form1->StringGrid1->Cells[i][2]=trafione[i];


if (jest_trafienie)    //Jesli trafilismy, to zapisujemy liczby wylosowane i wytypowane w pliku
 {
 FILE *win;

  win=fopen("trafienia.txt","a+b");  //Odpalamy se plik w trybie binarnym i dopisywania na koniec
   fwrite(&los,sizeof(los),1,win);  //dodajemy do pliku wypelnion¹ strukture
     fclose(win);                //i zamykamy go




 }












     }   else   //Jesli losowanie zostalo odbyte, to trza wyczyscic wszystko...
     {

       for (int i=0; i<Form1->CheckListBox1->Items->Count-1 ; i++)    //Odznacz wszystkie CheckBox'y
        if (Form1->CheckListBox1->Checked[i]) Form1->CheckListBox1->Checked[i]=False;


       Form1->BitBtn1->Caption=">>LOSUJ<<" ; //Zmien nazwe przycisku

       for (int i=0; i<6; i++){    // Wyczysc wszystkie te liczby w StringGridzie
        Form1->StringGrid1->Cells[i][0]="";
        Form1->StringGrid1->Cells[i][1]="";
        Form1->StringGrid1->Cells[i][2]="";
                              }
       Form1->BitBtn1->Enabled=False;
      losowanie_odbyte=!losowanie_odbyte; //Ustaw ze losowanie NIE zostalo odbyte
     }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------

