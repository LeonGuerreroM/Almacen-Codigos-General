library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;


entity  semaforos
    Port (  clk 	: in  STD_LOGIC;	
				pulso	: inout  STD_LOGIC:='0';
				sensor1	:in	STD_LOGIC;
				sensor2	:in	STD_LOGIC;
				semaforo1	: out std_logic_vector(1 downto 0);
				semaforo2: out std_logic_vector(1 downto 0)); 
				
				
end semaforos;

architecture cSemaforos of semaforos is
signal contador : integer :=1;
begin

    cero:process(clk) 
	begin
	  
		if(clk'event and clk='1') then --Cada que haya un flanco de subida (solo en el flanco)
	  				contador <=contador+1;
				if(contador = 25000000) then --count = freq barrido --250MHz para medio segundo
					pulso <= not pulso;
					contador <=1;
				end if;
		end if;
		
	end process cero;
		
		
	uno:process(pulso) 
	VARIABLE autos : integer:=0;
	VARIABLE semaforoActual : bit:='0';
	begin
	
		if(pulso'event and pulso='1') then
			if( sensor1='1' and semaforoActual='0' ) then
				autos:=autos+1;
				
				if(autos1 = 5) then 
					autos:=0;
					semaforoActual:='1';
				end if;
			
			elsif( sensor2='1' and semaforoActual='1' ) then
				autos:=autos+1;
			
				if(autos = 5) then 
					autos:=0;
					semaforoActual:='0';
				end if;
				
			end if;
			
		end if;

	
		if(semaforoActual='0') then 
						semaforo1 <="01";
						semaforo2 <="10";
			
		elsif(semaforoActual='1') then
						semaforo1 <="10";
						semaforo2 <="01";		

		end if;		
		
	end process uno;
	
	
end cSemaforos;

//////////////////////////////////////////////////////
///////////////////////////////////////////////////////

				
net "semauno(0)" loc=;
NET "semauno(1)" loc=;
NET "semados(0)" loc=;
NET "semados(1)" loc=;

net "clk" loc=b8;
net "pulbar" loc=j14;

NET "suno" loc=;
NET "sdos" loc=;

