object Form1: TForm1
  Left = 756
  Top = 113
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsDialog
  Caption = 'Lotto'
  ClientHeight = 570
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 313
    Height = 209
  end
  object Bevel2: TBevel
    Left = 8
    Top = 224
    Width = 313
    Height = 105
  end
  object Label1: TLabel
    Left = 32
    Top = 240
    Width = 72
    Height = 13
    Caption = 'Wybrane liczby'
  end
  object Label2: TLabel
    Left = 16
    Top = 272
    Width = 90
    Height = 13
    Caption = 'Wylosowane liczby'
  end
  object Bevel3: TBevel
    Left = 8
    Top = 352
    Width = 313
    Height = 185
  end
  object Label3: TLabel
    Left = 32
    Top = 304
    Width = 72
    Height = 13
    Caption = 'Trafione Liczby'
  end
  object CheckListBox1: TCheckListBox
    Left = 16
    Top = 16
    Width = 297
    Height = 193
    OnClickCheck = CheckListBox1ClickCheck
    BevelInner = bvLowered
    BevelOuter = bvSpace
    Columns = 4
    Ctl3D = False
    ItemHeight = 13
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5'
      '6'
      '7'
      '8'
      '9'
      '10'
      '11'
      '12'
      '13'
      '14'
      '15'
      '16'
      '17'
      '18'
      '19'
      '20'
      '21'
      '22'
      '23'
      '24'
      '25'
      '26'
      '27'
      '28'
      '29'
      '30'
      '31'
      '32'
      '33'
      '34'
      '35'
      '36'
      '37'
      '38'
      '39'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49')
    ParentCtl3D = False
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 112
    Top = 232
    Width = 201
    Height = 89
    Color = clMoneyGreen
    ColCount = 6
    DefaultColWidth = 32
    FixedColor = clMoneyGreen
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goHorzLine]
    ScrollBars = ssNone
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 360
    Width = 297
    Height = 33
    Caption = '>>LOSUJ<<'
    Enabled = False
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 16
    Top = 400
    Width = 297
    Height = 33
    Caption = '>>STATYTSTYKI WYSTAPIEN NUMERKA<<'
    TabOrder = 3
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 16
    Top = 440
    Width = 297
    Height = 33
    Caption = '>>WYGRANE<<'
    TabOrder = 4
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 16
    Top = 488
    Width = 297
    Height = 33
    Caption = '>>ZAMKNIJ APLIKACJE<<'
    TabOrder = 5
    OnClick = BitBtn4Click
  end
end
