{$APPTYPE CONSOLE}

uses testlib;

const nmax=500;
      mmax=500;

var a,b:array[1..nmax*mmax] of longint;
    c:array[1..nmax] of longint;
    n:integer;

procedure readinf;
  var i,j,k:longint;
      kk:longint;
  begin
  kk:=0;
  n:=inf.readinteger;
  for i:=1 to n do begin
    k:=inf.readinteger;
    if k=0 then
      c[i]:=0
    else begin
      inc(kk);
      a[kk]:=inf.readinteger;
      b[kk]:=0;
      for j:=2 to k do begin
        inc(kk);
        a[kk]:=inf.readinteger;
        b[kk]:=kk-1;
        end;
      c[i]:=kk;
      end;
    end;
  end;

procedure nosol;
  begin
  if ans.readinteger=0 then quit(_OK,'No solution');
  quit(_WA,'No solution when solution exists');
  end;

procedure swap(q,w:integer);
  var e:integer;
  begin
  if (q<1) or (q>n) or (w<1) or (w>n) then quit(_PE,'Integer in output is not in 1..N');
  if q=w then exit;
  if (c[q]=0) then quit(_WA,'Take from empty pile');
  e:=c[q];
  c[q]:=b[e];
  b[e]:=c[w];
  c[w]:=e;
  end;


procedure readouf;
  var q,w:integer;
  begin
  if ouf.seekeof then exit;
  q:=ouf.readinteger;
  if q=0 then nosol;
  w:=ouf.readinteger;
  swap(q,w);
  while not ouf.seekeof do begin
    q:=ouf.readinteger;
    w:=ouf.readinteger;
    swap(q,w);
    end;
  end;

procedure checkres;
  var i,j:integer;
  begin
  for i:=1 to n do begin
    j:=c[i];
    while j<>0 do begin
      if a[j]<>i then quit(_WA,'Final position of boxes is wrong');
      j:=b[j];
      end;
    end;
  if ans.readinteger=1 then quit(_OK,'');
  quit(_Fail,'Found solution when no solution');
  end;



begin
readinf;
readouf;
checkres;
end.
