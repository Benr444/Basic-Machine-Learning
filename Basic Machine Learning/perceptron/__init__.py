import numpy as np

CLASS_A = 1;
CLASS_B = -1;
threshold = 1; #See unit_step function definition
learning_rate = 0.5; #How much weights change for every set, 0 -> 1

dataset = [[50,30,CLASS_A],[0,0,CLASS_B],[20,40,CLASS_A],[4,3,CLASS_B],[0,0.1,CLASS_B]]

def decide(z_val):
    if (z_val >= threshold):
        return CLASS_A
    else:
        return CLASS_B


w = np.array([[0.1],[0.3]]) #Weighting for each input, 0 -> 1
for i in range(0, len(dataset)):
    x = np.array(dataset[i][0:2]).T
    z = w.T.dot(x) #Culumlation of x and w
    output = decide(z)
    for r in range(0, len(w)):
        for c in range(0, len(w[r])):
            d_weight = (learning_rate * (dataset[i][2] - output) * x[c]);
            w[r][c] = w[r][c] + d_weight
    
    print("In entry index " + str(i) + ", \n" + "    The true class was " + str(dataset[i][2]) + "\n" + "    The guessed class was " + str(output) + "\n" + "    w_0 = " + str(w[0][0]) + "\n" + "    w_1 = " + str(w[1][0]))

print("Finished")