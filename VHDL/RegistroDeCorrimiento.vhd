library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--Registro de Corrimiento
entity Registro is port(
	w,clk: in STD_LOGIC; 
	Q: out STD_LOGIC_VECTOR(2 downto 0); 
end Registro;

architecture cRegistro of Registro is
begin
	process(clk,w) 
	begin
		elsif(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then --¿Por que es asi?	
				Q(2 downto 1)<=Q(1 downto 0); --lo que tienen dos a lo que tienen dos, para ir recorriendo. SI s ehace desde el primero
				Q(0)<=w; --w simplemente es el dato
				contador<=1;
			end if
		end if;
	end process;
	
end Registro;