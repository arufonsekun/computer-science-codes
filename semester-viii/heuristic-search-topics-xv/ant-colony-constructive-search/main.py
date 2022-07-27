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


def get_range_factor(p):
    factor = 1
    while p < 1:
        p = p * 10
        factor = factor * 10
    return factor


def get_neighbor_from_ranges(random_range, neighbor_ranges):
    next_neighbor = 0
    for r in neighbor_ranges:
        if random_range > r[0] and random_range <= r[1]:
            return next_neighbor
        next_neighbor += 1
    return next_neighbor-1


def ant_colony_search(dist_matrix):
    amount_of_cities = len(dist_matrix[0])
    limit_time = 60 * amount_of_cities / 1000
    best_solutions_costs = []
    runtime = []
    feromone = np.zeros((amount_of_cities, amount_of_cities), dtype=float)
    feromone.fill(amount_of_cities)

    for j in range(10):
        print(f"Running nº { j }")
        end_time = time.time() + limit_time
        start_time = time.time()
        best_solution_cost = 100000000

        while time.time() < end_time:
            initial_random_city = random.randint(0, amount_of_cities-1)
            solution = [initial_random_city]

            for n in range(amount_of_cities-1):
                v_total = 0
                # last city added to the solution
                anchor = solution[-1]
                # Computes the summation of feromone / distance
                for i in range(amount_of_cities):
                    if i == anchor: continue
                    v = feromone[anchor][i] / dist_matrix[anchor][i]
                    v_total += v

                ranges = []
                for i in range(amount_of_cities):
                    if i == anchor:
                        # To avoid appending 0 then append amount_of_cities instead
                        ranges.append(amount_of_cities)
                        continue
                    v = feromone[anchor][i] / dist_matrix[anchor][i]
                    p = v / v_total
                    ranges.append(p)

                range_factor = get_range_factor(min(ranges))
                ranges[ranges.index(amount_of_cities)] = -1
                ranges_normalized = [int(x * range_factor) for x in ranges]
                ranges_normalized[ranges_normalized.index(-range_factor)] = -1
                neighbor_ranges = []

                ranges_sum = sum(ranges_normalized) + 1
                if ranges_sum < range_factor:
                    remaining_range = range_factor - ranges_sum
                    for r in range(remaining_range):
                        if ranges_normalized[r] != 0:
                            ranges_normalized[r] += 1

                for r in range(len(ranges_normalized)):
                    if ranges_normalized[r] == -1:
                        neighbor_ranges.append((-1, -1))
                        continue
                    if r == 0:
                        neighbor_ranges.append((0, ranges_normalized[0]))
                    else:
                        previous_range = neighbor_ranges[-2][1] if neighbor_ranges[-1][1] == -1 else neighbor_ranges[-1][1]
                        neighbor_ranges.append((previous_range, previous_range + ranges_normalized[r]))
                
                random_range = random.randint(1, range_factor-1)
                next_neighbor = get_neighbor_from_ranges(random_range, neighbor_ranges)
                while next_neighbor in solution:
                    random_range = random.randint(0, range_factor-1)
                    next_neighbor = get_neighbor_from_ranges(random_range, neighbor_ranges)

                solution.append(next_neighbor)

            cost = make_span(solution, dist_matrix)
            feromone_update_factor = 0
            if cost < best_solution_cost:
                best_solution_cost = cost
                feromone_update_factor = 1.2
            else:
                feromone_update_factor = 0.8

            for f in range(amount_of_cities-1):
                x = solution[f]
                y = solution[f+1]
                feromone[x][y] *= feromone_update_factor
            x = solution[0]
            y = solution[amount_of_cities-1]
            feromone[x][y] *= feromone_update_factor

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
        "dj38.tsp": "Djibouti",
        "qa194.tsp": "Qatar",
        "uy734.tsp": "Uruguay",
        "wi29.tsp": "Western Sahara",
        "zi929.tsp": "Zimbabwe",
    }

    for file,country in countries.items():
        print(f"Country = {country}")
        dist_matrix = load_adjacency_matrix(file)
        report = ant_colony_search(dist_matrix)
        save_report(country, report)