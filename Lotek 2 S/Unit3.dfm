object Form3: TForm3
  Left = 530
  Top = 127
  BorderStyle = bsToolWindow
  Caption = 'Wygrane'
  ClientHeight = 720
  ClientWidth = 287
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 273
    Height = 649
  end
  object Bevel2: TBevel
    Left = 8
    Top = 664
    Width = 273
    Height = 49
  end
  object Memo1: TMemo
    Left = 16
    Top = 16
    Width = 257
    Height = 633
    BevelInner = bvLowered
    BevelKind = bkTile
    BevelOuter = bvSpace
    Color = clScrollBar
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Arial'
    Font.Style = [fsItalic]
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 672
    Width = 257
    Height = 33
    Caption = 'Zamknij'
    TabOrder = 1
    OnClick = BitBtn1Click
  end
end
