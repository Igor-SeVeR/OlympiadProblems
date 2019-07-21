uses
    testlib, sysutils;

var
    i, n, ja, pa: longint;
    a, b, c: array [1..300000] of longint;

begin
    n := inf.readlongint;
    for i := 1 to n do
    begin
        a[i] := inf.readlongint;
    end;

    ja := ans.readlongint;
    pa := ouf.readlongint;
    if ja <> pa then
        quit(_wa, 'expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    for i := 1 to n do
    begin
        c[i] := ouf.readlongint;
        if (c[i] < 1) or (c[i] > pa) then
            quit(_wa, 'invalid color: ' + inttostr(c[i]));
        if b[c[i]] <> 0 then
            if a[b[c[i]]] >= a[i] then
                quit(_wa, 'not increasing for color ' + inttostr(c[i]));
            
        b[c[i]] := i;
    end;

    quit(_ok, '');
end.