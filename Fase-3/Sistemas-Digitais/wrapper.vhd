-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_unsigned.all;
--use ieee.numeric_std.all;

entity wrapper is
	port(
		  i0 : in std_logic;
        i1 : in std_logic;
        i2 : in std_logic;
        i3 : in std_logic;
        i4 : in std_logic;
        i5 : in std_logic;
        i6 : in std_logic;
        i7 : in std_logic;
		  
        o0 : out std_logic;
        o1 : out std_logic;
        o2 : out std_logic;
        o3 : out std_logic;
        o4 : out std_logic;
        o5 : out std_logic;
        o6 : out std_logic;
        o7 : out std_logic;
		  
		  key0 : in std_logic;
		  key1 : in std_logic;
		  key2 : in std_logic;
		  key3 : in std_logic
    );
end wrapper;

architecture behaviour of wrapper is

	signal input  : std_logic_vector(7 downto 0);
	
	signal out_sum  : std_logic_vector(7 downto 0);
	signal out_sub  : std_logic_vector(7 downto 0);
	signal out_div  : std_logic_vector(7 downto 0);
	signal out_mult : std_logic_vector(7 downto 0);
	
	signal cout : std_logic;

begin


	SUM  : entity work.adder_subtractor_8 port map(
		i0 => i0, i1 => i1, i2 => i2, i3 => i3, i4 => i4, i5 => i5, i6 => i6, i7 => i7,
		o0 => out_sum(0), o1 => out_sum(1), o2 => out_sum(2), o3 => out_sum(3), o4 => out_sum(4), o5 => out_sum(5), o6 => out_sum(6), o7 => out_sum(7),
		op => '0', cout => cout
	);
	
	SUB  : entity work.adder_subtractor_8 port map(
		i0 => i0, i1 => i1, i2 => i2, i3 => i3, i4 => i4, i5 => i5, i6 => i6, i7 => i7,
		o0 => out_sub(0), o1 => out_sub(1), o2 => out_sub(2), o3 => out_sub(3), o4 => out_sub(4), o5 => out_sub(5), o6 => out_sub(6), o7 => out_sub(7),
		op => '1', cout => cout
	);
	
	DIV  : entity work.divisor port map(
		i0 => i0, i1 => i1, i2 => i2, i3 => i3, i4 => i4, i5 => i5, i6 => i6, i7 => i7,
		o0 => out_div(0), o1 => out_div(1), o2 => out_div(2), o3 => out_div(3), o4 => out_div(4), o5 => out_div(5), o6 => out_div(6), o7 => out_div(7)
	);
	
	MULT : entity work.multiplicador port map(
		i0 => i0, i1 => i1, i2 => i2, i3 => i3, i4 => i4, i5 => i5, i6 => i6, i7 => i7,
		o0 => out_mult(0), o1 => out_mult(1), o2 => out_mult(2), o3 => out_mult(3), o4 => out_mult(4), o5 => out_mult(5), o6 => out_mult(6), o7 => out_mult(7)
	);
	
	
	process(key0, key1, key2, key3)
	
	begin
		
		if (key0 = '0') then
			o0 <= out_sum(0);
         o1 <= out_sum(1);
         o2 <= out_sum(2);
         o3 <= out_sum(3);
         o4 <= out_sum(4);
         o5 <= out_sum(5);
         o6 <= out_sum(6);
         o7 <= out_sum(7);
		
		elsif (key1 = '0') then
			o0 <= out_sub(0);
         o1 <= out_sub(1);
         o2 <= out_sub(2);
         o3 <= out_sub(3);
         o4 <= out_sub(4);
         o5 <= out_sub(5);
         o6 <= out_sub(6);
         o7 <= out_sub(7);		
		
		elsif (key2 = '0') then
			o0 <= out_div(0);
         o1 <= out_div(1);
         o2 <= out_div(2);
         o3 <= out_div(3);
         o4 <= out_div(4);
         o5 <= out_div(5);
         o6 <= out_div(6);
         o7 <= out_div(7);		
		
		elsif (key3 = '0') then
			o0 <= out_mult(0);
         o1 <= out_mult(1);
         o2 <= out_mult(2);
         o3 <= out_mult(3);
         o4 <= out_mult(4);
         o5 <= out_mult(5);
         o6 <= out_mult(6);
         o7 <= out_mult(7);		
			
		else
			o0 <= '0';
			o1 <= '0';
			o2 <= '0';
			o3 <= '0';
			o4 <= '0';
			o5 <= '0';
			o6 <= '0';
			o7 <= '0';
		
		end if;
	
	end process;

end behaviour;

