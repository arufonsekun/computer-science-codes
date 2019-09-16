-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity bitToBCD is

	port(
		i0		:	 IN STD_LOGIC;
		i1		:	 IN STD_LOGIC;
		i2		:	 IN STD_LOGIC;
		i3		:	 IN STD_LOGIC;
		i4		:	 IN STD_LOGIC;
		i5		:	 IN STD_LOGIC;
		i6		:	 IN STD_LOGIC;
		i7		:	 IN STD_LOGIC;
		i8		:	 IN STD_LOGIC;
		i9		:	 IN STD_LOGIC;
		o0		:	 OUT STD_LOGIC;
		o1		:	 OUT STD_LOGIC;
		o2		:	 OUT STD_LOGIC;
		o3		:	 OUT STD_LOGIC;
		o4		:	 OUT STD_LOGIC;
		o5		:	 OUT STD_LOGIC;
		o6		:	 OUT STD_LOGIC;
		o7		:	 OUT STD_LOGIC;
		o8		:	 OUT STD_LOGIC;
		o9		:	 OUT STD_LOGIC;
		o10	:	 OUT STD_LOGIC;
		o11	:	 OUT STD_LOGIC;
		o12	:	 OUT STD_LOGIC;
		o13	:	 OUT STD_LOGIC;
		o14	:	 OUT STD_LOGIC;
		o15	:	 OUT STD_LOGIC
	);

end bitToBCD;

architecture miau of bitToBCD is

begin
	 
	 	 
   process(i0,i1,i2,i3,i4,i5,i6,i7,i8,i9)
		
		variable input : std_logic_vector(11 downto 0);
		variable bcd : unsigned (15 downto 0) := (others => '0');
	
	begin		
		bcd := (others => '0');
		
		input(0) := i0; input(1) := i1; input(2) := i2; input(3) := i3;
		input(4) := i4; input(5) := i5; input(6) := i6; input(7) := i7;
		input(8) := i8; input(9) := i9;
		
		for i in 0 to 11 loop
		
			if bcd(3 downto 0) > 4 then 
			  bcd(3 downto 0) := bcd(3 downto 0) + 3;
			end if;
			
			if bcd(7 downto 4) > 4 then 
			  bcd(7 downto 4) := bcd(7 downto 4) + 3;
			end if;
		 
			if bcd(11 downto 8) > 4 then  
			  bcd(11 downto 8) := bcd(11 downto 8) + 3;
			end if;
			
			bcd := bcd(14 downto 0) & input(11);
			input := input(10 downto 0) & '0';
			
		end loop;
		
		o0 <= bcd(0);
		o1 <= bcd(1);
		o2 <= bcd(2);
		o3 <= bcd(3);
		
		o4 <= bcd(4);
		o5 <= bcd(5);
		o6 <= bcd(6);
		o7 <= bcd(7);
		
		o8 <= bcd(8);
		o9 <= bcd(9);
		o10 <= bcd(10);
		o11 <= bcd(11);
		
		o12 <= bcd(12);
		o13 <= bcd(13);
		o14 <= bcd(14);
		o15 <= bcd(15);
		
	end process;
	
end miau;