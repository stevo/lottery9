//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "main_form.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

bool blokada = False;  //ustawiamy na true po wykonaniu losowania, zeby niemozna bylo nic mieszac :-P
int liczby[50];  //tablica z czestotliwosciami (jej index to numer a zawartosc tablicy pod tym indexem to czestotliwosc)

int wylosowane[6];
int wybrane[6];

FILE *ZBIOR; //zmienna plikowa do roznych zastosowan - zapisywania wygranych, uaktualniania statystyk itp.

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
Edit1->Text=TrackBar1->Position; //gdy przesuwamy suwakiem to w okienku obok niego wyswietla sie obecna pozycja tego suwaka
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
Edit2->Text=TrackBar2->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{
Edit3->Text=TrackBar3->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar4Change(TObject *Sender)
{
Edit4->Text=TrackBar4->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar5Change(TObject *Sender)
{
Edit5->Text=TrackBar5->Position;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrackBar6Change(TObject *Sender)
{
Edit6->Text=TrackBar6->Position;
}

bool sprawdz_powtorzenia() //zwraca true jesli dwa lub wiecej razy wybralismy ten sam numerek
{
bool powtorzenie=FALSE; //zakladamy ze nie ma powtorzenia numerku na track barach

 wybrane[0]=atoi(Form1->Edit1->Text.c_str()); //wypelniamy tablice z numerkami wybranymi
 wybrane[1]=atoi(Form1->Edit2->Text.c_str()); //tymi numerami ktore znajduja sie w okienkach obok
 wybrane[2]=atoi(Form1->Edit3->Text.c_str()); //trackbar'ów
 wybrane[3]=atoi(Form1->Edit4->Text.c_str());
 wybrane[4]=atoi(Form1->Edit5->Text.c_str());
 wybrane[5]=atoi(Form1->Edit6->Text.c_str());

  for (int i=0; i<5; i++)  //dla kazdego numerku w tablicy (bez ostatniego)
   for (int j=i+1; j<6; j++)//sprawdzamy czy kolejne nie sa mu rowne
    if (wybrane[i]==wybrane[j]) powtorzenie=TRUE; //co oznaczaloby ze wybralismy ponownie ten sam numerek

return powtorzenie;    



}

void wylosuj_liczby()
{
randomize(); //Uruchamiamy generator liczb losowych

int temporary;

      for (int i=0; i<6; i++)  //Wypelnij tablice "wylosowane" wylosowanymi liczbami
        {
         temporary=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
              //i wstawia ja do tablicy

                 for (int j=0; j<6; j++)
                  if (wylosowane[j]==temporary) i--;   //jesli taka liczba byla juz wylosowana to powtorzymy jej losowanie

                  wylosowane[i]=temporary; //wiec nie przeszkadza nam wpisanie jej do tablicy, poniewaz podczas kolejnego losowania
                                           //i tak zostanie nadpisana
         }

}




void pokaz_liczby()
{
Form1->okienko_komunikatow->Lines->Add("");

Form1->okienko_komunikatow->Lines->Add("::WYLOSOWANE::");
for (int i=0; i<6; i++)            //wyswietla wylosowane liczby w memo
 {
  Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+wylosowane[i];
  Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+" ";
 }


Form1->okienko_komunikatow->Lines->Add("");

Form1->okienko_komunikatow->Lines->Add("::WYBRANE::");
for (int i=0; i<6; i++)        //wyswietla wybrane liczby w memo
 {
  Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+wybrane[i];
  Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+" ";
 }


Form1->Edit7->Text=wylosowane[0];
Form1->Edit8->Text=wylosowane[1];
Form1->Edit9->Text=wylosowane[2];
Form1->Edit10->Text=wylosowane[3];
Form1->Edit11->Text=wylosowane[4];
Form1->Edit12->Text=wylosowane[5];
}

void blokuj_suwaki()
{
Form1->TrackBar1->Enabled=False;   //blokujemy suwaki
Form1->TrackBar2->Enabled=False;
Form1->TrackBar3->Enabled=False;
Form1->TrackBar4->Enabled=False;
Form1->TrackBar5->Enabled=False;
Form1->TrackBar6->Enabled=False;
blokada=True;      //ustawiamy ze losowanie zostalo odbyte
Form1->Button1->Caption="NOWE LOSOWANIE";
}

void nowe_losowanie()
{
Form1->Button1->Caption="LOSUJ";
blokada=False;
Form1->TrackBar1->Enabled=True;   //uaktywniamy suwaki
Form1->TrackBar2->Enabled=True;
Form1->TrackBar3->Enabled=True;
Form1->TrackBar4->Enabled=True;
Form1->TrackBar5->Enabled=True;
Form1->TrackBar6->Enabled=True;

Form1->TrackBar1->Position=1;   //ustawiamy suwaki
Form1->TrackBar2->Position=2;
Form1->TrackBar3->Position=3;
Form1->TrackBar4->Position=4;
Form1->TrackBar5->Position=5;
Form1->TrackBar6->Position=6;

Form1->okienko_komunikatow->Clear();
Form1->okienko_komunikatow->Lines->Add("Obstaw swoje liczby za pomoc¹ suwaków powy¿ej...");
}

void dodaj_do_statystyk()
{
ZBIOR=fopen("liczby.dat","r+"); //Otwieramy plik przechowywujacy statystyki
fread(&liczby,sizeof(liczby),1,ZBIOR);  //Zczytujemy tablice z czestotliwosciami

for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
 liczby[wylosowane[i]]++;


fwrite(liczby,sizeof(liczby),1,ZBIOR); //i zapisujemy uaktualniona tablice w miejsce starej
fclose(ZBIOR);                          //zamykamy plik
}


void dodaj_wygrana()
{
for (int i=0; i<6; i++)
 for (int j=0; j<6; j++)
  if (wybrane[i]==wylosowane[j])
   {
     Form1->okienko_komunikatow->Lines->Add("!!!!WYGRANA!!!!");
     ZBIOR=fopen("trafienia.dat","a+b");  //Odpalamy plik w trybie binarnym, dopisywania na koniec

      fwrite(&wylosowane,sizeof(wylosowane),1,ZBIOR);  //dodajemy do pliku tablice z wylosowanymi numerkami
      fwrite(&wybrane,sizeof(wybrane),1,ZBIOR);  //i z wybranymi

     fclose(ZBIOR);

     break;
   }
}

void pokaz_statystyki()
{
if ((ZBIOR=fopen("liczby.dat","r+"))!=0)    //Otwieramy plik z czestotliwosciami
 {
fread(&liczby,sizeof(liczby),1,ZBIOR);  //Zczytujemy tablice z czestotliwosciami, po czym zamykamy plik
fclose(ZBIOR);
 Form1->okienko_komunikatow->Clear();
 Form1->okienko_komunikatow->Lines->Add(" ::WYSTAPIENIA NUMERKOW::");

for (int i=1; i<50; i++)
 {

 Form1->okienko_komunikatow->Lines->Add(i);
 Form1->okienko_komunikatow->Lines->Add("BYLO WYLOSOWANE");
 Form1->okienko_komunikatow->Lines->Add(liczby[i]);
 Form1->okienko_komunikatow->Lines->Add(" ::::::  :::::: ");

 }



 }
}

void pokaz_wygrane()
{
bool wylos=TRUE;
int tablica[6];

ZBIOR=fopen("trafienia.dat","r+b");  //Odpalamy se plik w trybie binarnym i odczytu

Form1->okienko_komunikatow->Lines->Add("_________________________");
Form1->okienko_komunikatow->Lines->Add(":::TRAFIENIA:::");

while (fread(&tablica,sizeof(tablica),1,ZBIOR)) //dopoki udaje sie zczytac cala tablice to robimy to
        {
         if (wylos) Form1->okienko_komunikatow->Lines->Add("Liczby wylosowane"); else //jako ze odczytujemy na zmiane tablice
          Form1->okienko_komunikatow->Lines->Add("Liczby wybrane"); // z numerkami wylosowanymi i wybranymi, to

          wylos=!wylos; //sprawdzamy ktorre jest obecnie za pomoca tej zmiennej



          for(int i=0; i<6;i++)
          {
            Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+tablica[i];
            Form1->okienko_komunikatow->Text=Form1->okienko_komunikatow->Text+" ";
          }
           Form1->okienko_komunikatow->Lines->Add("");

        }





fclose(ZBIOR);
}



//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (!sprawdz_powtorzenia())   //jesli liczby wybrane sie nie powtarzaja
 {
   if (!blokada) //i mozna odbyc losowanie, to...
    {
   Form1->okienko_komunikatow->Clear();
   wylosuj_liczby(); //losujemy liczby
   pokaz_liczby();  //pokazujemy wylosowane i wybrane w memo
   blokuj_suwaki(); //blokujemy suwaki
   dodaj_do_statystyk(); //uaktualniamy statystyki wystapien numerkow
   dodaj_wygrana(); //jesli bylo trafienie to zapisujemy to;
    } else nowe_losowanie();  //jesli nie to przygotowujemy nowe losowanie
 } else
ShowMessage(AnsiString("!Podano wiele razy ten sam numerek!"));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
pokaz_statystyki();
pokaz_wygrane();
}
//---------------------------------------------------------------------------

