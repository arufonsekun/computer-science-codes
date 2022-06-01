import os
import numpy as np

def get_file_list(path) -> list:
    """
    Generates a list of file names given a path.

    This function lists all files given a dir path
    and returs a list of file names.

    Parameters
    ----------
    path : str
        A directory path
    
    Returns
    -------
    list
        A list of file names.

    Example
    -------
    >>> get_file_list("./problem-instances")
    ["ar9152.tsp", "bm33708.tsp", ..., "zi929.tsp"]
    """
    with os.popen(f"ls { path }") as problem_files:
        files = problem_files.readlines()
        return [f.rstrip() for f in files]


def read_problem_instance(path, problem_file_name) -> list:
    with open(f"{path}{ problem_file_name }") as problem_file:
        lines = problem_file.readlines()
        total_lines_except_eof = len(lines) - 1
        return [f.rstrip() for f in lines[7:total_lines_except_eof]]
        

def compute_adjacency_list(points, problem_file_name):
    shape = (len(points), len(points))
    adjacency_matrix = np.zeros(shape, dtype=int)

    for point in points:
        index, x1, y1 = point.split(" ")
        print(f"Computing distances for city {index}")
        for i in range(int(index), len(points)):
            point1 = np.array((float(x1), float(y1)))
            _, x2, y2 = points[i].split(" ")
            point2 = np.array((float(x2), float(y2)))
            adjacency_matrix[int(index) -1][i] = round(np.linalg.norm(point1 - point2))
            adjacency_matrix[i][int(index) -1] = round(np.linalg.norm(point1 - point2))

    with open(f"./adjacency-lists/{problem_file_name}.npy", "wb") as f:
        np.save(f, adjacency_matrix)

if __name__ == "__main__":
    problem_files = get_file_list("./problem-instances/")
    print(problem_files[23])
    points = read_problem_instance("./problem-instances/", problem_files[23])
    compute_adjacency_list(points, problem_files[23])
