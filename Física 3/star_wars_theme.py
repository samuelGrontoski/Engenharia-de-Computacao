import numpy as np
import sounddevice as sd

# Dicionário com frequências das notas (em Hz)
notes_freq = {
    'A3': 220.00, 'Bb3': 233.08, 'B3': 246.94, 'C4': 261.63, 'Db4': 277.18, 'D4': 293.66, 'Eb4': 311.13, 'E4': 329.63,
    'F4': 349.23, 'Gb4': 369.99, 'G4': 392.00, 'Ab4': 415.30, 'A4': 440.00, 'Bb4': 466.16, 'B4': 493.88,
    'C5': 523.25, 'Db5': 554.37, 'D5': 587.33, 'Eb5': 622.25, 'E5': 659.25, 'F5': 698.46, 'Gb5': 739.99, 'G5': 783.99,
    'Ab5': 830.61, 'A5': 880.00, 'Bb5': 932.33, 'B5': 987.77, 'C6': 1046.50, 'D6': 1174.66, 'Eb6': 1244.51,
    'F6': 1396.91, 'REST': 0.0
}

# Nova melodia com acordes (notas simultâneas)
melody = [
    (['Bb4'], 0.5), (['Bb4'], 0.5), (['F4'], 0.5), (['Eb4'], 0.25), (['Bb4'], 0.25),
    (['F5', 'D5'], 1.0), (['Eb5', 'C5'], 1.0), (['Bb4'], 0.5), (['F4'], 0.25), (['Eb4'], 0.25),
    (['Bb4'], 1.0), (['F5'], 1.0), (['Eb5'], 1.0), (['Bb4'], 0.5), (['F4'], 0.25),
    (['Eb4'], 0.25), (['C5'], 1.0), (['D5'], 1.0), (['Bb4'], 0.5), (['F4'], 0.25),
    (['G4'], 0.25), (['A4'], 1.0),

    # Refrão com acordes
    (['Bb4', 'D5'], 0.5), (['C5', 'Eb5'], 0.5), (['D5', 'F5'], 1.0),
    (['Bb4'], 0.5), (['C5'], 0.5), (['D5'], 1.0),
    (['Eb5'], 0.25), (['F5'], 0.25), (['G5'], 1.0),
    (['REST'], 0.25), (['F5'], 0.25), (['Eb5'], 0.5), (['D5'], 0.5), (['C5'], 0.5), (['Bb4'], 1.0)
]

# Configurações de áudio
sample_rate = 44100
volume = 0.5

def generate_tone(frequencies, duration):
    t = np.linspace(0, duration, int(sample_rate * duration), False)
    if all(freq == 0.0 for freq in frequencies):
        return np.zeros_like(t)
    waves = [np.sin(2 * np.pi * freq * t) for freq in frequencies if freq > 0]
    combined = np.sum(waves, axis=0)
    return combined / len(waves)  # normaliza o volume

def play_melody(melody):
    song = np.array([], dtype=np.float32)
    for notes, duration in melody:
        freqs = [notes_freq.get(note, 0.0) for note in notes]
        tone = generate_tone(freqs, duration)
        pause = np.zeros(int(sample_rate * 0.02))
        song = np.concatenate((song, tone, pause))
    song *= volume
    print("🎺 Tocando Star Wars com acordes...")
    sd.play(song, sample_rate)
    sd.wait()
    print("✅ Finalizado com polifonia.")

# Executa
play_melody(melody)
