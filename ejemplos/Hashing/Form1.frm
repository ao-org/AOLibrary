VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3030
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   4560
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   8.25
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   3030
   ScaleWidth      =   4560
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox chkVerificar 
      Caption         =   "Comparar"
      Height          =   255
      Left            =   3240
      TabIndex        =   3
      Top             =   2280
      Width           =   1095
   End
   Begin VB.CommandButton cmdHash 
      Caption         =   "Hash"
      Height          =   360
      Left            =   1800
      TabIndex        =   2
      Top             =   2160
      Width           =   990
   End
   Begin VB.TextBox txtHashed 
      Height          =   495
      Left            =   360
      TabIndex        =   1
      Top             =   1320
      Width           =   3735
   End
   Begin VB.TextBox txtRaw 
      Height          =   495
      Left            =   360
      TabIndex        =   0
      Top             =   480
      Width           =   3735
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Declare Function HashPassword Lib "AOLibrary.dll" (ByVal RawPassword As String, Optional ByVal Workload As Byte = 5) As String
Private Declare Function VerifyPassword Lib "AOLibrary.dll" (ByVal RawPassword As String, ByVal HashedPassword As String) As Boolean

Private Sub cmdHash_Click()
    
    If chkVerificar.Value = vbChecked Then
    
        If VerifyPassword(txtRaw.Text, txtHashed.Text) Then
            MsgBox "COINCIDEN"
        Else
            MsgBox "NO COINCIDEN"
        End If
        
    Else
        txtHashed.Text = HashPassword(txtRaw.Text)
    End If
    
End Sub
