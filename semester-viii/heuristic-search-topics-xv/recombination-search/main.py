from os.path import exists
import numpy as np
import time, random, csv, math

BIG_INT = 10000000000000000000

def load_adjacency_matrix(country):
    """
    Load adjacency matrix given a country
    """
    matrix = np.load(f"./adjacency-matrices/{country}.npy")
    return matrix


def make_span(solution, adjacency_matrix):
    """
    Computes the cost of a solution given a matrix
    of distances.
    Given a sequence of cities (possible solution) and
    a matrix of costs, it computes the cost of visiting all
    cities and returning to the first one.
    Parameters
    ----------
    solution : list
        A list of integers representing a traveling salesman route.
    adjacency_matrix : list
        A 2D numpy array storing the cost of traveling between cities.
    """
    cost = 0
    amount_of_cities = len(solution)
    for i in range(amount_of_cities-1):
        x = solution[i]
        y = solution[i+1]
        cost += adjacency_matrix[x][y]
    x = solution[0]
    y = solution[amount_of_cities-1]
    cost += adjacency_matrix[x][y]
    return cost


def round_up_to_nearest_even_number(num):
    return math.ceil(num / 2) * 2


def generate_initial_population(amount_of_cities):
    amount_of_initial_solutions = round_up_to_nearest_even_number(math.sqrt(amount_of_cities))
    population = []
    for n in range(amount_of_initial_solutions):
        indexes = [i for i in range(amount_of_cities)]
        solution = []
        for i in range(amount_of_cities):
            index = random.choice(indexes)
            indexes.remove(index)
            solution.append(index)
        population.append(solution)
    return population


def generate_pairs(population_len):
    pairs = []
    indexes = [i for i in range(population_len)]
    for i in range(population_len // 2):
        index1 = random.choice(indexes)
        indexes.remove(index1)
        index2 = random.choice(indexes)
        indexes.remove(index2)
        pairs.append((index1, index2))
    return pairs


def alternating_edge_crossover(p1, p2):
    initial_city = random.randint(0, len(p1)-1)
    child = [initial_city]
    remaining_cities = [i for i in range(len(p1))]
    remaining_cities.remove(child[-1])
    for i in range(len(p1)-1):
        if i % 2 == 0:
            p1_index = p1.index(child[-1])
            p1_index = p1_index + 1 if p1_index < len(p1)-1 else 0
            if p1[p1_index] in child:
                city = random.choice(remaining_cities)
                child.append(city)
                remaining_cities.remove(city)
            else:
                child.append(p1[p1_index])
                remaining_cities.remove(p1[p1_index])
        else:
            p2_index = p2.index(child[-1])
            p2_index = p2_index + 1 if p2_index < len(p2)-1 else 0
            if p2[p2_index] in child:
                city = random.choice(remaining_cities)
                child.append(city)
                remaining_cities.remove(city)
            else:
                child.append(p2[p2_index])
                remaining_cities.remove(p2[p2_index])
    return child


def get_best_solutions(solutions, n_bests, dist_matrix):
    """
    Returns n_best solutions
    """
    cost_solution = {}
    for s in solutions:
        cost = make_span(s, dist_matrix)
        cost_solution[cost] = s
    
    costs = sorted(cost_solution.keys())

    best_solutions = []
    for i in range(n_bests):
        c = costs.pop(0)
        best_solutions.append(cost_solution[c])

    return best_solutions


def recombination_search(dist_matrix):
    amount_of_cities = len(dist_matrix[0])
    time_limit = 180 * amount_of_cities / 1000
    best_solutions = []
    runtime = []
    population = generate_initial_population(amount_of_cities)
    for j in range(10):
        t_end = time.time() + time_limit
        t_start = time.time()
        best_solution_cost = BIG_INT

        while time.time() < t_end:
            child_solutions = []
            pairs = generate_pairs(len(population))
            for p in pairs:
                p1, p2 = p
                child1 = alternating_edge_crossover(population[p1], population[p2])
                child2 = alternating_edge_crossover(population[p2], population[p1])
                child_solutions.append(child1)
                child_solutions.append(child2)

            # Swaps two elements from 20% child solutions
            mutation_amount = round(20 * len(child_solutions) / 100)
            child_solution_indexes = [i for i in range(len(child_solutions))]

            for m in range(mutation_amount):
                child_solution_index = random.choice(child_solution_indexes)
                swap_index1 = random.randint(0, amount_of_cities-1)
                swap_index2 = random.randint(0, amount_of_cities-1)

                # Prevents choosing the same child for swaping
                while swap_index1 == swap_index2:
                    swap_index2 = random.randint(0, amount_of_cities-1)

                temp = child_solutions[child_solution_index][swap_index1]
                child_solutions[child_solution_index][swap_index1] = child_solutions[child_solution_index][swap_index2]
                child_solutions[child_solution_index][swap_index2] = temp
                child_solution_indexes.remove(child_solution_index)

            # Natural selection
            n_parents = round(20 * len(population) / 100)
            n_childs = len(population) - n_parents
            best_parent_solutions = get_best_solutions(population, n_parents, dist_matrix)
            best_child_solutions = get_best_solutions(child_solutions, n_childs, dist_matrix)
            population.clear()
            population += best_parent_solutions + best_child_solutions

            best_solution = get_best_solutions(population, 1, dist_matrix)[0]

            local_best_solution = make_span(best_solution, dist_matrix)
            if local_best_solution < best_solution_cost:
                best_solution_cost = local_best_solution

        best_solutions.append(best_solution_cost)
        runtime.append(time.time() - t_start)

    report = [
        round(np.mean(best_solutions)),
        round(np.std(best_solutions), 2),
        round(np.mean(runtime))
    ]

    return report


def write_results_header():
    """
    Writes report file header
    """
    with open("./resultados.csv", "w") as results:
        header = [
            "instancia", "autoria", "algoritmo",
            "q-medio", "q-desvio", "t-medio"
        ]
        writer = csv.writer(results)
        writer.writerow(header)


def save_report(city, report):
    results_exists = exists("./resultados.csv")
    author = "Junior"
    algorithm = "AGAEX"
    if not results_exists:
        write_results_header()
    
    with open("./resultados.csv", "a") as results:
        report.insert(0, algorithm)
        report.insert(0, author)
        report.insert(0, city)
        writer = csv.writer(results)
        writer.writerow(report)


# O tipo de recombinação escolhida foi:
# Alternating Edge Crossover - AGAEX
if __name__ == "__main__":
    countries = {
        "dj38.tsp": "Djibouti",
        "qa194.tsp": "Qatar",
        "wi29.tsp": "Western Sahara",
    }

    for file,country in countries.items():
        dist_matrix = load_adjacency_matrix(file)
        report = recombination_search(dist_matrix)
        save_report(country, report)