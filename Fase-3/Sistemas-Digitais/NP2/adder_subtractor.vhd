library IEEE;
use IEEE.std_logic_1164.all;

entity adder_subtractor is
	port(
    	  in1_0 : in std_logic;
        in1_1 : in std_logic;
        in1_2 : in std_logic;
        in1_3 : in std_logic;
		  
        in2_0 : in std_logic;
        in2_1 : in std_logic;
        in2_2 : in std_logic;
        in2_3 : in std_logic;
		  
        cin : in std_logic;
		  op: in std_logic;
        o0 : out std_logic;
        o1 : out std_logic;
        o2 : out std_logic;
        o3 : out std_logic;
        cout : out std_logic
    );
    
end adder_subtractor;

architecture behavior of adder_subtractor is
	
    signal c0 : std_logic := '0';
    signal c1 : std_logic := '0';
    signal c2 : std_logic := '0';
    
	begin
    
      o0 <= (in1_0 XOR op) XOR in2_0 XOR cin;
      c0 <= ((in1_0 XOR op) AND in2_0) OR ((in1_0 XOR op) AND cin) OR (in2_0 AND cin);

      o1 <= (in1_1 XOR op) XOR in2_1 XOR c0;
      c1 <= ((in1_1 XOR op) AND in2_1) OR ((in1_1 XOR op) AND c0) OR (in2_1 AND c0);

      o2 <= (in1_2 XOR op) XOR in2_2 XOR c1;
      c2 <= ((in1_2 XOR op) AND in2_2)OR ((in1_2 XOR op) AND c1) OR (in2_2 AND c1);

      o3 <= (in1_3 XOR op) XOR in2_3 XOR c2;
      cout <= ((in1_3 XOR op) AND in2_3) OR ((in1_3 XOR op) AND c2) OR (in2_3 AND c2);
      
  	end behavior;