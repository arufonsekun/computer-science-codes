from os.path import exists
import numpy as np
import time, random, csv


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


def ant_colony_search():
    pass


def save_report(city, report):
    results_exists = exists("./resultados.csv")
    author = "Junior"
    algorithm = "BCCF"
    if not results_exists:
        write_results_header()
    
    with open("./resultados.csv", "a") as results:
        report.insert(0, algorithm)
        report.insert(0, author)
        report.insert(0, city)
        writer = csv.writer(results)
        writer.writerow(report)


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


if __name__ == "__main__":
    countries = {
        # "dj38.tsp": "Djibouti",
        # "qa194.tsp": "Qatar",
        # "uy734.tsp": "Uruguay",
        "wi29.tsp": "Western Sahara",
        # "zi929.tsp": "Zimbabwe",
    }

    for file,country in countries.items():
        print(f"Country = {country}")
        dist_matrix = load_adjacency_matrix(file)
        report = ant_colony_search(dist_matrix)
        save_report(country, report)