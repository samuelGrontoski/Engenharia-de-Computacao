------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (17/06/2025, 14:28:51)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 3.01.250 (Feb 28, 2025)
-- Copyright (c) 2002-2025 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------
-- FPGA Board: "DE10-Lite Board"
-- Chip FPGA: Intel/Altera MAX 10 (r) (10M50DAF484C7G)
-- Proprietary EDA Tool: Quartus(r) II (Ver = 12.1sp1)
------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.all;


ENTITY circuito_01 IS
  PORT( 
    --------------------------------------> Inputs:
    iID0008:      IN  std_logic;   --> PIN_C10,  Switch: Sw[00]
    iID0015_03:   IN  std_logic;   --> PIN_F15,  Switch: Sw[09]
    iID0015_02:   IN  std_logic;   --> PIN_B14,  Switch: Sw[08]
    iID0015_01:   IN  std_logic;   --> PIN_A14,  Switch: Sw[07]
    iID0015_00:   IN  std_logic;   --> PIN_A13,  Switch: Sw[06]
    --------------------------------------> Outputs:
  --oSAIDA, decoded:
    oSAIDA_a:     OUT std_logic;   --> PIN_C14,  Seven Segm. Display: HEX 0 Segment: 0 (a)
    oSAIDA_b:     OUT std_logic;   --> PIN_E15,  Seven Segm. Display: HEX 0 Segment: 1 (b)
    oSAIDA_c:     OUT std_logic;   --> PIN_C15,  Seven Segm. Display: HEX 0 Segment: 2 (c)
    oSAIDA_d:     OUT std_logic;   --> PIN_C16,  Seven Segm. Display: HEX 0 Segment: 3 (d)
    oSAIDA_e:     OUT std_logic;   --> PIN_E16,  Seven Segm. Display: HEX 0 Segment: 4 (e)
    oSAIDA_f:     OUT std_logic;   --> PIN_D17,  Seven Segm. Display: HEX 0 Segment: 5 (f)
    oSAIDA_g:     OUT std_logic;   --> PIN_C17,  Seven Segm. Display: HEX 0 Segment: 6 (g)
    --------------------------------------> Default Outputs:
    oPIN_A8:      OUT std_logic;   --> PIN_A8,   LED (Red): LEDR[00]
    oPIN_A9:      OUT std_logic;   --> PIN_A9,   LED (Red): LEDR[01]
    oPIN_A10:     OUT std_logic;   --> PIN_A10,  LED (Red): LEDR[02]
    oPIN_B10:     OUT std_logic;   --> PIN_B10,  LED (Red): LEDR[03]
    oPIN_D13:     OUT std_logic;   --> PIN_D13,  LED (Red): LEDR[04]
    oPIN_C13:     OUT std_logic;   --> PIN_C13,  LED (Red): LEDR[05]
    oPIN_E14:     OUT std_logic;   --> PIN_E14,  LED (Red): LEDR[06]
    oPIN_D14:     OUT std_logic;   --> PIN_D14,  LED (Red): LEDR[07]
    oPIN_A11:     OUT std_logic;   --> PIN_A11,  LED (Red): LEDR[08]
    oPIN_B11:     OUT std_logic;   --> PIN_B11,  LED (Red): LEDR[09]
    oPIN_C18:     OUT std_logic;   --> PIN_C18,  Seven Segm. Display:  HEX 1 0 (a)
    oPIN_D18:     OUT std_logic;   --> PIN_D18,  Seven Segm. Display:  HEX 1 1 (b)
    oPIN_E18:     OUT std_logic;   --> PIN_E18,  Seven Segm. Display:  HEX 1 2 (c)
    oPIN_B16:     OUT std_logic;   --> PIN_B16,  Seven Segm. Display:  HEX 1 3 (d)
    oPIN_A17:     OUT std_logic;   --> PIN_A17,  Seven Segm. Display:  HEX 1 4 (e)
    oPIN_A18:     OUT std_logic;   --> PIN_A18,  Seven Segm. Display:  HEX 1 5 (f)
    oPIN_B17:     OUT std_logic;   --> PIN_B17,  Seven Segm. Display:  HEX 1 6 (g)
    oPIN_A16:     OUT std_logic;   --> PIN_A16,  Seven Segm. Display:  HEX 1 Dot
    oPIN_B20:     OUT std_logic;   --> PIN_B20,  Seven Segm. Display:  HEX 2 0 (a)
    oPIN_A20:     OUT std_logic;   --> PIN_A20,  Seven Segm. Display:  HEX 2 1 (b)
    oPIN_B19:     OUT std_logic;   --> PIN_B19,  Seven Segm. Display:  HEX 2 2 (c)
    oPIN_A21:     OUT std_logic;   --> PIN_A21,  Seven Segm. Display:  HEX 2 3 (d)
    oPIN_B21:     OUT std_logic;   --> PIN_B21,  Seven Segm. Display:  HEX 2 4 (e)
    oPIN_C22:     OUT std_logic;   --> PIN_C22,  Seven Segm. Display:  HEX 2 5 (f)
    oPIN_B22:     OUT std_logic;   --> PIN_B22,  Seven Segm. Display:  HEX 2 6 (g)
    oPIN_A19:     OUT std_logic;   --> PIN_A19,  Seven Segm. Display:  HEX 2 Dot
    oPIN_F21:     OUT std_logic;   --> PIN_F21,  Seven Segm. Display:  HEX 3 0 (a)
    oPIN_E22:     OUT std_logic;   --> PIN_E22,  Seven Segm. Display:  HEX 3 1 (b)
    oPIN_E21:     OUT std_logic;   --> PIN_E21,  Seven Segm. Display:  HEX 3 2 (c)
    oPIN_C19:     OUT std_logic;   --> PIN_C19,  Seven Segm. Display:  HEX 3 3 (d)
    oPIN_C20:     OUT std_logic;   --> PIN_C20,  Seven Segm. Display:  HEX 3 4 (e)
    oPIN_D19:     OUT std_logic;   --> PIN_D19,  Seven Segm. Display:  HEX 3 5 (f)
    oPIN_E17:     OUT std_logic;   --> PIN_E17,  Seven Segm. Display:  HEX 3 6 (g)
    oPIN_D22:     OUT std_logic;   --> PIN_D22,  Seven Segm. Display:  HEX 3 Dot
    oPIN_F18:     OUT std_logic;   --> PIN_F18,  Seven Segm. Display:  HEX 4 0 (a)
    oPIN_E20:     OUT std_logic;   --> PIN_E20,  Seven Segm. Display:  HEX 4 1 (b)
    oPIN_E19:     OUT std_logic;   --> PIN_E19,  Seven Segm. Display:  HEX 4 2 (c)
    oPIN_J18:     OUT std_logic;   --> PIN_J18,  Seven Segm. Display:  HEX 4 3 (d)
    oPIN_H19:     OUT std_logic;   --> PIN_H19,  Seven Segm. Display:  HEX 4 4 (e)
    oPIN_F19:     OUT std_logic;   --> PIN_F19,  Seven Segm. Display:  HEX 4 5 (f)
    oPIN_F20:     OUT std_logic;   --> PIN_F20,  Seven Segm. Display:  HEX 4 6 (g)
    oPIN_F17:     OUT std_logic;   --> PIN_F17,  Seven Segm. Display:  HEX 4 Dot
    oPIN_J20:     OUT std_logic;   --> PIN_J20,  Seven Segm. Display:  HEX 5 0 (a)
    oPIN_K20:     OUT std_logic;   --> PIN_K20,  Seven Segm. Display:  HEX 5 1 (b)
    oPIN_L18:     OUT std_logic;   --> PIN_L18,  Seven Segm. Display:  HEX 5 2 (c)
    oPIN_N18:     OUT std_logic;   --> PIN_N18,  Seven Segm. Display:  HEX 5 3 (d)
    oPIN_M20:     OUT std_logic;   --> PIN_M20,  Seven Segm. Display:  HEX 5 4 (e)
    oPIN_N19:     OUT std_logic;   --> PIN_N19,  Seven Segm. Display:  HEX 5 5 (f)
    oPIN_N20:     OUT std_logic;   --> PIN_N20,  Seven Segm. Display:  HEX 5 6 (g)
    oPIN_L19:     OUT std_logic    --> PIN_L19,  Seven Segm. Display:  HEX 5 Dot
    ------------------------------------------------------
    );
END circuito_01;


ARCHITECTURE structural OF circuito_01 IS 

  ----------------------------------------> Components:
  COMPONENT SevenSegm_Decoder IS
    PORT( iD3:    IN  std_logic;  -- iD3 = MSB, iD0 = LSB
          iD2:    IN  std_logic;
          iD1:    IN  std_logic;
          iD0:    IN  std_logic;
          oHEX_a: OUT std_logic;  -- All "Active Low"
          oHEX_b: OUT std_logic;
          oHEX_c: OUT std_logic;
          oHEX_d: OUT std_logic;
          oHEX_e: OUT std_logic;
          oHEX_f: OUT std_logic;
          oHEX_g: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT ROM16x4C004 IS
    PORT( CS  : IN  std_logic;
          A00 : IN  std_logic;   -- ADR 3..0 (16 locations)
          A01 : IN  std_logic;
          A02 : IN  std_logic;
          A03 : IN  std_logic;
          D00 : OUT std_logic;   -- Data Output 3..0 (4-bits)
          D01 : OUT std_logic;
          D02 : OUT std_logic;
          D03 : OUT std_logic );
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

  ----------------------------------------> Added Signals:
  SIGNAL oSAIDA_03: std_logic;
  SIGNAL oSAIDA_02: std_logic;
  SIGNAL oSAIDA_01: std_logic;
  SIGNAL oSAIDA_00: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S009 <= iID0008;
  S005 <= iID0015_00;
  S006 <= iID0015_01;
  S007 <= iID0015_02;
  S008 <= iID0015_03;

  ----------------------------------------> Output:
  oSAIDA_00 <= S004;
  oSAIDA_01 <= S003;
  oSAIDA_02 <= S002;
  oSAIDA_03 <= S001;

  ----------------------------------------> Constants:
  oPIN_A8   <= '0';
  oPIN_A9   <= '0';
  oPIN_A10  <= '0';
  oPIN_B10  <= '0';
  oPIN_D13  <= '0';
  oPIN_C13  <= '0';
  oPIN_E14  <= '0';
  oPIN_D14  <= '0';
  oPIN_A11  <= '0';
  oPIN_B11  <= '0';
  oPIN_C18  <= '1';
  oPIN_D18  <= '1';
  oPIN_E18  <= '1';
  oPIN_B16  <= '1';
  oPIN_A17  <= '1';
  oPIN_A18  <= '1';
  oPIN_B17  <= '1';
  oPIN_A16  <= '1';
  oPIN_B20  <= '1';
  oPIN_A20  <= '1';
  oPIN_B19  <= '1';
  oPIN_A21  <= '1';
  oPIN_B21  <= '1';
  oPIN_C22  <= '1';
  oPIN_B22  <= '1';
  oPIN_A19  <= '1';
  oPIN_F21  <= '1';
  oPIN_E22  <= '1';
  oPIN_E21  <= '1';
  oPIN_C19  <= '1';
  oPIN_C20  <= '1';
  oPIN_D19  <= '1';
  oPIN_E17  <= '1';
  oPIN_D22  <= '1';
  oPIN_F18  <= '1';
  oPIN_E20  <= '1';
  oPIN_E19  <= '1';
  oPIN_J18  <= '1';
  oPIN_H19  <= '1';
  oPIN_F19  <= '1';
  oPIN_F20  <= '1';
  oPIN_F17  <= '1';
  oPIN_J20  <= '1';
  oPIN_K20  <= '1';
  oPIN_L18  <= '1';
  oPIN_N18  <= '1';
  oPIN_M20  <= '1';
  oPIN_N19  <= '1';
  oPIN_N20  <= '1';
  oPIN_L19  <= '1';

  ----------------------------------------> Component Mapping:
  SevenSegm_Decoder_oSAIDA: SevenSegm_Decoder PORT MAP ( 
    oSAIDA_03, oSAIDA_02, oSAIDA_01, oSAIDA_00, 
    oSAIDA_a, oSAIDA_b, oSAIDA_c, oSAIDA_d, oSAIDA_e, oSAIDA_f, oSAIDA_g );

  C004: ROM16x4C004 PORT MAP ( S009, S005, S006, S007, S008, 
                               S004, S003, S002, S001 );
END structural;
