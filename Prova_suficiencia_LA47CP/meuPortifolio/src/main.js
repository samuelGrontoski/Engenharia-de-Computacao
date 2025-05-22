const toggleBtn = document.getElementById("themeToggleBtn");
const body = document.body;

toggleBtn.addEventListener("click", () => {
    body.classList.toggle("dark-mode");
    body.classList.toggle("light-mode");

    // Mudar texto do botão
    if (body.classList.contains("dark-mode")) {
        toggleBtn.innerHTML = "☀️ Modo Claro";
        toggleBtn.classList.remove("btn-outline-secondary");
        toggleBtn.classList.add("btn-outline-light");
    } else {
        toggleBtn.innerHTML = "🌙 Modo Escuro";
        toggleBtn.classList.remove("btn-outline-light");
        toggleBtn.classList.add("btn-outline-secondary");
    }
});
