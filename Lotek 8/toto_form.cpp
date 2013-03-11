#include <vcl.h>
#include <stdio.h>
#pragma hdrstop
#include "toto_form.h"
#pragma package(smart_init)
#pragma resource "*.dfm"

/*                    -> ZMIENNE <-                  */
TForm1 *Form1;
bool losowanie_rozpoczete = False;  //ustawiamy na true po rozpoczeciu losowania

int wl[6];
int wb[6];
int frequencies[50];  //tablica z czestotliwosciami

FILE *Plik; //zmienna plikowa



/*                    -> KONSTRUKTOR FORMATKI <-                  */
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}






bool Podwojne() //zwraca true jesli dwa lub wiecej razy wybralismy ten sam numerek
{
bool temp;
temp=FALSE;
for (int i=0; i<6; i++)
   wb[i]=atoi(Form1->StringGrid1->Cells[i][0].c_str());
for (int i=0; i<5; i++)           //dla kazdego numerku w tablicy (bez ostatniego)
   for (int j=i+1; j<6; j++)     //sprawdzamy czy kolejne nie sa mu rowne
    if (wb[i]==wb[j]) temp=TRUE; //co oznaczaloby ze wybralismy ponownie ten sam numerek
return temp;
}

void LOSOWANIE_LICZB()
{
randomize(); //Uruchamiamy generator liczb losowych
int temp;
 for (int i=0; i<6; i++)  //Wypelnij tablice "wl" wylosowanymi liczbami
        {
         temp=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
          for (int j=0; j<6; j++)
           if (wl[j]==temp) i-=1;   //jesli taka liczba byla juz wylosowana to powtorzymy jej losowanie
            wl[i]=temp;
         }
}




void WYSWIETLENIE_WYNIKOW()
{
for (int i=0; i<6; i++)
 Form1->StringGrid1->Cells[i][1]=wl[i];
Form1->message_wnd->Lines->Add("->Liczby obstawione<-");
for (int i=0; i<6; i++)        //wyswietla wybrane numery w memo
 {
  Form1->message_wnd->Text=Form1->message_wnd->Text+wb[i];
  Form1->message_wnd->Text=Form1->message_wnd->Text+" ";
 }

Form1->message_wnd->Lines->Add("");

Form1->message_wnd->Lines->Add("->Liczby wylosowane<-");

for (int i=0; i<6; i++)            //wyswietla wylosowane numery w memo
 {
  Form1->message_wnd->Text=Form1->message_wnd->Text+wl[i];
  Form1->message_wnd->Text=Form1->message_wnd->Text+" ";
 }
}




void BLOKADA()
{
Form1->GroupBox1->Enabled=False;       //blokujemy wszystkie suwaki
losowanie_rozpoczete=True;       //ustawiamy ze losowanie zostalo odbyte
Form1->LOSUJ1->Caption="OD NOWA";
}

void PONOWNE_LOSOWANIE()
{
Form1->LOSUJ1->Caption="LOSOWANIE";
losowanie_rozpoczete=False;
Form1->GroupBox1->Enabled=True;

int temp=1;
Form1->TrackBar1->Position=temp++;   //ustawiamy suwaki
Form1->TrackBar2->Position=temp++;
Form1->TrackBar3->Position=temp++;
Form1->TrackBar4->Position=temp++;
Form1->TrackBar5->Position=temp++;
Form1->TrackBar6->Position=temp;

Form1->message_wnd->Clear();
Form1->message_wnd->Lines->Add("Obstaw swoje typy...");
}

void UAKTUALNIENIE_STATYSTYK()
{
if ((Plik=fopen("frequencies.st","r+"))!=NULL){ //Otwieramy plik przechowywujacy statystyki
fread(&frequencies,sizeof(frequencies),1,Plik);  //Zczytujemy tablice z czestotliwosciami
for (int i=0;i<6;i++)                        //Inkremetujemy te numerki ktore zostaly wylosowane
 frequencies[wl[i]]++;
fwrite(frequencies,sizeof(frequencies),1,Plik); //i zapisujemy uaktualniona tablice w miejsce starej
fclose(Plik);                          //zamykamy plik
}
}


void UAKTUALNIENIE_TRAFIEN()
{
bool TRAF=FALSE;
for (int i=0; i<6; i++)
 for (int j=0; j<6; j++)
  if (wb[i]==wl[j]) {
                        TRAF=!TRAF;
                        break;
                    }
  if (TRAF)
   {
   Form1->message_wnd->Lines->Add("Bylo trafienie");
     Plik=fopen("hits.st","a+b");  //Odpalamy plik w trybie binarnym, dopisywania na koniec
      fwrite(&wl,sizeof(wl),1,Plik);  //dodajemy do pliku tablice z wylosowanymi numerkami
       fwrite(&wb,sizeof(wb),1,Plik);  //i z wybranymi
        fclose(Plik);
   }
}

void Show_Number_Statistics()
{
if ((Plik=fopen("frequencies.st","r+"))!=NULL)    //Otwieramy plik z czestotliwosciami
 {
fread(&frequencies,sizeof(frequencies),1,Plik);  //Zczytujemy tablice z czestotliwosciami, po czym zamykamy plik
fclose(Plik);

 Form1->message_wnd->Lines->Add("Lista czestotliwosci wystapien numerkow");

for (int i=1; i<50; i++)
 {

 Form1->message_wnd->Lines->Add(i);
  Form1->message_wnd->Lines->Add("#");
   Form1->message_wnd->Lines->Add(frequencies[i]);
    Form1->message_wnd->Lines->Add("...............");
 }

 }
}

void Show_Winners_Results()
{
Form1->message_wnd->Lines->Add("->Lista trafnych typowan<-");
Form1->message_wnd->Lines->Add("Liczby pokazywane sa w parach wylosowane/obstawione");

Plik=fopen("hits.st","r+b");  //Odpalamy se plik w trybie binarnym i odczytu

int temp=1;
int TAB[6];

while (fread(&TAB,sizeof(TAB),1,Plik)) //dopoki udaje sie zczytac cala tablice
        {
         if ((temp++)%2) Form1->message_wnd->Lines->Add("..............."); //co dwa przejscia wstawiamy te kropki
          for(int i=0; i<6;i++)
          {
          Form1->message_wnd->Text=Form1->message_wnd->Text+TAB[i];
          Form1->message_wnd->Text=Form1->message_wnd->Text+" ";
          }
           Form1->message_wnd->Lines->Add("");
          }
fclose(Plik);
}



//-------------------------OBSLUGA SUWAKOW-----------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
StringGrid1->Cells[0][0]=TrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
StringGrid1->Cells[1][0]=TrackBar2->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
StringGrid1->Cells[2][0]=TrackBar3->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar4Change(TObject *Sender)
{
StringGrid1->Cells[3][0]=TrackBar4->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar5Change(TObject *Sender)
{
StringGrid1->Cells[4][0]=TrackBar5->Position;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar6Change(TObject *Sender)
{
StringGrid1->Cells[5][0]=TrackBar6->Position;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::LOSUJ1Click(TObject *Sender)
{
if (!Podwojne())   //jesli frequencies wb sie nie powtarzaja

{

if (!losowanie_rozpoczete) //i mozna odbyc losowanie, to...

{
  BLOKADA();  //blokujemy grupe suwakow
   LOSOWANIE_LICZB();           //losujemy numery
    UAKTUALNIENIE_STATYSTYK(); //uaktualniamy statystyki
     UAKTUALNIENIE_TRAFIEN();   //juaktualniamy tablice trafien
      WYSWIETLENIE_WYNIKOW();      //pokazujemy je w okienku


} else PONOWNE_LOSOWANIE();  //jesli nie to czyscimy wszystko

} else {
        Form1->message_wnd->Lines->Add("!!!UWAGA!!!");
        Form1->message_wnd->Lines->Add("!!!Nie mozna wybrac dwoch tych samych liczb!!!");
       }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Numerkow1Click(TObject *Sender)
{
Show_Number_Statistics();
       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wygranych1Click(TObject *Sender)
{
Show_Winners_Results();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::WYJSCIE1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CZYSCMSG1Click(TObject *Sender)
{
Form1->message_wnd->Clear();
}
//---------------------------------------------------------------------------

