{$APPTYPE CONSOLE}
{$R+,Q+,S+,I+,H+,O-}
{$MINSTACKSIZE 4000000}
Uses SysUtils,testlib;

Const
  MaxN=100000;
  SkipChar='-';
  SitChar='+';

Type
  Integer=LongInt;
  TArr=Array[1..MaxN*2+50]Of Integer;

Function EvaluateJumps(N,X:Integer; Const A:TArr; S:String):Integer;
Var
  Left,Right:TArr;
  I,LFirst,LLast,RFirst,RLast,LAt,RAt:Integer;
  WeSit:Boolean;
Begin
  FillChar(Left,SizeOf(Left),0);
  FillChar(Right,SizeOf(Right),0);

  LFirst:=1;
  LLast:=1;
  Left[1]:=0;
  For I:=1 To X-1 Do If A[I]<=A[X] Then Begin
    If Odd(LLast) Then Begin
      Inc(LLast);
      Left[LLast]:=0;
    End;
    Inc(Left[LLast]);
  End Else Begin
    If Not Odd(LLast) Then Begin
      Inc(LLast);
      Left[LLast]:=0;
    End;
    Inc(Left[LLast]);
  End;
  If Not Odd(LLast) Then Begin
    Inc(LLast);
    Left[LLast]:=0;
  End;

  RFirst:=1;
  RLast:=3;
  Right[1]:=0;
  Right[2]:=0;
  Right[3]:=0;
  For I:=X+1 To N Do If A[I]<A[X] Then Begin
    If Odd(RLast) Then Begin
      Inc(RLast);
      Right[RLast]:=0;
    End;
    Inc(Right[RLast]);
  End Else Begin
    If Not Odd(RLast) Then Begin
      Inc(RLast);
      Right[RLast]:=0;
    End;
    Inc(Right[RLast]);
  End;
  If Not Odd(RLast) Then Begin
    Inc(RLast);
    Right[RLast]:=0;
  End;

  LAt:=1;
  RAt:=1;

  For I:=1 To N-1 Do Begin
    WeSit:=S[I]=SitChar;

    While (LAt<=LLast-2) And (Left[LAt]=0) Do Inc(LAt,2);
    If (Left[LAt]>0) Then Begin
      Dec(Left[LAt]);
      Inc(Left[LLast]);
      If Not WeSit Then Begin
        Dec(Left[LLast]);
        Inc(Right[RAt]);
      End;
    End Else Begin
      If Not WeSit Then Begin
        While (RFirst<RLast) And (Right[RFirst]=0) Do Begin
          Inc(RFirst);
          Inc(LLast);
          Left[LLast]:=Right[RFirst];
          Inc(RFirst);
          Inc(LLast);
          Left[LLast]:=0;
        End;
        If RAt<RFirst Then RAt:=RFirst;
      End;
    End;

    While (RAt<=RLast-2) And (Right[RAt]=0) Do Inc(RAt,2);
    If (Right[RAt]>0) Then Begin
      Dec(Right[RAt]);
      Inc(Right[RLast]);
    End;
  End;

  Result:=1;
  For I:=LFirst To LLast Do Inc(Result,Left[I]);
End;

Var
  N,X,K,I:Integer;
  A:TArr;
  Cnt,Y,Jury,Z:Integer;
  S:String;

Begin
  N:=Inf.ReadLongInt;
  X:=Inf.ReadLongInt;
  K:=Inf.ReadLongInt;
  For I:=1 To N Do A[I]:=Inf.ReadLongInt;

  Y:=Ouf.ReadLongInt;
  If (Y<1) Or (Y>N) Then Quit(_WA,'');
  S:=Ouf.ReadWord(NumberBefore,NumberAfter);
  If Length(S)<>N-1 Then Quit(_PE,'');
  For I:=1 To N-1 Do
    If (S[I]<>SkipChar) And (S[I]<>SitChar) Then Quit(_PE,'');
  Cnt:=0;
  For I:=1 To N-1 Do If S[I]=SitChar Then Inc(Cnt);
  If Cnt>K Then Quit(_WA,'');

  Z:=EvaluateJumps(N,X,A,S);

  If Y<>Z Then Quit(_WA,'');

  Jury:=Ans.ReadLongInt;
  If Y>Jury Then Quit(_WA,'');
  If Y<Jury Then Quit(_Fail,Format('The answer of contestant is better: %d instead of %d', [Y, Jury]));

  Quit(_OK,Format('N = %d, K = %d', [N, K]));
End.
