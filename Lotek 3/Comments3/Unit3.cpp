//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormActivate(TObject *Sender)
{
FILE *win;

struct losowanie //deklarujemy taka sama strukturke jak w glownym programie
       {
        unsigned int liczby_wybrane[6];
        unsigned int liczby_wylosowane[6];
       } los;

      

Form3->Memo1->Lines->Add(">>TRAFIENIA<<");


  win=fopen("trafienia.txt","r+b");  //Odpalamy se plik w trybie binarnym i odczytu

 while (fread(&los,sizeof(los),1,win)) //dopoki udaje sie zczytac cala strukture to robimy to
       {
         Form3->Memo1->Lines->Add(">>WYGRANA :::liczby wybrane i wylosowane:::<<");

          char temp1[2]={'\0','\0'};            //Zerujemy tablice (bufory)... tak na wszelki wypadek
                                         // tzn. kazdy element zasrtepujemy nullem ('/0'== NULL)
          char temp2[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
          char temp3[2]={'\0','\0'};
          char temp4[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};


          for(int i=0; i<6;i++)
          {

         itoa(los.liczby_wybrane[i],temp1,10);  //w buforach tworzymy zapisy w postaci numer1:numer2:numer3. (np 			1:42:14:21:53:12:)
         
         strcat(temp2,temp1); //do temp2 doklejamy zawrtosc temp 1
         strcat(temp2,":");
        

         itoa(los.liczby_wylosowane[i],temp3,10);
         strcat(temp4,temp3);
         strcat(temp4,":");
          }


        Form3->Memo1->Lines->Add(temp2);    //Wyswietlamy zawartosci buforow
        Form3->Memo1->Lines->Add(temp4);
        Form3->Memo1->Lines->Add("_______________");
        }
      fclose(win);   //Zamykamy plik...

}
//---------------------------------------------------------------------------
void __fastcall TForm3::BitBtn1Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
