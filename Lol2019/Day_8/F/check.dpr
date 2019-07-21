uses testlib, SysUtils;
const
	M_MAX = 100000;
	N_MAX = 1000;
type
	int = longint;
	tEdge = record
		ve : int;
		ne : int;
	end;

var
	n,m : int;
	u,v : array [1..M_MAX] of int;
	an, ran : int;
	a,b : int;
	f : array [1..N_MAX] of int;
	edge : array [1..2*M_MAX] of tEdge;
	marked : array [1..N_MAX] of boolean;
	inve : int;
	i : int;

procedure add(a,b,i: int);
begin
	{check vertex}
	if ((a<>u[i]) or (b<>v[i])) and ((a<>v[i]) or (b<>u[i])) then quit(_pe,'Illegal edge.');
	{add edge}
	edge[2*i-1].ve := b;
	edge[2*i-1].ne := f[a];
	f[a] := 2*i-1;		

	edge[2*i].ve := -a;
	edge[2*i].ne := f[b];
	f[b] := 2*i;
end;

procedure dfs(k : int);
var
	p : int;
begin
	marked[k] := true;	
	p := f[k];
	while (p<>0) do begin
		if (edge[p].ve*inve>0) then
			if (not marked[edge[p].ve*inve]) then dfs(edge[p].ve*inve);		
		p := edge[p].ne;
	end;
end;

procedure check_1connectness(t : int);
var
	i : int;
begin
	inve := t; {transposed (-1) or not (1)}
	fillchar(marked,sizeof(marked),0);
	dfs(1);
	for i:=1 to n do 
		if not marked[i] then quit(_wa,'Graph is not strongly connected - '+inttostr(i)+' vertex')
end;

begin	
	{get N and M}
	n := inf.readlongint;
	m := inf.readlongint;
	{check whether participant's solution is correct (if exists)}
	an := ouf.readlongint;
    if (an<>0) then 
    begin {participant offers solution} 		
		{get edges}
		for i:=1 to m do
		begin
			u[i] := inf.readlongint;
			v[i] := inf.readlongint;
		end;
		fillchar(f,sizeof(f),0);		
		a := an;
		b := ouf.readlongint;
		{check numbers}
		add(a,b,1);
		for i:=2 to m do 
		begin
			a := ouf.readlongint;
			b := ouf.readlongint;
			add(a,b,i);
		end;

		check_1connectness(1); {normal graph}
		check_1connectness(-1); {transposed graph}
	
    end;

    ran := ans.readlongint;
    if (an<>0) and (ran=0) then quit(_fail,'Participant find correct solution, but not we!');
    if (an=0) and (ran<>0) then quit(_wa,'Participant do not find solution, but it exists.');
    
    quit(_ok,'N='+inttostr(n)+' M='+inttostr(m)+' EXISTS=('+inttostr(ran)+'!=0)');

end.