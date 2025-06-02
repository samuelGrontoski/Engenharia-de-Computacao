library ieee;
use ieee.std_logic_1164.all;
-- Removido ieee.numeric_std.all pois não é estritamente necessário para este exemplo simples
-- mas pode ser útil para conversões ou operações aritméticas mais complexas.

entity contador_aleatorio is
    port (
        CLK   : in  std_logic;                             -- Entrada de Clock
        RESET : in  std_logic;                             -- Entrada de Reset assíncrono
        Q_out : out std_logic_vector(3 downto 0)       -- Saída de 4 bits do contador
    );
end entity contador_aleatorio;

architecture Behavioral of contador_aleatorio is

    -- Definição dos estados para clareza
    constant STATE_A : std_logic_vector(3 downto 0) := "1010"; -- A (10)
    constant STATE_8 : std_logic_vector(3 downto 0) := "1000"; -- 8
    constant STATE_4 : std_logic_vector(3 downto 0) := "0100"; -- 4
    constant STATE_7 : std_logic_vector(3 downto 0) := "0111"; -- 7
    constant STATE_F : std_logic_vector(3 downto 0) := "1111"; -- F (15)
    constant STATE_5 : std_logic_vector(3 downto 0) := "0101"; -- 5
    constant STATE_D : std_logic_vector(3 downto 0) := "1101"; -- D (13)

    -- Sinal interno para armazenar o estado atual do contador
    signal estado_atual : std_logic_vector(3 downto 0);
    -- Sinal interno para determinar o próximo estado (lógica combinacional)
    signal proximo_estado : std_logic_vector(3 downto 0);

begin

    -- Processo para o registrador de estado (Flip-Flops)
    -- Este processo é sensível às bordas de subida do clock e ao reset.
    state_register_proc : process (CLK, RESET)
    begin
        if RESET = '1' then
            estado_atual <= STATE_A; -- Ao resetar, vai para o estado inicial 'A'
        elsif rising_edge(CLK) then
            estado_atual <= proximo_estado; -- Em cada borda de subida do clock, atualiza o estado
        end if;
    end process state_register_proc;

    -- Processo para a lógica combinacional (Malha Secundária / Lógica de Próximo Estado)
    -- Este processo determina qual será o próximo estado com base no estado atual.
    next_state_logic_proc : process (estado_atual)
    begin
        case estado_atual is
            when STATE_A =>
                proximo_estado <= STATE_8;
            when STATE_8 =>
                proximo_estado <= STATE_4;
            when STATE_4 =>
                proximo_estado <= STATE_7;
            when STATE_7 =>
                proximo_estado <= STATE_F;
            when STATE_F =>
                proximo_estado <= STATE_5;
            when STATE_5 =>
                proximo_estado <= STATE_D;
            when STATE_D =>
                proximo_estado <= STATE_A;
            when others =>
                -- Para quaisquer outros estados (não utilizados na sequência)
                -- é uma boa prática definir um próximo estado, como o estado de reset.
                proximo_estado <= STATE_A;
        end case;
    end process next_state_logic_proc;

    -- Atribui o estado atual à saída do contador
    Q_out <= estado_atual;

end architecture Behavioral;