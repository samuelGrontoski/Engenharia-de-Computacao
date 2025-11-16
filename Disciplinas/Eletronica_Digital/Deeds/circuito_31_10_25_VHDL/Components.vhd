------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (31/10/2025, 15:09:41)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 3.01.250 (Feb 28, 2025)
-- Copyright (c) 2002-2025 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY NAND2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END NAND2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF NAND2_gate IS
BEGIN
  O <= (not (I0 and I1));
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END OR2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR2_gate IS
BEGIN
  O <= (I0 or I1);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY DpetFF IS
  PORT(  D, Ck   : IN std_logic;
         nCL, nPR: IN std_logic;
         Q, nQ   : OUT std_logic );
END DpetFF;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF DpetFF IS 
BEGIN
  Dff: PROCESS( Ck, nCL, nPR ) 
  BEGIN
    if    (nCL = '0') and (nPR = '0') then  Q <= 'X';  nQ <= 'X';
    elsif (nCL = '0') and (nPR = '1') then  Q <= '0';  nQ <= '1';
    elsif (nCL = '1') and (nPR = '0') then  Q <= '1';  nQ <= '0';
    elsif (nCL = '1') and (nPR = '1') then
      if (Ck'event) AND (Ck='1') THEN -- Positive Edge -----------
                                            Q <=  D;   nQ <= not D;
      END IF;
    else                                    Q <= 'X';  nQ <= 'X';
    END IF;
  END PROCESS; 
END behavioral;


