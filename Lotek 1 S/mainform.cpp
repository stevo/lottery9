//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int Wytypowane[6];   //Tablica do przechowywania wytypowanych numerkow
int Wylosowane[6];   //... tych wylosowanych
int Statystyki[50];  //... oraz czestotliwosci ich wystapien w losowaniach
bool Trafienie;      //true lub false - w zaleznosci czy trafilismy jakis numerek
FILE *PlikStatystyk; //Plik ze statystykami
FILE *PlikWygranych; //...oraz z wygranymi

struct trafienie   //Struktura przechowywujaca wylosowane i wytypowane liczby w przypadku wygranej
{
int wylosowane[6];
int wytypowane[6];
};

trafienie tr;   //tr bedzie wlasnie taka struktur¹


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Form1->Memo1->Lines->Add("Obstaw swoje numerki i nacisnij przycisk [Losuj]");
}

bool Sprawdz(int liczba,int tab[]) //Sprawdza czy liczba istnieje w tablicy
{
bool jest=False;  // Zakladamy ze nie istnieje
 for (int i=0; i<6; i++)  //Dla kazdego elementu tej tablicy
  if (tab[i]==liczba)     //Jesli liczba jest rowna temu elementowi
    {
    jest=True;     // Ro zwaracamy true;
    break;        //i przerywamy petle, bo po co ciagnac ja dalej
    }
return jest;  // w przeciwnym wypadku pozostanie false
}




void Losowanie()
{
int liczba;

randomize(); //Uruchamiamy generator liczb losowych
for (int i=0; i<6; i++)
        {
          liczba=(rand()%49)+1;  //losuje liczbe z przedzialu 1-49 (to +1 jest dlatego, ze normalnie wyszlaby z przedzialu 0-48)
         if (!Sprawdz(liczba,Wylosowane)) Wylosowane[i]=liczba; //Jesli jeszcze takiej nie wylosowano to wstawia ja do tablicy
          else i--;  //W przeciwnym wypadku powtarza ten krok

        }
}


void PokazWyniki()
{
Trafienie=False; //Zakladamy ze nic nie trafilismy (pesymistycznie tak... ;-P)
char buf[2]; //robimy sobie buforek na przechowywanie stringow z numerkami

itoa(Wylosowane[0],buf,10); //zamieniamy kolejny element tablicy z wylosowanymi elementami na stringa
if (Sprawdz(Wylosowane[0],Wytypowane)) //jesli taki wytypowalismy
 {
 Form1->Edit7->Color=clRed;   //to oznaczamy pole w ktorym byl ten numerek na czerwono
 Form1->Memo1->Lines->Add("Trafiles!"); //i walimy komunikat
 Trafienie=True; // Skoro trafilsm to sobie to zapiszmy w zmiennej Trafienie :-)))
 }

 Form1->Edit7->Text=buf;  //wpsiujemy do odpowiedniego pola, te wartosc


itoa(Wylosowane[1],buf,10);       //i od nowa, dla kolejnego pola...
if (Sprawdz(Wylosowane[1],Wytypowane))
 {
 Form1->Edit8->Color=clRed;
 Form1->Memo1->Lines->Add("Trafiles!");
 Trafienie=True;
 }
Form1->Edit8->Text=buf;

itoa(Wylosowane[2],buf,10);
if (Sprawdz(Wylosowane[2],Wytypowane))
 {
 Form1->Edit9->Color=clRed;
 Form1->Memo1->Lines->Add("Trafiles!");
 Trafienie=True;
 }
Form1->Edit9->Text=buf;

itoa(Wylosowane[3],buf,10);
if (Sprawdz(Wylosowane[3],Wytypowane))
 {
 Form1->Edit10->Color=clRed;
 Form1->Memo1->Lines->Add("Trafiles!");
 Trafienie=True;
 }
Form1->Edit10->Text=buf;

itoa(Wylosowane[4],buf,10);
if (Sprawdz(Wylosowane[4],Wytypowane))
{
 Form1->Edit11->Color=clRed;
 Form1->Memo1->Lines->Add("Trafiles!");
 Trafienie=True;
 }
Form1->Edit11->Text=buf;

itoa(Wylosowane[5],buf,10);
if (Sprawdz(Wylosowane[5],Wytypowane))
 {
 Form1->Edit12->Color=clRed;
 Form1->Memo1->Lines->Add("Trafiles!");
 Trafienie=True;
 }
Form1->Edit12->Text=buf;

if (!Trafienie) Form1->Memo1->Lines->Add("Niestety nic nie trafiles..."); else
Form1->Memo1->Lines->Add("!!! Gratulacje !!!");
}


void UaktualnijStatystyki()
{
if ((PlikStatystyk=fopen("st.txt","r+"))==NULL)       //Otwieramy plik statystyk
 ShowMessage(AnsiString("Brak pliku statystyk")); else
   {
   fread(&Statystyki,sizeof(Statystyki),1,PlikStatystyk);  //Zczytujemy jedn¹ tablice
   fclose(PlikStatystyk);                                  //I zamykamy plik

   for (int i=0;i<6;i++)                                  //Inkremetujemy te numerki ktore zostaly wylosowane
     Statystyki[Wylosowane[i]]+=1;

    PlikStatystyk=fopen("st.txt","r+");                   //Ponownie otwieramy plik
   fwrite(Statystyki,sizeof(Statystyki),1,PlikStatystyk); //i zapisujemy uaktualniona tablice w miejsce starej
   fclose(PlikStatystyk);                                 //zamykamy plik


   }



}

void ZapiszWyniki()
{

for (int i=0; i<6; i++)          //Przepsiujemy numerki wylosowane i wytypowane do struktury TRAFIENIE
 {
  tr.wylosowane[i]=Wylosowane[i];
  tr.wytypowane[i]=Wytypowane[i];
 }



if ((PlikWygranych=fopen("wyg.txt","a+b"))==NULL)  //Odpalamy se plik w trybie binarnym i dopisywania na koniec
 ShowMessage(AnsiString("Brak pliku z wygranymi!"));
 else
   {
   fwrite(&tr,sizeof(tr),1,PlikWygranych);  //dodajemy do pliku wypelnion¹ strukture
   fclose(PlikWygranych);                //i zamykamy go
   }


}





//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if (!Sprawdz(0,Wytypowane)) //jesli we wszystkich polach sa podane wartosci (czyli tablica jest wypelniona liczbami roznymi od 0)
{
Edit1->ReadOnly=TRUE;    // to blokuje wszystkie pola do wpisywania
Edit2->ReadOnly=TRUE;
Edit3->ReadOnly=TRUE;
Edit4->ReadOnly=TRUE;
Edit5->ReadOnly=TRUE;
Edit6->ReadOnly=TRUE;

Losowanie();  //losuje numerki
PokazWyniki();  //i wyswietla je w polach obok
Button1->Enabled=False; //Wylaczamy mozliwosc losowania;
BitBtn1->Enabled=True;  //za to wlaczamy przycisk czyszczenia
if (Trafienie) ZapiszWyniki();
UaktualnijStatystyki();
}
else ShowMessage(AnsiString("Nie podano wszystkich liczb!"));  // w przeciwnym wypadku komunikuje, ze nie podano wszyrkich liczb


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Exit(TObject *Sender)  //Instrukcje sa wywolywane gdy "opuszcza" sie pole do wpisywania numerkow
{
if ((atoi(Edit1->Text.c_str())>49) || (atoi(Edit1->Text.c_str())<0)) //Sprawdza czy podano liczbe z zakresu od 1 do 49
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit1->SetFocus();
                        }

if (atoi(Edit1->Text.c_str())==0) //Sprawdza czy wogole wpisano liczbe (atoi zwraca 0 jesli nie uda mu sie przekonwertowac tekstu na liczbe)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit1->SetFocus();
                          goto koniec; //pomija kolejnego if'a gdyz podczas inicjalizacji tablica jest wypelniona zerami i kolejny if bylby na TRUE tak czy inaczej
                        }

if (!Sprawdz(atoi(Edit1->Text.c_str()),Wytypowane)) Wytypowane[0]=atoi(Edit1->Text.c_str()); else //sprawdza czy czasami nie wybrano takiej liczby wczesniej
 if (atoi(Edit1->Text.c_str())==Wytypowane[0]) Wytypowane[0]=atoi(Edit1->Text.c_str()); else  //jesli wybrano, to musi ona byc w tym samym polu co poprzednio
  {                                                                                    //w przeciwnym wypadku zakomunikuj, ze taka liczba juz byla
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit1->SetFocus();
                        }
koniec:
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
if ((atoi(Edit2->Text.c_str())>49) || (atoi(Edit2->Text.c_str())<0))
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit2->SetFocus();
                        }

if (atoi(Edit2->Text.c_str())==0)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit2->SetFocus();
                          goto koniec;
                        }

                        if (!Sprawdz(atoi(Edit2->Text.c_str()),Wytypowane)) Wytypowane[1]=atoi(Edit2->Text.c_str()); else
 if (atoi(Edit2->Text.c_str())==Wytypowane[1]) Wytypowane[1]=atoi(Edit2->Text.c_str()); else
  {
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit2->SetFocus();
                        }
koniec:
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
if ((atoi(Edit3->Text.c_str())>49) || (atoi(Edit3->Text.c_str())<0))
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit3->SetFocus();
                        }

if (atoi(Edit3->Text.c_str())==0)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit3->SetFocus();
                          goto koniec;
                        }
if (!Sprawdz(atoi(Edit3->Text.c_str()),Wytypowane)) Wytypowane[2]=atoi(Edit3->Text.c_str()); else
 if (atoi(Edit3->Text.c_str())==Wytypowane[2]) Wytypowane[2]=atoi(Edit3->Text.c_str()); else
  {
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit3->SetFocus();
                        }
  koniec:
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit4Exit(TObject *Sender)
{
if ((atoi(Edit4->Text.c_str())>49) || (atoi(Edit4->Text.c_str())<0))
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit4->SetFocus();
                        }

if (atoi(Edit4->Text.c_str())==0)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit4->SetFocus();
                          goto koniec;
                        }
if (!Sprawdz(atoi(Edit4->Text.c_str()),Wytypowane)) Wytypowane[3]=atoi(Edit4->Text.c_str()); else
 if (atoi(Edit4->Text.c_str())==Wytypowane[3]) Wytypowane[3]=atoi(Edit4->Text.c_str()); else
  {
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit4->SetFocus();
                        }
 koniec:
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit5Exit(TObject *Sender)
{
if ((atoi(Edit5->Text.c_str())>49) || (atoi(Edit5->Text.c_str())<0))
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit5->SetFocus();
                        }

if (atoi(Edit5->Text.c_str())==0)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit5->SetFocus();
                          goto koniec;
                        }
if (!Sprawdz(atoi(Edit5->Text.c_str()),Wytypowane)) Wytypowane[4]=atoi(Edit5->Text.c_str()); else
 if (atoi(Edit5->Text.c_str())==Wytypowane[4]) Wytypowane[4]=atoi(Edit5->Text.c_str()); else
  {
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit5->SetFocus();
                        }
  koniec:
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit6Exit(TObject *Sender)
{
if ((atoi(Edit6->Text.c_str())>49) || (atoi(Edit6->Text.c_str())<0))
                        {
                          ShowMessage(AnsiString("Prosze podac liczbe z zakresu 1-49"));
                          Edit6->SetFocus();

                        }

if (atoi(Edit6->Text.c_str())==0)
                        {
                          ShowMessage(AnsiString("Prosze uzyc znakow od 0-9"));
                          Edit6->SetFocus();
                          goto koniec;
                        }

if (!Sprawdz(atoi(Edit6->Text.c_str()),Wytypowane)) Wytypowane[5]=atoi(Edit6->Text.c_str()); else
 if (atoi(Edit6->Text.c_str())==Wytypowane[5]) Wytypowane[5]=atoi(Edit6->Text.c_str()); else
  {
                          ShowMessage(AnsiString("Podano juz taka liczbe"));
                          Edit6->SetFocus();
                        }
 koniec:
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
Form1->Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
for (int i=0; i<6; i++)     //Wypelniamy tablice zerami
{
Wylosowane[i]=0;
Wytypowane[i]=0;
}

Form1->Edit1->Clear();        //Czyscimy pola do typowania
Form1->Edit2->Clear();
Form1->Edit3->Clear();
Form1->Edit4->Clear();
Form1->Edit5->Clear();
Form1->Edit6->Clear();

Form1->Edit1->ReadOnly=False;       //Ukatywaniamy je
Form1->Edit2->ReadOnly=False;
Form1->Edit3->ReadOnly=False;
Form1->Edit4->ReadOnly=False;
Form1->Edit5->ReadOnly=False;
Form1->Edit6->ReadOnly=False;


Form1->Edit7->Clear();         //Czyscimy pola z wylosowanymi literkami
Form1->Edit8->Clear();
Form1->Edit9->Clear();
Form1->Edit10->Clear();
Form1->Edit11->Clear();
Form1->Edit12->Clear();

Form1->Edit7->Color=clWhite;        //"Robimy" je na bialo
Form1->Edit8->Color=clWhite;
Form1->Edit9->Color=clWhite;
Form1->Edit10->Color=clWhite;
Form1->Edit11->Color=clWhite;
Form1->Edit12->Color=clWhite;

Form1->Memo1->Lines->Add("Mozna rozpoczac kolejne losowanie");   //Komunikat :-)
BitBtn1->Enabled=False;     //Ukatywniamy przycisk losowania
Button1->Enabled=True;      //a wylaczamy czyszczenia

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
if ((PlikStatystyk=fopen("st.txt","r+"))==NULL)      //Tak samo jak przy uaktualnianiu
 ShowMessage(AnsiString("Brak pliku statystyk")); else
   {
   fread(&Statystyki,sizeof(Statystyki),1,PlikStatystyk);
   fclose(PlikStatystyk);
   }
Form1->Memo1->Lines->Add("Statystyki wystapien numerow :");
char buf[6], buf2[6];;
for (int i=1; i<50;i++)
{
 itoa(i,buf,10);   //buf bedzie zawieral numerek
 strcat(buf," = ");  // i znak =
 itoa(Statystyki[i],buf2,10); //buf2 bedzie zawieral ilosc wystapien danego numerka
 strcat(buf,buf2);  //laczymy oba zeby to wygladalo +/- tak   1 = 12    (jedynka zostala wylosowana 12 razy)
 Form1->Memo1->Lines->Add(buf); //i wypisujemy to do memo
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
if ((PlikWygranych=fopen("wyg.txt","r+b"))==NULL)  //Odpalamy se plik w trybie binarnym i odczytywania
 ShowMessage(AnsiString("Brak pliku z wygranymi!"));
 else
  {
        Form1->Memo1->Lines->Add("");
        Form1->Memo1->Lines->Add("::::WYGRANE:::: ");

       while (fread(&tr,sizeof(tr),1,PlikWygranych)) //dopoki udaje sie zczytac cala strukture to robimy to
       {
         Form1->Memo1->Lines->Add("---------------");
          char buf11[2]={'\0','\0'};            //Zerujemy tablice (bufory)... tak na wszelki wypadek
          char buf12[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
          char buf21[2]={'\0','\0'};
          char buf22[20]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

          for(int i=0; i<6;i++)
          {
         itoa(tr.wytypowane[i],buf11,10);  //w buforach tworzymy zapisy w postaci numer1.numer2.numer3. (np 1.42.14.21.53.12.)
         strcat(buf12,buf11);
         strcat(buf12,".");


         itoa(tr.wylosowane[i],buf21,10);
         strcat(buf22,buf21);
         strcat(buf22,".");
          }
        Form1->Memo1->Lines->Add("Wytypowane: ");    //Wyswietlamy zawartosci buforow
        Form1->Memo1->Lines->Add(buf12);
        Form1->Memo1->Lines->Add("Wylosowane: ");
        Form1->Memo1->Lines->Add(buf22);

       }





   fclose(PlikWygranych);   //Zamykamy plik...


  }


}
//---------------------------------------------------------------------------
