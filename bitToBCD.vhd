-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
USE ieee.numeric_std.ALL;
use ieee.std_logic_unsigned.all;

entity bitToBCD is
	port(
		e : in std_logic;
		i1 : in std_logic;
		i2 : in std_logic;
		i3 : in std_logic;
		i4 : in std_logic;
		i5 : in std_logic;
		i6 : in std_logic;
		i7 : in std_logic;
		i8 : in std_logic;
		i9 : in std_logic;
		o0 : out std_logic;
		o1 : out std_logic;
		o2 : out std_logic;
		o3 : out std_logic;
		o4 : out std_logic;
		o5 : out std_logic;
		o6 : out std_logic;
		o7 : out std_logic;
		o8 : out std_logic;
		o9 : out std_logic;
		o10 : out std_logic;
		o11 : out std_logic;
		o12 : out std_logic;
		o13 : out std_logic;
		o14 : out std_logic;
		o15 : out std_logic
		
	);
end bitToBCD;

architecture converter of bitToBCD is
begin

	process(e, i1, i2, i3, i4, i5, i6, i7, i8 ,i9)
    variable z : std_logic_vector(26 downto 0);
    variable shifts : integer;
    variable pos0 : integer; 
	 variable pos1 : integer;
	 
    begin
      --setar as posições pra 0
      for i in 0 to 26 loop
          z(i) := '0';
      end loop;
		
		shifts := 0;
		pos0 := 10;
		pos1 := 0;
		
      z(0) := e; z(1) := i1;
		z(2) := i2; z(3) := i3;
		z(4) := i4; z(5) := i5;
		z(6) := i6; z(7) := i7;
		z(8) := i8; z(9) := i9;
      
      while shifts < 10 loop
          if to_integer(signed(z(13 downto 10))) >= 4 then
              z(14 downto 10) := z(14 downto 10) + 3;
              --z(pos0 downto pos1+1) := z(pos0-1 downto pos1);--shift nas posições
          end if;

          if to_integer(signed(z(17 downto 14))) >= 4 then
              z(18 downto 14) := z(18 downto 14) + 3; --18 por causa do overflow da soma
              --z(pos0 downto pos1+1) := z(pos0-1 downto pos1);
          end if;

          if to_integer(signed(z(21 downto 18))) >= 4 then
              z(22 downto 18) := z(22 downto 18) + 3;
              --z(pos0 downto pos1+1) := z(pos0-1 downto pos1);
          end if;

          if to_integer(signed(z(25 downto 22))) >= 4 then
              z(26 downto 22) := z(26 downto 22) + 3;
          	  --z(pos0 downto pos1+1) := z(pos0-1 downto pos1);
          end if;
			 
			 z(pos0 downto pos1+1) := z(pos0-1 downto pos1);
			 --z(pos1) := '0';
          shifts := shifts + 1;
          pos0 := pos0 + 1;
			 pos1 := pos1 + 1;
          
      end loop;
		
      o0 <= z(10); o1 <= z(11); o2 <= z(12); o3 <= z(13);
		o4 <= z(14); o5 <= z(15); o6 <= z(16); o7 <= z(17);
		o8 <= z(18); o9 <= z(19); o10 <= z(20); o11 <= z(21);
		o12 <= z(22); o13 <= z(23); o14 <= z(24); o15 <= z(25);
    end process;
end converter;