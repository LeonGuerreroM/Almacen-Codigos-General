library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity MaquinaEstados is port(
	clk, x, reset : in STD_LOGIC; --x es la señal de entrada
	Pulso : inout  STD_LOGIC:='0';
	y : out STD_LOGIC); 
end MaquinaEstados;

architecture Behavioral of MaquinaEstados is --se ponen señales y constantes. Dentro de la entidad van variables I/O
	type estados is (A,B,C); --identifica el tipo de dato a usar
	signal edoPresente, edoFuturo : estados; --del mismo tipo de dato de abc para asignar los valores de a b c
	signal count : integer :=1;
begin --los procesos se ejecutan como procesos clasicos
	uno : process(edoPresente,x) --identifica donde estoy y que me llega para cambiar de estado
	begin
		case(edoPresente) is --se va moviendo en el diagrama de estados 
			when A=> if (x='0')then edoFuturo <=A; y<='0';
						else edoFuturo <=B; y<='0'; end if;
			when B=> if (x='0')then edoFuturo <=C; y<='0';
						else edoFuturo <=B; y<='0'; end if;
			when C=> if (x='0')then edoFuturo <=A; y<='0';
						else edoFuturo <=A; y<='1'; end if;
		end case;
	end process uno;
	
	dos: process(clk, reset)
	begin
		if(reset='1') then edoPresente<=A;
		elsif(clk'event and clk='1') then 
			count <= count+1;
			if(count = 50000000) then --25M para ciclo de un Hz, la mitad de subida y la mitad de bajada. Con f=50MHz. Nexys 3 con 100MHZ
				Pulso <=not Pulso;
				count <=1;--edoPresente<=edoFuturo;
			end if;
			if(Pulso = 1) then edoPresente<=edoFuturo; end if;
		end if;
	end process dos;
end Behavioral;
