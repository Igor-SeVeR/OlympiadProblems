uses testlib;

var n,o,a,i:longint;

begin
a:=ans.readlongint;
o:=ouf.readinteger;
if (a=0) and (o=0) then begin
  if ans.readlongint=ouf.readlongint then quit(_OK,'No solution');
  quit (_WA,'Wrong number of train when No solution');
  end;
if (a=0) and (o<>0) then
  quit(_WA,'Found solution when No solution');
if (o=0) and (a<>0) then
  quit(_WA,'No solution when solution exists');
if a<>o then quit(_WA,'');
n:=inf.readlongint;
n:=inf.readlongint;
for i:=2 to n do
  if ans.readlongint<>ouf.readlongint then quit(_WA,'');
quit(_OK,'');
end.
