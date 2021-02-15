library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--flip flop tipo JK
entity FFJK is port(
	J,K,Clr,Pre,clk: in STD_LOGIC; 
	Q, Qn : out STD_LOGIC; 
end FFJK;

architecture cFFJK of FFJK is
begin
	process(clk,J,K,Pre,Clr) 
	begin
		if(Clr='0') then Q='0'; Qn='1'; --se prenden con 0 en este ff
		elsif(Pre='0') then Q='1'; Qn='0';
		elsif(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then	
				Q<=(J and (not(Q))) or ((not(K)) and Q); --resultado de la funcion de su tabla de verdad
				Qn<=not(D);
				contador<=1;
			end if
			
		end if;
	end process;
	
end cFFJK;