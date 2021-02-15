library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_unsigned.ALL;


entity  semaforos
    Port (  clk 	: in  STD_LOGIC;	
				pulso	: inout  STD_LOGIC:='0';
				sensor1	:in	STD_LOGIC;
				sensor2	:in	STD_LOGIC;
				semaforo1	: out std_logic_vector(2 downto 0);
				semaforo2: out std_logic_vector(2 downto 0)); 
				
				
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
	VARIABLE autos1 : integer:=0;
	VARIABLE pedirAmarillo : integer:=0;
	VARIABLE semaforoActual : bit:='0'
	VARIABLE cont : integer:=0;
	begin
	
		if(pulso'event and pulso='1') then
			if( sensor1='1' and semaforoActual='0' ) then
				autos1:=autos1+1;
				
				if(autos1 = 5) then 
					autos1:=0;
					pedirAmarillo:=1;
					semaforoActual:='1';
				end if;
			
			elsif( sensor2='1' and semaforoActual='1' ) then
				autos2:=autos2+1;
			
				if(autos2 = 5) then 
					autos2:=0;
					pedirAmarillo:=2;
					semaforoActual:='0';
				end if;
				
			end if;
			
		end if;
		
		if(pedirAmarillo=1) then
			semaforo1<="010";
			pedirAmarillo=0;
			if(pulso'event and pulso='1') then
				cont:=cont+1;
				if(cont=250000000) then
					semaforo1<="000";
				end if;
			end if;
		elsif(pedirAmarillo=2) then
			semaforo2<="010";
			pedirAmarillo=0;
			if(pulso'event and pulso='1') then
				cont:=cont+1;
				if(cont=250000000) then
					semaforo2<="000";
				end if;
			end if;
		end if;
		
	
		if(semaforoActual='0' and pedirAmarillo=0) then 
						semaforo1 <="001"; --rojo,amarillo,verde
						semaforo2 <="100";	
		elsif(semaforoActual='1' and pedirAmarillo=0) then
						semaforo1 <="100";
						semaforo2 <="001";		
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

