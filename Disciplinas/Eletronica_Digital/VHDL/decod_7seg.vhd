-- conversor binario para 7 segmentos

library ieee;
use ieee.std_logic_1164.all;

entity decod_7seg is
	port (	d : in	std_logic_vector (3 downto 0);
				q : out	std_logic_vector (6 downto 0)
	);
end decod_7seg;

architecture decod_7seg_arch of decod_7seg is
begin
	-- saida = leds abcdefg do display de 7 segmentos. Aciona em nivel BAIXO.
	
	with d select
		q <= 	"0000001" when "0000", -- 0 -- 01
				"1001111" when "0001", -- 1 -- 4F
				"0010010" when "0010", -- 2 -- 12
				"0000110" when "0011", -- 3 -- 06
				"1001100" when "0100", -- 4 -- 4C
				"0100100" when "0101", -- 5 -- 24
				"0100000" when "0110", -- 6 -- 20
				"0001101" when "0111", -- 7 -- 0D
				"0000000" when "1000", -- 8 -- 00
				"0000100" when "1001", -- 9 -- 04
				"0001000" when "1010", -- A -- 08
				"1100000" when "1011", -- B -- 60
				"0110001" when "1100", -- C -- 31
				"1000010" when "1101", -- D -- 42
				"0110000" when "1110", -- E -- 30
				"0111000" when "1111"; -- F -- 38
end decod_7seg_arch;
			