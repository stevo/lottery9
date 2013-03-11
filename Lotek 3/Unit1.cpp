//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct liczby         // struktura do przechowywania wylosowanych i wybranych liczb;
 {
 int wyb[6];
 int wyl[6];
 } numery;

FILE *PLIK; //Plik przechowywujacy czestotliwosc wystapien liczb



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
if (ListBox2->Items->Count!=6)
 {
  if (ListBox1->ItemIndex!=-1)
     {
     ListBox2->Items->Add(ListBox1->Items->Strings[ListBox1->ItemIndex].c_str());
     ListBox1->Items->Delete(ListBox1->ItemIndex);
     }
 }
  else
ShowMessage(AnsiString("Wybrano juz 6 numerow!"));

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
if (ListBox2->ItemIndex!=-1) {
ListBox1->Items->Add(ListBox2->Items->Strings[ListBox2->ItemIndex].c_str());
ListBox2->Items->Delete(ListBox2->ItemIndex);
                         }
}
//---------------------------------------------------------------------------
int sprawdz_ilosc_wystapien (int liczba)
{
int wystapienia = 0; //zakladmay ze w tablicy nie ma podanej liczby

for (int i=0; i<6; i++)
  if (numery.wyl[i]==liczba)
   wystapienia++;

  return wystapienia;
}




void __fastcall TForm1::Button1Click(TObject *Sender)
{



if (ListBox2->Items->Count==6) //jesli wybrano 6 numerkow to...
   {
    Button1->Enabled=False;  //wylaczamy mozliwosc losowania

     int buf;
     for (int i=0; i<6; i++)  //zerowanie tablicy wylosowanych i wypelnianie wybranych
      {
       buf=atoi(ListBox2->Items->Strings[i].c_str());
       numery.wyb[i]=buf;
       numery.wyl[i]=0;
      }


      /* LOSOWANIE NUMEROW I WSTAWIANIE ICH DO TABLICY */


      randomize(); //Uruchamiamy generator liczb losowych
      for (int i=0; i<6; i++)  //Wypelnij tablice los.liczby_wwylosowane wylosowanymi numerami
        {
         numery.wyl[i]=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
        if (sprawdz_ilosc_wystapien(numery.wyl[i])>1) i--; //Jesli byla juz wylosowana to powtarzamy ten krok (dekrementujemy i)
         }


    /* WYSWIETLENIE WYLOSOWANYCH NUMEROW W ListBox3 */

     for (int i=0; i<6; i++)
      ListBox3->Items->Add(numery.wyl[i]);


    /*UAKTUALNIAMY TABLICE WYSTAPIEN NUMERKOW */

 int tablica[50];  //tablica z czestotliwosciami (jej index to numer a zawartosc tablicy pod tym indexem to czestotliwosc)

PLIK=fopen("czestotliwosc.txt","r+"); //Otwieramy plik przechowywujacy statystyki

  fread(&tablica,sizeof(tablica),1,PLIK);  //Zczytujemy tablice z czestotliwosciami


   for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
     tablica[numery.wyl[i]]+=1;


fwrite(tablica,sizeof(tablica),1,PLIK); //i zapisujemy uaktualniona tablice w miejsce starej
   fclose(PLIK);                          //zamykamy plik



        /* SPRAWDZENIE CZY NASTAPILO TRAFIENIE */

     int WYGRANA=0;

       for (int i=0; i<6; i++)
        if (sprawdz_ilosc_wystapien(numery.wyb[i])>0) WYGRANA++;

      if (WYGRANA)
        {
        ShowMessage(AnsiString("GRATULACJE"));

                /* ZAPIS EWENTUALNEJ WYGRANEJ DO PLIKU */

                PLIK=fopen("zwyciezcy.txt","a+b");  //Odpalamy plik w trybie binarnym, dopisywania na koniec
                fwrite(&numery,sizeof(numery),1,PLIK);  //dodajemy do pliku  strukture  zawierajaca numery wylosowane i wytypowane
                fclose(PLIK);                //i zamykamy go








        }





   } else ShowMessage(AnsiString("Prosze najpierw wybrac 6 numerow"));




}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
ListBox3->Clear();    //czyscimy ListBox3 (ten z wylosowanymi liczbami)

int count=ListBox2->Items->Count; //Sprawdzamy ile jest elementow w lsistbox2 (z wybranymi)

for (int i=count-1; i>=0; i--)  //i wszystkie je przenosimy do listbox1 jednoczesnie usuwajac je z listbox2
 {
  ListBox1->Items->Add(ListBox2->Items->Strings[i].c_str());
  ListBox2->Items->Delete(i);
 }

 Button1->Enabled=True;    //wlaczamy mozliwosc losowania
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
int tablica[50];
PLIK=fopen("czestotliwosc.txt","r+"); //Otwieramy plik z czestotliwosciami
fread(&tablica,sizeof(tablica),1,PLIK);  //Zczytujemy tablice z czestotliwosciami
fclose(PLIK);


StringGrid1->Cells[0][0]="Numer";
StringGrid1->Cells[1][0]="Wyst¹pieñ";
StringGrid1->RowCount=50;

for (int i=1; i<50; i++)
 {
  StringGrid1->Cells[0][i]=i;
  StringGrid1->Cells[1][i]=tablica[i];
 }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
StringGrid1->Cells[0][0]="Wybrane";
StringGrid1->Cells[1][0]="Wylosowane";
StringGrid1->RowCount=2;

PLIK=fopen("zwyciezcy.txt","r+b");  //Odpalamy se plik w trybie binarnym i odczytu

while (fread(&numery,sizeof(numery),1,PLIK)) //dopoki udaje sie zczytac cala strukture to robimy to
        {
          char b1[2]={'\0','\0'}; //bufory do przchowywania stringow
          char b2[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
          char b3[2]={'\0','\0'};
          char b4[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};


          for(int i=0; i<6;i++)
          {

         itoa(numery.wyb[i],b1,10);  //w buforach tworzymy zapisy w postaci numer1 numer2 numer3. (np 1 42 14 21 53 12 )
         strcat(b2,b1);
         strcat(b2," ");
         itoa(numery.wyl[i],b3,10);
         strcat(b4,b3);
         strcat(b4," ");
         }

         StringGrid1->Cells[0][StringGrid1->RowCount-1]=b2; //wyswietlamy to w StringGridzie
         StringGrid1->Cells[1][StringGrid1->RowCount-1]=b4;
         StringGrid1->RowCount++;  //i zwiekszamy ilosc wierszy o 1
        }
StringGrid1->RowCount--; //likwiduje ostatnie wolne miejsce
fclose(PLIK);
}
//---------------------------------------------------------------------------
