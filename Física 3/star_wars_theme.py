import numpy as np
import sounddevice as sd
import time

# Dicionário com frequências das notas (em Hz)
notes_freq = {
    'A4': 440.00,
    'Bb4': 466.16,
    'B4': 493.88,
    'C5': 523.25,
    'D5': 587.33,
    'Eb5': 622.25,
    'F5': 698.46,
    'G5': 783.99,
    'A5': 880.00,
    'Bb5': 932.33,
    'D6': 1174.66,
    'F4': 349.23,
    'Eb4': 311.13,
    'C4': 261.63,
    'REST': 0.00
}

# Melodia principal do tema de Star Wars (notas e duração em segundos)
melody = [
    ('Bb4', 0.5), ('Bb4', 0.5), ('F4', 0.5), ('Eb4', 0.25), ('Bb4', 0.25),
    ('F5', 1.0), ('Eb5', 1.0), ('Bb4', 0.5), ('F4', 0.25), ('Eb4', 0.25),
    ('Bb4', 1.0), ('F5', 1.0), ('Eb5', 1.0), ('Bb4', 0.5), ('F4', 0.25),
    ('Eb4', 0.25), ('C5', 1.0), ('D5', 1.0), ('Bb4', 0.5), ('F4', 0.25),
    ('G4', 0.25), ('A4', 1.0), ('Bb4', 0.5), ('Bb4', 0.5), ('F4', 0.5),
    ('Eb4', 0.25), ('Bb4', 0.25), ('F5', 1.0), ('Eb5', 1.0), ('Bb4', 0.5),
    ('F4', 0.25), ('Eb4', 0.25), ('Bb4', 1.0), ('F5', 1.0), ('Eb5', 1.0),
    ('Bb4', 0.5), ('F4', 0.25), ('Eb4', 0.25), ('C5', 1.0), ('D5', 1.0),
    ('Bb4', 0.5), ('F4', 0.25), ('G4', 0.25), ('A4', 1.0)
]

# Configurações de áudio
sample_rate = 44100
volume = 0.5

def generate_tone(frequency, duration):
    t = np.linspace(0, duration, int(sample_rate * duration), False)
    if frequency == 0.0:
        return np.zeros_like(t)
    wave = np.sin(2 * np.pi * frequency * t)
    return wave

def play_melody(melody):
    song = np.array([], dtype=np.float32)
    for note, duration in melody:
        freq = notes_freq.get(note, 0.0)
        tone = generate_tone(freq, duration)
        song = np.concatenate((song, tone, np.zeros(int(sample_rate * 0.02))))  # pausa curta entre notas
    song *= volume
    print("🎺 Tocando tema de Star Wars...")
    sd.play(song, sample_rate)
    sd.wait()
    print("✅ Fim da execução.")

# Executa
play_melody(melody)
