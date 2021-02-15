library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--flip flop tipo D
entity FFD is port(
	D,Clr,Pre,clk: in STD_LOGIC; 
	Q, Qn : out STD_LOGIC; 
end FFD;

architecture cFFD of FFD is
begin
	process(clk,D,Pre,Clr) 
	begin
		if(Clr='0') then Q='0'; Qn='1'; --se prenden con 0 en este ff
		elsif(Pre='0') then Q='1'; Qn='0';
		elsif(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then	
				Q<=D;
				Qn<=not(D);
				contador<=1;
			end if
			
		end if;
	end process;
	
end cFFD;