library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--contador anillo de dos bits
entity contador is port(
	clk: in STD_LOGIC; 
	Q : out STD_LOGIC_vector(1 downto 0)); 
end contador;

architecture cContador of contador is
type estados is(A,B,C,D);
signal edoActual, edoFuturo: estados;
signal contador : integer :=1;
begin
	
	cero: process(clk) 
	begin
		if(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then	
				edoActual<=edoFuturo;
				contador<=1;
			end if
			
		end if;
	end process cero;


	uno: process(edoActual) --no hace falta hacer algo con un pulso pues en el proceso de arriba cada que se cumple el tiempo, pasa automaticamente al estado siguiente
	begin
		case edoActual is
			when A => Q<="00"; edoFuturo<=B; --el Q obtiene el valor del estado al que avanza
			when B => Q<="01"; edoFuturo<=C; 
			when C => Q<="10"; edoFuturo<=D;
			when D => Q<="11"; edoFuturo<=A;
		end case;
		
	end process uno;
	
end cContador;