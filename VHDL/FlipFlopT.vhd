library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
--flip flop tipo T
entity FFT is port(
	J,K,Clr,Pre,clk: in STD_LOGIC; 
	Q, Qn : out STD_LOGIC; 
end FFT;

architecture cFFT of FFT is
begin
	process(clk,T,Pre,Clr) 
	begin
		if(Clr='0') then Q='0'; Qn='1'; --se prenden con 0 en este ff
		elsif(Pre='0') then Q='1'; Qn='0';
		elsif(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then	
				if(T='0') then
					Q<=Q;
					Qn<=not Q;
				elsif(T='1') then
					Q<=Qn;
					Qn<=not Q;
				end if
				contador<=1;
			end if
			
		end if;
	end process;
	
end cFFT;