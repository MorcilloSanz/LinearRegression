import matplotlib.pyplot as plt

def read_data() -> tuple[list[int], list[float]]:
    
    loss: list[float] = []
    epochs: int = 0

    file = open("loss.txt", "r")

    for line in file    :
        line.strip()
        losses: list[str] = line.split(" ")
        for l in losses:
            loss.append(float(l))
            epochs += 1

    file.close()

    return loss, list(range(1, epochs + 1))


if __name__ == "__main__":

    loss, epochs = read_data()

    plt.figure()
    plt.plot(epochs, loss, linestyle='-')
    plt.title('Loss vs Epochs')
    plt.xlabel('Epoch')
    plt.ylabel('Loss')
    plt.grid(True)
    plt.show()