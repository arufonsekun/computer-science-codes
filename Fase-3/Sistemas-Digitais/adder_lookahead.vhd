-- Code your design here
library IEEE;
use IEEE.std_logic_1164.all;

entity adder_lookahead is
	port(
		--a7, a6, a5, a4, a3, a2, a1, a0 : in std_logic;
		b0, b1, b2, b3, b4, b5, b6, b7 : in std_logic;
      cin  : in std_logic;
      cout : out std_logic;
      s0, s1, s2, s3, s4, s5, s6, s7 : out std_logic
	);
end adder_lookahead;

architecture behaviour of adder_lookahead is
	
    signal g, p, c : std_logic_vector(7 downto 0);
	 signal a7, a6, a5, a4, a3, a2, a1, a0 : std_logic;
    
begin
    
	 a7 <= '0';
	 a6 <= '1';
	 a5 <= '1';
	 a4 <= '0';
	 a3 <= '1';
	 a2 <= '1';
	 a1 <= '0';
	 a0 <= '1';
	 
    g(0) <= a0 AND b0;
    g(1) <= a1 AND b1;
    g(2) <= a2 AND b2;
    g(3) <= a3 AND b3;
	 g(4) <= a4 AND b4;
    g(5) <= a5 AND b5;
    g(6) <= a6 AND b6;
    g(7) <= a7 AND b7;
    
    p(0) <= a0 XOR b0;
    p(1) <= a1 XOR b1;
    p(2) <= a2 XOR b2;
    p(3) <= a3 XOR b3;
	 p(4) <= a4 XOR b4;
    p(5) <= a5 XOR b5;
    p(6) <= a6 XOR b6;
    p(7) <= a7 XOR b7;
    
    -- c(0) == c1, cin == c0
	 -- Essa disgraça deveria ser feita até 4 e com 2 circuitos.
    c(0) <= g(0) OR (p(0) AND cin);
    c(1) <= g(1) OR (p(1) AND g(0)) OR (p(1) AND p(0) AND cin);
    c(2) <= g(2) OR (p(2) AND g(1)) OR (p(2) AND p(1) AND g(0)) OR (p(2) AND p(1) AND p(0) AND cin);
    c(3) <= g(3) OR (p(3) AND g(2)) OR (p(3) AND p(2) AND g(1)) OR (p(3) AND p(2) AND p(1) AND g(0)) OR (p(3) AND p(2) AND p(1) AND p(0) AND cin);
	 c(4) <= g(4) OR (p(4) AND g(3)) OR (p(4) AND p(3) AND g(2)) OR (p(4) AND p(3) AND p(2) AND g(1)) OR (p(4) AND p(3) AND p(2) AND p(1) AND g(0)) OR (p(4) AND p(3) AND p(2) AND p(1) AND p(0) AND cin);
	 c(5) <= g(5) OR (p(5) AND g(4)) OR (p(5) AND p(4) AND g(3)) OR (p(5) AND p(4) AND p(3) AND g(2)) OR (p(5) AND p(4) AND p(3) AND p(2) AND g(1)) OR (p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND g(0)) OR (p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND p(0) AND cin);
	 c(6) <= g(6) OR (p(6) AND g(5)) OR (p(6) AND p(5) AND g(4)) OR (p(6) AND p(5) AND p(4) AND g(3)) OR (p(6) AND p(5) AND p(4) AND p(3) AND g(2)) OR (p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND g(1)) OR (p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND g(0)) OR (p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND p(0) AND cin);
	 c(7) <= g(7) OR (p(7) AND g(6)) OR (p(7) AND p(6) AND g(5)) OR (p(7) AND p(6) AND p(5) AND g(4)) OR (p(7) AND p(6) AND p(5) AND p(4) AND g(3)) OR (p(7) AND p(6) AND p(5) AND p(4) AND p(3) AND g(2)) OR (p(7) AND p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND g(1)) OR (p(7) AND p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND g(0)) OR (p(7) AND p(6) AND p(5) AND p(4) AND p(3) AND p(2) AND p(1) AND p(0) AND cin);
    
    s0 <= p(0) XOR cin;
    s1 <= p(1) XOR c(0);
    s2 <= p(2) XOR c(1);
    s3 <= p(3) XOR c(2);
	 s4 <= p(4) XOR c(3);
	 s5 <= p(5) XOR c(4);
	 s6 <= p(6) XOR c(5);
	 s7 <= p(7) XOR c(6);
    
    cout <= c(7);

end architecture;
    