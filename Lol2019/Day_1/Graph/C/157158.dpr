{$I+,Q+,R+,S+}

Const
 Nmax=101;
 InpFile='c.in';
 OutFile='c.out';

Type
 Int=longint;

var
 pole,paint: array[0..Nmax,0..Nmax] of int;
 s: array[1..Nmax*Nmax] of int;
 n,m: int;
 answer,num: int;

procedure InpData;
 var
  i,j: int;
begin
 fillchar(pole,sizeof(pole),63);
   readln(n,m);
   for i:=1 to n do
     for j:=1 to m do
       read(pole[i,j]);
end;

procedure go(x,y: int);
begin
  if paint[x,y]<>0 then exit;
  paint[x,y]:=num;

  if ((x-1) in [1..N]) and (y in [1..M]) then begin
    if pole[x-1,y]=pole[x,y] then go(x-1,y);
    if pole[x-1,y]<pole[x,y] then s[num]:=1;
  end;

  if ((x+1) in [1..N]) and (y in [1..M]) then begin
    if pole[x+1,y]=pole[x,y] then go(x+1,y);
    if pole[x+1,y]<pole[x,y] then s[num]:=1;
  end;

  if (x in [1..N]) and ((y-1) in [1..M]) then begin
    if pole[x,y-1]=pole[x,y] then go(x,y-1);
    if pole[x,y-1]<pole[x,y] then s[num]:=1;
  end;

  if (x in [1..N]) and ((y+1) in [1..M]) then begin
    if pole[x,y+1]=pole[x,y] then go(x,y+1);
    if pole[x,y+1]<pole[x,y] then s[num]:=1;
  end;

end;

procedure Solve;
 var
  i,j: int;
begin
  fillchar(paint,sizeof(paint),0);
  fillchar(s,sizeof(s),0);
  answer:=0;
  num:=0;

  for i:=1 to n do
    for j:=1 to m do
      if paint[i,j]=0 then begin
        inc(num);
        go(i,j);
      end;

  for i:=1 to Num do
    if s[i]=0 then inc(answer);
end;

procedure OutData;
begin
    writeln(answer);
end;

begin
 InpData;
 Solve;
 OutData;
end.
