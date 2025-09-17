------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (17/06/2025, 14:47:53)
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


ENTITY circuito_02 IS
  PORT( 
    --------------------------------------> Clocks:
    iCLOCK_50MHz: IN  std_logic;   --> PIN_P11
                                   --> "iID0003"  Clock: 2 Hz
                                   --> "inReset" (Reset Generator) Switch: Sw[01]
    --------------------------------------> Inputs:
    inReset:      IN  std_logic;   --> PIN_C11,  Switch: Sw[01] (Reset Generator)
    iID0016_03:   IN  std_logic;   --> PIN_F15,  Switch: Sw[09]
    iID0016_02:   IN  std_logic;   --> PIN_B14,  Switch: Sw[08]
    iID0016_01:   IN  std_logic;   --> PIN_A14,  Switch: Sw[07]
    iID0016_00:   IN  std_logic;   --> PIN_A13,  Switch: Sw[06]
    --------------------------------------> Outputs:
  --oID0026, decoded:
    oID0026_L_a:  OUT std_logic;   --> PIN_C14,  Seven Segm. Display: HEX 0 Segment: 0 (a)
    oID0026_L_b:  OUT std_logic;   --> PIN_E15,  Seven Segm. Display: HEX 0 Segment: 1 (b)
    oID0026_L_c:  OUT std_logic;   --> PIN_C15,  Seven Segm. Display: HEX 0 Segment: 2 (c)
    oID0026_L_d:  OUT std_logic;   --> PIN_C16,  Seven Segm. Display: HEX 0 Segment: 3 (d)
    oID0026_L_e:  OUT std_logic;   --> PIN_E16,  Seven Segm. Display: HEX 0 Segment: 4 (e)
    oID0026_L_f:  OUT std_logic;   --> PIN_D17,  Seven Segm. Display: HEX 0 Segment: 5 (f)
    oID0026_L_g:  OUT std_logic;   --> PIN_C17,  Seven Segm. Display: HEX 0 Segment: 6 (g)
    oID0026_H_a:  OUT std_logic;   --> PIN_C18,  Seven Segm. Display: HEX 1 Segment: 0 (a)
    oID0026_H_b:  OUT std_logic;   --> PIN_D18,  Seven Segm. Display: HEX 1 Segment: 1 (b)
    oID0026_H_c:  OUT std_logic;   --> PIN_E18,  Seven Segm. Display: HEX 1 Segment: 2 (c)
    oID0026_H_d:  OUT std_logic;   --> PIN_B16,  Seven Segm. Display: HEX 1 Segment: 3 (d)
    oID0026_H_e:  OUT std_logic;   --> PIN_A17,  Seven Segm. Display: HEX 1 Segment: 4 (e)
    oID0026_H_f:  OUT std_logic;   --> PIN_A18,  Seven Segm. Display: HEX 1 Segment: 5 (f)
    oID0026_H_g:  OUT std_logic;   --> PIN_B17,  Seven Segm. Display: HEX 1 Segment: 6 (g)
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
END circuito_02;


ARCHITECTURE structural OF circuito_02 IS 

  ----------------------------------------> Components:
  COMPONENT ClockScaler IS
    PORT( iMClk: IN  std_logic;   -- Master Clock
          iH4:   IN  std_logic;   -- iH4..iH0 = "high" frequency selection
          iH3:   IN  std_logic;
          iH2:   IN  std_logic;
          iH1:   IN  std_logic;
          iH0:   IN  std_logic;
          iL3:   IN  std_logic;   -- iL3..iL0 = "low" frequency selection
          iL2:   IN  std_logic;   --                  and Button Modes
          iL1:   IN  std_logic;
          iL0:   IN  std_logic;
          iSwch: IN  std_logic;   -- Switch (low: iH<n> selection, high: iL<n> selection)
          iBut:  IN  std_logic;   -- Button for manual pulsed Clock
          oSClk: OUT std_logic;   -- Output Clock
          oLed:  OUT std_logic 	-- Slow "Clock Pulse" Led
          );
  END COMPONENT;
  --
  COMPONENT AutoResetGen IS
    PORT( iMClk: IN  std_logic;   -- Master Clock
          inBut: IN  std_logic;   -- PushBut, Switch on Ext. Reset (active low)
          onRes: OUT std_logic    -- Reset Output (active low)
          );
  END COMPONENT;
  --
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
  COMPONENT ROM64x8C001 IS
    PORT( CS  : IN  std_logic;
          A00 : IN  std_logic;   -- ADR 5..0 (64 locations)
          A01 : IN  std_logic;
          A02 : IN  std_logic;
          A03 : IN  std_logic;
          A04 : IN  std_logic;
          A05 : IN  std_logic;
          D00 : OUT std_logic;   -- Data Output 7..0 (8-bits)
          D01 : OUT std_logic;
          D02 : OUT std_logic;
          D03 : OUT std_logic;
          D04 : OUT std_logic;
          D05 : OUT std_logic;
          D06 : OUT std_logic;
          D07 : OUT std_logic );
  END COMPONENT;

  COMPONENT CounterUDE8 IS
    PORT( Ck : IN std_logic;
          nCL: IN std_logic;
          ENP: IN std_logic;
          UD : IN std_logic;		  
          Q7 : OUT std_logic;
          Q6 : OUT std_logic;
          Q5 : OUT std_logic;
          Q4 : OUT std_logic;
          Q3 : OUT std_logic;
          Q2 : OUT std_logic;
          Q1 : OUT std_logic;
          Q0 : OUT std_logic;		  
          Tc : OUT std_logic );
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
  SIGNAL S018: std_logic;
  SIGNAL S019: std_logic;

  ----------------------------------------> Not Connected Pins:
  SIGNAL ncp5_C002: std_logic;
  SIGNAL ncp6_C002: std_logic;
  SIGNAL ncp13_C002: std_logic;
  SIGNAL ncp3_C016: std_logic;

  ----------------------------------------> Added Signals:
  SIGNAL iID0003: std_logic;
  SIGNAL iID0003_LED_NotCon: std_logic;
  SIGNAL inReset_ResGen: std_logic;
  SIGNAL oID0026_07: std_logic;
  SIGNAL oID0026_06: std_logic;
  SIGNAL oID0026_05: std_logic;
  SIGNAL oID0026_04: std_logic;
  SIGNAL oID0026_03: std_logic;
  SIGNAL oID0026_02: std_logic;
  SIGNAL oID0026_01: std_logic;
  SIGNAL oID0026_00: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S001 <= iID0003;
  S008 <= NOT inReset_ResGen;
  S010 <= iID0016_00;
  S009 <= iID0016_01;
  ncp3_C016 <= iID0016_02;
  S011 <= iID0016_03;

  ----------------------------------------> Output:
  oID0026_00 <= S019;
  oID0026_01 <= S018;
  oID0026_02 <= S017;
  oID0026_03 <= S016;
  oID0026_04 <= S015;
  oID0026_05 <= S014;
  oID0026_06 <= S013;
  oID0026_07 <= S012;

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

  ClockScaler_iID0003: ClockScaler PORT MAP ( 
      iCLOCK_50MHz, '1', '0', '1', '0', '0', '0', '0', '0', '0',
      '0', '0', iID0003, iID0003_LED_NotCon );

  AutoResetGen_inReset: AutoResetGen PORT MAP ( 
      iCLOCK_50MHz, inReset, inReset_ResGen );

  SevenSegm_Decoder_oID0026_L: SevenSegm_Decoder PORT MAP ( 
    oID0026_03, oID0026_02, oID0026_01, oID0026_00, 
    oID0026_L_a, oID0026_L_b, oID0026_L_c, oID0026_L_d, oID0026_L_e, oID0026_L_f, oID0026_L_g );

  SevenSegm_Decoder_oID0026_H: SevenSegm_Decoder PORT MAP ( 
    oID0026_07, oID0026_06, oID0026_05, oID0026_04, 
    oID0026_H_a, oID0026_H_b, oID0026_H_c, oID0026_H_d, oID0026_H_e, oID0026_H_f, oID0026_H_g );

  C001: ROM64x8C001 PORT MAP ( S011, S002, S003, S004, S005, 
                               S006, S007, S019, S018, S017, 
                               S016, S015, S014, S013, S012 );
  C002: CounterUDE8 PORT MAP ( S001, S008, S009, S010, ncp5_C002, 
                               ncp6_C002, S007, S006, S005, S004, 
                               S003, S002, ncp13_C002 );
END structural;
