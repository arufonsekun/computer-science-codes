-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity adder_subtractor_8 is
	port(
		i0 : in std_logic;
		i1 : in std_logic;
		i2 : in std_logic;
		i3 : in std_logic;
		i4 : in std_logic;
		i5 : in std_logic;
		i6 : in std_logic;
		i7 : in std_logic;
		op : in std_logic;
		
		o0 : out std_logic;
		o1 : out std_logic;
		o2 : out std_logic;
		o3 : out std_logic;
		o4 : out std_logic;
		o5 : out std_logic;
		o6 : out std_logic;
		o7 : out std_logic;
		cout : out std_logic
		
	);
end adder_subtractor_8;

architecture behavior of adder_subtractor_8 is

	signal coute : std_logic := '0';
	signal const : std_logic_vector(7 downto 0) := "00000011";
	
	begin
	
	adder1 : entity work.adder_subtractor port map(in1_0 => i0, in1_1 => i1, in1_2 => i2, in1_3 => i3, in2_0 => const(0), in2_1 => const(1), in2_2 => const(2), in2_3 => const(3), op=>op, cout=>coute, cin=>op, o0=>o0, o1=>o1, o2=>o2, o3=>o3);
	adder2 : entity work.adder_subtractor port map(in1_0 => i4, in1_1 => i5, in1_2 => i6, in1_3 => i7, in2_0 => const(4), in2_1 => const(5), in2_2 => const(6), in2_3 => const(7), op=>op, cin=>coute, o0=>o4, o1=>o5, o2=>o6, o3=>o7, cout=>cout);

	end behavior;
