//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

FILE *plik, *plik2;


struct liczby_struct
       {
      int liczby_los[6];
      int liczby_typ[6];
       } liczby;

int statystyki[49];


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
for (int i=0; i<49; i++) //Wypelniamy oba checkListBOx'y elementami
 {
  CheckListBox1->Items->Add(i+1);
  CheckListBox2->Items->Add(i+1);
 }

CheckListBox2->Enabled=False;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
int zaznaczone;
zaznaczone=0;

for (int i=0; i<Form1->CheckListBox1->Items->Count ; i++)//lecimy po calym CheckListBoxie i zliczamy zaznaczone elementy
 if (Form1->CheckListBox1->Checked[i]) zaznaczone++;

if (zaznaczone>=6) Form1->BitBtn1->Enabled=True;  //jesli jest 6 to mozemy losowac
 else Form1->BitBtn1->Enabled=False;


 if (zaznaczone>6) Form1->CheckListBox1->Checked[Form1->CheckListBox1->ItemIndex]=False; //jak jest juz szesc to nie pozwalamy zaznaczyc kolejnego


}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{

bool wygrana = False;
int j=0; //zmienna sluzaca do wypelniania kolejnych pol tablic

for (int i=0; i<Form1->CheckListBox1->Items->Count ; i++)   //wypelniamy tablice wybranymi numerami
 if (Form1->CheckListBox1->Checked[i]) liczby.liczby_typ[j++]=i+1;


int liczba;
randomize(); //Uruchamiamy generator liczb losowych


  for (int i=0; i<6; i++)  //Wypelnij tablice los.liczby_wwylosowane wylosowanymi numerami
        {
          liczba=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
         if (!Form1->CheckListBox2->Checked[liczba-1]) Form1->CheckListBox2->Checked[liczba-1]=True; //jesli ta liczba nie byla jeszcze wylosowana to zaznaczamy ja w CheckListBox2
          else i-=1; //w przeciwnym razie powtarzamy ten krok
        }

j=0;

Form1->CheckListBox2->Enabled=True;

for (int i=0; i<Form1->CheckListBox2->Items->Count ; i++)   //wypelniamy tablice wylosowanymi numerami
 if (Form1->CheckListBox2->Checked[i]) liczby.liczby_los[j++]=i+1;

Form1->CheckListBox2->Enabled=False; //wylaczamy mozliwosc zmian w CheckListBox'ach
Form1->CheckListBox1->Enabled=False;
Form1->BitBtn1->Enabled=False;

for (int i=0; i<Form1->CheckListBox1->Items->Count-1 ; i++)   //jesli w obu CheckListBoxach jest zaznaczona ta sama liczba, to oznacza to wygrana
 if ( (Form1->CheckListBox1->Checked[i]) && (Form1->CheckListBox2->Checked[i]) ) wygrana=True;

plik=fopen("dane.txt","r+");
if (plik!=NULL) {
                fread(&statystyki,sizeof(statystyki),1,plik);
                  fclose(plik);

                 for (int i=0; i<6; i++)       //uaktualniamy tablice ze statystykami
                  statystyki[(liczby.liczby_los[i])-1]++;

                plik=fopen("dane.txt","r+");
                fwrite(statystyki,sizeof(statystyki),1,plik);
                 fclose(plik);
                }
if (wygrana)    //jesli byla wygrana, to informacje o niej zachowujemy w pliku
 {
   plik2=fopen("dane2.txt","a+b");
   fwrite(&liczby,sizeof(liczby),1,plik);
   fclose(plik);
}

Form1->BitBtn4->Enabled=True;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
Form1->CheckListBox1->Clear();
Form1->CheckListBox2->Clear();

for (int i=0; i<49; i++) //Wypelniamy oba checkListBOx'y elementami
 {
  CheckListBox1->Items->Add(i+1);
  CheckListBox2->Items->Add(i+1);
 }

Form1->BitBtn1->Enabled=True;
Form1->BitBtn4->Enabled=False;
Form1->CheckListBox1->Enabled=True;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
Form2->Show();
Form1->Hide();
}
//---------------------------------------------------------------------------
