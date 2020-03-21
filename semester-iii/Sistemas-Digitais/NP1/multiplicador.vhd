-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use ieee.numeric_std.all;

entity multiplicador is
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
      o7 : out std_logic
    );
end multiplicador;

architecture behavior of multiplicador is	
    begin
    
    process(i0,i1,i2,i3,i4,i5,i6,i7)
    
    	variable number : unsigned (15 downto 0) := (others => '0');
    	variable cons : std_logic_vector(7 downto 0) := "00000011";
        variable output : unsigned (15 downto 0) := (others => '0');
   		
        begin
        
          output := (others => '0');
          
          number(0) := i0; number(1) := i1; number(2) := i2;
          number(3) := i3; number(4) := i4; number(5) := i5;
          number(6) := i6; number(7) := i7; number(8) := '0';
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
