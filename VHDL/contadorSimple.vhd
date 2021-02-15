library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity contadorSimple is port(
	clk: in STD_LOGIC; 
	ascdesc: in STD_LOGIC; 
	q : out STD_LOGIC_vector(6 downto 0)); 
end contadorSimple;

architecture cContadorSimple of contadorSimple is
type estados is(A,B,C,D,E,F,G,H);
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


	uno: process(edoActual)
	begin
	
		if(ascdesc='1') then --con 1 es contad asc
			case edoActual is
				when A => q<="0000001"; edoFuturo<=B; --el q es lo que se pasa al display y se asigna segmento a segmento del display
				when B => q<="1001111"; edoFuturo<=C; --codigos en 7seg de la A a la G
				when C => q<="0010010"; edoFuturo<=D;
				when D => q<="0000110"; edoFuturo<=E;
				when E => q<="1001100"; edoFuturo<=F;
				when F => q<="0100100"; edoFuturo<=G;
				when G => q<="0100000"; edoFuturo<=H;
				when H => q<="0001111"; edoFuturo<=A;
			end case;
		elsif(ascdesc='0') then
			case edoActual is
				when A => q<="0000001"; edoFuturo<=H;
				when B => q<="1001111"; edoFuturo<=A;
				when C => q<="0010010"; edoFuturo<=B;
				when D => q<="0000110"; edoFuturo<=C;
				when E => q<="1001100"; edoFuturo<=D;
				when F => q<="0100100"; edoFuturo<=E;
				when G => q<="0100000"; edoFuturo<=F;
				when H => q<="0001111"; edoFuturo<=G;
			end case;
		end if
		
	end process uno;
	
end cContadorSimple;