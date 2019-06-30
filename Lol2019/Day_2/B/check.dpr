uses testlib;
begin
if abs(ans.readreal-ouf.readreal)<0.015 then quit(_OK,'');
quit(_wa,'');
end.