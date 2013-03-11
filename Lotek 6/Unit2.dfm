object Form2: TForm2
  Left = 219
  Top = 229
  Width = 532
  Height = 484
  Caption = 'InformacjE'
  Color = 10802681
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 16
    Top = 8
    Width = 497
    Height = 393
  end
  object Label1: TLabel
    Left = 24
    Top = 408
    Width = 97
    Height = 13
    Caption = 'Statystyki numerkow'
  end
  object Label2: TLabel
    Left = 272
    Top = 408
    Width = 43
    Height = 13
    Caption = 'Wygrane'
  end
  object Memo1: TMemo
    Left = 24
    Top = 16
    Width = 225
    Height = 377
    Color = clMoneyGreen
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 264
    Top = 16
    Width = 241
    Height = 377
    Color = clMoneyGreen
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 424
    Width = 497
    Height = 25
    Caption = 'ZamkniJ OknO StatystyK'
    TabOrder = 2
    OnClick = BitBtn1Click
  end
end
