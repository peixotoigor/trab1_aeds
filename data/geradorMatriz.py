import random

# Dimensão da matriz
rows, cols = 10,10
# Cálculo do total de células e distribuição
total_cells = rows * cols  
num_ones = int(total_cells * 0.7)  # arvores saudaveis
num_zeros = int(total_cells * 0.2) # espaços vazios
num_fours = total_cells - num_ones - num_zeros  # agua

# Geração inicial de uma lista com os valores distribuídos
cell_values = [1] * num_ones + [0] * num_zeros + [4] * num_fours

random.shuffle(cell_values)

# Transformar a lista de valores em uma matriz
matrix = [
    [cell_values[i * cols + j] for j in range(cols)]
    for i in range(rows)
]

# Escolher uma posição aleatória para o fogo e marcá-la como 2
fire_position = (random.randint(0, rows - 1), random.randint(0, cols - 1))
matrix[fire_position[0]][fire_position[1]] = 2

try:
    file_name = "../data/matriz.dat"
    with open(file_name, "w") as file:
        file.write(f"{rows} {cols} {fire_position[0]} {fire_position[1]}\n")
        for row in matrix:
            file.write(" ".join(map(str, row)) + "\n")
    print(
        f"Matriz '{rows}x{cols}' salva no arquivo '{file_name}' com sucesso!")
except Exception as e:
    print(f"Erro ao salvar o arquivo: {e}")
