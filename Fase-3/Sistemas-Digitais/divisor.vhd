-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_unsigned.all;
--use ieee.numeric_std.all;

entity divisor is
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
end divisor;

architecture div84 of divisor is

  procedure div4(
      numer : in std_logic_vector(7 downto 0);
      denom : in std_logic_vector(3 downto 0);
      quotient : out std_logic_vector(3 downto 0);
      remainder : out std_logic_vector(3 downto 0)) is 
      
  variable d, n1 : std_logic_vector(4 downto 0);
  variable n2 : std_logic_vector(3 downto 0);
  
  begin
      d := '0' & denom;
      n2 := numer(3 downto 0);
      n1 := '0' & numer(7 downto 4);
      for i in 0 to 3 loop
          n1 := n1(3 downto 0) & n2(3);
          n2 := n2(2 downto 0) & '0';
          if n1 >= d then
              n1 := n1 - d;
              n2(0) := '1';
          end if;
      end loop;
      quotient := n2;
      remainder := n1(3 downto 0);
      
  end procedure;
    
    begin 
    	process (i0,i1,i2,i3,i4,i5,i6,i7)
        variable remH, remL, quotH, quotL : std_logic_vector(3 downto 0);
        begin
        	div4("0000" & i7 & i6 & i5 & i4, "0011", quotH, remH);
            div4(remH & i3 & i2 & i1 & i0, "0011", quotL, remL);
				
				 o0 <= quotL(0);
				 o1 <= quotL(1);
				 o2 <= quotL(2);
				 o3 <= quotL(3);
				 o4 <= quotH(0);
				 o5 <= quotH(1);
				 o6 <= quotH(2);
				 o7 <= quotH(3);

    end process;
    
end div84;

