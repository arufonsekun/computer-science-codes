                                   library IEEE;
use IEEE.std_logic_1164.all;

entity bloco_operacional is
	port(
		i0,i1,i2,i3,i4,i5,i6,i7 : in std_logic;
		comando_pop,comando_push : in std_logic_vector(2 downto 0);
		o0,o1,o2,o3,o4,o5,o6,o7 : out std_logic
	);
	
end bloco_operacional;

architecture behavior of bloco_operacional is
	
	TYPE state_type is (tem0, tem1, tem2, tem3, tem4, tem5, tem6, tem7, tem8);
	signal state : state_type;
	
	TYPE memory is array (0 to 7) of std_logic_vector(7 downto 0);
   signal stack : memory := (others => (others => '0'));
	
	signal val0, val1, res : std_logic_vector(7 downto 0) := "00000000";	
	signal op : std_logic_vector(1 downto 0);
		
begin
	
	CALC : entity work.arithmetic port map(
		a0 => val0(0), a1 => val0(1), a2 => val0(2), a3 => val0(3), a4 => val0(4), a5 => val0(5), a6 => val0(6), a7 => val0(7), 
		b0 => val1(0), b1 => val1(1), b2 => val1(2), b3 => val1(3), b4 => val1(4), b5 => val1(5), b6 => val1(6), b7 => val1(7),
		op0 => op(0), op1 => op(1),
		o0 => res(0), o1 => res(1), o2 => res(2), o3 => res(3), o4 => res(4), o5 => res(5), o6 => res(6), o7 => res(7)
	);
	
	process(comando_pop, comando_push)
	
	begin
	
		case state is
		
			when tem0 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					state <= tem0;
					
				-- PUSH
				elsif (comando_push = "100") then
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					state <= tem1;
		
				end if;
				
			when tem1 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					state <= tem1;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem2;
		
				end if;
				
			when tem2 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
				
					val0 <= stack(0);
					val1 <= stack(1);
					stack(0) <= res;
					stack(1) <= "00000000";
					
					op <= comando_pop(1 downto 0);
					
					state <= tem1;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem3;
		
				end if;
				
			when tem3 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= "00000000";
					
					op <= comando_pop(1 downto 0);
					
					state <= tem2;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(3) <= stack(2);
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem4;
		
				end if;
				
			when tem4 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					
					op <= comando_pop(1 downto 0);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= stack(3);
					stack(3) <= "00000000";
					
					state <= tem3;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(4) <= stack(3);
					stack(3) <= stack(2);
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem5;
		
				end if;
				
			when tem5 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					op <= comando_pop(1 downto 0);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= stack(3);
					stack(3) <= stack(4);
					stack(4) <= "00000000";
					
					state <= tem4;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(5) <= stack(4);
					stack(4) <= stack(3);
					stack(3) <= stack(2);
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem6;
		
				end if;
				
			when tem6 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					op <= comando_pop(1 downto 0);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= stack(3);
					stack(3) <= stack(4);
					stack(4) <= stack(5);
					stack(5) <= "00000000";
					
					state <= tem5;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(6) <= stack(5);
					stack(5) <= stack(4);
					stack(4) <= stack(3);
					stack(3) <= stack(2);
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem7;
		
				end if;
				
			when tem7 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					op <= comando_pop(1 downto 0);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= stack(3);
					stack(3) <= stack(4);
					stack(4) <= stack(5);
					stack(5) <= stack(6);
					stack(6) <= "00000000";
					
					state <= tem6;
				
				-- PUSH
				elsif (comando_push = "100") then
					stack(7) <= stack(6);
					stack(6) <= stack(5);
					stack(5) <= stack(4);
					stack(4) <= stack(3);
					stack(3) <= stack(2);
					stack(2) <= stack(1);
					stack(1) <= stack(0);
					
					stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
					stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
					
					state <= tem8;
		
				end if;
				
			when tem8 =>
				-- POP com operação
				if (comando_pop(2) = '0') then
					val0 <= stack(0);
					val1 <= stack(1);
					op <= comando_pop(1 downto 0);
					
					stack(0) <= res;
					stack(1) <= stack(2);
					stack(2) <= stack(3);
					stack(3) <= stack(4);
					stack(4) <= stack(5);
					stack(5) <= stack(6);
					stack(6) <= stack(7);
					stack(7) <= "00000000";
					
					state <= tem7;
				
				-- PUSH
				elsif (comando_push = "100") then
					state <= tem8;
				end if;
		
		end case;
		
			o0 <= stack(0)(0); o1 <= stack(0)(1); o2 <= stack(0)(2); o3 <= stack(0)(3);
			o4 <= stack(0)(4); o5 <= stack(0)(5); o6 <= stack(0)(6); o7 <= stack(0)(7);
				
	end process;	

end behavior;
