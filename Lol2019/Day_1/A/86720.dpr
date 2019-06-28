program fsd;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
 n,ans,i,m,u,v:integer;
 s :array [1..100,1..100] of integer;
 used :array [1..100] of boolean;
 p:array [1..100] of integer;
procedure dfs(u:integer);
var
 i:integer;
begin
 used[u]:=true;
 inc (ans);
 for i:=1 to n do
  if (s[u][i]=1) then begin
   if p[i]=p[u] then begin
     writeln ('NO');
     halt;
   end;
   p[i]:=3-p[u];
   if not (used[i]) then
   dfs(i);
  end;
end;
begin
//reset (input,'input.txt');
//rewrite (output,'output.txt');
 readln (n,m);
 for i:=1 to n do
  p[i]:=0;
 for i:=1 to m do begin
   readln (u,v);
   s[u][v]:=1;
   s[v][u]:=1;
 end;
 for i:=1 to n do begin
  if not (used[i]) then begin
   p[i]:=1;
   dfs(i);
  end;
 end;
 writeln ('YES');
 for i:=1 to n do begin
    if p[i]=1 then
     write(i,' ');
 end;
// close (input);
// close (output);
end.
