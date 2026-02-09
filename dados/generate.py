import random
import sys

def generate_input(filename, n, w_max, v_max, p_max):
    with open(filename, 'w') as f:
        f.write(f"{n} {w_max}\n\n")
        for _ in range(n):
            v = random.randint(10, v_max)
            p = random.randint(1, p_max)
            f.write(f"{v} {p}\n")

if __name__ == "__main__":
    # enerate_input("input0.txt", 3, 50, 50, 20) # exemplo manual
    #generate_input("input1.txt", 10, 50, 50, 20) # 10^1
    #generate_input("input2.txt", 100, 500, 100, 50) # 10^2
    #generate_input("input3.txt", 1000, 2000, 200, 100) # 10^3
    #generate_input("input4.txt", 10000, 10000, 500, 200) # 10^4
    #generate_input("input5.txt", 100000, 50000, 1000, 500) # 10^5
    #generate_input("input6.txt", 1000000, 500000, 10000, 5000) # 10^6
    #generate_input("input7.txt", 10000000, 5000000, 100000, 50000) # 10^7
    generate_input("input8.txt", 100000000, 50000000, 1000000, 500000) # 10^8
    print("Files generated!")
