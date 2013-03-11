object Form1: TForm1
  Left = 179
  Top = 100
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsDialog
  Caption = '..::TotoLotek::..'
  ClientHeight = 443
  ClientWidth = 339
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
    Width = 329
    Height = 185
    Shape = bsFrame
    Style = bsRaised
  end
  object Bevel2: TBevel
    Left = 8
    Top = 200
    Width = 329
    Height = 241
    Shape = bsFrame
    Style = bsRaised
  end
  object Bevel3: TBevel
    Left = 144
    Top = 32
    Width = 57
    Height = 153
  end
  object Bevel4: TBevel
    Left = 16
    Top = 32
    Width = 65
    Height = 153
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 62
    Height = 13
    Caption = 'Wytypowane'
  end
  object Label2: TLabel
    Left = 144
    Top = 16
    Width = 61
    Height = 13
    Caption = 'Wylosowane'
  end
  object Button1: TButton
    Left = 216
    Top = 32
    Width = 113
    Height = 25
    Caption = 'Losuj'
    TabOrder = 0
    OnClick = Button1Click
  end
  object BitBtn1: TBitBtn
    Left = 216
    Top = 64
    Width = 113
    Height = 25
    Caption = 'Czysc'
    Enabled = False
    TabOrder = 1
    OnClick = BitBtn1Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00500005000555
      555557777F777555F55500000000555055557777777755F75555005500055055
      555577F5777F57555555005550055555555577FF577F5FF55555500550050055
      5555577FF77577FF555555005050110555555577F757777FF555555505099910
      555555FF75777777FF555005550999910555577F5F77777775F5500505509990
      3055577F75F77777575F55005055090B030555775755777575755555555550B0
      B03055555F555757575755550555550B0B335555755555757555555555555550
      BBB35555F55555575F555550555555550BBB55575555555575F5555555555555
      50BB555555555555575F555555555555550B5555555555555575}
    NumGlyphs = 2
  end
  object BitBtn2: TBitBtn
    Left = 216
    Top = 96
    Width = 113
    Height = 25
    Caption = 'Statystyki numerow'
    TabOrder = 2
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 216
    Top = 128
    Width = 113
    Height = 25
    Caption = 'Wygrane'
    TabOrder = 3
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 216
    Top = 160
    Width = 113
    Height = 25
    Caption = 'Koniec'
    TabOrder = 4
    OnClick = BitBtn4Click
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033BBBBBBBBBB
      BB33337777777777777F33BB00BBBBBBBB33337F77333333F37F33BB0BBBBBB0
      BB33337F73F33337FF7F33BBB0BBBB000B33337F37FF3377737F33BBB00BB00B
      BB33337F377F3773337F33BBBB0B00BBBB33337F337F7733337F33BBBB000BBB
      BB33337F33777F33337F33EEEE000EEEEE33337F3F777FFF337F33EE0E80000E
      EE33337F73F77773337F33EEE0800EEEEE33337F37377F33337F33EEEE000EEE
      EE33337F33777F33337F33EEEEE00EEEEE33337F33377FF3337F33EEEEEE00EE
      EE33337F333377F3337F33EEEEEE00EEEE33337F33337733337F33EEEEEEEEEE
      EE33337FFFFFFFFFFF7F33EEEEEEEEEEEE333377777777777773}
    NumGlyphs = 2
  end
  object Memo1: TMemo
    Left = 16
    Top = 208
    Width = 313
    Height = 201
    Color = clGradientActiveCaption
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Edit1: TEdit
    Left = 24
    Top = 40
    Width = 41
    Height = 21
    TabOrder = 6
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 24
    Top = 64
    Width = 41
    Height = 21
    TabOrder = 7
    OnExit = Edit2Exit
  end
  object Edit3: TEdit
    Left = 24
    Top = 88
    Width = 41
    Height = 21
    TabOrder = 8
    OnExit = Edit3Exit
  end
  object Edit4: TEdit
    Left = 24
    Top = 112
    Width = 41
    Height = 21
    TabOrder = 9
    OnExit = Edit4Exit
  end
  object Edit5: TEdit
    Left = 24
    Top = 136
    Width = 41
    Height = 21
    TabOrder = 10
    OnExit = Edit5Exit
  end
  object Edit6: TEdit
    Left = 24
    Top = 160
    Width = 41
    Height = 21
    TabOrder = 11
    OnExit = Edit6Exit
  end
  object Edit7: TEdit
    Left = 152
    Top = 40
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 12
  end
  object Edit8: TEdit
    Left = 152
    Top = 64
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 13
  end
  object Edit9: TEdit
    Left = 152
    Top = 88
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 14
  end
  object Edit10: TEdit
    Left = 152
    Top = 112
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 15
  end
  object Edit11: TEdit
    Left = 152
    Top = 136
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 16
  end
  object Edit12: TEdit
    Left = 152
    Top = 160
    Width = 41
    Height = 21
    ReadOnly = True
    TabOrder = 17
  end
  object BitBtn5: TBitBtn
    Left = 16
    Top = 416
    Width = 313
    Height = 17
    Caption = 'Czysc Okienko Komunikatow'
    TabOrder = 18
    OnClick = BitBtn5Click
  end
end
