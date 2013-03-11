//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
extern unsigned int Freq[49];
FILE *Frequency;

void __fastcall TForm2::FormActivate(TObject *Sender)
{
Frequency=fopen("freq.txt","r+"); //Otwieramy plik statystyk

  fread(&Freq,sizeof(Freq),1,Frequency);  //Zczytujemy tablice z czestotliwosciami
   fclose(Frequency);


Form2->Memo1->Lines->Add(">>Czestotliwosci<<");
char temp[4], temp2[6];

for (int i=0; i<49;i++)
{
 itoa(i+1,temp,10);   //temp bedzie zawieral numer   (itoa(liczba,bufor,system-tu dziesietny))  i+1 bo pierwsze jest 1 a nie 0 jak wynika z petli
 itoa(Freq[i],temp2,10); //temp2 bedzie zawieral ilosc wystapien numeru

 strcat(temp," wylosowano ");
 strcat(temp2," razy ");

 strcat(temp,temp2);  //laczymy oba -> np. 5 wylosowano 42 razy
 Form2->Memo1->Lines->Add(temp); //walimy to do memo

}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------

