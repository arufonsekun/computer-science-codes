library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplicador is
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
		  
      o0 : out std_logic;
      o1 : out std_logic;
      o2 : out std_logic;
      o3 : out std_logic;
      o4 : out std_logic;
      o5 : out std_logic;
      o6 : out std_logic;
      o7 : out std_logic
    );
end multiplicador;

architecture behavior of multiplicador is	
    begin
    
    process(a0,a1,a2,a3,a4,a5,a6,a7,
				b0,b1,b2,b3,b4,b5,b6,b7)
    
    	variable number : unsigned (15 downto 0) := (others => '0');
    	variable cons : std_logic_vector(7 downto 0) := b7 & b6 & b5 & b4 & b3 & b2 & b1 & b0;
        variable output : unsigned (15 downto 0) := (others => '0');
   		
        begin
        
          output := (others => '0');
          
          number(0) := a0; number(1) := a1; number(2) := a2;
          number(3) := a3; number(4) := a4; number(5) := a5;
          number(6) := a6; number(7) := a7; number(8) := '0';
          number(9) := '0';number(10) := '0';number(11) := '0';
          number(12) := '0';number(13) := '0';number(14) := '0';
          number(15) := '0';
	
    	  --report std_logic'image(number(0));

          for i in 0 to 7 loop
              if cons(i) = '1' then
              	  output := output + number;
              end if;
              number := number(14 downto 0) & '0';
          end loop;

          o0 <= output(0);
          o1 <= output(1);
          o2 <= output(2);
          o3 <= output(3);
          o4 <= output(4);
          o5 <= output(5);
          o6 <= output(6);
          o7 <= output(7);
    
    end process;
    
end behavior;