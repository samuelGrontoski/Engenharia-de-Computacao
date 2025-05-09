document.addEventListener("DOMContentLoaded", function () {
    const competidores = [];
    const botaoAdicionar = document.getElementById("adicionar");
    const nomeInput = document.getElementById("nome");
    const pontuacaoInput = document.getElementById("pontuacao");

    botaoAdicionar.addEventListener("click", function () {
        const nome = nomeInput.value.trim();
        const pontuacao = parseInt(pontuacaoInput.value);

        if (nome && !isNaN(pontuacao) && pontuacao >= 0) {
            const novoCompetidor = { nome: nome, pontuacao: pontuacao };
            inserirCompetidor(novoCompetidor);
            exibirPlacar();
            nomeInput.value = "";
            pontuacaoInput.value = "";
        } else {
            alert("Por favor, insira um nome e uma pontuação válidos.");
        }
    });

    function inserirCompetidor(novoCompetidor) {
        let inicio = 0;
        let fim = competidores.length - 1;

        // Busca binária para encontrar o índice de inserção
        while (inicio <= fim) {
            const meio = Math.floor((inicio + fim) / 2);
            if (competidores[meio].pontuacao < novoCompetidor.pontuacao) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }

        competidores.splice(inicio, 0, novoCompetidor);
    }

    function exibirPlacar() {
        let placarDiv = document.getElementById("placar");

        // Cria o placar se ele não existir
        if (!placarDiv) {
            placarDiv = document.createElement("div");
            placarDiv.id = "placar";
            document.body.appendChild(placarDiv);
        }

        // Limpa o conteúdo anterior do placar
        placarDiv.innerHTML = "<h2>Placar Atual</h2>";

        // Adiciona cada competidor ao placar
        competidores.forEach((competidor, index) => {
            const competidorDiv = document.createElement("div");
            competidorDiv.className = "competidor";
            competidorDiv.textContent = `${index + 1}. ${competidor.nome} - ${competidor.pontuacao} pontos`;
            placarDiv.appendChild(competidorDiv);
        });
    }
});
