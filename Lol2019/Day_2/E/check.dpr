{$APPTYPE CONSOLE}

uses testlib, SysUtils;

var 
	n, i: longint;
	ja, pa: string;

begin
	While true do
	begin
		if (ouf.seekeof) and (ans.seekeof) then quit(_ok, '');
		if (ouf.seekeof) or (ans.seekeof) then quit(_pe, 'Wrong number of lines');
		ja := ans.readstring;
		pa := ouf.readstring;
		if (ja <> pa) then quit(_wa, 'line #' + inttostr(i));
	end;
end.
