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
    return cost


def generate_initial_solution(amount_of_cities):
    indexes = [i for i in range(amount_of_cities)]
    initial_solution = []
    for i in range(amount_of_cities):
        index = random.choice(indexes)
        indexes.remove(index)
        initial_solution.append(index)

    initial_solution.append(initial_solution[0])
    return initial_solution


def two_opt_swap1(solution, neighborhood_size):
    neighbors = []

    for n in range(neighborhood_size):
        city1 = 0
        city2 = 0

        # Gerar duas cidades que serão trocadas
        while city1 == city2:
            # Evitar alterar a cidade de partida e chegada
            city1 = random.randint(1, len(solution)-2)
            city2 = random.randint(1, len(solution)-2)

        if city1 > city2:
            tmp = city1
            city1 = city2
            city2 = tmp

        tmp = solution[city1:city2]
        new_solution = solution[:city1] + tmp[::-1] + solution[city2:]
        neighbors.append(new_solution)

    return neighbors

def two_opt_swap2(solution, neighborhood_size):
    neighbors = []
    n = 0
    for i in range(1, len(solution)-2):
        for j in range(i+1, len(solution)):
            if j - i == 1: continue
            new_solution = solution[:]
            new_solution[i:j] = solution[j-1:i-1:-1]
            neighbors.append(new_solution)
            n += 1
            if n == neighborhood_size:
                break
        if n == neighborhood_size:
            break
    return neighbors


def tabu_search(dist_matrix):
    maxTabuSize = 10000

    amount_of_cities = len(dist_matrix[0])
    best_solution = generate_initial_solution(amount_of_cities)
    cost_best_solution = make_span(best_solution, dist_matrix)
    best_candidate = best_solution
    
    neighborhood_size = round(1000 * amount_of_cities / 29)

    # how long a tabu will last on tabu_list
    tabu_tenure = round(amount_of_cities / 5)
    
    # movements to avoid
    tabu_list = [best_candidate]
    tabu_list_tenures = [tabu_tenure]
    
    limit_time = 60 * amount_of_cities / 1000
    
    best_solutions = []
    runtimes = []
    for run in range(10):
        print(f"run nº {run}")
        start_time = time.time()
        end_time = start_time + limit_time
        while time.time() < end_time:
            neighbors = two_opt_swap2(best_candidate, neighborhood_size)
            best_candidate = neighbors[0]

            for sCandidate in neighbors:
                sCandidateCost = make_span(sCandidate, dist_matrix)
                best_candidate_cost = make_span(best_candidate, dist_matrix)
        
                if sCandidateCost < best_candidate_cost:
                    # caso a possível solução não for um tabu aceitá-la 
                    if sCandidate not in tabu_list:
                        best_candidate = sCandidate

                    # caso for um tabu então verificar seu mandato antes de aceitá-la
                    elif tabu_list_tenures[tabu_list.index(sCandidate)] == 0:
                        best_candidate = sCandidate


            if make_span(best_candidate, dist_matrix) < make_span(best_solution, dist_matrix):
                best_solution = best_candidate
                cost_best_solution = make_span(best_solution, dist_matrix)

            for i in range(len(tabu_list_tenures)):
                if tabu_list_tenures[i] > 0:
                    tabu_list_tenures[i] -= 1

            tabu_list.append(best_candidate)
            tabu_list_tenures.append(tabu_tenure)

            if len(tabu_list) > maxTabuSize:
                tabu_list.pop(0)
                tabu_list_tenures.pop(0)

        
        best_solutions.append(cost_best_solution)
        runtimes.append(time.time() - start_time)

    report = [
        round(np.mean(best_solutions)),
        round(np.std(best_solutions), 2),
        round(np.mean(runtimes), 2)
    ]

    return report


def save_report(city, report):
    results_exists = exists("./resultados.csv")
    author = "Junior"
    algorithm = "BT2opt"
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
        "dj38.tsp": "Djibouti",
        "qa194.tsp": "Qatar",
        "uy734.tsp": "Uruguay",
        "wi29.tsp": "Western Sahara",
        "zi929.tsp": "Zimbabwe",
    }

    for file,country in countries.items():
        print(f"Country = {country}")
        dist_matrix = load_adjacency_matrix(file)
        report = tabu_search(dist_matrix)
        save_report(country, report)
