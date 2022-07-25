from os.path import exists
import numpy as np
import time, random, csv

ALPHA = 30

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


def all_candidates_already_in_solution(solution, i, candidates_cost, dist_matrix):
    for cost in candidates_cost:
        candidate = np.where(dist_matrix[solution[i]] == cost)[0][0]
        if candidate not in solution:
            return False
    return True


def closest_neighbors(dist_matrix):
    amount_of_cities = len(dist_matrix[0])
    amount_of_best_cadidates = round(ALPHA * amount_of_cities / 100)
    limit_time = 60 * amount_of_cities / 1000
    best_solutions_costs = []
    runtime = []
    
    for j in range(10):
        print(f"Running nº { j }")
        end_time = time.time() + limit_time
        start_time = time.time()
        best_solution_cost = 100000000

        while time.time() < end_time:
            initial_random_city = random.randint(0, amount_of_cities-1)
            solution = [initial_random_city]
            for i in range(amount_of_cities):
                # candidates are evaluated by closest neighbors
                neighbors = sorted(dist_matrix[solution[i]])

                # if all candidates already are in the solution, then get the
                # best candidate that follows (amount_of_best_cadidates+1)
                if all_candidates_already_in_solution(solution, i, neighbors[1:amount_of_best_cadidates+1], dist_matrix):
                    new_cadidate_cost = neighbors[amount_of_best_cadidates+1]
                    new_candidate = np.where(dist_matrix[solution[i]] == new_cadidate_cost)[0][0]
                
                # otherwise chooses randomly a candidate from 30% of closest neighbors
                else:
                    # slice start in 1 to ignore cost = 0
                    new_cadidate_cost = random.choice(neighbors[1:amount_of_best_cadidates+1])
                    
                    # always considers first occurence of that cost -> [0][0]
                    new_candidate = np.where(dist_matrix[solution[i]] == new_cadidate_cost)[0][0]

                    # Keeps choosing a new candidate if the
                    # first one choose is already in the solution
                    while new_candidate in solution:
                        # slice start in 1 to ignore cost = 0
                        new_cadidate_cost = random.choice(neighbors[1:amount_of_best_cadidates+1])
                        # always consider first occurence of that cost
                        new_candidate = np.where(dist_matrix[solution[i]] == new_cadidate_cost)[0][0]

                solution.append(new_candidate)

            cost = make_span(solution, dist_matrix)
            if cost < best_solution_cost:
                best_solution_cost = cost
            
        best_solutions_costs.append(best_solution_cost)
        runtime.append(time.time() - start_time)
    
    report = [
        round(np.mean(best_solutions_costs)),
        round(np.std(best_solutions_costs), 2),
        round(np.mean(runtime))
    ]
    
    return report

def save_report(city, report):
    results_exists = exists("./resultados.csv")
    author = "Junior"
    algorithm = "BCGα"
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
        report = closest_neighbors(dist_matrix)
        save_report(country, report)