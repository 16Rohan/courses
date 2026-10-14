import random

class chrome:
    def __init__(self, binstr):
        self.binstr = binstr
        self.fitness = 0
        self.fit_percent = 0

def copy_chromo(chromo: chrome):
    temp = chrome(chromo.binstr)
    temp.fit_percent = chromo.fit_percent
    temp.fitness = chromo.fitness
    return temp

def calculate_fitness(population: list[chrome]):
    total_fitness = 0
    for i in range(len(population)):
        fitness_cur = fitness(population[i].binstr)
        total_fitness += fitness_cur
    
    for i in range(len(population)):
        population[i].fit_percent = population[i].fitness / total_fitness

def goal_reached(population: list[chrome]):
    for chromo in population:
        if chromo.fitness == 8:
            return True
    return False

def crossover_strs(chromo1, chromo2):
    crossover_point = random.randint(1,7)
    temp1 = chromo1[:crossover_point] + chromo2[crossover_point:]
    temp2 = chromo2[:crossover_point] + chromo1[crossover_point:]
    return temp1, temp2

def crossover_pops(population: list[chrome]):
    population.sort(key = lambda x: x.fit_percent)
    for i in range(0, len(population), 2):
        population[i].binstr, population[i+1].binstr = crossover_strs(population[i].binstr, population[i+1].binstr)
    
def mutate_population(population: list[chrome]):
    mutate_1_MAX = 20
    mutate_2_MAX = 75
    mutation_chance = random.randint(1,100)

    if mutation_chance > mutate_1_MAX:




def fitness(chromo):
    # pop is a binary string, we have to count the number of 1s in the binary string.
    return chromo.count("1")

def init_population(str_list):
    popset = list
    for chromo in str_list:
        popset.append(chrome(chromo, 0))

    return popset

def sanitize_input(str_list):
    for i in range(len(str_list)):
        leftover = 8 - len(str_list[i])
        if leftover > 0:
            str_list[i] = "0"*leftover + str_list[i]
        elif leftover < 0:
            str_list[i] = str_list[i][:8]
    

if __name__ == "__main__":
    bin_input = input("Enter four binary strings: ")
    str_list = bin_input.split()
    sanitize_input(str_list)
    print("Input Sanitized")

    population = init_population(str_list)
    new_population = set()

    while True:
        # Fitness Calculation
        # Fitness Percentage
        calculate_fitness(population)
        if goal_reached(population):
            break        
        # Crossover
        crossover_pops(population)
        # Mutation
        mutate_population(population)


