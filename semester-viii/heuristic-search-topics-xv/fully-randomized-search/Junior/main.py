from os.path import exists
import numpy as np
import time, random, csv


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
    for i in range(amount_of_cities):
        x = solution[i]
        if i+1 == len(solution):
            y = solution[0]
            cost += adjacency_matrix[x][y]
        else:
            y = solution[i+1]
            cost += adjacency_matrix[x][y]
    return cost


def seach_fully_randomized(adjacency_matrix):
    amount_of_cities = len(adjacency_matrix[0])
    limit_time = 60 * amount_of_cities / 1000
    best_solutions = []
    runtime = []
    for j in range(10):
        best_solution = BIG_INT
        t_end = time.time() + limit_time
        start_t = time.time()
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
        end_t = time.time()
        runtime.append(end_t - start_t)
        best_solutions.append(best_solution)
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
    algorithm = "BTA"
    if not results_exists:
        write_results_header()
    
    with open("./resultados.csv", "a") as results:
        report.insert(0, algorithm)
        report.insert(0, author)
        report.insert(0, city)
        writer = csv.writer(results)
        writer.writerow(report)


if __name__ == "__main__":
    countries = {
        "dj38.tsp": "Djibouti",
        "qa194.tsp": "Qatar",
        "uy734.tsp": "Uruguay",
        "wi29.tsp": "Western Sahara",
        "zi929.tsp": "Zimbabwe",
    }
    for file,country in countries.items():
        adjacency_matrix = load_adjacency_matrix(file)
        report = seach_fully_randomized(adjacency_matrix)
        save_report(country, report)