-- Code your testbench here
library IEEE;
use IEEE.std_logic_1164.all;

entity fsm is
	port(
			i0,i1,i2,i3,i4,i5,i6,i7 : in std_logic;
			op0 : in std_logic; --sw[8]
			op1 : in std_logic; --sw[9]
			vai : in std_logic; --key[0]
			reset : in std_logic; --key[1]
			o0,o1,o2,o3,o4,o5,o6,o7 : out std_logic
    );
end fsm;

architecture behavior of fsm is

	TYPE state_type is (tem0, tem1, tem2, tem3, tem4, tem5, tem6, tem7, tem8);
    signal estado : state_type;
    
    type memory is array (0 to 7) of std_logic_vector(7 downto 0);
    signal stack : memory;
    
    begin
    
    process (vai)
      begin
		
		if reset = '0' then
          estado <= tem0;
			 stack(0) <= "00000000"; stack(1) <= "00000000"; stack(2) <= "00000000"; stack(3) <= "00000000";
			 stack(4) <= "00000000"; stack(5) <= "00000000"; stack(6) <= "00000000"; stack(7) <= "00000000"; 

		
      elsif (vai = '0') then
          case estado is
          	when tem0 => 
            	if op1 = '0' and op0 = '1' then
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem1;
					end if;	
                if op1 = '1' and op0 = '0' then
                	estado <= tem0;
                end if;
                
           when tem1 =>
           		if op1 = '0' and op0 = '1' then
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem2;
						end if;
                if op1 = '1' and op0 = '0' then
						stack(0) <= "00000000";
                	estado <= tem0;
                end if;
                
           when tem2 =>
           		if op1 = '0' and op0 = '1' then
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem3;
					end if;	
                if op1 = '1' and op0 = '0' then
						stack(0) <= stack(1);
						stack(1) <= "00000000";
                	estado <= tem1;
                end if;
                
           when tem3 =>
           		if op1 = '0' and op0 = '1' then
                	stack(3)<= stack(2);
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem4;
					end if;
                if op1 = '1' and op0 = '0' then
					 estado <= tem2;
						stack(0)(7) <= stack(1)(7); stack(0)(6) <= stack(1)(6); stack(0)(5) <= stack(1)(5); stack(0)(4) <= stack(1)(4);
						stack(0)(3) <= stack(1)(3); stack(0)(2) <= stack(1)(2); stack(0)(1) <= stack(1)(1); stack(0)(0) <= stack(1)(0);				
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= "00000000";
                	
                end if;
                
           when tem4 =>
           		if op1 = '0' and op0 = '1' then
                	stack(4)<= stack(3);
                	stack(3)<= stack(2);
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem5;
					end if;	
                if op1 = '1' and op0 = '0' then
						estado <= tem3;
						stack(0) <= stack(1);
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= "00000000";
                	
                end if;
                
           when tem5 =>
           		if op1 = '0' and op0 = '1' then
                	stack(5)<= stack(4);	
                	stack(4)<= stack(3);
                	stack(3)<= stack(2);
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem6;
					end if;	
                if op1 = '1' and op0 = '0' then
						stack(0) <= stack(1);
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= stack(4);
						stack(4) <= "00000000";
                	estado <= tem4;
                end if;
                
           when tem6 =>
           		if op1 = '0' and op0 = '1' then
                	stack(6)<= stack(5);
                	stack(5)<= stack(4);
                	stack(4)<= stack(3);
                	stack(3)<= stack(2);
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem6;
					end if;	
                if op1 = '1' and op0 = '0' then
						stack(0) <= stack(1);
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= stack(4);
						stack(4) <= stack(5);
						stack(5) <= "00000000";
                	estado <= tem5;
                end if;
                
           when tem7 =>
           		if op1 = '0' and op0 = '1' then
                	stack(7)<= stack(6);
                  stack(6)<= stack(5);
                	stack(5)<= stack(4);	
                	stack(4)<= stack(3);
                	stack(3)<= stack(2);
                	stack(2)<= stack(1);
                	stack(1) <= stack(0);
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
                	estado <= tem8;
					 end if;
					
                if op1 = '1' and op0 = '0' then
						stack(0) <= stack(1);
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= stack(4);
						stack(4) <= stack(5);
						stack(5) <= stack(6);
						stack(6) <= "00000000";
                	estado <= tem6;
                end if;
                
          when tem8 =>
           		if op1 = '0' and op0 = '1' then --01 means push
                	estado <= tem8;
						stack(0)(7) <= i7; stack(0)(6) <= i6; stack(0)(5) <= i5; stack(0)(4) <= i4;
						stack(0)(3) <= i3; stack(0)(2) <= i2; stack(0)(1) <= i1; stack(0)(0) <= i0;
						end if;
						
                if op1 = '1' and op0 = '0' then --10 means popthen
						stack(0)(7) <= stack(1)(7); stack(0)(6) <= stack(1)(6); stack(0)(5) <= stack(1)(5); stack(0)(4) <= stack(1)(4);
						stack(0)(3) <= stack(1)(3); stack(0)(2) <= stack(1)(2); stack(0)(1) <= stack(1)(1); stack(0)(0) <= stack(1)(0);						
						stack(1) <= stack(2);
						stack(2) <= stack(3);
						stack(3) <= stack(4);
						stack(4) <= stack(5);
						stack(5) <= stack(6);
						stack(6) <= stack(7);
						stack(7) <= "00000000";
                	estado <= tem7;
                end if;
          end case;
      end if;
		o0 <= stack(1)(0); o1 <= stack(1)(1); o2 <= stack(1)(2); o3 <= stack(1)(3);
		o4 <= stack(1)(4); o5 <= stack(1)(5); o6 <= stack(1)(6); o7 <= stack(1)(7);
    end process;
	 
	 --process (estado)
	 --begin
		--o0 <= stack(0)(0); o1 <= stack(0)(1); o2 <= stack(0)(2); o3 <= stack(0)(3);
		--o4 <= stack(0)(4); o5 <= stack(0)(5); o6 <= stack(0)(6); o7 <= stack(0)(7);
	 --end process;
	 
end behavior;
