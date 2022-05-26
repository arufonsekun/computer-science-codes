import numpy as np
import time, random

def load_matrix(file_path):
    matrix = np.load(file_path)
    return matrix


# Computes the cost for a given solution
def make_span(solution, adjacency_matrix):
    cost = 0
    for i in range(solution):
        if i+1 == len(solution):
            print(f"adjacency_matrix[i][0] = {adjacency_matrix[i][0]}")
            cost += adjacency_matrix[i][0]
        else:
            print(f"adjacency_matrix[i][i+1] = {adjacency_matrix[i][i+1]}")
            cost += adjacency_matrix[i][i+1]


def random_solutions(adjacency_matrix):
    t_end = time.time() + 30

    while time.time() < t_end:
        indexes = [i for i in range(29)]
        solution = []
        for i in range(29):
            index = random.choice(indexes)
            indexes.remove(index)
            solution.append(index)
        print(f"solution: { solution }")
        cost = make_span(solution, adjacency_matrix)


if __name__ == "__main__":
    adjacency_matrix = load_matrix("./adjacency-lists/wi29.tsp.npy")
    solution = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28]
    make_span(solution, )


# TODO
# - Aleatório: gerar soluções por 30s e armazenar a menor, executar 10x e fazer a média.
# - Força bruta: armazenar o tempo de execução e a melhor solução.