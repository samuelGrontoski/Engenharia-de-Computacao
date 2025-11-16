------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (31/10/2025, 15:09:41)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 3.01.250 (Feb 28, 2025)
-- Copyright (c) 2002-2025 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.all;


ENTITY circuito_31_10_25 IS
  PORT( 
    --------------------------------------> Inputs:
    iPL:          IN  std_logic;
    iSERIAL:      IN  std_logic;
    iButons:      IN  std_logic_vector( 3 downto 0 );
    iCK:          IN  std_logic;
    iReset:       IN  std_logic;
    --------------------------------------> Outputs:
    oQ1:          OUT std_logic;
    oQ2:          OUT std_logic;
    oQ3:          OUT std_logic;
    oQ4:          OUT std_logic 
    ------------------------------------------------------
    );
END circuito_31_10_25;


ARCHITECTURE structural OF circuito_31_10_25 IS 

  ----------------------------------------> Components:
  COMPONENT NAND2_gate IS
    PORT( I0,I1: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR2_gate IS
    PORT( I0,I1: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT DpetFF IS
    PORT( D, Ck   : IN std_logic;
          nCL, nPR: IN std_logic;
          Q, nQ   : OUT std_logic );
  END COMPONENT;

  ----------------------------------------> Signals:
  SIGNAL S001: std_logic;
  SIGNAL S002: std_logic;
  SIGNAL S003: std_logic;
  SIGNAL S004: std_logic;
  SIGNAL S005: std_logic;
  SIGNAL S006: std_logic;
  SIGNAL S007: std_logic;
  SIGNAL S008: std_logic;
  SIGNAL S009: std_logic;
  SIGNAL S010: std_logic;
  SIGNAL S011: std_logic;
  SIGNAL S012: std_logic;
  SIGNAL S013: std_logic;
  SIGNAL S014: std_logic;
  SIGNAL S015: std_logic;
  SIGNAL S016: std_logic;
  SIGNAL S017: std_logic;

  ----------------------------------------> Not Connected Pins:
  SIGNAL ncp6_C005: std_logic;
  SIGNAL ncp6_C006: std_logic;
  SIGNAL ncp6_C007: std_logic;
  SIGNAL ncp6_C008: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S001 <= iPL;
  S017 <= iSERIAL;
  S002 <= iButons(0);
  S003 <= iButons(1);
  S004 <= iButons(2);
  S005 <= iButons(3);
  S006 <= iCK;
  S007 <= iReset;

  ----------------------------------------> Output:
  oQ1 <= S008;
  oQ2 <= S009;
  oQ3 <= S010;
  oQ4 <= S011;

  ----------------------------------------> Component Mapping:
  C001: NAND2_gate PORT MAP ( S005, S001, S012 );
  C002: NAND2_gate PORT MAP ( S004, S001, S013 );
  C003: NAND2_gate PORT MAP ( S003, S001, S014 );
  C004: NAND2_gate PORT MAP ( S002, S001, S015 );
  C005: DpetFF PORT MAP ( S016, S006, S007, S012, S008, ncp6_C005 );
  C006: DpetFF PORT MAP ( S008, S006, S007, S013, S009, ncp6_C006 );
  C007: DpetFF PORT MAP ( S009, S006, S007, S014, S010, ncp6_C007 );
  C008: DpetFF PORT MAP ( S010, S006, S007, S015, S011, ncp6_C008 );
  C127: OR2_gate PORT MAP ( S017, S011, S016 );
END structural;
