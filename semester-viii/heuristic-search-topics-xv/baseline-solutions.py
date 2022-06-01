import numpy as np
import time, random
import itertools

BIG_INT = 10000000000000000000

def load_matrix(file_path):
    matrix = np.load(f"{file_path}.npy")
    return matrix


# Computes the cost for a given solution
def make_span(solution, adjacency_matrix):
    """
    Computes the cost of a solution give a matrix
    of distances.

    Given a sequence of cities (possible solution) and
    a matrix of costs, it computes the cost of visiting all
    cities.

    Parameters
    ----------
    solution : list
        A list of integers representing a traveling salesman route.
    adjacency_matrix : list
        A 2D numpy array storing the cost of traveling between the cities.
    """
    cost = 0
    amount_of_cities = len(solution)
    for i in range(amount_of_cities):
        x = solution[i]
        if i+1 == len(solution):
            y = solution[0]
            cost += adjacency_matrix[x][y]
        else:
            y = solution[i+1]
            cost += adjacency_matrix[x][y]

    return cost


def brute_force(adjacency_matrix):
    cost = 0
    amount_of_cities = len(adjacency_matrix[0])
    best_solution_cost = BIG_INT
    best_solution = ()
    amount_of_solutions = 0
    start = time.time()
    try:
        for s in itertools.permutations(range(amount_of_cities)):
            if s[0] <= s[-1]:
                cost = make_span(s, adjacency_matrix)
                amount_of_solutions += 1
                print(f"Testando solução nº { amount_of_solutions }")
                if cost < best_solution_cost:
                    print(f"Encontrou uma solução melhor { cost }")
                    best_solution_cost = cost
                    best_solution = s
    except KeyboardInterrupt:
        end = time.time()
        print(f"O método de força bruta levou { end - start } segundos para achar a melhor solução")
        print(f"O menor custo encontrado foi { best_solution_cost }")
        print(f"A solução com menor custo é { best_solution }")
        print(f"A quantidade de soluções testadas foi { amount_of_solutions }")

def random_solutions(adjacency_matrix):
    amount_of_cities = len(adjacency_matrix[0])
    print(f"amount_of_cities {amount_of_cities}")
    amount_of_solutions = 0
    best_solution = BIG_INT
    t_end = time.time() + 30

    while time.time() < t_end:
        indexes = [i for i in range(amount_of_cities)]
        solution = []
        for i in range(amount_of_cities):
            index = random.choice(indexes)
            indexes.remove(index)
            solution.append(index)
        cost = make_span(solution, adjacency_matrix)
        if cost < best_solution:
            best_solution = cost
        print(f"solution: { solution } -> { cost }")
        amount_of_solutions += 1
    print(f"amount_of_solutions { amount_of_solutions }")
    print(f"best_solution { best_solution }")


if __name__ == "__main__":
    adjacency_matrix = load_matrix("./adjacency-lists/wi29.tsp")
    # random_solutions(adjacency_matrix)
    # brute_force(adjacency_matrix)
    print(make_span((0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 23, 26, 24, 25, 27, 28, 20, 22, 21, 18), adjacency_matrix))

# TODO
# - Aleatório: gerar soluções por 30s e armazenar a menor, executar 10x e fazer a média.
# - Força bruta: armazenar o tempo de execução e a melhor solução.