# Function to compute lambda closure for a given state
def lambda_closure(state, NFA):
    closure = {state}  # Start with the given state
    # For each state reachable by a lambda transition
    for new_state in NFA[state].get('lambda', []):
        # Add the lambda closure of the new state
        closure |= lambda_closure(new_state, NFA)
    return closure

# Function to compute the set of states reachable from a set of states on a given symbol
def move(states, symbol, NFA):
    result = set()
    for state in states:
        # Add all states reachable from the current state on the given symbol
        result |= set(NFA[state].get(symbol, []))
    return result

def main():
    NFA = {}  # The transition function of the NFA, represented as a nested dictionary
    num_states = int(input("Enter the number of states: "))
    num_symbols = int(input("Enter the number of symbols: "))

    # Input the transition function
    for i in range(num_states):
        NFA[i] = {}
        for j in range(num_symbols):
            # Input the states reachable from state i on symbol j
            NFA[i][j] = list(map(int, input(f"Enter the states from state {i} on symbol {j}, separated by space: ").split()))
        # Input the states reachable from state i by lambda transitions
        NFA[i]['lambda'] = list(map(int, input(f"Enter the lambda transitions from state {i}, separated by space: ").split()))

    # Input the initial state and the symbol
    q = int(input("Enter the initial state q: "))
    a = int(input("Enter the symbol a: "))

    # Compute δ(q, a)
    closure_q = lambda_closure(q, NFA)  # Compute the lambda closure of q
    move_q = move(closure_q, a, NFA)  # Compute the states reachable from closure_q on symbol a
    result_q = set()
    for state in move_q:
        # Add the lambda closure of each state in move_q
        result_q |= lambda_closure(state, NFA)

    print(f"δ(q{q}, {a}) = {sorted(list(result_q))}")

    # Input the set of states T
    T = list(map(int, input("Enter the set of states T, separated by space: ").split()))

    # Compute δ(T, a)
    closure_T = set()
    for state in T:
        # Compute the lambda closure of each state in T
        closure_T |= lambda_closure(state, NFA)
    move_T = move(closure_T, a, NFA)  # Compute the states reachable from closure_T on symbol a
    result_T = set()
    for state in move_T:
        # Add the lambda closure of each state in move_T
        result_T |= lambda_closure(state, NFA)

    print(f"δ(T, {a}) = {sorted(list(result_T))}")

if __name__ == "__main__":
    main()