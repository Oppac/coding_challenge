import string
import random

LETTERS = " " + string.ascii_letters

def gen_new_pop(pop_nb, mutation, pop):
    mating_pool = []
    for p in pop:
        for _ in range(p[1]):
            mating_pool.append(p[0])

    new_pop = []
    for i in range(pop_nb):
        pa = random.choice(mating_pool)
        pb = random.choice(mating_pool)
        while not pb != pa:
            pb = random.choice(mating_pool)
        pal = random.randint(1, len(pa)-1)
        child = pa[:pal] + pb[pal:]

        for l in range(len(child)):
            if random.random() < mutation:
                child[:l] + random.choice(LETTERS) + child[l+1:]
        new_pop.append(child)
    return new_pop

def fitness_pop(target_str, pop):
    fitness = [len([target_str[i] for i in range(len(target_str))
               if target_str[i] == pop[p][i]]) for p in range(len(pop))]
    return [p for p in list(zip(pop, fitness)) if p[1] > 0]

def best_guesses(pop):
    maxi = max(p[1] for p in pop)
    return set(p for p in pop if p[1] == maxi)

def check_solution(target_str, pop):
    for p in pop:
        if p[0] == target_str: return True
    return False

def main():
    target_str = "Jade is cute"
    pop_nb = 10000
    mutation_rate = 0.1

    init_pop = [''.join(random.choice(LETTERS) for i in range(len(target_str)))
                for _ in range(pop_nb)]

    pop = fitness_pop(target_str, init_pop)
    print(best_guesses(pop))
    print()

    i = 0
    while True:
        print(f"Generation {i}")
        pop = gen_new_pop(pop_nb, mutation_rate, pop)
        pop = fitness_pop(target_str, pop)
        print(best_guesses(pop))
        print()
        if check_solution(target_str, pop): break
        i += 1



main()
