//---------------------------------------------------------------------------

#ifndef toto_formH
#define toto_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *message_wnd;
        TBevel *Bevel2;
        TStringGrid *StringGrid1;
        TGroupBox *GroupBox1;
        TTrackBar *TrackBar1;
        TTrackBar *TrackBar2;
        TTrackBar *TrackBar3;
        TTrackBar *TrackBar4;
        TTrackBar *TrackBar5;
        TTrackBar *TrackBar6;
        TMainMenu *MainMenu1;
        TMenuItem *LOSUJ1;
        TMenuItem *WYSW1;
        TMenuItem *WYJSCIE1;
        TMenuItem *Numerkow1;
        TMenuItem *Wygranych1;
        TLabel *Label1;
        TLabel *Label2;
        TStaticText *StaticText1;
        TMenuItem *CZYSCMSG1;
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall TrackBar3Change(TObject *Sender);
        void __fastcall TrackBar4Change(TObject *Sender);
        void __fastcall TrackBar5Change(TObject *Sender);
        void __fastcall TrackBar6Change(TObject *Sender);
        void __fastcall LOSUJ1Click(TObject *Sender);
        void __fastcall Numerkow1Click(TObject *Sender);
        void __fastcall Wygranych1Click(TObject *Sender);
        void __fastcall WYJSCIE1Click(TObject *Sender);
        void __fastcall CZYSCMSG1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
