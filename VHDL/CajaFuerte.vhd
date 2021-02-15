library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity claveTeclado is port(
	clk: in STD_LOGIC; 
	--tecladoX: in STD_LOGIC_vector(2 downto 0); --filas del teclado
	tecladoY: in STD_LOGIC_vector(2 downto 0); --columnas del teclado
	Pulso : inout  STD_LOGIC:='0';
	letra : out STD_LOGIC_vector(6 downto 0); --letra que aparece en el display
	displays : out STD_LOGIC_vector(3 downto 0)); --display en el que aparece
end claveTeclado;

architecture claveTecladoc of claveTeclado is
type estados is(A,B,C,D);
signal edoActual, edoFuturo: estados;
signal claveLista : integer:=0;
signal contador : integer:=0;
begin
	
	cero: process(clk) --proceso del clock
	begin
		if(clk'event and clk='1') then
			contador<=contador+1;
			if(contador=50000000) then	
				pulso <= not pulso; --cada que pase cierto tiempo se hace la transicion de flanco
				contador<=1;
			end if;
		end if;
	end process cero;


	uno: process(edoActual,tecladoY,pulso)
	begin
		
		if(pulso'event and pulso='1') then 
			if(tecladoY="100") then --tecladoX y tecladoY deben tener las coordenadas de 1.
				case edoActual is
					when A => edoFuturo<=B;
					when B => edoFuturo<=A;
					when C => edoFuturo<=A;
					when D => edoFuturo<=A;
				end case;
				edoActual<=edoFuturo;
			elsif(tecladoY="010") then
				case edoActual is
					when A => edoFuturo<=A;
					when B => edoFuturo<=C;
					when C => edoFuturo<=A;
					when D => edoFuturo<=A;
				end case;
				edoActual<=edoFuturo;
			elsif(tecladoY="001") then
				case edoActual is
					when A => edoFuturo<=A;
					when B => edoFuturo<=A;
					when C => if(claveLista=0) then 
						edoFuturo<=D; 
						claveLista<=1; 
					elsif(claveLista=2) then 
						claveLista<=3; 
						edoFuturo<=D; 
					end if;
					when D => edoFuturo<=A;
				end case;
				edoActual<=edoFuturo;
			end if;
		end if;
	end process uno;
	
	dos: process(claveLista)
	VARIABLE letraAvanzar : integer:=0;
	VARIABLE salida : integer:=0;
	begin
		if(pulso'event and pulso='1' and claveLista=1) then 
			if(letraAvanzar=0) then
				letra<="0000001";
				displays<="0111"; --estoy prendiendo los displays con 0
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=1) then
				letra<="0011000";
				displays<="1011";
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=2) then
				letra<="0110000";
				displays<="1101";
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=3) then
				letra<="0001001";
				displays<="1110";
				letraAvanzar:=letraAvanzar+1;
				salida:=salida+1;
				if(salida=3) then
					claveLista<=2;
					letraAvanzar:=0;
					salida:=0;
				end if;
			end if;
		elsif(pulso'event and pulso='1' and claveLista=3) then 
			if(letraAvanzar=0) then
				letra<="0110001";
				displays<="0111"; --estoy prendiendo los displays con 0
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=1) then
				letra<="1110001";
				displays<="1011";
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=2) then
				letra<="0000001";
				displays<="1101";
				letraAvanzar:=letraAvanzar+1;
			elsif(letraAvanzar=3) then
				letra<="0100100";
				displays<="1110";
				letraAvanzar:=letraAvanzar+1;
				salida:=salida+1;
				if(salida=3) then
					claveLista<=0;
					letraAvanzar:=0;
					salida:=0;
				end if;
			end if;
		end if;		
	end process dos;		
				
end claveTecladoc;