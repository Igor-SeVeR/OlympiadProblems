uses SysUtils, testlib;
const NN = 100;

var
n,m:longint;
ja,ca: string;
color: array [1..NN] of longint;
i,j,x,y:longint;

begin
	ja:=ans.readstring;
	ca:=ouf.readstring;
	if ca='NO' then begin
		if ja='NO' then
			quit(_ok,'Answer NO')
		else
			quit(_wa,'NO when solution exists');
	end;
	n:=inf.readlongint;
	m:=inf.readlongint;
	for i:=1 to n do color[i]:=0;
	while not (ouf.seekeof) do begin
		j:=ouf.readlongint;
		if (j<1)or(j>n) then quit(_pe,'Invalid number');
		color[j]:=1;
	end;
	for i:=1 to m do begin
		x:=inf.readlongint;
		y:=inf.readlongint;
		if color[x]=color[y] then quit(_wa,'Incorrect');
	end;
	if ja='NO' then quit(_fail,'Contestant is better');
	quit(_ok,'Ok!!!');
end.
