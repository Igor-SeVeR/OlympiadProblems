uses testlib,SysUtils;
const
	MaxK = 100;
var
	K: longint;
	a: array [1..MaxK,1..MaxK] of longint;
	score: array [1..MaxK] of longint;
	i,j,s: longint;
begin
	K := inf.readlongint;
	for i := 1 to K do
		score[i] := inf.readlongint;
	for i := 1 to K do
		for j := 1 to K do
			a[i,j] := ouf.readlongint;
	for i := 1 to K do begin
		for j := i+1 to K do begin
			if a[i,j] < 0 then quit(_wa,'Not a valid table');
			if a[i,j] > 2 then quit(_wa,'Not a valid table');
			if a[i,j] + a[j,i] <> 2 then quit(_wa,'Not a valid table');
		end;
		if a[i,i] <> 0 then quit(_wa,'Not a valid table');
	end;
	for i := 1 to K do begin
		s := 0;
		for j := 1 to K do begin
			s := s + a[i,j];
		end;
		if s <> score[i] then quit(_wa,'Team '+inttostr(i)+': score mismatch');
	end;
	quit(_ok,'');
end.
