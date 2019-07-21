program sd;
Var a,s:array[0..101,0..101]of shortint;
    b:array[1..10000,1..2]of integer;
    i,j,n,m,k,j1,i1,t,c:integer;
begin
read(n,m);
for i:=1 to n do begin
 readln;
 for j:=1 to m do begin
  read(a[i,j]);
  if a[i,j]=0 then a[i,j]:=3;
 end;
end;

b[1,1]:=1;
b[1,2]:=1;
s[1,1]:=1;
j:=1;
j1:=2;
While j<>j1 do begin
 inc(c);
 k:=j1;
 for i:=j to j1-1 do begin
  i1:=b[i,1];
  t:=b[i,2];
  While a[i1+1,t]=3 do
   inc(i1);
  if a[i1+1,t]=2 then begin writeln(c); halt(0) end;
  if (i1<>b[i,1])and(s[i1,t]=0) then
   begin b[k,1]:=i1; b[k,2]:=t; s[i1,t]:=1;inc(k); end;
  i1:=b[i,1];
  While a[i1-1,t]=3 do
   dec(i1);
  if a[i1-1,t]=2 then begin writeln(c); halt(0) end;
  if (i1<>b[i,1])and(s[i1,t]=0) then
   begin b[k,1]:=i1; b[k,2]:=t; s[i1,t]:=1;inc(k); end;
  i1:=b[i,1];
  While a[i1,t+1]=3 do
   inc(t);
  if a[i1,t+1]=2 then begin writeln(c); halt(0) end;
  if (t<>b[i,2])and(s[i1,t]=0) then
   begin b[k,1]:=i1; b[k,2]:=t; s[i1,t]:=1;inc(k); end;
  t:=b[i,2];
  While a[i1,t-1]=3 do
   dec(t);
  if a[i1,t-1]=2 then begin writeln(c); halt(0) end;
  if (t<>b[i,2])and(s[i1,t]=0) then
   begin b[k,1]:=i1; b[k,2]:=t;inc(k); s[i1,t]:=1; end
 end;
 j:=j1; j1:=k;
end
end.
