object Form1: TForm1
  Left = 329
  Top = 146
  Width = 544
  Height = 412
  Caption = 'TOTO LOTEK'
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 232
    Top = 72
    Width = 297
    Height = 289
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 216
    Top = 8
    Width = 87
    Height = 13
    Caption = 'Liczby obstawiane'
  end
  object Label2: TLabel
    Left = 216
    Top = 40
    Width = 91
    Height = 13
    Caption = 'Liczby wylosowane'
  end
  object message_wnd: TMemo
    Left = 240
    Top = 80
    Width = 281
    Height = 273
    Cursor = crHandPoint
    BevelInner = bvLowered
    BevelKind = bkSoft
    Color = 1546581
    Ctl3D = True
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = 1109860
    Font.Height = -12
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentCtl3D = False
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 0
    Width = 201
    Height = 57
    Color = 1546581
    ColCount = 6
    Ctl3D = False
    DefaultColWidth = 32
    FixedColor = clSkyBlue
    FixedCols = 0
    RowCount = 2
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 1109860
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goHorzLine, goRangeSelect]
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 64
    Width = 217
    Height = 297
    Caption = 'Liczby obstawiane'
    Ctl3D = False
    ParentCtl3D = False
    TabOrder = 2
    object TrackBar1: TTrackBar
      Left = 8
      Top = 16
      Width = 45
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 0
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar1Change
    end
    object TrackBar2: TTrackBar
      Left = 40
      Top = 16
      Width = 45
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 1
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar2Change
    end
    object TrackBar3: TTrackBar
      Left = 72
      Top = 16
      Width = 25
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 2
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar3Change
    end
    object TrackBar4: TTrackBar
      Left = 104
      Top = 16
      Width = 45
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 3
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar4Change
    end
    object TrackBar5: TTrackBar
      Left = 136
      Top = 16
      Width = 45
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 4
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar5Change
    end
    object TrackBar6: TTrackBar
      Left = 168
      Top = 16
      Width = 45
      Height = 273
      Max = 49
      Min = 1
      Orientation = trVertical
      Frequency = 1
      Position = 1
      SelEnd = 0
      SelStart = 0
      TabOrder = 5
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = TrackBar6Change
    end
  end
  object StaticText1: TStaticText
    Left = 328
    Top = 0
    Width = 195
    Height = 31
    Caption = 'Toto Lotek ver.1.0'
    Color = clInactiveBorder
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clNavy
    Font.Height = -19
    Font.Name = 'Arial Black'
    Font.Style = [fsItalic]
    ParentColor = False
    ParentFont = False
    TabOrder = 3
  end
  object MainMenu1: TMainMenu
    Left = 496
    Top = 40
    object LOSUJ1: TMenuItem
      Caption = 'LOSOWANIE'
      OnClick = LOSUJ1Click
    end
    object WYSW1: TMenuItem
      Caption = 'STATYSTYKI'
      object Numerkow1: TMenuItem
        Caption = 'Numerkow'
        OnClick = Numerkow1Click
      end
      object Wygranych1: TMenuItem
        Caption = 'Wygranych'
        OnClick = Wygranych1Click
      end
    end
    object WYJSCIE1: TMenuItem
      Caption = 'WYJSCIE'
      OnClick = WYJSCIE1Click
    end
    object CZYSCMSG1: TMenuItem
      Caption = 'CZYSC MSG'
      OnClick = CZYSCMSG1Click
    end
  end
end
