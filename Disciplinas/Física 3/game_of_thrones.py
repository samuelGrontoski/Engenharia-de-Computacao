import numpy as np
import sounddevice as sd
import time

# Configurações
volume = 0.5
sample_rate = 44100

# Frequências das notas musicais (escala temperada padrão)
NOTAS = {
    'A3': 220.00, 'A#3': 233.08, 'B3': 246.94,
    'C4': 261.63, 'C#4': 277.18, 'D4': 293.66, 'D#4': 311.13, 'E4': 329.63,
    'F4': 349.23, 'F#4': 369.99, 'G4': 392.00, 'G#4': 415.30,
    'A4': 440.00, 'A#4': 466.16, 'B4': 493.88,
    'C5': 523.25, 'C#5': 554.37, 'D5': 587.33, 'D#5': 622.25, 'E5': 659.25,
    'F5': 698.46, 'F#5': 739.99, 'G5': 783.99, 'G#5': 830.61,
    'A5': 880.00, 'B5': 987.77, 'C6': 1046.50,
    'R': 0  # silêncio (rest)
}

# Gera onda senoidal para uma nota
def gerar_onda(frequencia, duracao):
    if frequencia == 0:
        return np.zeros(int(sample_rate * duracao))
    t = np.linspace(0, duracao, int(sample_rate * duracao), False)
    onda = np.sin(frequencia * t * 2 * np.pi)
    return volume * onda

# Sequência da melodia principal (nota, duração em segundos)
melodia = [
    # Trecho 1 (intro épica)
    ('G4', 0.5), ('C5', 0.25), ('D5', 0.25), ('E5', 0.5),
    ('G4', 0.5), ('C5', 0.25), ('D5', 0.25), ('E5', 0.5),
    ('F5', 0.5), ('E5', 0.25), ('D5', 0.25), ('C5', 0.5),
    ('E4', 0.5), ('G4', 0.25), ('A4', 0.25), ('B4', 0.5),
    ('C5', 0.25), ('B4', 0.25), ('A4', 0.5),
    ('F4', 0.5), ('G4', 0.25), ('A4', 0.25), ('B4', 0.5),
    ('C5', 0.25), ('B4', 0.25), ('A4', 0.5),

    # Trecho 2 (variações)
    ('E5', 0.25), ('F5', 0.25), ('G5', 0.5),
    ('D5', 0.25), ('E5', 0.25), ('F5', 0.5),
    ('C5', 0.25), ('D5', 0.25), ('E5', 0.5),
    ('B4', 0.25), ('C5', 0.25), ('D5', 0.5),
    ('G4', 0.5), ('R', 0.25), ('G4', 0.5), ('R', 0.25),

    # Refrão principal (épico)
    ('G4', 0.5), ('C5', 0.25), ('D5', 0.25), ('E5', 0.5),
    ('G4', 0.5), ('C5', 0.25), ('D5', 0.25), ('E5', 0.5),
    ('F5', 0.5), ('E5', 0.25), ('D5', 0.25), ('C5', 0.5),
    ('E4', 0.5), ('G4', 0.25), ('A4', 0.25), ('B4', 0.5),
    ('C5', 0.25), ('B4', 0.25), ('A4', 0.5),
]

# Toca a música
print("🎵 Tocando Game of Thrones (versão senoidal)...")
musica = np.concatenate([gerar_onda(NOTAS[nota], duracao) for nota, duracao in melodia])
sd.play(musica, samplerate=sample_rate)
sd.wait()
print("🏁 Música finalizada.")
