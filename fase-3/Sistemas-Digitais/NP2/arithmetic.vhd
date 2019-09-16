library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_unsigned.all;
--use ieee.numeric_std.all;

entity arithmetic is
	port(
		  a0 : in std_logic;
        a1 : in std_logic;
        a2 : in std_logic;
        a3 : in std_logic;
        a4 : in std_logic;
        a5 : in std_logic;
        a6 : in std_logic;
        a7 : in std_logic;
		  
		  b0 : in std_logic;
        b1 : in std_logic;
        b2 : in std_logic;
        b3 : in std_logic;
        b4 : in std_logic;
        b5 : in std_logic;
        b6 : in std_logic;
        b7 : in std_logic;
		  
		  op0 : in std_logic;
		  op1 : in std_logic;
		  
        o0 : out std_logic;
        o1 : out std_logic;
        o2 : out std_logic;
        o3 : out std_logic;
        o4 : out std_logic;
        o5 : out std_logic;
        o6 : out std_logic;
        o7 : out std_logic
    );
end arithmetic;

architecture behaviour of arithmetic is

	signal input  : std_logic_vector(7 downto 0);
	
	signal out_sum  : std_logic_vector(7 downto 0);
	signal out_sub  : std_logic_vector(7 downto 0);
	signal out_div  : std_logic_vector(7 downto 0);
	signal out_mult : std_logic_vector(7 downto 0);
	
	signal cout : std_logic;

begin


	SUM  : entity work.adder_subtractor_8 port map(
		a0 => a0, a1 => a1, a2 => a2, a3 => a3, a4 => a4, a5 => a5, a6 => a6, a7 => a7,
		b0 => b0, b1 => b1, b2 => b2, b3 => b3, b4 => b4, b5 => b5, b6 => b6, b7 => b7,
		o0 => out_sum(0), o1 => out_sum(1), o2 => out_sum(2), o3 => out_sum(3), o4 => out_sum(4), o5 => out_sum(5), o6 => out_sum(6), o7 => out_sum(7),
		op => '0', cout => cout
	);
	
	SUB  : entity work.adder_subtractor_8 port map(
		a0 => a0, a1 => a1, a2 => a2, a3 => a3, a4 => a4, a5 => a5, a6 => a6, a7 => a7,
		b0 => b0, b1 => b1, b2 => b2, b3 => b3, b4 => b4, b5 => b5, b6 => b6, b7 => b7,
		o0 => out_sub(0), o1 => out_sub(1), o2 => out_sub(2), o3 => out_sub(3), o4 => out_sub(4), o5 => out_sub(5), o6 => out_sub(6), o7 => out_sub(7),
		op => '1', cout => cout
	);
	
--	DIV  : entity work.divisor port map(
--		a0 => a0, a1 => a1, a2 => a2, a3 => a3, a4 => a4, a5 => a5, a6 => a6, a7 => a7,
--		b0 => b0, b1 => b1, b2 => b2, b3 => b3, b4 => b4, b5 => b5, b6 => b6, b7 => b7,
--		o0 => out_div(0), o1 => out_div(1), o2 => out_div(2), o3 => out_div(3), o4 => out_div(4), o5 => out_div(5), o6 => out_div(6), o7 => out_div(7)
--	);
	
	MULT : entity work.multiplicador port map(
		a0 => a0, a1 => a1, a2 => a2, a3 => a3, a4 => a4, a5 => a5, a6 => a6, a7 => a7,
		b0 => b0, b1 => b1, b2 => b2, b3 => b3, b4 => b4, b5 => b5, b6 => b6, b7 => b7,
		o0 => out_mult(0), o1 => out_mult(1), o2 => out_mult(2), o3 => out_mult(3), o4 => out_mult(4), o5 => out_mult(5), o6 => out_mult(6), o7 => out_mult(7)
	);
	
	
	process(op1, op0)
	
	begin
		
		if (op1 = '0' and op0 = '0') then
			o0 <= out_sum(0);
         o1 <= out_sum(1);
         o2 <= out_sum(2);
         o3 <= out_sum(3);
         o4 <= out_sum(4);
         o5 <= out_sum(5);
         o6 <= out_sum(6);
         o7 <= out_sum(7);
		
		elsif (op1 = '0' and op0 = '1') then
			o0 <= out_sub(0);
         o1 <= out_sub(1);
         o2 <= out_sub(2);
         o3 <= out_sub(3);
         o4 <= out_sub(4);
         o5 <= out_sub(5);
         o6 <= out_sub(6);
         o7 <= out_sub(7);		
		
--		elsif (op1 = '1' and op0 = '1') then
--			o0 <= out_div(0);
--         o1 <= out_div(1);
--         o2 <= out_div(2);
--         o3 <= out_div(3);
--         o4 <= out_div(4);
--         o5 <= out_div(5);
--         o6 <= out_div(6);
--         o7 <= out_div(7);		
		
		elsif (op1 = '1' and op0 = '0') then
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