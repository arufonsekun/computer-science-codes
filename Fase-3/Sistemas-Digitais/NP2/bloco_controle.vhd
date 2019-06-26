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

		
		-- inputs vindos do bloco operativo
		--status : in std_logic;
				
		-- saidas do bloco de controle que n vai pro bloco operativo
		o0,o1,o2,o3,o4,o5,o6,o7 : out std_logic
		
	);
end bloco_controle;

architecture behavior of bloco_controle is

	signal comando_pop : std_logic_vector(2 downto 0);
	signal comando_push : std_LoGic_VeCTor(2 downto 0);

begin

	BO : entity work.bloco_operacional port map(
		i0 => i0, i1 => i1, i2 => i2, i3 => i3, i4 => i4, i5 => i5, i6 => i6, i7 => i7, 
		comando_pop => comando_pop, comando_push => comando_push,
		o0 => o0, o1 => o1, o2 => o2, o3 => o3, o4 => o4, o5 => o5, o6 => o6, o7 => o7
	);
		
	-- PUP
	process (pop)
	
	begin

		if (pop'EVENT and pop = '0') then --clk'EVENT and clk = '1' and 
			comando_pop <= '0' & op1 & op0;
				
		else
			comando_pop <= "111";
			
		end if;
			
	
	end process;
	
	-- POSH
	process(push)
	
	begin
	
		-- ADICIONA NÚMERO
		if (push'EVENT and push = '0') then --clk'EVENT and clk = '1' and 
			comando_push <= "100";
			
		else
			comando_push <= "000";
		
		end if;
	
	end process;

end behavior;


