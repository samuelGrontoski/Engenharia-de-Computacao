function calcularParcela() {
    
    const P = parseFloat(document.getElementById("p").value); // Valor do Empréstimo
    const i = parseFloat(document.getElementById("taxa").value) / 100; // Taxa de Juros
    const n = parseInt(document.getElementById("parcelas").value); // Número de Parcelas

    // Validação básica de entrada
    if (isNaN(P) || isNaN(i) || isNaN(n) || P <= 0 || i <= 0 || n <= 0) {
        document.getElementById("resultado").textContent = "Por favor, insira valores válidos.";
        return;
    }

    const tolerancia = 1e-6;
    const maxIter = 1000;
    let M = 100;  

    
    function f(M) {
        return M * (1 - Math.pow(1 + i, -n)) / i - P;
    }

    function f_derivada() {
        return (1 - Math.pow(1 + i, -n)) / i;
    }

    // Método de Newton para encontrar o valor de M que zera a função
    for (let iter = 0; iter < maxIter; iter++) {
        const f_M = f(M);
        const f_derivada_M = f_derivada();
        const M_novo = M - f_M / f_derivada_M;

        
        if (Math.abs(M_novo - M) < tolerancia) {
            document.getElementById("resultado").textContent = 
                `Parcela mensal ideal: R$ ${M_novo.toFixed(2)}`;
            return;
        }
        
        M = M_novo;
    }

    // Exibe uma mensagem caso o cálculo não convirja
    document.getElementById("resultado").textContent = 
        "O cálculo não convergiu. Tente ajustar os valores.";
}
