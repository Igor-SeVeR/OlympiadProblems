uses testlib;

var s1,s2:string;

function dostr(s:string):string;
  var q:string;
      i:integer;
  begin
  q:='';
  for i:=1 to length(s) do
    if s[i] in ['a'..'z','A'..'Z','0'..'9'] then
      q:=q+upcase(s[i]);

  dostr:=q;
  end;


begin
s1:=dostr(ouf.readstring);
s2:=dostr(ans.readstring);
if s1=s2 then quit(_OK,s1);
if (s1='YES') or (s1='NO') then quit(_WA,'');
quit(_PE,'');
end.

