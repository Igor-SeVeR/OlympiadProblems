{$APPTYPE CONSOLE}

uses testlib, SysUtils;

const
	maxn = 10000;
	maxm = 1000000;

type
	tarr = array of integer;
	tarrarr = array of tarr;
		
procedure qsort(var a : tarr);

    procedure qsort(l, r : integer);
    var
    	i, j : integer;
        x, t : integer;

    begin
		i := l;
        j := r;
        x := a[l + random(r - l)];
        while i <= j do begin
        	while a[i] < x do
            	inc(i);
            while x < a[j] do
            	dec(j);
            if i <= j then begin
            	t := a[i];
                a[i] := a[j];
                a[j] := t;
            	inc(i);
                dec(j);
            end;
        end;
        if l < j then
        	qsort(l, j);
        if i < r then
        	qsort(i, r);
    end;

begin
	qsort(0, length(a) - 1);
end;

function isLess(const a, b : tarr) : boolean;
var
	i : integer;
begin
	if length(a) < length(b) then begin
		isLess := true;
		exit;
	end;

	if length(a) > length(b) then begin
		isLess := false;
		exit;
	end;

	for i := 0 to length(a) - 1 do begin
		if a[i] < b[i] then begin
			isLess := true;
			exit;
		end;
		if a[i] > b[i] then begin
			isLess := false;
			exit;
		end;
	end;
	
	isLess := false;
end;

function areEqual(const a, b : tarr) : boolean;
begin
	areEqual := not isLess(a, b) and not isLess(b, a);
end;
	
procedure qsort2(var a : tarrarr);

    procedure qsort2(l, r : integer);
    var
    	i, j : integer;
        x, t : tarr;

    begin
		i := l;
        j := r;
        x := a[l + random(r - l)];
        while i <= j do begin
        	while isLess(a[i], x) do
            	inc(i);
            while isLess(x, a[j]) do
            	dec(j);
            if i <= j then begin
            	t := a[i];
                a[i] := a[j];
                a[j] := t;
            	inc(i);
                dec(j);
            end;
        end;
        if l < j then
        	qsort2(l, j);
        if i < r then
        	qsort2(i, r);
    end;

	
begin
	qsort2(0, length(a) - 1);
end;

var                
	tmpArray : array[0..maxn - 1] of integer;
	
	
procedure readArray(var s : instream; var a : tarr);
var
	i, n : integer;
	
begin
	n := 0;
	while not s.seekeoln do begin
		if n >= maxn then
			quit(_wa, 'List is too long');
		tmpArray[n] := s.readInteger;
		inc(n);
	end;
	s.nextline;
	setlength(a, n);
	for i := 0 to n - 1 do
		a[i] := tmpArray[i];
end;

var
	ja, pa : tarrarr;

var
	tmpArray2 : array[0..maxm - 1] of tarr;

procedure readArrays(var s : instream; var a : tarrarr);
var
	i, m : integer;

begin
	m := 0;
	while not s.seekeof do begin
		if m >= maxm then
			quit(_wa, 'Too many lists');
		readArray(s, tmpArray2[m]);
		qsort(tmpArray2[m]);
		inc(m);
	end;
	if m=0 then
		quit(_pe,'');
	setlength(a, m);
	for i := 0 to m - 1 do
		a[i] := tmpArray2[i];
	qsort2(a);
end;

procedure dump(const a : tarrarr);
var
	i, j : integer;
	
begin
	for i := 0 to length(a) - 1 do begin
		for j := 0 to length(a[i]) - 1 do
			write(a[i][j], ' ');
		writeln;
	end;		
end;

var
	i : integer;
    
begin
	write('reading and sorting answer... ');
	readArrays(ans, ja);
	writeln('done');
    
	write('reading ans sorting output... ');
	readArrays(ouf, pa);
	writeln('done');

    if length(ja) <> length(pa) then
    	quit(_wa, format('Number of lists differ: %d != %d', [length(pa), length(ja)]));

	write('comparing... ');
    for i := 0 to length(ja) - 1 do
    	if not areEqual(pa[i], ja[i]) then
        	quit(_wa, 'List content differs');
	writeln('done');
	
    quit(_OK, '');
end.
