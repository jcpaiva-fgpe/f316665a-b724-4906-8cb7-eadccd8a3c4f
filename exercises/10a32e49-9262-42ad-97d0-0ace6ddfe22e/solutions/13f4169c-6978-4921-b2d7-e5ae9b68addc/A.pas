program bola;

var
   pa, pb, jornadas :  Integer;

begin

   Read(pa,pb,jornadas);


  If (pa >= pb+3*jornadas) Then
    Writeln(':-D')
  else If (pa +3*jornadas <= pb) Then    
    Writeln(':-(')
  else If (pa > pb) Then
    Writeln(':-)')
  else 
    Writeln(':-|');

end.
