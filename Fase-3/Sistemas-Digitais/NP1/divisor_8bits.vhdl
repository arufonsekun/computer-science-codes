library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_unsigned.all;

entity divisor_8bits is
    port(
        --numerator
        a0 : in std_logic;
        a1 : in std_logic;
        a2 : in std_logic;
        a3 : in std_logic;
        a4 : in std_logic;
        a5 : in std_logic;
        a6 : in std_logic;
        a7 : in std_logic;

        --denominator
        b0 : in std_logic;
        b1 : in std_logic;
        b2 : in std_logic;
        b3 : in std_logic;
        b4 : in std_logic;
        b5 : in std_logic;
        b6 : in std_logic;
        b7 : in std_logic;

        --quotient
        o0 : out std_logic;
        o1 : out std_logic;
        o2 : out std_logic;
        o3 : out std_logic;
        o4 : out std_logic;
        o5 : out std_logic;
        o6 : out std_logic;
        o7 : out std_logic

    );
end divisor_8bits;

architecture behavior of divisor_8bits is

    procedure div8(
        numer : in std_logic_vector(7 downto 0);
        denom : in std_logic_vector(7 downto 0);
        quotient : std_logic_vector(7 downto 0)) is

    variable d, n1 : std_logic_vector(8 downto 0);
    variable n2 : std_logic_vector(7 downto 0);

    begin
        d := '0' & denom;
        n2 := numer;
        n1 := '0' & numer;
        for i in 0 to 7 loop
            n1 := n1(7 downto 0) & n2(7);
            n2 := n2(6 downto 0) & '0';

            if n1 >= d then
                n1 := n1 - d;
                n2(0) := '1';
            end if;
        end loop;
        quotient := n2;
    end procedure;

    begin --architecture

        process(a0,a1,a2,a3,a4,a5,a6,a7,b0,b1,b2,b3,b4,b5,b6,b7)
            variable output : std_logic_vector(7 downto 0);
            begin
                div8(a7 & a6 & a5 & a4 & a3 & a2 & a1 & a0, b7 & b6 & b5 & b4 & b3 & b2 & b1 & b0, output);
                o7 < output(7); o6 < output(6); o5 < output(5); o4 < output(4);
                o3 < output(3); o2 < output(2); o1 < output(1); o0 < output(0);
        end process;

    end behavior;
            
