# Function to simulate the DFA
def simulate_DFA(DFA, start_state, accept_states, s):
    current_state = start_state
    for symbol in s:
        # Move to the next state according to the transition function
        current_state = DFA[current_state][symbol]
    # The string is accepted if the final state is an accept state
    return current_state in accept_states

def main():
    DFA = {}  # The transition function of the DFA, represented as a nested dictionary
    num_states = int(input("Enter the number of states: "))
    symbols = input("Enter the symbols, separated by space: ").split()

    # Input the transition function
    for i in range(num_states):
        DFA[i] = {}
        for symbol in symbols:
            # Input the state reachable from state i on symbol
            DFA[i][symbol] = int(input(f"Enter the state from state {i} on symbol {symbol}: "))

    # Input the start state and the accept states
    start_state = int(input("Enter the start state: "))
    accept_states = set(map(int, input("Enter the accept states, separated by space: ").split()))

    # Input the string to be checked
    s = input("Enter the string to be checked: ")

    # Check if the string is accepted by the DFA
    if simulate_DFA(DFA, start_state, accept_states, s):
        print(f"The string '{s}' is accepted by the DFA.")
    else:
        print(f"The string '{s}' is not accepted by the DFA.")

if __name__ == "__main__":
    main()