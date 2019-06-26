library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.STD_LOGIC_unsigned.all;

entity divisor is
    port(
        --numerator
        i0 : in std_logic;
        i1 : in std_logic;
        i2 : in std_logic;
        i3 : in std_logic;
        i4 : in std_logic;
        i5 : in std_logic;
        i6 : in std_logic;
        i7 : in std_logic;

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
end divisor;

architecture behavior of divisor is

    procedure div8(
        numer : in std_logic_vector(7 downto 0);
        denom : in std_logic_vector(7 downto 0);
        quotient : out std_logic_vector(7 downto 0)) is

    variable d, n1 : std_logic_vector(8 downto 0);
    variable n2 : std_logic_vector(7 downto 0);

    begin
        d := '0' & denom;
        n2 := numer;
        n1 := "000000000";
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

        process(i0,i1,i2,i3,i4,i5,i6,i7)
            variable output : std_logic_vector(7 downto 0);
            begin
                div8(i7 & i6 & i5 & i4 & i3 & i2 & i1 & i0, "10000000", output);
                o7 <= output(7); o6 <= output(6); o5 <= output(5); o4 <= output(4);
                o3 <= output(3); o2 <= output(2); o1 <= output(1); o0 <= output(0);
        end process;

    end behavior;
