object Form2: TForm2
  Left = 410
  Top = 140
  BorderStyle = bsToolWindow
  Caption = 'Zaliczenie C++'
  ClientHeight = 356
  ClientWidth = 327
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
  object Bevel2: TBevel
    Left = 8
    Top = 8
    Width = 313
    Height = 297
  end
  object Bevel1: TBevel
    Left = 16
    Top = 16
    Width = 297
    Height = 281
  end
  object Memo1: TMemo
    Left = 24
    Top = 24
    Width = 89
    Height = 265
    Cursor = crHandPoint
    Alignment = taCenter
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 16706003
    Ctl3D = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clTeal
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentCtl3D = False
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 8
    Top = 312
    Width = 313
    Height = 33
    TabOrder = 1
    OnClick = BitBtn1Click
    Kind = bkClose
  end
  object Memo2: TMemo
    Left = 120
    Top = 24
    Width = 185
    Height = 265
    Cursor = crHandPoint
    Alignment = taCenter
    BevelInner = bvNone
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = 16706003
    Ctl3D = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clTeal
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentCtl3D = False
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
  end
end
