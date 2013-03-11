#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <string.h>
#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
FILE *plik1;
FILE *plik2;
int tablica_czestotliwosci[49];
struct numbers
       {
        int drewn[6];            //wylosowane
        int choosed[6];         //wybrane
       } losowanie;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}



void __fastcall TForm2::FormActivate(TObject *Sender)
{
plik2=fopen("p1.fil","r+"); //Otwieramy plik statystyk
 fread(&tablica_czestotliwosci,sizeof(tablica_czestotliwosci),1,plik2);  //Zczytujemy tablice z czestotliwosciami
  fclose(plik2);

String buf1,buf2;  //dwie zmienne typu string
for (int i=0; i<49;i++)
{
 buf1=i+1;
  buf1=buf1+" # ";
   buf1=buf1+tablica_czestotliwosci[i];
    Form2->Memo1->Lines->Add(buf1); //walimy to do memo

}
plik1=fopen("p2.fil","r+b");  //Odpalamy se plik w trybie binarnym i odczytu

Form2->Memo2->Lines->Add("Liczby wybrane");
 Form2->Memo2->Lines->Add("Liczby wylosowane");
  Form2->Memo2->Lines->Add("...:.:.:.:.:.:...");
while (fread(&losowanie,sizeof(losowanie),1,plik1)) //dopoki udaje sie zczytac cala strukture to robimy to
       {
        buf1="";
        buf2="";

         for (int i=0; i<6; i++)
         {
          buf1=buf1+losowanie.choosed[i];
           buf1=buf1+" ";
            buf2=buf2+losowanie.drewn[i];
             buf2=buf2+" ";
         }
        Form2->Memo2->Lines->Add(buf1);    //Wyswietlamy zawartosci buforo
         Form2->Memo2->Lines->Add(buf2);
          Form2->Memo2->Lines->Add("...:.:.:.:.:.:...");
        }
      fclose(plik1);   //Zamykamy plik...
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------

