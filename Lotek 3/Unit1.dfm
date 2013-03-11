object Form1: TForm1
  Left = 357
  Top = 268
  BorderStyle = bsToolWindow
  Caption = '+KOLEKTURA+'
  ClientHeight = 409
  ClientWidth = 583
  Color = 7646630
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 0
    Top = 376
    Width = 577
    Height = 25
    Shape = bsFrame
  end
  object Bevel1: TBevel
    Left = 0
    Top = 8
    Width = 577
    Height = 361
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 8
    Top = 384
    Width = 30
    Height = 13
    Caption = 'Liczby'
  end
  object Label2: TLabel
    Left = 176
    Top = 144
    Width = 43
    Height = 13
    Caption = 'Wybrane'
  end
  object Label3: TLabel
    Left = 224
    Top = 144
    Width = 61
    Height = 13
    Caption = 'Wylosowane'
  end
  object Label4: TLabel
    Left = 416
    Top = 384
    Width = 49
    Height = 13
    Caption = 'Informacje'
  end
  object Bevel3: TBevel
    Left = 168
    Top = 16
    Width = 121
    Height = 345
  end
  object ListBox1: TListBox
    Left = 8
    Top = 16
    Width = 73
    Height = 345
    Color = cl3DLight
    Columns = 2
    ItemHeight = 13
    Items.Strings = (
      '1'
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
      '2'
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
      '3'
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
      '4'
      '40'
      '41'
      '42'
      '43'
      '44'
      '45'
      '46'
      '47'
      '48'
      '49'
      '5'
      '6'
      '7'
      '8'
      '9')
    Sorted = True
    TabOrder = 0
  end
  object ListBox2: TListBox
    Left = 176
    Top = 24
    Width = 41
    Height = 113
    BevelKind = bkFlat
    Color = clScrollBar
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
  end
  object BitBtn1: TBitBtn
    Left = 88
    Top = 16
    Width = 73
    Height = 169
    Caption = '->'
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 88
    Top = 192
    Width = 73
    Height = 169
    Caption = '<-'
    TabOrder = 3
    OnClick = BitBtn2Click
  end
  object ListBox3: TListBox
    Left = 240
    Top = 24
    Width = 41
    Height = 113
    BevelKind = bkFlat
    Color = clScrollBar
    ItemHeight = 13
    Sorted = True
    TabOrder = 4
  end
  object Button1: TButton
    Left = 176
    Top = 160
    Width = 105
    Height = 41
    Caption = 'Draw'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 200
    Width = 105
    Height = 41
    Caption = 'Clear'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 240
    Width = 105
    Height = 41
    Caption = 'Stats'
    TabOrder = 7
    OnClick = Button3Click
  end
  object StringGrid1: TStringGrid
    Left = 304
    Top = 16
    Width = 265
    Height = 345
    Color = cl3DLight
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    TabOrder = 8
    ColWidths = (
      92
      106)
  end
  object BitBtn3: TBitBtn
    Left = 176
    Top = 280
    Width = 105
    Height = 41
    Caption = 'Winners'
    TabOrder = 9
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 176
    Top = 320
    Width = 105
    Height = 33
    Caption = 'Quit'
    TabOrder = 10
    OnClick = BitBtn4Click
  end
end
