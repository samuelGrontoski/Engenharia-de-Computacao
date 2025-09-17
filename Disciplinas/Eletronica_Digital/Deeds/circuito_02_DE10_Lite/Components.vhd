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

--------------------------------------------------------------------
LIBRARY ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY ROM64x8C001 IS           -- (programmable) ROM 64 x 8
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
END ROM64x8C001;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF ROM64x8C001 IS
  --
  type ROM_Array is array (0 to 63) of std_logic_vector(7 downto 0);
  SIGNAL A : std_logic_vector( 5 downto 0);
  SIGNAL D : std_logic_vector( 7 downto 0);

  -- ROM Memory Array ----------------------------------------------
  constant ROM_Cells: ROM_Array:= (
		00000 => "00000101",
		00001 => "11011101",
		00002 => "11000010",
		00003 => "10101010",
		00004 => "10011101",
		00005 => "10010101",
		00006 => "10001001",
		00007 => "10000111",
		00008 => "10010000",
		00009 => "10011001",
		00010 => "10100100",
		00011 => "10101011",
		00012 => "10110111",
		00013 => "11000001",
		00014 => "11000110",
		00015 => "11001100",
		00016 => "11001011",
		00017 => "11001101",
		00018 => "11001011",
		00019 => "11001001",
		00020 => "11000111",
		00021 => "11001111",
		00022 => "11010010",
		00023 => "11011011",
		00024 => "11011111",
		00025 => "11101100",
		00026 => "11101110",
		00027 => "11110001",
		00028 => "11111011",
		00029 => "00000001",
		00030 => "00000000",
		00031 => "00000001",
		00032 => "00000001",
		00033 => "00000011",
		00034 => "11111100",
		00035 => "00000000",
		00036 => "00000110",
		00037 => "00001101",
		00038 => "00010110",
		00039 => "00011101",
		00040 => "00100011",
		00041 => "00100110",
		00042 => "00110011",
		00043 => "00110111",
		00044 => "00111010",
		00045 => "00110010",
		00046 => "00110111",
		00047 => "00110001",
		00048 => "00101111",
		00049 => "00110011",
		00050 => "00111100",
		00051 => "01000010",
		00052 => "01001000",
		00053 => "01010001",
		00054 => "01100101",
		00055 => "01100110",
		00056 => "01101111",
		00057 => "01110110",
		00058 => "01110111",
		00059 => "01110100",
		00060 => "01101000",
		00061 => "01001110",
		00062 => "00111010",
		00063 => "00011101",
		OTHERS=> "11111111"
		);


BEGIN
  A <= (A05 & A04 & A03 & A02 & A01 & A00);
  --
  PROCESS( CS, A )
  BEGIN
    if (CS = '1') then
          D <= ROM_Cells(to_integer(unsigned(A))); -- READ condition
    else  D <= (others => '0');                    -- Chip Select Off
    end if;
  END PROCESS;
  --
  D07 <= D(7); D06 <= D(6); D05 <= D(5); D04 <= D(4);
  D03 <= D(3); D02 <= D(2); D01 <= D(1); D00 <= D(0);
END behavioral;

--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY CounterUDE8 IS
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
END CounterUDE8;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF CounterUDE8 IS
BEGIN
  CountUDE8: PROCESS( Ck, nCL, ENP, UD )
  variable aCnt: unsigned( 7 downto 0 );
  BEGIN
    if    (nCL = '0') then          		aCnt := (others =>'0');
    elsif (nCL = '1') then
      if (Ck'event) AND (Ck='1') then
        if  (ENP = '1') then
          if    (UD = '1') then
            if (aCnt < "11111111") then	aCnt := aCnt + 1;
            else                    		aCnt := (others =>'0');
            end if;
          elsif (UD = '0') then
            if (aCnt > "00000000") then 	aCnt := aCnt - 1;
            else                    		aCnt := (others =>'1');
            end if;
          else                     	 		aCnt := (others =>'X'); -- (UD: Unknown)
          END IF;
        elsif not(ENP ='0') then    		aCnt := (others =>'X'); -- (ENP: Unknown)
        END IF;
      END IF;
    else                            		aCnt := (others =>'X'); -- (nCL: Unknown)
    END IF;
    --
	 Tc <=     (aCnt(7) and aCnt(6) and aCnt(5) and aCnt(4) and aCnt(3) and aCnt(2) and aCnt(1) and aCnt(0) and UD) or
          (not(aCnt(7) or  aCnt(6) or  aCnt(5) or  aCnt(4) or  aCnt(3) or  aCnt(2) or  aCnt(1) or  aCnt(0) or  UD));
    --
    Q7 <= aCnt(7);
    Q6 <= aCnt(6);
    Q5 <= aCnt(5);
    Q4 <= aCnt(4);
    Q3 <= aCnt(3);
    Q2 <= aCnt(2);
    Q1 <= aCnt(1);
    Q0 <= aCnt(0);
    --
  END PROCESS;
END behavioral;



--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

-- Clock Scaler (Altera DE1, DE2 and DE2-115 version, master clock = 50 MHz)

ENTITY ClockScaler IS
	PORT(	iMClk: IN  std_logic;   -- Master Clock
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
	END ClockScaler;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF ClockScaler IS

-- "Auto Reset" shift register & flip-flop --------------------
SIGNAL	ASHR:	unsigned( 15 downto 0 );
SIGNAL 	AFBack: std_logic;		 
SIGNAL	nAutoReset: std_logic;

-- 10 mS Tick, input debounce ---------------------------------
--                               Clock 50 MHz --> 100Hz = 10 mS
constant	aDebCountMax:	integer:= 500000-1;
SIGNAL	aDebCount:		integer range 0 to aDebCountMax;
SIGNAL	aButton_SHR:	unsigned( 2 downto 0 );
SIGNAL	aSwitch_SHR:	unsigned( 2 downto 0 );
SIGNAL	aButton: 		std_logic;
SIGNAL	aSwitch: 		std_logic;
SIGNAL	aTick: 			std_logic;

-- Main Clock Scaler ------------------------------------------
constant	nBits:	integer:= 32;
constant	highBit:	integer:= nBits -1;
SIGNAL	aCount:  unsigned( highBit downto 0 );
SIGNAL	aCntMod: unsigned( highBit downto 0 );
SIGNAL	aCntMid: unsigned( highBit downto 0 );
SIGNAL 	aHIGH: unsigned( 4 downto 0 );
SIGNAL 	aLOW:  unsigned( 3 downto 0 );

-- Clock and LED Outputs --------------------------------------
SIGNAL	ManualClkMode: std_logic;
SIGNAL	StepPulse:		std_logic;
SIGNAL	StepLED:			std_logic;

BEGIN
   ------------------------------------------------------------------
   -- Shift register to create an "Auto-Reset" signal.
	-- (it appears over-complicated, but a simpler structure,
	--  even if accepted by the VHDL compiler, is deleted anyway
   --  by the logic optimizer) 
   ------------------------------------------------------------------
   AFBack <= not( ASHR(15) and ASHR(14) and ASHR(13) and ASHR(12) and 
						ASHR(11) and ASHR(10) and ASHR(09) and ASHR(08) and
						ASHR(07) and ASHR(06) and ASHR(05) and ASHR(04) and 
						ASHR(03) and ASHR(02) and ASHR(01) and ASHR(00) );
							
   Res: process( iMClk )
   begin
      if (nAutoReset = '0') and rising_edge( iMClk ) then 
			ASHR <= AFBack & ASHR(15 downto 1);
			nAutoReset <= ASHR(00) or ASHR(01);
      end if;
   end process;
	
	
	------------------------------------------------------------
	-- Counter to generate 10 mS Time Tick used to debounce
	-- switches and button used for the "slow clock" and the
	-- "Instruction Step by Step" modes. It is used also as
	-- time base for the timing of button pressing repetitions.
	------------------------------------------------------------
	DebTick: process( nAutoReset, iMClk )
	begin
		if (nAutoReset = '0') then
			aDebCount <= 0;
			aTick <= '0';
		--
		elsif rising_edge( iMClk ) then
			if (aDebCount = 0) then
				aDebCount <= aDebCountMax;	-- re-init. count
				aTick <= '1'; 					-- generate 10 mS Time Tick
         else
				aDebCount <= aDebCount - 1;
				aTick <= '0';
			end if;
		end if;
	end process;

	------------------------------------------------------------
	-- Shift registers for sincronize and debounce the signals:
	-- iSwch --> becomes  "aSwitch"
	-- iBut  --> becomes  "aButton"
	------------------------------------------------------------
	Debounce: process( nAutoReset, iMClk )
	begin
		if (nAutoReset = '0') then
			aSwitch_SHR <= "000";
			aSwitch <= '1';
			aButton_SHR <= "000";
			aButton <= '0';
		--
		elsif rising_edge( iMClk ) then
		  if (aTick = '1') then -- (10 mS period)

				--------- Switch ----------------------------------
				if    (aSwitch_SHR = "000") then  aSwitch <= '1';	-- '1' at Reset
				elsif (aSwitch_SHR = "111") then  aSwitch <= '0';
				end if;
				aSwitch_SHR <= (not iSwch) & aSwitch_SHR(2) & aSwitch_SHR(1);

			   --------- Button -----------------------------------
				if    (aButton_SHR = "000") then  aButton <= '0';	-- '0' at Reset
				elsif (aButton_SHR = "111") then  aButton <= '1';
				end if;
				aButton_SHR <= iBut & aButton_SHR(2) & aButton_SHR(1);
				--
			end if;
		end if;
	end process;

	------------------------------------------------------------
	-- Scaled Clock: Frequency and Mode setting
	------------------------------------------------------------
	aHIGH <= iH4 & iH3 & iH2 & iH1 & iH0;
	aLOW  <= iL3 & iL2 & iL1 & iL0;

	CK_PERIOD: process( aSwitch, aHIGH, aLOW )
	begin
		ManualClkMode <= '0';
		--
		if (aSwitch = '0') then  -- "normal mode" ---------------------
		---------------------------------------------------------------
			case aHIGH is
			---- 10 MHz ------------------------------------------------
			when "00000" =>   aCntMod <= TO_UNSIGNED( 5, nBits);
									aCntMid <= TO_UNSIGNED( 2, nBits);
			----  5 MHz ------------------------------------------------
			when "00001" =>   aCntMod <= TO_UNSIGNED(10, nBits);
									aCntMid <= TO_UNSIGNED( 5, nBits);
			----  2 MHz ------------------------------------------------
			when "00010" =>   aCntMod <= TO_UNSIGNED(25, nBits);
									aCntMid <= TO_UNSIGNED(12, nBits);
			----  1 MHz ------------------------------------------------
			when "00011" =>   aCntMod <= TO_UNSIGNED(50, nBits);
									aCntMid <= TO_UNSIGNED(25, nBits);
			---- 500 KHz -----------------------------------------------
			when "00100" =>   aCntMod <= TO_UNSIGNED(100, nBits);
									aCntMid <= TO_UNSIGNED( 50, nBits);
			---- 200 KHz -----------------------------------------------
			when "00101" =>   aCntMod <= TO_UNSIGNED(250, nBits);
									aCntMid <= TO_UNSIGNED(125, nBits);
			---- 100 KHz -----------------------------------------------
			when "00110" =>   aCntMod <= TO_UNSIGNED(500, nBits);
									aCntMid <= TO_UNSIGNED(250, nBits);
			---- 50 KHz ------------------------------------------------
			when "00111" =>   aCntMod <= TO_UNSIGNED(1000, nBits);
									aCntMid <= TO_UNSIGNED( 500, nBits);
			---- 20 KHz ------------------------------------------------
			when "01000" =>   aCntMod <= TO_UNSIGNED(2500, nBits);
									aCntMid <= TO_UNSIGNED(1250, nBits);
			---- 10 KHz ------------------------------------------------
			when "01001" =>   aCntMod <= TO_UNSIGNED(5000, nBits);
									aCntMid <= TO_UNSIGNED(2500, nBits);
			---- 5 KHz -------------------------------------------------
			when "01010" =>   aCntMod <= TO_UNSIGNED(10000, nBits);
									aCntMid <= TO_UNSIGNED( 5000, nBits);
			---- 2 KHz -------------------------------------------------
			when "01011" =>   aCntMod <= TO_UNSIGNED(25000, nBits);
									aCntMid <= TO_UNSIGNED(12500, nBits);
			---- 1 KHz -------------------------------------------------
			when "01100" =>   aCntMod <= TO_UNSIGNED(50000, nBits);
									aCntMid <= TO_UNSIGNED(25000, nBits);
			---- 500 Hz ------------------------------------------------
			when "01101" =>   aCntMod <= TO_UNSIGNED(100000, nBits);
									aCntMid <= TO_UNSIGNED( 50000, nBits);
			---- 200 Hz ------------------------------------------------
			when "01110" =>   aCntMod <= TO_UNSIGNED(250000, nBits);
									aCntMid <= TO_UNSIGNED(125000, nBits);
			---- 100 Hz ------------------------------------------------
			when "01111" =>   aCntMod <= TO_UNSIGNED(500000, nBits);
									aCntMid <= TO_UNSIGNED(250000, nBits);
			---- 50 Hz -------------------------------------------------
			when "10000" =>   aCntMod <= TO_UNSIGNED(1000000, nBits);
									aCntMid <= TO_UNSIGNED( 500000, nBits);
			---- 20 Hz -------------------------------------------------
			when "10001" =>   aCntMod <= TO_UNSIGNED(2500000, nBits);
									aCntMid <= TO_UNSIGNED(1250000, nBits);
			---- 10 Hz -------------------------------------------------
			when "10010" =>   aCntMod <= TO_UNSIGNED(5000000, nBits);
									aCntMid <= TO_UNSIGNED(2500000, nBits);
			---- 5 Hz --------------------------------------------------
			when "10011" =>   aCntMod <= TO_UNSIGNED(10000000, nBits);
									aCntMid <= TO_UNSIGNED( 5000000, nBits);
			---- 2 Hz --------------------------------------------------
			when "10100" =>   aCntMod <= TO_UNSIGNED(25000000, nBits);
									aCntMid <= TO_UNSIGNED(12500000, nBits);
			---- 1 Hz --------------------------------------------------
			when "10101" =>   aCntMod <= TO_UNSIGNED(50000000, nBits);
									aCntMid <= TO_UNSIGNED(25000000, nBits);
			--- if error: 1 Hz -----------------------------------------
			when others  =>   aCntMod <= TO_UNSIGNED(50000000, nBits);
									aCntMid <= TO_UNSIGNED(25000000, nBits);
			end case;

		else -- if (aSwitch = '1'.. "Slow clock modes" ----------------
		---------------------------------------------------------------
			case aLOW is
			---- 100 Hz ------------------------------------------------
			when "0000" =>	aCntMod <= TO_UNSIGNED(500000, nBits);
								aCntMid <= TO_UNSIGNED(250000, nBits);								
			---- 50 Hz -------------------------------------------------
			when "0001" =>	aCntMod <= TO_UNSIGNED(1000000, nBits);
								aCntMid <= TO_UNSIGNED( 500000, nBits);
			---- 20 Hz -------------------------------------------------
			when "0010" =>	aCntMod <= TO_UNSIGNED(2500000, nBits);
								aCntMid <= TO_UNSIGNED(1250000, nBits);
			---- 10 Hz -------------------------------------------------
			when "0011" =>	aCntMod <= TO_UNSIGNED(5000000, nBits);
								aCntMid <= TO_UNSIGNED(2500000, nBits);
			---- 5 Hz --------------------------------------------------
			when "0100" =>	aCntMod <= TO_UNSIGNED(10000000, nBits);
								aCntMid <= TO_UNSIGNED( 5000000, nBits);
			---- 2 Hz --------------------------------------------------
			when "0101" =>	aCntMod <= TO_UNSIGNED(25000000, nBits);
								aCntMid <= TO_UNSIGNED(12500000, nBits);
			---- 1 Hz --------------------------------------------------
			when "0110" =>	aCntMod <= TO_UNSIGNED(50000000, nBits);
								aCntMid <= TO_UNSIGNED(25000000, nBits);
			---- 0.5 Hz ------------------------------------------------
			when "0111" =>	aCntMod <= TO_UNSIGNED(100000000, nBits);
								aCntMid <= TO_UNSIGNED( 50000000, nBits);
			---- 0.2 Hz ------------------------------------------------
			when "1000" =>	aCntMod <= TO_UNSIGNED(250000000, nBits);
								aCntMid <= TO_UNSIGNED(125000000, nBits);
			---- 0.1 Hz ------------------------------------------------
			when "1001" =>	aCntMod <= TO_UNSIGNED(500000000, nBits);
								aCntMid <= TO_UNSIGNED(250000000, nBits);
			--
			---- Slow Clock Step ---------------------------------------
			when others =>  ManualClkMode <= '1';
			end case;
		end if;
	end process;


	------------------------------------------------------------
	-- Clock Scaler Main Counter
	-- In "Manual Clock Mode", the clock is inhibited.
	-- In "Normal Mode", the clock is obtained by frequency
	--    division from the 50 MHz master clock.
	------------------------------------------------------------
	CNT: process( nAutoReset, iMClk )
	begin
		if (nAutoReset = '0') then
			aCount <= (aCntMod - 1);
			oSClk <= '0';
			oLed <= '0';
		--
		elsif rising_edge( iMClk ) then
			if (ManualClkMode = '0') then

				--- Normal (or Slow) Cyclic Clock Mode ------------
				if ((aCount < 0) or (aCount >= aCntMod)) then
					aCount <= (aCntMod - 1); -- "Pseudo Reset"
				elsif (aCount = 0) then
					aCount <= (aCntMod - 1);
				else
					aCount <= (aCount - 1);
				end if;
				--
				if (aCount < aCntMid)	then
					oSClk <= '1'; 				-- High if count is Low!
					if (aSwitch = '1') then
							oLed <= '1';
					else	oLed <= '0';
					end if;
				else
					oSClk <= '0';
					oLed <= '0';
				end if;
			else
				--(ManualClkMode = '1') -------------------------
				oSClk <= StepPulse;
				oLed <= StepLED;
			end if;
		end if;
	end process;


	------------------------------------------------------------
	-- Button Step and Step Repetition Handler
	------------------------------------------------------------
	PULSE: process( nAutoReset, iMClk )
		constant IsTime: integer := 100;
		constant IsLedEnd: integer := 25;
		variable Stepper: integer range 0 to IsTime;
		--
		constant TimeCycle: integer := 25;
		variable Pulser: integer range 0 to TimeCycle;
		--
		variable Level: integer range 0 to 1;
		variable Pulsing: boolean;
		--
	begin
		if (nAutoReset = '0') then
			Stepper:= 0;
			Pulsing:= false;
			Pulser:= 0;
			StepPulse <= '0';
			StepLED <= '0';
		--
		elsif rising_edge( iMClk ) then
	      ------------------------------------------------------
			if (ManualClkMode = '0') then
				Stepper:= 0;
				Pulsing:= false;
				Pulser:= 0;
				StepPulse <= '0';
				StepLED <= '0';
	         ---------------------------------------------------

			else --(ManualClkMode = '1')
	         ----- Button Pulsed Mode --------------------------
				if (aTick = '1') then -- every 10 mS
					--
					if (aButton = '1')	then
               	if (not Pulsing) then
                  	if (Stepper < IsTime) then
								---------------------------------------
								StepPulse <= '1';
								StepLED <= '1';
                     	Stepper:= Stepper + 1;
                     else
								--(Stepper = IsTime) ------------------
                     	Pulsing:= true;
                     	Pulser:= TimeCycle;
                        Level := 0;
								StepPulse <= '0';
								StepLED <= '0';
                     end if;

                  else --(Pulsing)
                  	if (Pulser > 0) then
								---------------------------------------
                     	Pulser:= Pulser -1;
                     else
								--(Pulser = 0) ------------------------
                     	Pulser:= TimeCycle;
                        if (Level = 0) then
									Level:= 1;
									StepPulse <= '1';
									StepLED <= '1';
                        else -- (oLevel = 1)
									Level:= 0;
									StepPulse <= '0';
									StepLED <= '0';
								end if;
                     end if;
							------------------------------------------
                  end if; -- Pulsed
						--
					else -- (aButton = '0')
           			Stepper:= 0;
               	if (not Pulsing) then
							StepPulse <= '0';
							StepLED <= '0';
                  else --(Pulsing)
                  	if (Pulser > 0) then
                     	Pulser:= Pulser -1;
                     else --(Pulser = 0)
                     	Pulsing:= false;
								StepPulse <= '0';
								StepLED <= '0';
							end if;
						end if;
					end if;
            end if;
			end if;
		end if;
	end process;

END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

ENTITY AutoResetGen IS				-- Auto Reset Generator
   PORT( iMClk: IN  std_logic;   -- Master Clock
         inBut: IN  std_logic;   -- PushBut, Switch on Ext. Reset (active low)
         onRes: OUT std_logic    -- Reset Output (active low)
         );
   END AutoResetGen;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF AutoResetGen IS

SIGNAL FFR: std_logic;
SIGNAL SHR: unsigned( 15 downto 0 );
SIGNAL FeedBack: std_logic;		 

BEGIN
   ------------------------------------------------------------------
   -- 16-bits shift-register-based "Auto-Reset" network.
	-- It appears over-complicated, but a simpler structure,
	-- even if accepted by the VHDL compiler, is deleted
   -- by the logic optimizer. This one... not!
   ------------------------------------------------------------------
   FeedBack <= not( 	SHR(15) and SHR(14) and SHR(13) and SHR(12) and 
							SHR(11) and SHR(10) and SHR(09) and SHR(08) and
							SHR(07) and SHR(06) and SHR(05) and SHR(04) and 
							SHR(03) and SHR(02) and SHR(01) and SHR(00) );
							
   ARG: process( iMClk, inBut )
   begin
		if (inBut = '0') then
			SHR <= "0000000000000000";
		   FFR <= '0';
      elsif (FFR = '0') and rising_edge( iMClk ) then 
			SHR <= FeedBack & SHR(15 downto 1);
			FFR <= SHR(00) or SHR(01);
      end if;
   end process;
	--
	onRes <= FFR;
	--
END behavioral;

--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

-- Seven Segment Display Decoder

ENTITY SevenSegm_Decoder IS
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
END SevenSegm_Decoder;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF SevenSegm_Decoder IS
  SIGNAL HexNumber: std_logic_vector( 3 downto 0 );
BEGIN
  -- REM: All Segment are active Low
  HexNumber <= iD3 & iD2 & iD1 & iD0;
  with HexNumber select
    oHEX_a <= '0' when "0000", '1' when "0001", '0' when "0010", '0' when "0011",
              '1' when "0100", '0' when "0101", '0' when "0110", '0' when "0111",
              '0' when "1000", '0' when "1001", '0' when "1010", '1' when "1011",
              '0' when "1100", '1' when "1101", '0' when "1110", '0' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_b <= '0' when "0000", '0' when "0001", '0' when "0010", '0' when "0011",
              '0' when "0100", '1' when "0101", '1' when "0110", '0' when "0111",
              '0' when "1000", '0' when "1001", '0' when "1010", '1' when "1011",
              '1' when "1100", '0' when "1101", '1' when "1110", '1' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_c <= '0' when "0000", '0' when "0001", '1' when "0010", '0' when "0011",
              '0' when "0100", '0' when "0101", '0' when "0110", '0' when "0111",
              '0' when "1000", '0' when "1001", '0' when "1010", '0' when "1011",
              '1' when "1100", '0' when "1101", '1' when "1110", '1' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_d <= '0' when "0000", '1' when "0001", '0' when "0010", '0' when "0011",
              '1' when "0100", '0' when "0101", '0' when "0110", '1' when "0111",
              '0' when "1000", '0' when "1001", '1' when "1010", '0' when "1011",
              '0' when "1100", '0' when "1101", '0' when "1110", '1' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_e <= '0' when "0000", '1' when "0001", '0' when "0010", '1' when "0011",
              '1' when "0100", '1' when "0101", '0' when "0110", '1' when "0111",
              '0' when "1000", '1' when "1001", '0' when "1010", '0' when "1011",
              '0' when "1100", '0' when "1101", '0' when "1110", '0' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_f <= '0' when "0000", '1' when "0001", '1' when "0010", '1' when "0011",
              '0' when "0100", '0' when "0101", '0' when "0110", '1' when "0111",
              '0' when "1000", '0' when "1001", '0' when "1010", '0' when "1011",
              '0' when "1100", '1' when "1101", '0' when "1110", '0' when "1111",
              '1' when others;
  with HexNumber select
    oHEX_g <= '1' when "0000", '1' when "0001", '0' when "0010", '0' when "0011",
              '0' when "0100", '0' when "0101", '0' when "0110", '1' when "0111",
              '0' when "1000", '0' when "1001", '0' when "1010", '0' when "1011",
              '1' when "1100", '0' when "1101", '0' when "1110", '0' when "1111",
              '1' when others;
END behavioral;

