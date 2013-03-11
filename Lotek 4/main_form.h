//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Losowanie1;
        TMenuItem *Informacje1;
        TMenuItem *Losuj1;
        TMenuItem *NoweLosowanie1;
        TMenuItem *Pokazczestoscwylosowanychnumerow1;
        TMenuItem *Pokaznumerywylosowoaneiwybranezprzynajmniejjednymtrafieniem1;
        TMenuItem *Zakonczpraceprogramu1;
        TBevel *Bevel1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn9;
        TBitBtn *BitBtn10;
        TBitBtn *BitBtn12;
        TBitBtn *BitBtn13;
        TBitBtn *BitBtn14;
        TBitBtn *BitBtn15;
        TBitBtn *BitBtn16;
        TBitBtn *BitBtn17;
        TBitBtn *BitBtn18;
        TBitBtn *BitBtn19;
        TBitBtn *BitBtn20;
        TBitBtn *BitBtn22;
        TBitBtn *BitBtn23;
        TBitBtn *BitBtn24;
        TBitBtn *BitBtn25;
        TBitBtn *BitBtn26;
        TBitBtn *BitBtn27;
        TBitBtn *BitBtn28;
        TBitBtn *BitBtn29;
        TBitBtn *BitBtn30;
        TBitBtn *BitBtn32;
        TBitBtn *BitBtn33;
        TBitBtn *BitBtn34;
        TBitBtn *BitBtn35;
        TBitBtn *BitBtn36;
        TBitBtn *BitBtn37;
        TBitBtn *BitBtn38;
        TBitBtn *BitBtn39;
        TBitBtn *BitBtn40;
        TBitBtn *BitBtn42;
        TBitBtn *BitBtn43;
        TBitBtn *BitBtn44;
        TBitBtn *BitBtn45;
        TBitBtn *BitBtn46;
        TBitBtn *BitBtn47;
        TBitBtn *BitBtn48;
        TBitBtn *BitBtn49;
        TBitBtn *BitBtn50;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn11;
        TBitBtn *BitBtn21;
        TBitBtn *BitBtn31;
        TBitBtn *BitBtn41;
        TStringGrid *StringGrid1;
        void __fastcall Zakonczpraceprogramu1Click(TObject *Sender);
        void __fastcall BitBtn11Click(TObject *Sender);
        void __fastcall BitBtn50Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall BitBtn10Click(TObject *Sender);
        void __fastcall BitBtn12Click(TObject *Sender);
        void __fastcall BitBtn13Click(TObject *Sender);
        void __fastcall BitBtn14Click(TObject *Sender);
        void __fastcall BitBtn15Click(TObject *Sender);
        void __fastcall BitBtn16Click(TObject *Sender);
        void __fastcall BitBtn17Click(TObject *Sender);
        void __fastcall BitBtn18Click(TObject *Sender);
        void __fastcall BitBtn19Click(TObject *Sender);
        void __fastcall BitBtn20Click(TObject *Sender);
        void __fastcall BitBtn22Click(TObject *Sender);
        void __fastcall BitBtn23Click(TObject *Sender);
        void __fastcall BitBtn24Click(TObject *Sender);
        void __fastcall BitBtn25Click(TObject *Sender);
        void __fastcall BitBtn26Click(TObject *Sender);
        void __fastcall BitBtn27Click(TObject *Sender);
        void __fastcall BitBtn28Click(TObject *Sender);
        void __fastcall BitBtn29Click(TObject *Sender);
        void __fastcall BitBtn30Click(TObject *Sender);
        void __fastcall BitBtn32Click(TObject *Sender);
        void __fastcall BitBtn33Click(TObject *Sender);
        void __fastcall BitBtn34Click(TObject *Sender);
        void __fastcall BitBtn35Click(TObject *Sender);
        void __fastcall BitBtn36Click(TObject *Sender);
        void __fastcall BitBtn37Click(TObject *Sender);
        void __fastcall BitBtn38Click(TObject *Sender);
        void __fastcall BitBtn39Click(TObject *Sender);
        void __fastcall BitBtn40Click(TObject *Sender);
        void __fastcall BitBtn42Click(TObject *Sender);
        void __fastcall BitBtn43Click(TObject *Sender);
        void __fastcall BitBtn44Click(TObject *Sender);
        void __fastcall BitBtn45Click(TObject *Sender);
        void __fastcall BitBtn46Click(TObject *Sender);
        void __fastcall BitBtn47Click(TObject *Sender);
        void __fastcall BitBtn48Click(TObject *Sender);
        void __fastcall BitBtn49Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn21Click(TObject *Sender);
        void __fastcall BitBtn31Click(TObject *Sender);
        void __fastcall BitBtn41Click(TObject *Sender);
        void __fastcall Losuj1Click(TObject *Sender);
        void __fastcall NoweLosowanie1Click(TObject *Sender);
        void __fastcall Pokaznumerywylosowoaneiwybranezprzynajmniejjednymtrafieniem1Click(
          TObject *Sender);
        void __fastcall Pokazczestoscwylosowanychnumerow1Click(
          TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
