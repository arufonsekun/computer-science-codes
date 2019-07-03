library IEEE;
use IEEE.std_logic_1164.all;

entity bloco_controle is
	port(
		-- input do bloco de controle
		i0,i1,i2,i3,i4,i5,i6,i7 : in std_logic;
		
		-- ativa comando
		op1  : in std_logic; -- SW[9]
		op0  : in std_logic; -- SW[8]
		push : in std_logic; -- KEY[0]
		pop  : in std_logic; -- KEY[1]
		reset: in std_logic; -- KEY[2]
		gambi: in std_logic; -- KEY[3]
		
		-- inputs vindos do bloco operativo
		--status : in std_logic;
				
		-- saidas do bloco de controle que n vai pro bloco operativo
		o0,o1,o2,o3,o4,o5,o6,o7 : out std_logic
		
	);
end bloco_controle;

architecture behavior of bloco_controle is

	TYPE state_type is (tem0, tem1, tem2, tem3, tem4, tem5, tem6, tem7, tem8);
	signal state : state_type := tem0;
	
	TYPE memory is array (0 to 7) of std_logic_vector(7 downto 0);
   signal stack : memory;
	
	signal val0, val1, res : std_logic_vector(7 downto 0) := "00000000";
	signal arith0, arith1 : std_logic;
	signal reset_output : std_logic := '0';

begin
	
	BO : entity work.bloco_operacional port map(
		a0 => val0(0), a1 => val0(1), a2 => val0(2), a3 => val0(3), a4 => val0(4), a5 => val0(5), a6 => val0(6), a7 => val0(7),
		b0 => val1(0), b1 => val1(1), b2 => val1(2), b3 => val1(3), b4 => val1(4), b5 => val1(5), b6 => val1(6), b7 => val1(7),
		arith1 => arith1, arith0 => arith0, reset => reset_output,
		o0 => res(0), o1 => res(1), o2 => res(2), o3 => res(3), o4 => res(4), o5 => res(5), o6 => res(6), o7 => res(7)
	);
	
	process(gambi)
	
	begin
	
		if (gambi'Event and gambi = '0') then
			
			if reset = '0' then
				state <= tem0;
				reset_output <= '1';
				stack(0) <= "00000000"; stack(1) <= "00000000"; stack(2) <= "00000000"; stack(3) <= "00000000";
				stack(4) <= "00000000"; stack(5) <= "00000000"; stack(6) <= "00000000"; stack(7) <= "00000000";
			else
				case state is
				
					when tem0 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem0;
							
						-- PUSH
						elsif (push = '0') then
							state <= tem1;
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem1 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem1;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem2;
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem2 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem1;
							--op <= comando_pop(1 downto 0);
							val0 <= stack(0);
							val1 <= stack(1);
							stack(1) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							
							stack(0) <= res;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem3;
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem3 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem2;
							
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							
							stack(0) <= res;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem4;
							stack(3) <= stack(2);
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem4 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem3;
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= stack(3);
							stack(3) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							
							stack(0) <= res;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem5;
							stack(4) <= stack(3);
							stack(3) <= stack(2);
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem5 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem4;
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= stack(3);
							stack(3) <= stack(4);
							stack(4) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							--op <= op1&op0;
							
							stack(0) <= res;					
						
						-- PUSH
						elsif (push = '0') then
							state <= tem6;	
							stack(5) <= stack(4);
							stack(4) <= stack(3);
							stack(3) <= stack(2);
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem6 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem5;
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= stack(3);
							stack(3) <= stack(4);
							stack(4) <= stack(5);
							stack(5) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							--op <= op1&op0;
							
							stack(0) <= res;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem7;
							stack(6) <= stack(5);
							stack(5) <= stack(4);
							stack(4) <= stack(3);
							stack(3) <= stack(2);
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
							
				
						end if;
						
					when tem7 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem6;
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= stack(3);
							stack(3) <= stack(4);
							stack(4) <= stack(5);
							stack(5) <= stack(6);
							stack(6) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
							
							stack(0) <= res;
						
						-- PUSH
						elsif (push = '0') then
							state <= tem8;
							stack(7) <= stack(6);
							stack(6) <= stack(5);
							stack(5) <= stack(4);
							stack(4) <= stack(3);
							stack(3) <= stack(2);
							stack(2) <= stack(1);
							stack(1) <= stack(0);
							
							stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
							stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
				
						end if;
						
					when tem8 =>
						-- POP com operação
						if (pop = '0') then
							state <= tem7;
							val0 <= stack(0);
							val1 <= stack(1);
							
							stack(1) <= stack(2);
							stack(2) <= stack(3);
							stack(3) <= stack(4);
							stack(4) <= stack(5);
							stack(5) <= stack(6);
							stack(6) <= stack(7);
							stack(7) <= "00000000";
							
							arith1 <= op1; arith0 <= op0; -- isso vai acionar o processa no bloco_operacional
					
							stack(0) <= res;
							
						
						-- PUSH
						elsif (push = '0') then
							state <= tem8;
						end if;
				
				
				end case;
				
			end if;
			
		end if; -- gambi 
		o0 <= stack(0)(0); o1 <= stack(0)(1); o2 <= stack(0)(2); o3 <= stack(0)(3);
		o4 <= stack(0)(4); o5 <= stack(0)(5); o6 <= stack(0)(6); o7 <= stack(0)(7);
				
	end process;

end behavior;


