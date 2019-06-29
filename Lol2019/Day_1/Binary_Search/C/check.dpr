program check;

uses
	testlib, sysutils;

const
	maxn = 100000;

var
	ja, pa, n, m, i, d, e1, e2: longint;
	a, b: array [1..maxn] of longint;
	ue, ud: array [1..maxn] of boolean;

begin
	ja := ans.readlongint;
	pa := ouf.readlongint;

	if pa < ja then
		quit(_wa, format('expected: %d, found: %d', [ja, pa]));

	m := inf.readlongint;
	n := inf.readlongint;
	for i := 1 to m do
		a[i] := inf.readlongint;
	for i := 1 to n do
		b[i] := inf.readlongint;

	for i := 1 to pa do begin
		d := ouf.readlongint;
		e1 := ouf.readlongint;
		e2 := ouf.readlongint;

		if (d < 1) or (d > m) then
			quit(_wa, format('invalid deer number: %d', [d]));
		if (e1 < 1) or (e1 > n) then
			quit(_wa, format('invalid elf number: %d', [d]));
		if (e2 < 1) or (e2 > n) then
			quit(_wa, format('invalid elf number: %d', [d]));
		if ud[d] then
			quit(_wa, format('deer used twice: %d', [d]));
		ud[d] := true;
		if ue[e1] then
			quit(_wa, format('elf used twice: %d', [e1]));
		ue[e1] := true;
		if ue[e2] then
			quit(_wa, format('elf used twice: %d', [e2]));
		ue[e2] := true;

		if not ((b[e1] < a[d]) and (a[d] < b[e2])) then
			quit(_wa, format('elves %d (%d) and %d (%d) cannot ride deer %d (%d)', [e1, b[e1], e2, b[e2], d, a[d]]));
	end;

	if pa > ja then
		quit(_fail, format('expected: %d, found: %d', [ja, pa]));

	quit(_ok, format('%d deers', [pa]));
end.